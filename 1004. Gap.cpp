#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string order;
    long long int number;
    while (cin>>n)
    {
        vector<long long int> p;
        for (int i = 0;i < n;i++)
        {
            cin>>order;
            if (order == "Add")
            {
                  cin>>number;
                  p.push_back(number);
                  continue;
            }
            else if(order == "Query")
            {
                vector<long long int>::iterator q = p.begin();
                sort(q,q+p.size());
                int mindis = p[1] - p[0];
                for (int i = 2;i < p.size();i++)
                {
                    if (mindis > p[i] - p[i-1])
                    {
                        mindis = p[i] - p[i-1];
                    }
                }
                cout<<mindis<<endl;
            }
        }
    }

}


