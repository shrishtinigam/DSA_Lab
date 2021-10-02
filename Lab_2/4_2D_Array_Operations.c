// 4_2D_Array_Operations.c
#include <stdio.h>
#include <stdbool.h>

void Transpose(int r, int c, int * matrix, int * result) // Stores result in a separate matrix
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            *((result + j*r) + i) = *((matrix + i*c) + j);
        }
    }
}

bool Addition(int r1, int c1, int r2, int c2, int * matrix1, int * matrix2, int * result)
{
    if(r1 != r2 || c1 != c2)
    {
        printf("Matrix Addition is not possible.\n");
        return false;
    }
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c1; j++)
        {
            *((result + i*c1) + j) = *((matrix1 + i*c1) + j) + *((matrix2 + i*c1) + j);
        }
    }
    return true;
}

bool Multiplication(int r1, int c1, int r2, int c2, int * matrix1, int * matrix2, int * result)
{
    if(c1 != r2)
    {
        printf("Matrix Multiplication is not possible.\n");
        return false;
    }
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            *((result + i*c1) + j) = 0;
            for(int k = 0; k < c1; k++)
            {
                *((result + i*c1) + j) += ((*((matrix1 + i*c1) + k)) * (*((matrix2 + k*c2) + j)));
            }
        }
    }
    return true;
}

void display1(int r, int c, int * matrix)
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
    // Getting two matrices as inputs
    printf("Input the matrices\n");
    int r1, c1;
    scanf("%d%d",&r1,&c1);
    int r2, c2;
    scanf("%d%d",&r2,&c2);
    int matrixA[r1][c1];
    int matrixB[r2][c2];
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c1; j++)
        {
            scanf("%d", &matrixA[i][j]);
        }
    }
    for(int i = 0; i < r2; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Transpose of Matrix
    // Lets find the transpose of the first matrix
    int matrixT[c1][r1]; // cols become rows and vice versa
    printf("Transpose: \n");
    Transpose(r1, c1, (int *)matrixA, (int *)matrixT);
    display1(c1, r1, (int *)matrixT);

    // Matrix Addition
    int matrixC[r1][c1]; // Result of the addition will be stored here
    printf("Addition: \n");
    if(Addition(r1, c1, r2, c2, (int *)matrixA, (int *)matrixB, (int *)matrixC)) 
    {
        display1(r1, c1, (int *)matrixC);
    }

    // Matrix Multiplication 
    int matrixM[r1][c2];
    printf("Multiplication: \n");
    if(Multiplication(r1, c1, r2, c2, (int *)matrixA, (int *)matrixB, (int *)matrixM))
    {
        display1(r1, c1, (int *)matrixM);
    }
}