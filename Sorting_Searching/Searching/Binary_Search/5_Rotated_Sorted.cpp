// 5_Rotated_Sorted.cpp
// https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/
#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<int>arr);
int main()
{
    int n;

    cout << "Enter length of array: \n";
    cin >> n;
    vector <int> arr(n);
    cout << "Enter the rotated array: \n";
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Finding the number of times array was rotated....: ";
    cout << BinarySearch(arr);
}

int BinarySearch(vector<int>arr)
{
    int l = 0, r = arr.size() - 1, mid;
    while(l <= r)
    {
        // find & return the min element in the rotated sorted array
        mid = l + (r - l)/2; // to prevent overflow
        int arr_mid_next = (mid + 1) % arr.size();
        int arr_mid_prev = (mid + arr.size() - 1) % arr.size();
        if(arr[mid] < arr[arr_mid_prev] && arr[mid] < arr[arr_mid_next])
            return mid;
        else if (arr[mid] >= arr[arr.size()-1]) // mid will divide the array into two parts, a sorted part and an unsorted part. min will lie in the unsorted part.
            l = mid + 1;
        else
            r = mid - 1;
    } 
    return -1;
}

