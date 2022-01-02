#include <stdio.h>
void mergeSort(int arr[], int l, int r, int size);
void merge(int arr[],int l,int m, int r, int size);
int main()
{
    printf("Enter size of array: ");
    int size;
    scanf("%d", &size);
    int myarray[size];
 
    printf("Enter %d integers in any order: ", size);
    for(int i = 0; i < size; i++){
        scanf("%d", &myarray[i]);
    }
    
    printf("Before Sorting - \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");

    mergeSort(myarray, 0, (size - 1), size); 
 
    printf("After Sorting - \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", myarray[i]);
    }
 
    return 0;
}
void mergeSort(int arr[], int l, int r, int size)
{
    if (l < r) 
    {
        int m = (l + r)/2;
        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);
        merge(arr, l, m, r, size);
    }
}
void merge(int arr[], int l, int m, int r, int size)
{
    int i = l;
    int j = m +1;
    int k = l;

    int temp[size];

    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++]=arr[j++];
    }

    while(i<=m)
        temp[k++] = arr[i++];

    while(j<=r)
        temp[k++] = arr[j++];
    
    for (int p = l; p <= r; p++)
        arr[p] = temp[p];
}