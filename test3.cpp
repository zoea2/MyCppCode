#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
using namespace std;
vector<int> vec[101];
int inder[101];
int main()
{
    int myints[]= {10,60,50,20};

    priority_queue<int> first;
    priority_queue<int> second (myints,myints+4);
    priority_queue< int, vector<int>, greater<int> > third (myints,myints+4);
    for (int i = 0;i < 4;i++)
    {
        cout<<second.top();
        second.pop();
    }

}
