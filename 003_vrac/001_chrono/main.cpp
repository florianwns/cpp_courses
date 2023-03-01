//
// Created by Florian Rey on 27/02/2023.
//
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
namespace cr = std::chrono;

unsigned long fibo(unsigned long n)
{
    if (n<2) return n;
    return fibo(n-1)+fibo(n-2);
}

int main()
{
    auto start(cr::system_clock::now());
    cout << "fibo(42) = " << fibo(42) << endl;
    auto end(cr::system_clock::now());

    cr::duration<double> elapsed = end-start;
    auto end_time = cr::system_clock::to_time_t(end);

    cout << "Finished computation : " << ctime(&end_time) << "\n"
         << "Elapsed time : " << elapsed.count() << " sec" << endl;

    return 0;
}