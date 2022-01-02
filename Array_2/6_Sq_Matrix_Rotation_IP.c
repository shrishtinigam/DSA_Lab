// 6_Sq_Matrix_Rotation_IP.c

#include <stdio.h>

void display(int r, int c, int * matrix)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            printf("%d ", *((matrix + i*c) + j));
        printf("\n");
    }
}

void Transpose(int r, int c, int * matrix) // Stores result in a separate matrix
{
    int result1[r][r];
    int * result = (int *) result1;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            *((result + j*r) + i) = *((matrix + i*c) + j);
        }
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            *((matrix + i*c) + j) = *((result + i*r) + j);
        }
    }
}

void Clockwise_90(int r, int * result)
{
    int start = 0; int end = r - 1;
    while(start < end)
    {
        for(int i = 0; i < r; i++)
        {
            int temp = *((result + i*r) + start);
            *((result + i*r) + start) = *((result + i*r) + end);
            *((result + i*r + end)) = temp;
        }
        start++; end--;
    }
}

void Clockwise_180(int r, int * result)
{
    int start = 0; int end = r - 1;
    while(start <= end)
    {
        if(start == end)
        {
            for(int i = 0; i < (r/2); i++)
            {
                int temp = *((result + start*r) + i);
                *((result + start*r) + i) = *((result + start*r) + (r-1-i));
                *((result + start*r) + (r-1-i)) = temp;
            }
        }
        for(int i = 0; i < r; i++)
        {
            int temp = *((result + start*r) + i);
            *((result + start*r) + i) = *((result + end*r) + (r-1-i));
            *((result + end*r) + (r-1-i)) = temp;
        }
        start++; end--;
    }
}

void Anti_Clockwise_90(int r, int * result)
{
    int start = 0; int end = r - 1;
    while(start < end)
    {
        for(int i = 0; i < r; i++)
        {
            int temp = *((result + start*r) + i);
            *((result + start*r) + i) = *((result + end*r) + i);
            *((result + end*r) + i) = temp;
        }
        start++; end--;
    }
}

// Anti-Clockwise 180 is the same as Clockwise 180
void Anti_Clockwise_180(int r, int * result)
{
    int start = 0; int end = r - 1;
    while(start <= end)
    {
        if(start == end)
        {
            for(int i = 0; i < (r/2); i++)
            {
                int temp = *((result + start*r) + i);
                *((result + start*r) + i) = *((result + start*r) + (r-1-i));
                *((result + start*r) + (r-1-i)) = temp;
            }
        }
        for(int i = 0; i < r; i++)
        {
            int temp = *((result + start*r) + i);
            *((result + start*r) + i) = *((result + end*r) + (r-1-i));
            *((result + end*r) + (r-1-i)) = temp;
        }
        start++; end--;
    }
}

void Copy(int * arr, int * ans, int r)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            *((ans + i*r) + j) = *((arr + i*r) + j);
        }
    }
}

int main()
{
    int r;
    scanf("%d",&r);
    int matrixA[r][r];
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            scanf("%d", &matrixA[i][j]);
        }
    }

    
    int matrixB[r][r];

    Copy((int *) matrixA, (int *)matrixB, r);
    // We copy matrix A to B, so that we can perform the different rotations without losing the original transposed matrix
    
    printf("180 Degree Clockwise Rotation: \n");
    Clockwise_180(r, (int *) matrixB);
    display(r, r, (int *) matrixB);

    Copy((int *) matrixA, (int *)matrixB, r);

    printf("180 Degree Anticlockwise Rotation: \n"); // Same as 180 Clockwise Rotation
    Anti_Clockwise_180(r, (int *) matrixB);
    display(r, r, (int *) matrixB);

    Transpose(r, r, (int *) matrixA); // We transpose the matrix A
    Copy((int *) matrixA, (int *)matrixB, r); 
    // We copy transposed matrix A to B, so that we can perform the different rotations without losing the original transposed matrix
    
    // Rotating matrix inplace
    printf("90 Degree Clockwise Rotation: \n");
    Clockwise_90(r, (int *) matrixB);
    display(r, r, (int *) matrixB);

    // Reseting matrix to original transposed matrix
    Copy((int *) matrixA, (int *)matrixB, r);

    printf("90 Degree Anticlockwise Rotation: \n");
    Anti_Clockwise_90(r, (int *) matrixB);
    display(r, r, (int *) matrixB);

    
}