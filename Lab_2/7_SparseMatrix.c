// 7_SparseMatrix.c
// In previous programs, I dealt with different operations as different functions.
// Although it would have been easy to do the same here, I put all the operations in the main itself. 
#include <stdio.h>
int main()
{
    int rows, columns, x, i, j, k;
    int values = 0;

    // Input the no. of its rows and columns of the sparse matrix
    printf("Input the first matrix.\n");
    scanf("%d",&rows);
    scanf("%d",&columns);
    int arr[rows][columns];
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] != 0)
            {
                values++;
            }
        }
    }

    int sparse_matrix[values][3];
    
    k = 0;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            if(arr[i][j] != 0)
            {
                sparse_matrix[k][0] = i;
                sparse_matrix[k][1] = j;
                sparse_matrix[k][2] = arr[i][j];
                k++;
            }
        }
    }

    // Output the sparse matrix in table form
    printf("Printing the matrix in sparse matrix table format:\n");
    for(i = 0; i < values; i++)
    {
        printf("Row: %d ",sparse_matrix[i][0]);
        printf("Column: %d ",sparse_matrix[i][1]);
        printf("Value: %d ",sparse_matrix[i][2]);
        printf("\n");
    }
    
    // Search for any integer in the sparse matrix (note: this doesn't consider the zeroes in the actual matrix)
    printf("What value do you want to search in the matrix?\n");
    scanf("%d",&x);
    int flag = 0;
    for(i = 0; i < values; i++)
    {
        if(sparse_matrix[i][2] == x)
        {
            printf("Found: Row: %d, Columns: %d \n",sparse_matrix[i][0],sparse_matrix[i][1]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("Not found\n");
    } 

    // Output of the matrix in regular matrix format
    printf("Printing the matrix in regular format:\n");
    k = 0;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            if(sparse_matrix[k][0] == i && sparse_matrix[k][1] == j)
            {
                printf("%d ", sparse_matrix[k][2]);
                k++;
            }  
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    // Adding another matrix to the original matrix
    int rows2, columns2, values2;

    // Read the sparse matrix
    // Input the no. of its rows and columns of the sparse matrix
    printf("Addition of matrices. \nInput the second matrix.\n");
    scanf("%d",&rows2);
    scanf("%d",&columns2);

    int arr2[rows2][columns2];
    for(i = 0; i < rows2; i++)
    {
        for(j = 0; j < columns2; j++)
        {
            scanf("%d", &arr2[i][j]);
            if(arr2[i][j] != 0)
            {
                values2++;
            }
        }
    }

    int sparse_matrix2[values2][3];
    k = 0;
    for(i = 0; i < rows2; i++)
    {
        for(j = 0; j < columns2; j++)
        {
            if(arr2[i][j] != 0)
            {
                sparse_matrix2[k][0] = i;
                sparse_matrix2[k][1] = j;
                sparse_matrix2[k][2] = arr2[i][j];
                k++;
            }
        }
    }

    int sparse_matrix3[values + values2][3];
    int values3 = 0;
    i = 0; j = 0;
    if(rows != rows2 || columns != columns2)
    {
        printf("Addition of matrices is not possible.\n");
    }
    else
    {
        while(i < values && j < values2)
        {
            if((sparse_matrix[i][0] < sparse_matrix2[j][0]) || (sparse_matrix[i][0] == sparse_matrix2[j][0] && sparse_matrix[i][1] < sparse_matrix2[j][1]))
            {
                sparse_matrix3[values3][0] = sparse_matrix[i][0];
                sparse_matrix3[values3][1] = sparse_matrix[i][1];
                sparse_matrix3[values3][2] = sparse_matrix[i][2];
                i++;
                values3++;
            }
            else if((sparse_matrix[i][0] > sparse_matrix2[j][0]) || (sparse_matrix[i][0] == sparse_matrix2[j][0] && sparse_matrix[i][1] > sparse_matrix2[j][1]))
            {
                sparse_matrix3[values3][0] = sparse_matrix2[j][0];
                sparse_matrix3[values3][1] = sparse_matrix2[j][1];
                sparse_matrix3[values3][2] = sparse_matrix2[j][2];
                j++;
                values3++;
            }
            else
            {
                sparse_matrix3[values3][0] = sparse_matrix[i][0];
                sparse_matrix3[values3][1] = sparse_matrix[i][1];
                sparse_matrix3[values3][2] = sparse_matrix[i][2] + sparse_matrix2[j][2];
                i++; j++;
                values3++;
            }
        }
        while(i < values)
        {
            sparse_matrix3[values3][0] = sparse_matrix[i][0];
            sparse_matrix3[values3][1] = sparse_matrix[i][1];
            sparse_matrix3[values3][2] = sparse_matrix[i][2];
            i++;
            values3++;
        }
        while(j < values2)
        {
            sparse_matrix3[values3][0] = sparse_matrix2[j][0];
            sparse_matrix3[values3][1] = sparse_matrix2[j][1];
            sparse_matrix3[values3][2] = sparse_matrix2[j][2];
            j++;
            values3++;
        }

        // Output the of the summation sparse matrix in table form
        for(i = 0; i < values3; i++)
        {
            printf("Row: %d ",sparse_matrix3[i][0]);
            printf("Column: %d ",sparse_matrix3[i][1]);
            printf("Value: %d ",sparse_matrix3[i][2]);
            printf("\n");
        }
        // Output the of the summation sparse matrix in regular matrix format
        k = 0;
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < columns; j++)
            {
                if(sparse_matrix3[k][0] == i && sparse_matrix3[k][1] == j)
                {
                    printf("%d ", sparse_matrix3[k][2]);
                    k++;
                }  
                else
                {
                    printf("0 ");
                }
            }
            printf("\n");
        }

    } 

    // Finding the transpose of the matrix
    int sparse_matrix_transpose[values][3];
    for(i = 0; i < values; i++)
    {
        sparse_matrix_transpose[i][0] = sparse_matrix[i][1];
        sparse_matrix_transpose[i][1] = sparse_matrix[i][0];
        sparse_matrix_transpose[i][2] = sparse_matrix[i][2];
    }

    // Output of the transpose matrix in regular matrix format
    flag = 0;
    printf("Transpose of the first matrix: \n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            flag = 0;
            for(k = 0; k < values; k++)
            {
                if(sparse_matrix_transpose[k][0] == i && sparse_matrix_transpose[k][1] == j)
                {
                    printf("%d ", sparse_matrix_transpose[k][2]);
                    flag = 1;
                    break;
                }
            }  
            if(flag == 0)
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

}
/* Function to directly read a matrix as a sparse matrix
// Read the sparse matrix
    int values;
    scanf("%d", &values);
    for(i = 0; i < values; i++)
    {
        printf("Row value: \n");
        scanf("%d", &sparse_matrix[i][0]);
        printf("Column value: \n");
        scanf("%d", &sparse_matrix[i][1]);
        printf("Value: \n");
        scanf("%d", &sparse_matrix[i][2]);
    }
*/