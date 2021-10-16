#include <iostream>
using namespace std;
void mergeSort(int arr[], int l, int r, int size);
void merge(int arr[],int l,int m, int r, int size);
int main()
{
    cout << "Enter size of array: " << endl;
    int size;
    cin >> size;
    int myarray[size];
 
    cout << "Enter " << size << " integers in any order: " << endl;
    for(int i = 0; i<size; i++){
        cin >> myarray[i];
    }
    
    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << myarray[i] << " ";
    }
    cout << endl;

    mergeSort(myarray, 0, (size - 1), size); 
 
    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << myarray[i] << " ";
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