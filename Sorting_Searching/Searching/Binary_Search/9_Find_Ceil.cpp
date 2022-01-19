// 9_Find_Ceil.cpp
// https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/
#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<int>arr, int x);
int main()
{
    int x, n;
    
    cout << "Enter length of array: \n";
    cin >> n;
    vector <int> arr(n);
    cout << "Enter the integer values in ascending order: \n";
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Which number's ceil do you want to find? ";
    cin >> x;
    cout << BinarySearch(arr,x);
}

int BinarySearch(vector<int>arr , int x)
{
    int l = 0, r = arr.size() - 1;
    int result = -1;
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == x)
            return arr[mid];
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