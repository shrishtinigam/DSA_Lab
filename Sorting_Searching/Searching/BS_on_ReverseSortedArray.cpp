// BS_on_ReverseSortedArray.cpp
#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<int>arr,int x);
int main()
{
    int x, n;
    vector <int> arr;
    cout << "Enter the integer values in descending order, enter -1 when completed" << endl;
    
    do
    {
        cin>>x;
        arr.push_back(x);
    }while(x!=-1);

    cout << "Which number's existence do you want to check?" << endl;
    cin>>x;
    arr.pop_back();
    cout << BinarySearch(arr,x);
}

// Function the performs binary search on reverse sorted list
int BinarySearch(vector<int>arr , int x)
{
    int l = 0, r = arr.size() - 1;
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == x)
        {
            cout << "Found\n";
            return mid;
        }
        else if (arr[mid] > x)
            l = mid + 1;
        else
            r = mid - 1;
    } 
    cout << "Not Found\n";
    return -1; 
}