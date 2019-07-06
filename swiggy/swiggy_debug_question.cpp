/*
C++ : Debugging Round, SWIGGY July 5, 2019

Problem Statement:
 Aim is to calculate the sum of factorials of first n natural number.  
 Since this number can be verylarge so remainder has been taken with REM(1000000007).
 Mathematically, represented belowF inalAnswer= (k=n∑k=1k!)%REM
 
 To leverage the multiprocessing feature of modern CPUs, two threads has been created.  
 They divide this task equally in such a way that, first thread calculates for odd numbers and second calculates for even numbers.
 
 There are some issues in the provided code due to which code compiles but doesn’t complete the execution.  
 Make minimal code changes so that code runs completely and gives correct output.
 
 Sample TestCases:Input:  6, Output:  873
 Input:  1000, Output:  980630010
 
 You can compile the code with c++11 or latest(g++ -std=c++11 file.cpp -o program)
 
*/

#include <iostream>
#include <mutex>
#include <thread>

#define REM 1000000007

using namespace std;
 
std::mutex mutex1, mutex2, lockSum;
long long final_sum = 0;  

long long factorial(long long n){
    long long n_fact = 1;
    for(long long i=1;i<=n;i++){
        n_fact*=i;
    }
    return n_fact;
}

void ThreadA(long long n)
{
    for(long long i=1;i<=n;i=i+2){
        long long i_fac = factorial(i);

        // mutex2.lock();
        lockSum.lock();
        final_sum = final_sum + i_fac;
        lockSum.unlock();
        // mutex1.lock();
        // mutex2.unlock();
        // mutex1.unlock();
    }
}
 

void ThreadB(long long n)
{
    for(long long i=2;i<=n;i=i+2){
        long long i_fac = factorial(i);

        // mutex1.lock();
        lockSum.lock();
        final_sum = final_sum + i_fac;
        lockSum.unlock();
        // mutex2.lock();
        // mutex1.unlock();
        // mutex2.unlock();
    }
}

 
void ExecuteThreads(long long n)
{
	thread t1(ThreadA, n); 
	thread t2(ThreadB, n); 
    t1.join();
    t2.join();
 
    std::cout << "Finished! Final Answer is: " << final_sum % REM << std::endl;
}
 
int main()
{
    std::cout << "Give n: ";
    long long n;
    cin >> n;
    ExecuteThreads(n);
    
    return 0;
}