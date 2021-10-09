#include <stdio.h>
void InsertionSort(int arr[]);
int main()
{
    int arr[5]={3,2,6,4,8};

    InsertionSort(arr);

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}
// https://www.youtube.com/watch?v=OAyj2d-GH0c
// TC - BEST CASE - O(n)
// TC - WORST CASE CASE - O(n^2)
// SPACE COMPLEXITY - O(1) - IN PLACE
// It is a stable sort
// its most helpful when you have an almost sorted array
// used in online query - when elements are coming in one by one at random

void InsertionSort(int arr[])
{
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 1; i < n ; i++)
    {
        int key = arr[i];

        // start of the unsorted region
        int j = i -1;
        // element in the unsorted region is less than the current element
        while(j>=0 && arr[j]>key) // if the back of sorted region is greater than our key
                                  //"arr[j]>key" - here for equal elements, the ones on theleft will remain of the left side, making the algorithm "stable"
                                  //"arr[j]>=key" - here even if the element is equal to the current it will be moved to the right, and the cuurent element which was originally on the right side wiil come to the left, making the sort "unstable"
                                  // Stability of a sort can matter when elements being sorted are dictionaried/mapped with other data.
        {
            arr[j+1]=arr[j]; // shift that to the right
            j=j-1; // decrement the index by 1
        }

        arr[j+1]=key; // put in the key at the appropriate place
    }
}