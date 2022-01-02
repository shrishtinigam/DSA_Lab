// 1_Traversal_Modification.c
#include <stdio.h>
int main()
{
    int n;
    printf("Size of array must be less than or equal to 100");
    scanf("%d", &n);
    int arr[100];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Add x to every element in the array
    int x;
    scanf("%d", &x);
    for(int i = 0; i < n; i++)
    {
        arr[i] += x;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}