// https://www.youtube.com/watch?v=IJDJ0kBx2LM 23:00
#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string str)
{
    if(str.length() == 0 || str.length() == 1)
        return true;
    
    if(str[0] == str[str.length()-1])
    {
        str.erase(str.length()-1);
        str.erase(0, 1);
        return is_palindrome(str);
    }

    return false;
}

int main()
{
    string farewell = "Goodbye!";
    string car = "racecar";

    cout << is_palindrome(farewell) << "\n" << is_palindrome(car);
}