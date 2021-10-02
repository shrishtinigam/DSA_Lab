// 2_Union.c
// Union of sorted arrays. 
// Arrays can have repetitions, output will be a set with no repetitions.
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

void Union(int arr1[], int n, int arr2[], int m)
{
    int res[max(n,m)];
    int i = 0; int j = 0; int count = 0;
    while(i < n && j < m)
    {
        if(arr1[i] < arr2[j])
        {
            if(res[count-1] == arr1[i] && count > 0)
            {
                i++;
                continue;
            }
            res[count] = arr1[i];
            count++;
            i++;
        }
        else if(arr1[i] > arr2[j])
        {
            if(res[count - 1] == arr2[j] && count > 0)
            {
                j++;
                continue;
            }
            res[count] = arr2[j];
            count++;
            j++;
        }
        else
        {
            if(res[count-1] == arr1[i] && count > 0)
            {
                i++; j++;
                continue;
            }
            res[count] = arr1[i];
            count++;
            i++; j++;
        }
    }
    while(i < n)
    {
        if(res[count-1] == arr1[i] && count > 0)
        {
            i++;
            continue;
        }
        res[count] = arr1[i];
        i++; count++;
    }
    while(j < m)
    {
        if(res[count - 1] == arr2[j] && count > 0)
        {
            j++;
            continue;
        }
        res[count] = arr2[j];
        j++; count++;
    }

    for(i = 0; i < count; i++)
    {
        printf("%d ", res[i]);
    }
}
int main()
{
    int n, m;
    const int x = 10;
    int arr[x];
    printf("Input a sorted array\n");
    scanf("%d",&n);
    scanf("%d",&m);
    int arr1[n], arr2[m];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]); 
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]); 
    }

    Union(arr1, n, arr2, m);
}
