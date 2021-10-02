// Using STL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec{1, 2, 3, 4};
    // Iterator Loop
    for(auto& x : vec) 
    x += 10;
    // for_each
    for_each(vec.begin(), vec.end(), [](int &n){ n+=10; });
    // transform
    transform(vec.begin(), vec.end(), vec.begin(), [](int x) { return x + 10;});
    // valarray header file can also be used
}