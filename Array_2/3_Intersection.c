// 3_Intersection.c
// Intersection of a sorted array.
// Arrays can have repetitions, output will be a set with no repetitions.
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

void Intersection(int arr1[], int n, int arr2[], int m)
{
    int res[max(n,m)];
    int i = 0; int j = 0; int count = 0;
    while(i < n && j < m)
    {
        if(arr1[i] == arr2[j])
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
        else if(arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    for(i = 0; i < count; i++)
    {
        printf("%d ", res[i]);
    }
}
int main()
{
    int n, m;
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

    Intersection(arr1, n, arr2, m);
}

//yea and kinda leave upto the user 