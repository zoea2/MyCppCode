#include <iostream>
#include <algorithm>
using namespace std;
class id
{
    public:
        string name;
        string ip;
        int num;
};
bool cmp1(id a,id b)
{
    return a.name < b.name;
}
bool cmp2(id a,id b)
{
    return a.name < b.name;
}
int main()
{
    int n;
    for (; ;)
    {
        cin>>n;
        if (n == 0)
            break;
        id a[n];
        for (int i = 0;i < n;i++)
        {
            cin>>a[i].name>>a[i].ip;
            a[i].num = i + 1;
        }
        sort(a,a+n,cmp1);

        int count = 0;
        id b [n / 2];
        for (int i = 0;count < n / 2;i++)
        {
                for(int j = i + 1; j < n;j++)
                {
                    if (a[i].ip == a[j].ip)
                    {
                        if (a[i].num < a[j].num)
                        {
                            b[count] = a[i];
                            count++;
                        }
                        else
                        {
                            b[count] = a[j];
                            count++;
                        }
                    }

                }

        }
        sort(b,b+ n/2,cmp2);
        for (int i = 0;i < n / 2;i ++)
        {
            for(int j = 0;j < n;j++)
            {
                if(b[i].name != a[j].name)
                {
                    if(b[i].ip == a[j].ip)
                        cout<<a[j].name<<" is the MaJia of "<<b[i].name<<endl;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
