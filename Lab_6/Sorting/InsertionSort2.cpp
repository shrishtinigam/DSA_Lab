// InsertionSort2.cpp
#include <iostream>
#include <vector>
using namespace std;
#define rep(i,a,b) for (int i = a; i < b; i++)

vector <int> InsertionSort1(vector <int> v, int n);
vector <int> InsertionSort2(vector <int> v, int n);
vector <int> InsertionSort3(vector <int> v, int n);

int main()
{
    int n; cin >> n;
    vector <int> v(n);
    rep(i, 0, n)
        cin >> v[i];
    v = InsertionSort1(v, n);
    rep(i, 0, n)
        cout << v[i] << " ";
    v = InsertionSort2(v, n);
    rep(i, 0, n)
        cout << v[i] << " ";
    rep(i, 0, n)
        cin >> v[i];
    v = InsertionSort3(v, n);
    rep(i, 0, n)
        cout << v[i] << " ";
}
// ascending
vector <int> InsertionSort1(vector <int> v, int n)
{
    rep(i, 1, n)
    {
        int k = v[i];
        while(i-1 >= 0 && v[i-1] > k)
        {
            v[i] = v[i-1];
            i--;
        }
        //cout << " i = " << i << "\n";
        v[i] = k;
        //rep(i, 0, n)
            //cout << v[i] << " ";
        //cout << "\n";
    }
    return v;
}
// descending
vector <int> InsertionSort2(vector <int> v, int n)
{
    rep(i, 1, n)
    {
        int k = v[i];
        while(i-1 >= 0 && v[i-1] < k)
        {
            v[i] = v[i-1];
            i--;
        }
        //cout << " i = " << i << "\n";
        v[i] = k;
        //rep(i, 0, n)
            //cout << v[i] << " ";
        //cout << "\n";
    }
    return v;
}

// ascending recursively

vector <int> InsertionSort3(vector <int> v, int n)
{
    if(n <= 1)
        return v;
    v = InsertionSort3(v, n - 1);

    int last = v[n-1];
    int j = n - 2;
    while (j >= 0 && v[j] > last)
    {
        v[j+1] = v[j];
        j--;
    }
    v[j+1] = last;
    rep(i, 0, n)
        cout << v[i] << " ";
    cout << "\n";
    return v;
}

/* Example:
5 3 9 1 3 8 2
 i = 0
3 5 9 1 3 8 2
 i = 1
3 5 9 1 3 8 2
 i = 2
3 5 9 1 3 8 2
 i = 0
1 3 5 9 3 8 2
 i = 1
1 3 5 9 3 8 2 
 i = 2
1 3 5 9 3 8 2
 i = 3
1 3 5 9 3 8 2
 i = 2       --> shows that sort is stable 
1 3 3 5 9 8 2
 i = 3
1 3 3 5 9 8 2
 i = 4
1 3 3 5 9 8 2
 i = 4
1 3 3 5 8 9 2 
 i = 5
1 3 3 5 8 9 2
 i = 1
1 2 3 3 5 8 9
 i = 2
1 2 3 3 5 8 9
 i = 3
1 2 3 3 5 8 9
 i = 4
1 2 3 3 5 8 9
 i = 5
1 2 3 3 5 8 9
 i = 6
1 2 3 3 5 8 9
*/