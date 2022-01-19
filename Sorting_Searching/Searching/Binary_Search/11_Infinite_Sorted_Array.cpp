// 11_Infinite_Sorted_Array.cpp
// Suppose you have a sorted array of infinite numbers, how would you search an element in the array?
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
    cout << "Enter infinite integer values in sorted order: \n"; // this question is not possible irl
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Which number's existence do you want to check? ";
    cin >> x;
    cout << BinarySearch(arr,x);
}

int BinarySearch(vector<int>arr, int x)
{
    int l = 0, r = 1;
    while(x > arr[r])
    {
        l = r;
        r*=2;
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
    

