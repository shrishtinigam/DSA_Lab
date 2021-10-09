#include <iostream>
#include <vector>
using namespace std;
// This program uses vectors to accept values from users and performs selection sort
// O(n^2) time complexity, unstable sort, O(1) space complexity
// Stable with O(n) extra space or when using linked lists
int main()
{
    int x,n,hold,hold2;
    vector <int> arr;
    cout << " Enter the integer values, enter -1 when completed" << endl;
    // Takes in the values from the user
    do{
        cin>>x;
        arr.push_back(x);
    }while(x!=-1);
    arr.pop_back();
    
    n = arr.size();
    int j = 0; 

    while(j<n)
    {
        x = arr[j]; // Assume the first element of the unsorted part of the array is the smallest element
        for(int i = j;i < n; i++) // So, iterating over the unsorted part of the array,
        {
            if(x > arr[i]) // If our assumption is greater than an element,
            {
                x = arr[i]; // Change assumption to that element
                hold2 = i; // Remember the location of that element in 'hold2' var
            }
        } // Repeat till the end, now you have the smallest element in the unsorted array

        // Now you have to swap the first element of the unsorted array with the smallest element in the unsorted array

        hold = arr[j]; // Save the value of the first element of unsorted array in 'hold' var
        arr[j] = x; // Put the smallest element at the beginning of the unsorted array
        arr[hold2] = hold; // Put the value stored in 'hold' var in the location of the smallest elemnt (which we saved in 'hold2' var)

        j = j + 1;
    }
    cout << "Sorted Array"<<endl;
  for (int a = 0; a < arr.size(); ++a)
  {
    cout<< ' ' << arr[a]<<endl;
  }
}

