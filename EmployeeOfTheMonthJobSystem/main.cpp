#pragma once
#include <iostream>
#include "src/JobSystem.h"

constexpr int DATA_COUNT = 10000000;

void printSum(int* arrNums, int64_t& a_iAns)
{
	a_iAns = 0;
	for (size_t l_iIndex = 0; l_iIndex < DATA_COUNT; l_iIndex++)
	{
		a_iAns += arrNums[l_iIndex];
	}
}

//void printSum1(int* arrNums)
//{
//	int64_t l_iTotal = 0;
//
//	for (size_t l_iIndex = 0; l_iIndex < DATA_COUNT; l_iIndex++)
//	{
//		l_iTotal -= arrNums[l_iIndex];
//	}
//}
//
//void printSum2(int* arrNums)
//{
//	int64_t l_iTotal = 0;
//
//	for (size_t l_iIndex = 0; l_iIndex < DATA_COUNT; l_iIndex++)
//	{
//		l_iTotal += arrNums[l_iIndex];
//		l_iTotal += arrNums[l_iIndex];
//	}
//}
//
//void printSum3(int* arrNums)
//{
//	int64_t l_iTotal = 0;
//
//	for (size_t l_iIndex = 0; l_iIndex < DATA_COUNT; l_iIndex++)
//	{
//		l_iTotal -= arrNums[l_iIndex];
//		l_iTotal -= arrNums[l_iIndex];
//	}
//}

long long timer(std::chrono::high_resolution_clock::time_point& a_TimePoint1, std::chrono::high_resolution_clock::time_point& a_TimePoint2)
{
	return std::chrono::duration_cast<std::chrono::microseconds>(a_TimePoint2 - a_TimePoint1).count();
};

int main(int a_iArgC, char** a_ArgV)
{
	int* arrNums = new int[DATA_COUNT];
	for (size_t l_iIndex = 0; l_iIndex < DATA_COUNT; l_iIndex++)
	{
		arrNums[l_iIndex] = l_iIndex;
	}

	int64_t m_iAns1  = 0;
	int64_t m_iAns2  = 0;
	int64_t m_iAns3  = 0;
	int64_t m_iAns4  = 0;
	int64_t m_iAns5  = 0;
	int64_t m_iAns6  = 0;
	int64_t m_iAns7  = 0;
	int64_t m_iAns8  = 0;
	int64_t m_iAns9  = 0;
	int64_t m_iAns10 = 0;

	int64_t m_iAns11 = 0;
	int64_t m_iAns12 = 0;
	int64_t m_iAns13 = 0;
	int64_t m_iAns14 = 0;
	int64_t m_iAns15 = 0;
	int64_t m_iAns16 = 0;
	int64_t m_iAns17 = 0;
	int64_t m_iAns18 = 0;
	int64_t m_iAns19 = 0;
	int64_t m_iAns20 = 0;

	std::chrono::high_resolution_clock::time_point l_start;
	std::chrono::high_resolution_clock::time_point l_end;

#pragma BEGIN REGION PARALLEL

	FretBuzz::JobSystem* l_pJobSystem = FretBuzz::JobSystem::Initialize();

	l_start = std::chrono::high_resolution_clock::now();
	
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns1); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns2); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns3); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns4); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns5); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns6); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns7); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns8); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns9); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns10); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns11); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns12); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns13); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns14); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns15); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns16); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns17); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns18); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns19); });
	FretBuzz::JobSystem::Execute([&]() {printSum(arrNums, m_iAns20); });
	
	FretBuzz::JobSystem::Wait();
	l_end = std::chrono::high_resolution_clock::now();
	std::cout << "\n\nParallel Test : " << timer(l_start, l_end) << " microseconds\n ";
	std::cout <<
		  "Ans1  : " << m_iAns1 <<
		"\nAns2  : " << m_iAns2 <<
		"\nAns3  : " << m_iAns3 <<
		"\nAns4  : " << m_iAns4 <<
		"\nAns5  : " << m_iAns5 <<
		"\nAns6  : " << m_iAns6 <<
		"\nAns7  : " << m_iAns7 <<
		"\nAns8  : " << m_iAns8 <<
		"\nAns9  : " << m_iAns9 <<
		"\nAns10 : " << m_iAns10 <<
		"\nAns11 : " << m_iAns11 <<
		"\nAns12 : " << m_iAns12 <<
		"\nAns13 : " << m_iAns13 <<
		"\nAns14 : " << m_iAns14 <<
		"\nAns15 : " << m_iAns15 <<
		"\nAns16 : " << m_iAns16 <<
		"\nAns17 : " << m_iAns17 <<
		"\nAns18 : " << m_iAns18 <<
		"\nAns19 : " << m_iAns19 <<
		"\nAns20 : " << m_iAns20 << "\n";

	l_pJobSystem->destroy();

#pragma END REGION PARALLEL


#pragma BEGIN REGION SERIAL

	l_start = std::chrono::high_resolution_clock::now();
	printSum(arrNums, m_iAns1);
	printSum(arrNums, m_iAns2);
	printSum(arrNums, m_iAns3);
	printSum(arrNums, m_iAns4);
	printSum(arrNums, m_iAns5);
	printSum(arrNums, m_iAns6);
	printSum(arrNums, m_iAns7);
	printSum(arrNums, m_iAns8);
	printSum(arrNums, m_iAns9);
	printSum(arrNums, m_iAns10);
	printSum(arrNums, m_iAns11);
	printSum(arrNums, m_iAns12);
	printSum(arrNums, m_iAns13);
	printSum(arrNums, m_iAns14);
	printSum(arrNums, m_iAns15);
	printSum(arrNums, m_iAns16);
	printSum(arrNums, m_iAns17);
	printSum(arrNums, m_iAns18);
	printSum(arrNums, m_iAns19);
	printSum(arrNums, m_iAns20);

	l_end = std::chrono::high_resolution_clock::now();
	std::cout << "\n\nSerial Test : " << timer(l_start, l_end) << " microseconds\n";
	std::cout <<
		  "Ans1  : " << m_iAns1 <<
		"\nAns2  : " << m_iAns2 <<
		"\nAns3  : " << m_iAns3 <<
		"\nAns4  : " << m_iAns4 <<
		"\nAns5  : " << m_iAns5 <<
		"\nAns6  : " << m_iAns6 <<
		"\nAns7  : " << m_iAns7 <<
		"\nAns8  : " << m_iAns8 <<
		"\nAns9  : " << m_iAns9 <<
		"\nAns10 : " << m_iAns10 <<
		"\nAns11 : " << m_iAns11 <<
		"\nAns12 : " << m_iAns12 <<
		"\nAns13 : " << m_iAns13 <<
		"\nAns14 : " << m_iAns14 <<
		"\nAns15 : " << m_iAns15 <<
		"\nAns16 : " << m_iAns16 <<
		"\nAns17 : " << m_iAns17 <<
		"\nAns18 : " << m_iAns18 <<
		"\nAns19 : " << m_iAns19 <<
		"\nAns20 : " << m_iAns20 << "\n";

#pragma END REGION SERIAL

	system("pause");
	delete[] arrNums;

	return 0;
}