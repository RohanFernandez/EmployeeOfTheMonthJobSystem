#pragma once

namespace FretBuzz
{
	template<typename T_DATA, size_t BUFFER_CAPACITY>
	class ThreadSafeCircularBuffer
	{
	private:
		T_DATA m_Buffer[BUFFER_CAPACITY];
		std::mutex m_Mutex;
		size_t m_iHead = 0;
		size_t m_iTail = 0;

	public:
		ThreadSafeCircularBuffer() {};
		~ThreadSafeCircularBuffer() {};

		bool push(const T_DATA& a_Data)
		{
			bool l_bReturn = false;
			m_Mutex.lock();
			size_t l_iHeadPlus1Mod = (m_iHead + 1) % BUFFER_CAPACITY;
			if (l_iHeadPlus1Mod != m_iTail)
			{
				m_Buffer[m_iHead] = a_Data;
				m_iHead = l_iHeadPlus1Mod;
				l_bReturn = true;
			}
			m_Mutex.unlock();
			return l_bReturn;
		}

		bool pop(T_DATA& a_Data)
		{
			bool l_bReturn = false;
			m_Mutex.lock();
			if (m_iTail != m_iHead)
			{
				a_Data = m_Buffer[m_iTail];
				m_iTail = (m_iTail + 1) % BUFFER_CAPACITY;
				l_bReturn = true;
			}
			m_Mutex.unlock();
			return l_bReturn;
		}
	};
}