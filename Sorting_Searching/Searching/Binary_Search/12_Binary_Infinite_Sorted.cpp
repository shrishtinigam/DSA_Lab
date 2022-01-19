// 12_Binary_Infinite_Sorted.cpp
// https://www.geeksforgeeks.org/find-index-first-1-infinite-sorted-array-0s-1s/

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
    cout << "Enter infinite binary values 1 and 0 in sorted order: \n"; // this question is not possible irl
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Finding index of the first 1 in the Binary Sorted Infinite Array...: ";
    cout << BinarySearch(arr);
}
// Mix of Infine Sorted Array and Last Occurance
int BinarySearch(vector<int>arr)
{
    int result = -1;
    int l = 0, r = 1;
    while(arr[r] != 1)
    {
        l = r;
        r*=2;
    }
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == 1)
        {
            result = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    } 
    return result;
}