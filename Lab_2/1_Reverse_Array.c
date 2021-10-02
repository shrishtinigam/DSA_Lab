#include <stdio.h>

void reverseArray(int arr[], int start, int end)
{
    end--;
    while (start < end)
    {
        int temp = arr[start]; 
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    } 
} 

int main()
{
    int n;
    printf("Size of array must be less than or equal to 100. Enter size, then array elements");
    scanf("%d", &n);
    int arr[100];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    reverseArray(arr, 0, n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}