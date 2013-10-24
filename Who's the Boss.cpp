#include <iostream>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct em
{
    int ID;
    unsigned int height;
    int money;
};
bool cmp(em a,em b)
{
    return a.money<b.money;
}
int main()
{
    int t;
    cin>>t;
    int n,q;
    while(t--)
    {
        scanf("%d%d",&n,&q);
        em emp[n];
        for (int i = 0;i < n;i++)
        scanf("%d%d%d",&emp[i].ID,&emp[i].money,&emp[i].height);
        sort(emp,emp+n,cmp);
        map<int,int> boss;
        map<int,int> num;
        for (int i = n-1;i > 0;i--)
        {
            if (emp[i].height >= emp[i-1].height)
            {
                if (i == n-1)
                    boss[emp[i].ID] = 0;
                num[emp[i].ID] = i;
                boss[emp[i-1].ID] = emp[i].ID;
            }
            else
            {
                if (i == n-1)
                    boss[emp[i].ID] = 0;
                boss[emp[i-1].ID] =  boss[emp[i].ID];
            }
        }
        num[emp[0].ID] = 0;
        for (int i = 1;i < n;i++)
        {
             if (emp[i].height < emp[i-1].height)
                num[emp[i].ID] = num[emp[i-1].ID];
            else
                num[emp[i].ID] = i;
        }
        int temp;
        for (int i = 0;i < q;i++)
        {
            scanf("%d",&temp);
            printf("%d %d\n",boss[temp],num[temp]);
        }

    }
}
