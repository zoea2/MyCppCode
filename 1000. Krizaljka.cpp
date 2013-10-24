#include <iostream>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    for (int j = 0;j < a.size();j++)
    {
        for (int i = 0;i < b.size();i++)
        {
            if (b[i] == a[j])
            {
                for (int k = 0;k < b.size();k++)
                {
                    if (k == i)
                    cout<<a;
                    else
                    {
                        for (int z = 0;z < a.size();z++)
                        {
                            if (z == j)
                            cout<<b[k];
                            else
                            cout<<".";
                        }
                    }

                    cout<<endl;
                }
                return 0;
            }
        }
    }
}
