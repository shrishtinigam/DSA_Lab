// 5_Sq_Matrix_Rotation_BF.c
// Matrix rotation by given degree and angle by brute force method

#include <stdio.h>

void Clockwise_90(int r, int * matrix, int * result)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            *((result + j*r) + (r-i-1)) = *((matrix + i*r) + j);
        }
    }
}

void Clockwise_180(int r, int * matrix, int * result)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            *((result + (r-i-1)*r) + (r-j-1)) = *((matrix + i*r) + j);
        }
    }
}

void Anti_Clockwise_90(int r, int * matrix, int * result)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            *((result + (r-j-1)*r) + i) = *((matrix + i*r) + j);
        }
    }
}

// Anti-Clockwise 180 is the same as Clockwise 180
void Anti_Clockwise_180(int r, int * matrix, int * result)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            *((result + (r-i-1)*r) + (r-j-1)) = *((matrix + i*r) + j);
        }
    }
}

void display(int r, int c, int * matrix)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            printf("%d ", *((matrix + i*c) + j));
        printf("\n");
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
    int matrixC[r][r];
    int matrixD[r][r];
    int matrixE[r][r];
    printf("90 Degree Clockwise Rotation: \n");
    Clockwise_90(r, (int * )matrixA, (int *) matrixB);
    display(r, r, (int *) matrixB);
    printf("180 Degree Clockwise Rotation: \n");
    Clockwise_180(r, (int * )matrixA, (int *) matrixC);
    display(r, r, (int *) matrixC);
    printf("90 Degree Anticlockwise Rotation: \n");
    Anti_Clockwise_90(r, (int * )matrixA, (int *) matrixD);
    display(r, r, (int *) matrixD);
    printf("180 Degree Anticlockwise Rotation: \n");
    Anti_Clockwise_180(r, (int * )matrixA, (int *) matrixE);
    display(r, r, (int *) matrixE);
}