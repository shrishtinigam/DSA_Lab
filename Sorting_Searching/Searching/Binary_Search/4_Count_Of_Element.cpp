// 4_Count_Of_Element.cpp
// https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/
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
    cout << "Enter the integer values in ascending order: \n";
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Which number's count do you want to check?" << endl;
    cin >> x;
    cout << BinarySearch(arr,x);
}


int BinarySearch(vector<int>arr , int x)
{
    // First occurance
    int result1 = -1;
    int l = 0, r = arr.size() - 1;
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == x)
        {
            result1 = mid;
            r = mid - 1;
        }
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    } 

    // Last occurance
    int result2 = -1;
    l = 0, r = arr.size() - 1;
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == x)
        {
            result2 = mid;
            l = mid + 1;
        }
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    } 

    return result2 - result1 + 1;
}