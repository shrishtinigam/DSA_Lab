// 3_Decimal_to_Binary.cpp

#include <iostream>
#include <string>
using namespace std;

string find_binary(int d, string r)
{
    if(d == 0)
        return r;
    r = to_string(d % 2) + r;
    return find_binary(d/2, r);
}

string find_binary(int d)
{
    return find_binary(d, "");
}

int main()
{
    int n = 5;
    int n2 = 23;
    cout << find_binary(n) << " " << find_binary(n2);
}