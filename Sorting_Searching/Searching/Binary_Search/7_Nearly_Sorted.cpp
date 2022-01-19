// 7_Nearly_Sorted.cpp
// https://www.geeksforgeeks.org/search-almost-sorted-array/
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
    cout << "Enter the integer values in nearly sorted order: \n";
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Which number's existence do you want to check? ";
    cin >> x;
    cout << BinarySearch(arr,x);
}

int BinarySearch(vector<int>arr , int x)
{
    int l = 0, r = arr.size() - 1;
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == x)
        {
            cout << "Found\n";
            return mid;
        }
        else if (mid - 1 >= 0 && arr[mid - 1] == x)
        {
            cout << "Found\n";
            return mid - 1;
        }
        else if(mid + 1 < arr.size() && arr[mid + 1] == x)
        {
            cout << "Found\n";
            return mid + 1;
        }
        else if(arr[mid] < x)
            l = mid + 2;
        else
            r = mid - 2;
    } 
    return -1; 
}