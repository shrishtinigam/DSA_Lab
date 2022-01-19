// 10_Next_Alphabetical.cpp
// Given an array of letters sorted in ascending order, find the smallest letter in the the array which is greater than a given key letter.
#include <iostream>
#include <vector>
using namespace std;
char BinarySearch(vector<char>arr, char x);
int main()
{
    int n;
    char x;
    cout << "Enter length of array: \n";
    cin >> n;
    vector <char> arr(n);
    cout << "Enter the alphabetic values in ascending order: \n";
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Which alphabet's next alphabet do you want to find? ";
    cin >> x;
    cout << BinarySearch(arr,x);
}

char BinarySearch(vector<char>arr , char x)
{
    int l = 0, r = arr.size() - 1;
    char result = '-';
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == x)
            l = mid + 1;
        else if (arr[mid] < x)
            l = mid + 1;
        else
        {
            result = arr[mid];
            r = mid - 1;
        }
    } 
    return result; 
}