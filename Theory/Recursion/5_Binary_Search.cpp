// 5_Binary_Search.cpp
#include <iostream>
#include <string>
using namespace std;

int binary_search(int arr[], int left, int right, int x)
{
    if(left > right)
        return -1;
    int mid = (left + right)/2;
    if(x == arr[mid])
        return mid; // 0 based position is returned
    if(x < arr[mid])
        return binary_search(arr, left, mid - 1, x);
    return binary_search(arr, mid + 1, right, x);
}
int main()
{
    int x[] = {1, 2, 3, 4, 5, 6};
    cout << binary_search(x, 0, 6, 4) << " " << binary_search(x, 0, 6, 7);
}