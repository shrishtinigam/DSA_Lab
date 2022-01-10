// BS_Last_Occurance.cpp
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
    vector <int> arr;
    cout << "Enter the integer values in ascending order, enter -1 when completed" << endl;
    
    do
    {
        cin>>x;
        arr.push_back(x);
    }while(x!=-1);

    cout << "Which number's last occurance do you want to check?" << endl;
    cin>>x;
    arr.pop_back();
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
            l = mid + 1;
        }
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    } 
    return result;
}