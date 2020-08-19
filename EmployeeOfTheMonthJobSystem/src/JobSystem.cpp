#include "JobSystem.h"
#include <iostream>
#include <string>

namespace FretBuzz
{
	//singleton instance
	JobSystem* JobSystem::s_pInstance = nullptr;

	JobSystem* JobSystem::Initialize()
	{
		if (s_pInstance != nullptr)
		{
			return nullptr;
		}
		s_pInstance = new JobSystem();
		return s_pInstance;
	}

	void JobSystem::destroy()
	{
		delete s_pInstance;
		s_pInstance = nullptr;
	}

	JobSystem::JobSystem()
	{
		m_JobsFinished.store(0);
		m_iTotalThreads = std::thread::hardware_concurrency();
		//std::cout << "Total Threads : " << m_iTotalThreads <<"\n";

		for (size_t l_iThreadIndex = 0; l_iThreadIndex < m_iTotalThreads; l_iThreadIndex++)
		{
			std::thread l_Thread(
				[this, l_iThreadIndex]() {

					std::function<void()> l_Job;
					while (m_bIsActivated)
					{
						//std::cout << std::to_string(l_iThreadIndex) <<"\t" << std::this_thread::get_id() << "\n";

						if (m_JobPool.pop(l_Job))
						{
							l_Job();
							m_JobsFinished.fetch_add(1);
						}
						else
						{
							std::unique_lock<std::mutex> l_Lock(m_Mutex);
							m_WakeCondition.wait(l_Lock);
						}
					}
				});

			l_Thread.detach();
		}
	}

	JobSystem::~JobSystem()
	{
		m_bIsActivated = false;
		m_WakeCondition.notify_all();
	}

	bool JobSystem::IsBusy()
	{
		return s_pInstance->m_JobsFinished.load() < s_pInstance->m_JobsStarted;
	}

	void JobSystem::Wait()
	{
		while (IsBusy())
		{
			s_pInstance->m_WakeCondition.notify_one();
			std::this_thread::yield();
		}
	}

	void JobSystem::Execute(const std::function<void()>& a_Job)
	{
		++s_pInstance->m_JobsStarted;
		while (!s_pInstance->m_JobPool.push(a_Job))
		{
			s_pInstance->m_WakeCondition.notify_one();
			std::this_thread::yield();
		}
		s_pInstance->m_WakeCondition.notify_one();
	}
}