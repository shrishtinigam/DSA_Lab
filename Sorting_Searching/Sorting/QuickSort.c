#include <stdio.h>

/*
*   Comparision based sort
*   Divide and Conquer
*/
int Partition(int arr[], int beg, int end)
{
    int pivot = arr[end];
    int i = beg-1;
    int hold;
    for(int j = beg; j <= end-1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            hold = arr[j];
            arr[j] = arr[i];
            arr[i] = hold;
        }
    }
    hold = arr[end];
    arr[end] = arr[i+1];
    arr[i+1] = hold;
    return i + 1;
}
void QuickSort(int arr[], int beg, int end)
{
    if(beg < end)
    {
        int mid = Partition(arr, beg, end);
        QuickSort(arr, beg, mid - 1);
        QuickSort(arr, mid + 1, end);
    }
}

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

    QuickSort(arr, 0, n);

    printf("Sorted Array - ");
    for (int a = 0; a < n; ++a)
    {
        printf(" %d", arr[a]);
    }
}
