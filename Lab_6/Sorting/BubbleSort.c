// BubbleSort.c
#include <stdio.h>

void bubblesort_1(int arr[], int n);
void bubblesort_2(int arr[], int n);
void bubblesort_3(int arr[], int n);
// At the first passing, the largest element is moved to the end of the list. Similarly, at the second passing 
// the second largest element is moved to the second last index of the list.

// Time complexity:O(n*n)
// Sort stability: Stable sort
// Space complexity: O(1) - inplace
int main()
{
    int x, n, hold;
    int flag = 0;
    printf("Number of integers to sort: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the integer values\n");
    // Takes in the values from the user
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        arr[i] = x;
    }

    bubblesort_3(arr, n);

    printf("Sorted Array - ");
    for (int a = 0; a < n; ++a)
    {
        printf(" %d", arr[a]);
    }
}

// Worst method, will always go through the n*n iterations
void bubblesort_1(int arr[], int n)
{
    int hold;
    for(int i = 0; i < n-1; i++)
    {
        for(int i = 0; i < n-1; i++)
        {
            if(arr[i]>arr[i+1])
            {
                hold = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = hold;
            }
        }
    }
}

// Second method, if the total number of swaps during a pass is 0 then it exits as the list is sorted
void bubblesort_2(int arr[], int n)
{
    int flag, hold;
    do{
        flag = 0;
        for(int i = 0; i < n-1; i++)
        {
            if(arr[i]>arr[i+1])
            {
                hold = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = hold;
                flag = flag + 1;
            }
        }
    }while(flag != 0);
}

/*OPTIMIZED BUBBLE SORT*/
// Best method, along with exiting once the list is sorted (like second method), the value of n decreases every
// iteration (by 1). This is because after a pass, the largest element of the pass is moved to the last and we 
// don't need to check for swaps there.
void bubblesort_3(int arr[], int n)
{
    int flag, hold;
    do{
        flag = 0;
        for(int i = 0; i < n-1; i++)
        {
            if(arr[i]>arr[i+1])
            {
                hold = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = hold;
                flag = flag + 1;
            }
        }
        n--;  // to remove unneccessary comparisions towards the end
    }while(flag != 0);
}

// Another code for optimized bubble sort
/*
int flag = 0;
for(int j = 0; j < n -1; j++)
{
    flag = 0;
    for(int i = 0; i < n-j-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            hold = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = hold;
            flag = 1;
        }
    }
    if(flag == 0)
        break;
}
*/