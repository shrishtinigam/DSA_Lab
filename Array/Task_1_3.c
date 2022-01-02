#include <stdio.h>
void Insert(int arr[], int n, int num, int k)
{
    // If insertion at end
    if(k == n + 1)
    {
        arr[n] = num;
        return;
    }
    // if insertion at any other position (not end)
    int j = n;
    while(j >= (k - 1))
    {
        arr[j] = arr[j - 1];
        j--;
    }
    arr[k - 1] = num;
    return;
}

typedef struct Exactly_90{
    int count;
    int positions[10];
}Exactly_90;

void Modify_Under_70(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < 70)
        {
            arr[i] += 5;
        }
    }
}

Exactly_90 Exactly_90_Counter(int arr[], int n)
{
    Exactly_90 answer;
    answer.count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 90)
        {
            answer.positions[answer.count] = i;
            answer.count++;
        }
    }
    return answer;
}
  

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
    int graduation[10] = {67, 45, 93, 90, 68, 83, 90, 65, 90};
    // Marks before Insertion
    printf("Marks before Insertion of missing value - \n");
    display(graduation, 9);
    
    // lets say we forgot to insert marks m at position pos
    int m, pos;
    printf("Enter missing marks: \n");
    scanf("%d", &m);
    printf("Enter missing marks's position: \n");
    scanf("%d", &pos);

    Insert(graduation, 9, m, pos);

    // Marks after Insertion
    printf("Marks after Insertion of missing value - \n");
    display(graduation, 10);

    // Improve Marks
    Modify_Under_70(graduation, 10);
    Exactly_90 ans = Exactly_90_Counter(graduation, 10);
    printf("Improved marks: \n");
    display(graduation, 10);
    printf("\n");

    // Count the number of 90's
    printf("Number of 90's: %d \nTheir positions: ", ans.count);
    for(int i = 0; i < ans.count; i++)
    {
        printf("%d ", ans.positions[i] + 1);
    }
}