// 16_Row_Col_Wise_Sorted.cpp
// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
#include <iostream>
#include <vector>
using namespace std;
vector<int> BinarySearch(vector<vector<int>>arr , int x, int r, int c);
void print(vector<vector<int>> x, int r, int c, int m, int n);
int main()
{
    int x, r, c;
    
    cout << "Enter number of rows in 2D matrix: \n";
    cin >> r;
    cout << "Enter number of columns in 2D matrix: \n";
    cin >> c;
    vector <vector<int>> arr(r);
    cout << "Enter the rowise, columnwise sorted matrix, enter rowise: \n";
    
    vector <int> temp(c);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            cin >> temp[j];
        arr[i] = temp;
    }    

    cout << "Which number's existence do you want to check? ";
    cin >> x;
    vector<int> result = BinarySearch(arr,x,r,c);
    cout << "Found at "<< result[0] << " " << result[1] << "\n";
    print(arr, r, c, result[0], result[1]);
}

vector<int> BinarySearch(vector<vector<int>>arr , int x, int r, int c)
{
    int i = 0, j = c - 1;
    while(i >= 0 && i < r && j >= 0 && j < c)
    {
        if(arr[i][j] == x)
            return {i, j};
        else if (arr[i][j] > x)
            j--;
        else
            i++;
    } 
    return {-1, -1}; 
}

void print(vector<vector<int>> x, int r, int c, int m, int n)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(i == m && j == n)
                cout << "*"<<x[i][j] << "*";
            else
                cout << " " << x[i][j] << " ";
        }
        cout << "\n";
    }    
}
    