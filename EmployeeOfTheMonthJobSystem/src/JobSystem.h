#pragma once
#include <thread>
#include <condition_variable>
#include <vector>
#include <queue>
#include <functional>
#include "ThreadSafeCircularBuffer.h"

namespace FretBuzz
{
	class JobSystem
	{
	private:
		//singleton instance
		static JobSystem* s_pInstance;
		JobSystem();
		~JobSystem();

		static constexpr size_t JOB_POOL_CAPACITY = 100;
		bool m_bIsActivated = true;
		std::condition_variable m_WakeCondition;
		std::mutex m_Mutex;
		size_t m_iTotalThreads = 0;
		uint64_t m_JobsStarted = 0;
		std::atomic<uint64_t> m_JobsFinished;
		ThreadSafeCircularBuffer<std::function<void()>, JOB_POOL_CAPACITY> m_JobPool;

	public:
		static JobSystem* Initialize();
		void destroy();

		static bool IsBusy();
		static void Wait();

		static void Execute(const std::function<void()>& a_Job);
	};
}