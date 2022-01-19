// 15_Find_In_Bitonic_Array.cpp
// https://www.geeksforgeeks.org/find-element-bitonic-array/
#include <iostream>
#include <vector>
using namespace std;
int findMaxElement(vector<int>arr);
int IncreasingBinarySearch(vector<int>arr, int l, int r, int x);
int DecreasingBinarySearch(vector<int>arr, int l, int r, int x);

int main()
{
    int x, n;

    cout << "Enter length of array: \n";
    cin >> n;
    vector <int> arr(n);
    cout << "Enter the integer values in bitonic order: \n"; 
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Which number's existence do you want to check? ";
    cin >> x;

    int index = findMaxElement(arr);
    int result = IncreasingBinarySearch(arr, 0, index, x);
    if(result != -1)
        cout << result;
    else
        cout << DecreasingBinarySearch(arr, index + 1, arr.size() - 1, x);
}

int findMaxElement(vector<int> arr) 
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
int IncreasingBinarySearch(vector<int>arr, int l, int r, int x)
{
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
    return -1; 
}

int DecreasingBinarySearch(vector<int>arr, int l, int r, int x)
{
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            l = mid + 1;
        else
            r = mid - 1;
    } 
    return -1; 
}