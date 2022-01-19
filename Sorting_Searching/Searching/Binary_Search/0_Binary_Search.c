#include <stdio.h>
// This program accepts values from users and performs binary search using recursion
// Time Complexity - O(log n) (Best case- O(1))
// Space Complexity - (here, for recursive,  O(log n)) (for iterative, O(1))

int BinarySearch(int arr[], int l, int r, int x);
int BinarySearch2(int n, int arr[], int x);
int main()
{
    int x, n;
    printf("Enter the integer values in ascending order\n");
    scanf("%d", &n);
    printf("Number of integers to sort: ");
    int arr[n];
    
    // Takes in the values from the user
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        arr[i] = x;
    }

    printf("Which number's existence do you want to check?\n");
    scanf("%d", &x);
    int position = BinarySearch(arr, 0, n-1, x);
    printf("Found at position %d\n", position + 1);
    position = BinarySearch2(n, arr, x);
    printf("Found at position %d\n", position + 1);
}

// Function the performs binary search recursively
int BinarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) 
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return BinarySearch(arr, l, mid - 1, x);
        return BinarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

// Function the performs binary search  iteratively
int BinarySearch2(int n, int arr[], int x)
{
    int l = 0;
    int r = n-1;
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(arr[mid] == x)
        {
            printf("Found\n");
            return mid;
        }
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    } 
    return -1;
}
    



