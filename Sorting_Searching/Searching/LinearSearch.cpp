#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
// This program uses vectors to accept values from users and performs linear search
//  O(n) and Ω(1) for linear search
// array can be unsorted
int main()
{
    int x,n,y;
    int flag = 0;
    vector<int> arr;
    cout << " Enter the integer values, enter -1 when completed" << endl;
    do{
        cin>>x;
        arr.push_back(x);
    }while(x!=-1);
    cout << "Check for existence of which number?" << endl;
    cin>>x;
    n = arr.size();
    for(int i = 0;i < n;i++)
    {   
        y = arr[i];
        if(y==x)
        {
            cout << "Found at "<<i<<" position from 0 "<<endl;
            flag = 1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"Thank you!"<<endl;
    }
    else
    {
        cout<<"Not found!"<<endl;
    }

}


