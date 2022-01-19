// // BinarySearch.cpp
#include <iostream>
#include <vector>
using namespace std;
// This program uses vectors to accept values from users and performs binary search using recursion
// Time Complexity - O(log n) (Best case- O(1))
// Space Complexity - (here, for recursive,  O(log n)) (for iterative, O(1))

/*
    To recognize problems that can be solved using binary search, keep few conditions in mind
    Array is sorted/ partially sorted/ rotated sorted
    Question has to be solved in 0(log n) time
    

    To solve problems using binary search, find these key points
    A) The condition that the mid element is our required element
    B) The condition that will help we decide that the required element is in the left or right half of the array

    https://www.geeksforgeeks.org/binary-search/

    Sometimes binary search can be used to solve a question with an unsorted array. Here condition A and B will
    be suitably developed. See 14_Peak_Element.cpp
*/
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

    cout << "Which number's existence do you want to check? ";
    cin >> x;
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
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    } 
    cout << "Not Found\n";
    return -1; 
}
    



