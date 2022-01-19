// 17_Only_Appears_Once.cpp
// https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/
// Given a sorted array in which all elements appear twice (one after one) and one element appears only once.
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
    cout << "Enter the integer values in ascending order: \n";
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Finding the element that appears only once: ";
    cout << BinarySearch(arr);
}

int BinarySearch(vector<int>arr)
{
    int l = 0, r = arr.size() - 1;
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(mid == 0 && arr[mid + 1] != arr[mid])
            return arr[mid];
        if(mid == arr.size() - 1 && arr[mid - 1] != arr[mid])
            return arr[mid];
        if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
            return arr[mid];

        if((r - l) % 4 != 0)
        {
            if (arr[mid] == arr[mid + 1])
                r = mid - 1;
            else
                l = mid + 1;
        }        
        else
        {
            if (arr[mid] == arr[mid + 1])
                l = mid + 2;
            else
                r = mid - 2;
        }
    } 
    return -1; 
}

/* More efficient solution using maps in c++, no algorithm used*/
int singleNonDuplicate(vector<int>& nums) 
{
    map<int, int> times;
    for(auto num : nums) 
        times[num]++;
    for(auto num : times) 
        if(num.second == 1) 
            return num.first;
    return -1;
}