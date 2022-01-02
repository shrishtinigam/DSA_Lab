// MergeSort.cpp
// O(nlogn) time complexity, stable sort, O(n) space complexity
#include <iostream>
#include <vector>
#define rep(i,a,b) for (int i = a; i < b; i++)
using namespace std;
vector <int> merge(vector <int> data, int start, int mid, int end)
{
    // build temp array
    vector <int> temp(end - start + 1);
    int i(start), j(mid + 1), k(0);
    while(i <= mid && j <= end)
    {
        if(data[i] <= data[j])
        {
            temp[k] = data[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = data[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = data[i];
        k++;
        i++;
    }

    while (j <= end)
    {
        temp[k] = data[j];
        k++;
        j++;
    }

    for(i = start; i <= end; i++)
    {
        data[i] = temp[i-start];
    }
    return data;
}
vector <int> mergeSort(vector <int> data, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        data = mergeSort(data, start, mid);
        data = mergeSort(data, mid+1, end);
        data = merge(data, start, mid, end);
    }
    return data;
}

int main()
{
    vector <int> x = {-5, 20, 10, 3, 2, 0};
    x = mergeSort(x, 0, x.size()-1);
    rep(i, 0, x.size())
    {
        cout << x[i] << " ";
    }
}