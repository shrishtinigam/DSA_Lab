#include <stdio.h>

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[101];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array before deletion: ");
    display(arr, n);
    int pos;
    scanf("%d", &pos);
    if(pos == n - 1)
    {
        n--;
    }
    else
    {
        int j = pos - 1;
        while(j != n -1)
        {
            arr[j] = arr[j + 1];
        }
        n--;
    }
    printf("Array after deletion: ");
    display(arr, n);
}