// 6_Find_In_Rotated_Sorted.cpp
// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <iostream>
#include <vector>
using namespace std;
int FindMinElement(vector<int>arr);
int BinarySearch(vector<int>arr, int l, int r, int x);
int search(vector<int>& arr, int x);
int main()
{
    int x, n;
    
    cout << "Enter length of array: \n";
    cin >> n;
    vector <int> arr(n);
    cout << "Enter the rotated array: \n";
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Element to search in rotated sorted array: ";
    cin >> x;
    // doesn't work with arrays with non-distinct elements
    int index = FindMinElement(arr);
    if(x <= arr[arr.size()-1])
        cout << BinarySearch(arr, index, arr.size() - 1, x);
    else
        cout << BinarySearch(arr, 0, index - 1, x);
    // works with arrays with non-distinct elements
    cout << "\n" << search(arr, x);
}

int FindMinElement(vector<int>arr)
{
    if(arr.size() == 1)
        return 0;
    int l = 0, r = arr.size() - 1, mid;
    while(l <= r)
    {
        // find & return the min element in the rotated sorted array
        mid = l + (r - l)/2; // to prevent overflow
        int arr_mid_next = (mid + 1) % arr.size();
        int arr_mid_prev = (mid + arr.size() - 1) % arr.size();
        if(arr[mid] < arr[arr_mid_prev] && arr[mid] <= arr[arr_mid_next])
            return mid;
        else if (arr[mid] > arr[arr.size()-1]) // mid will divide the array into two parts, a sorted part and an unsorted part. min will lie in the unsorted part.
            l = mid + 1;
        else
            r = mid - 1;
    } 
    return r;
}

int BinarySearch(vector<int>arr, int l, int r, int x)
{
    if (arr.size() == 1)
    {
        if(arr[arr.size() - 1] == x)
            return 0;
        else
            return -1;
    }
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == x)
        {
            cout << "Found\n";
            return mid;
        }
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    } 
    return -1; 
}

// Find in rotated sorted - a better way that includes non-distinct elements
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

int search(vector<int>& arr, int x) 
{
    int l(0), r(arr.size()-1), n(arr.size());
    if(n == 1)
    {
        if(x == arr[0])
            return true;
        return false;
    }
    
    while(l <= r)
    {
        while(l < r && arr[l] == arr[r]) 
            l++;
        int mid = l + (r - l)/2;

        if(arr[l] == x)
            return l;
        if(arr[r] == x)
            return r; 
        if(arr[mid] == x)
            return mid;

        if(arr[l] <= arr[mid]) // left side is sorted
        {
            if(arr[l] < x && x < arr[mid]) // if x is arr[l] < x < arr[mid], then it is on the left side, otherwise on the right
                r = mid - 1;
            else
                l = mid + 1;
        }
        else if(arr[mid] <= arr[r]) // right side is sorted
        {
            if(arr[mid] < x && x < arr[r]) // if x is arr[mid] < x < arr[r], then it is on the right side, otherwise on the left
                l = mid + 1;
            else
                r = mid - 1;
        }
        else
            l++;
    }
    return -1;
}