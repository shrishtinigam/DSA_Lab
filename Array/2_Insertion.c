// 2_Insertion.c
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
    display(arr, n);
    int pos, num;
    scanf("%d", &pos);
    scanf("%d", &num);
    if(pos == n + 1) // At End
    {
        arr[n] = num;
        n++;
    }
    else // At any other position
    {
        int j = n-1;
        while(j >= (pos - 1))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[pos - 1] = num;
        n++;
    }
    display(arr, n);
} 