#include <iostream>
#include <vector>
using namespace std;

// This program uses vectors to accept values from users and performs binary search using recursion
// Time Complexity - O(log n) (Best case- O(1))
// Space Complexity - (here, for recursive,  O(log n)) (for iterative, O(1))

int BinarySearch(vector<int>arr,int x);
int main()
{
    int x,n;
    vector <int> arr;
    cout << "Enter the integer values in ascending order, enter -1 when completed" << endl;
    
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

// Function the performs binary search
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
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    } 
    return -1; 
}
    



