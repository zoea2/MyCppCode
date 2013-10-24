#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t,n,p;
    cin>>t;
    int casenum = 0;
    bool unwon = false;
    bool finish = false;
    while(t--)
    {
        casenum++;
        cin>>n;
        int totalsize = 52;
        queue<int> deck[n];
        int mark[10] = {0};
        int count0[10] = {0};
        for (int i = 0;i < 52;i++)
        {
            cin>>p;
            deck[0].push(p);
        }
        int count[10] = {0};
        unwon = false;
        finish = false;
        for (int i = 0;i < n;i++)
        {
            while(deck[i].empty())
            {
                i++;
                if (i >= n)
                i = 0;
                continue;
            }
            count0[i]++;
            count[i]++;
            if (deck[i].front() == count[i])
            {
                if (i < n-1)
                deck[i+1].push(deck[i].front());
                else
                totalsize--;
                mark[i] = deck[i].front();
                count0[i] = 0;
                cout<<mark[i]<<endl;
                cout<<"the "<<i<<" 's size "<<deck[i].size()<<endl;
                deck[i].pop();
            }
            else
            {

                deck[i].push(deck[i].front());
                deck[i].pop();

            }
            if (count[i] == 13)
                count[i] = 0;
            if (count0[i] > deck[i].size()*13)
            {
                unwon = true;
            }
            if (totalsize == 0)
            {
                finish = true;
            }
            if (i >= n-1)
                i = -1;
            if (unwon||finish)
            break;
        }

        if (unwon)
         cout<<"Case "<<casenum<<": unwinnable"<<endl;
        else if (finish)
        {
            cout<<"Case "<<casenum<<":";
            for (int q = 0;q < n;q++)
            cout<<" "<<mark[q];
            cout<<endl;
        }
    }
    return 0;
}
