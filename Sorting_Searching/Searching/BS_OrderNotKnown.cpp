// BS_OrderNotKnown.cpp

#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<int>arr,int x);
int main()
{
    int x, n;
    vector <int> arr;
    cout << "Enter the integer values in ascending or descending order, enter -1 when completed" << endl;
    
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

int BinarySearch(vector<int>arr , int x)
{
    int flag = 0;
    if(arr[0] <= arr[arr.size()-1])
        flag = 1;
    int l = 0, r = arr.size() - 1;
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == x)
        {
            cout << "Found\n";
            return mid;
        }
        else if ((arr[mid] > x && flag == 0) || (arr[mid] < x && flag == 1))
            l = mid + 1;
        else
            r = mid - 1;
    } 
    cout << "Not Found\n";
    return -1; 
}