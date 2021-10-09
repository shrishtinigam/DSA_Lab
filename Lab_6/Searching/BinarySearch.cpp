#include <iostream>
#include <vector>
using namespace std;

// This program uses vectors to accept values from users and performs binary search using recursion
// Time Complexity - O(log n) (Best case- O(1))
// Space Complexity - (here, for recursive,  O(log n)) (for iterative, O(1))

int BinarySearch(int n, vector<int>arr,int x);
int main()
{
    int x,n;
    vector <int> arr;
    cout << " Enter the integer values in ascending order, enter -1 when completed" << endl;
    
    do
    {
        cin>>x;
        arr.push_back(x);
    }while(x!=-1);

    cout << "Which number's existence do you want to check?" << endl;
    cin>>x;
    arr.pop_back();
    n = arr.size();
    BinarySearch(n,arr,x);
}

// Function the performs binary search
    int BinarySearch(int n, vector<int>arr , int x)
    {
        int flag = 0;
        
        if(n==1 && x!=arr[0])
        {
            cout<<"Not found"<<endl;
            flag = 1; // Once flag is 1, it will exit 
        }
        if(flag==0) // Only runs if flag is zero
        {
            if(n%2!=0) // for odd number of elements
            {
                if(x==arr[((n+1)/2)-1]) 
                {
                    cout << "Found"<< endl;
                    flag=1;
                }
                else if(x<arr[((n+1)/2)-1])
                {
                    arr.erase((arr.begin()+((n+1)/2)),arr.end());
                    BinarySearch(((n+1)/2),arr,x); 
                }
                else if(x>arr[((n+1)/2)-1])
                {
                    arr.erase(arr.begin(),(arr.begin()+((n-1)/2)));
                    BinarySearch(((n+1)/2),arr,x); 
                }
                
            }
            else // for even number of elements
            {
                if(x==arr[(n/2)])
                {
                    cout <<"Found"<<endl;
                    flag =1;
                }
                else if(x<arr[(n/2)+1])
                {
                    arr.erase(arr.begin()+(n/2),arr.end());
                    BinarySearch((n/2),arr,x);
                }
                else if(x>arr[(n/2)])
                {
                    arr.erase(arr.begin(),arr.begin()+(n/2));
                    BinarySearch((n/2),arr,x);
                }
            }
        }
        
        
    }
    



