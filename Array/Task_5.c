// Finding Max and Min Element and their Positions in the Array using Brute Force Approach.

#include <stdio.h>

typedef struct max_min{
    int max;
    int min;
    int c_max;
    int c_min;
    int pos_max[100];
    int pos_min[100];
}max_min;

max_min Max_Min_Element(int arr[], int n)
{
    max_min arr_max_min;
    arr_max_min.c_max = arr_max_min.c_min = 1;
    arr_max_min.max = arr_max_min.min = arr[0];
    arr_max_min.pos_max[0] = arr_max_min.pos_min[0] = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > arr_max_min.max)
        {
            arr_max_min.pos_max[0] = i;
            arr_max_min.c_max = 1;
            arr_max_min.max = arr[i];
        }
        else if(arr[i] == arr_max_min.max)
        {
            arr_max_min.pos_max[arr_max_min.c_max] = i;
            arr_max_min.c_max++;
        }
        else if(arr[i] < arr_max_min.min)
        {
            arr_max_min.pos_min[0] = i;
            arr_max_min.c_min = 1;
            arr_max_min.min = arr[i];
        }
        else if(arr[i] == arr_max_min.min)
        {
            arr_max_min.pos_min[arr_max_min.c_min] = i;
            arr_max_min.c_min++;
        }
    }
    return arr_max_min;
}


void display (max_min m)
{
    printf("Maximum is: %d\n", m.max);
    printf("Minimum is: %d\n", m.min);

    printf("Positions of Maximum: ");
    for(int i = 0; i < m.c_max; i++)
    {
        printf("%d ", m.pos_max[i] + 1);
    }
    printf("\nPositions of Minimum: ");
    for(int i = 0; i < m.c_min; i++)
    {
        printf("%d ", m.pos_min[i] + 1);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[100];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    } 
    max_min answer = Max_Min_Element(arr, n);
    display(answer);
}
