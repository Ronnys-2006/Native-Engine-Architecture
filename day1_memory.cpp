#include <iostream>

using namespace std;

#include <vector>

void displayadd(vector<int>& vec);

int main() {
    
    vector<int> vec = {13,45,32,55,32};

    displayadd(vec);

    return 0;
}

void displayadd(vector<int>& vec)
{
    for( int &val : vec)
    {
        cout << &val << endl ;
    }
}