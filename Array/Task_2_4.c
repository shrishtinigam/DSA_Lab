#include <stdio.h>
#include <ctype.h> 
int Insert(int arr[], int n)
{
    int reps;
    printf("Number of insertions: ");
    scanf("%d", &reps); 
    for(int i = 0; i < reps; i++)
    {
        int x, k;
        printf("Number to insert: ");
        scanf("%d", &x); 
        printf("Position to insert: ");
        scanf("%d", &k); 
        // If insertion at end
        if(k == n)
        {
            arr[n - 1] = x;
            continue;
        }
        // if insertion at any other position (not end)
        int j = n-1;
        while(j >= (k - 1))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[k - 1] = x;
        n++;
    }
    return reps;
}

void Modify(int arr[], int n)
{
    printf("Number to add to each element (Ex: Add -4 to each element) :");
    int x;
    scanf("%d", &x);
    for(int i = 0; i < n; i++)
    {
        arr[i] += x;
    }
}

int Delete(int arr[], int n)
{
    int reps;
    printf("Number of deletions: ");
    scanf("%d", &reps); 
    for(int i = 0; i < reps; i++)
    {
        int k;
        printf("Position to delete (n = %d): ", n);
        scanf("%d", &k);
        // Deletion at end
        if(k == n - 1)
        {
            n--;
        }
        else // Deletion at any other position
        {
            int j = k - 1;
            while(j != n - 1)
            {
                arr[j] = arr[j + 1];
                j++;
            }
            n--;
        }
    }
    return reps;
}

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    fflush(stdout);
}

void Copy(int arr[], int ans[], int n)
{
    for(int i = 0; i < n; i++)
    {
        ans[i] = arr[i];
    }
}

int main()
{
    int vaccines[100];
    int n;
    printf("Intialize the prices of vaccines\n");
    printf("Number of vaccines: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Price of vaccine number %d : ", i+1);
        scanf("%d", &vaccines[i]);
    }
    char choose = 'X';
    int vaccines_copy[100];
    do 
    {
        printf("I - Randomly Insert a price of vaccine\n"); 
        printf("M - Price modification\n");
        printf("D - Delete entry\n"); 
        printf("X - Exit menu\n");
        printf("C - Copy array\n");
        fflush(stdout);
        scanf(" %c", &choose);

        if(toupper(choose) == 'I')
        {
            n += Insert(vaccines, n);
            display(vaccines, n);
        }
        else if(toupper(choose) == 'M')
        {
            Modify(vaccines, n);
            display(vaccines, n);
        }
        else if(toupper(choose) == 'D')
        {
            n -= Delete(vaccines, n);
            display(vaccines, n);
        }
        else if(toupper(choose) == 'C')
        {
            Copy(vaccines, vaccines_copy, n);
            display(vaccines_copy, n);
        }
        else("Invalid response");
    }while(choose != 'X');
}