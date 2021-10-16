// 6_Fibonacci.cpp
#include <iostream>
#include <string>
using namespace std;

// not optimised
long long fib(long long n)
{
    if((n == 0) || (n == 1))
        return n;
    else
        return fib(n-1) + fib(n-2);
}

int main()
{
    cout << fib(67);
}