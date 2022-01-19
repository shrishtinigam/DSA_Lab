// 3_First_Occurance.cpp
// https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/
#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<int>arr,int x);
/*
Time Complexity : O(log n) 
Auxiliary Space : O(1) 
*/
int main()
{
    int x, n;
    
    cout << "Enter length of array: \n";
    cin >> n;
    vector <int> arr(n);
    cout << "Enter the integer values in ascending order: \n";
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Which number's first occurance do you want to check?" << endl;
    cin >> x;
    cout << BinarySearch(arr,x);
}

int BinarySearch(vector<int>arr , int x)
{
    int result = -1;
    int l = 0, r = arr.size() - 1;
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == x)
        {
            result = mid;
            r = mid - 1;
        }
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    } 
    return result;
}