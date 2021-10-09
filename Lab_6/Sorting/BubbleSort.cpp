#include <iostream>
#include <vector>
using namespace std;
// This program uses vectors to accept values from users and performs bubble sort
int main()
{
    int x,n,hold;
    int flag = 0;
    vector <int> arr;
    cout << " Enter the integer values, enter -1 when completed" << endl;
    // Takes in the values from the user
    do{
        cin>>x;
        arr.push_back(x);
    }while(x!=-1);
    arr.pop_back();
    
    n = arr.size();

    do{
        flag = 0;
        for(int i = 0; i<n-1; i++)
        {
            if(arr[i]>arr[i+1])
            {
                hold = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = hold;
                flag = flag + 1;
            }
        }
    }while(flag!=0);

    cout << "Sorted Array"<<endl;
    for (int a=0; a<arr.size(); ++a)
    {
        cout<< ' ' << arr[a];
    }
}
