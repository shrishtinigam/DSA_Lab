// 13_Min_Abs_Diff.cpp
// Given a sorted array, find the element in the array which has minimum difference with the given number.
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

    cout << "Which number's minimum absolute difference do you want to find?: ";
    cin >> x;
    cout << BinarySearch(arr, x);
}

int BinarySearch(vector<int>arr, int x)
{
    int l = 0, r = arr.size() - 1;
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    } 
    if(abs(arr[l] - x) < abs(arr[r] - x))
        return arr[l];
    return arr[h];
}