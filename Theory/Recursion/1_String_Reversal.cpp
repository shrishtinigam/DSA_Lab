// https://www.youtube.com/watch?v=IJDJ0kBx2LM 16:52
#include <iostream>
#include <string>
using namespace std;

string reverse_string(string str)
{
    if(str == "")
        return "";
    string temp (1, str[0]);
    str.erase(0, 1);
    return (reverse_string(str) + temp);
}

int main()
{
    string greeting = "Hello everyone!";
    cout << reverse_string(greeting);
}