// 4_Sum_Of_Natural_Numbers.cpp
#include <iostream>
#include <string>
using namespace std;

int sum(int n)
{
    if(n <= 1)
        return n;
    return(n + sum(n-1));
}

int main()
{
    int n = 12;
    cout << sum(12);
}