#include <stdio.h>

int ternarySearch(int l, int r, int key, int arr[])
{
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (arr[mid1] == key) 
            return mid1;
        if (arr[mid2] == key)
            return mid2;
 
        if (key < arr[mid1])
            return ternarySearch(l, mid1 - 1, key, arr);
        else if (key > arr[mid2])
            return ternarySearch(mid2 + 1, r, key, arr);
        else
            return ternarySearch(mid1 + 1, mid2 - 1, key, arr);
    }
    return -1;
}
 
// Driver code
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

    int p = ternarySearch(0, n-1, x, arr);
    printf("Index of %d is %d\n", x, p);

    printf("Which number's existence do you want to check?\n");
    scanf("%d", &x);
    
    p = ternarySearch(0, n-1, x, arr);
    printf("Index of %d is %d\n", x, p);
}