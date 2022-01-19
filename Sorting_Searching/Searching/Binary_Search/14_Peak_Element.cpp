// 14_Peak_Element.cpp
// https://leetcode.com/problems/find-peak-element/
// Example of solving using binary search on an unsorted algorithm
#include <iostream>
#include <vector>
using namespace std;
int findPeakElement(vector<int>arr);
int main()
{
    int x, n;

    cout << "Enter length of array: \n";
    cin >> n;
    vector <int> arr(n);
    cout << "Enter the integer values in any order: \n"; 
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Finding peak element...: ";
    cout << findPeakElement(arr);
}
int findPeakElement(vector<int> arr) 
{
    if(arr.size() == 1)
        return 0;
    int l(0), r(arr.size()-1);
    while(l <= r)
    {
        int mid = l + (r - l)/2;
        // edge cases
        if(mid == 0)
        {
            if(arr[0] > arr[1])
                return 0;
            return 1;
        }
        if(mid == arr.size() - 1)
        {
            if(arr[arr.size() - 1] > arr[arr.size() - 2])
                return arr.size() - 1;
            return arr.size() - 2;
        }
        
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) // condition that the mid element is our required element
            return mid;
        else if(arr[mid + 1] >= arr[mid]) // condition that will help we decide that the required element is in the left or right half of the array. choose the side that is greater than mid element. if both sides are greater than mid element, then it doesn't matter which side we choose, we will always get a peak element.
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}