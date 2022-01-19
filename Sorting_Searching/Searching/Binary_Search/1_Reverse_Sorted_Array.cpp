// 1_Reverse_Sorted_Array.cpp
// http://www.programming-algorithms.net/article/40119/Binary-search
#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<int>arr,int x);
int main()
{
    int x, n;
    
    cout << "Enter length of array: \n";
    cin >> n;
    vector <int> arr(n);
    cout << "Enter the integer values in descending order: \n";
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Which number's existence do you want to check? ";
    cin >> x;
    cout << BinarySearch(arr,x);
}

// Function the performs binary search on reverse sorted list
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
        else if (arr[mid] > x)
            l = mid + 1;
        else
            r = mid - 1;
    } 
    cout << "Not Found\n";
    return -1; 
}