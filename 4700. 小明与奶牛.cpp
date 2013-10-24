#include <iostream>
#include <algorithm>
using namespace std;
struct cow
{
    int classes;
    int milk;
};
bool cmp(cow a,cow b)
{
    if (a.classes != b.classes)
    return a.classes < b.classes;
    else
    return a.milk > b.milk;
}
int main()
{
    int t,n;
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        cow cows[n];
        for (int i = 0;i < n;i++)
        {
            cin>>cows[i].classes>>cows[i].milk;
        }
        sort(cows,cows + n,cmp);
        int classs = 0;
        for (int i = 0;i < n;i++)
        {
            if (classs != cows[i].classes)
            {
                cout<<cows[i].classes<<" "<<cows[i].milk<<endl;
                classs = cows[i].classes;
            }
        }
    }
}
