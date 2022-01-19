// 18_Allocate_Pages.cpp
// https://www.geeksforgeeks.org/allocate-minimum-number-pages/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int BinarySearch(vector<int>arr,int x);
bool isValid(vector<int>arr, int n, int k, int max);
int main()
{
    int x, n;
    
    cout << "Enter length of array: \n";
    cin >> n;
    vector <int> arr(n);
    cout << "Enter the amount of pages in each book: \n";
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "How many students? ";
    cin >> x;
    cout << BinarySearch(arr,x);
}

int BinarySearch(vector<int>arr , int k)
{
    int n = arr.size();
    if (n < k)
        return -1;
    int l = *max_element(arr.begin(), arr.end());
    int r = accumulate(arr.begin(), arr.end(), 0);
    int result = -1;
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(isValid(arr, n, k, mid) == true)
        {
            result = mid;
            r = mid - 1;
        }
        else 
            l = mid + 1;
    }
    return result; 
}

bool isValid(vector<int>arr, int n, int k, int max)
{
    int students = 1;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if(sum > max)
        {
            students++;
            if(students > k)
                return false;
            sum = arr[i];
        }
    }
    return true;
}