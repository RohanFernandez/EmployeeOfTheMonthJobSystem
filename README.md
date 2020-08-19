# **Job System**
A simple job system implementing the usage of my knowledge of multithreading in C++.

## **Initialize/ Destroy**
Initialize the system on start, thereby retrieving a pointer to the system and you should destroy the system on end.

## **Submit jobs to run in parallel**
Jobs can be sent to be executed. Every thread on your system will be running continuously from the start.
A thread will be put to sleep using a wake condition to avoid running the loop continuously if there are no jobs sent to be executed.
When a job is submitted, a sleeping thread will be notified and will take it upon itself to run the job on a thread parallely.

## **Job Pool**
A job pool is a fixed size circular buffer that stores all the submitted jobs. The pool is responsible for managing the head and the tail.
It works as a fixed size queue and with the help of mutex's it is built to be thread safe.
Being thread-safe only a single thread can take the next job and a job can be put onto the buffer by preserving the head and tail position of the buffer.

## ** Wait and Join**
As all threads are always running in parallel, there is no way to join the threads and the threads are only stopped on destroying the Job System.
Instead, the Wait function can be used to wait for execution for jobs on all threads to be completed until the main thread proceeds.
