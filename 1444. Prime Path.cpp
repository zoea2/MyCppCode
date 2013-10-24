#include<iostream>
#include <cmath>
#include <queue>
using namespace std;
bool prime(int a)
{
    for (int i = 2;i <= sqrt(a);i++)
    {
        if (a % i == 0)
        return false;
    }
    return true;
}
int main()
{
    int isPrime[10000] = {0};

    for (int i = 1000;i < 10000;i++)
    {
        if (prime(i))
        {
            isPrime[i] = 1;

        }
    }
    int t;
    cin>>t;
    bool isend = 0;
    while(t)
    {
        t--;
        int note[10000] = {0};
        bool isend = 0;
        int col[10000]={0};
        int begin,end;
        cin>>begin>>end;
        col[begin] = 1;
        queue<int> q;
        q.push(begin);
        int count = 0,count1 = 0,count2 = 0;
        while(!q.empty())
        {
            int temp = q.front();
            int temp2 = temp;
            q.pop();
            if (temp == end)
            {
                cout<<count<<endl;
                isend = 1;
                break;
            }
            int ge = temp % 10;
            temp /= 10;
            for (int i = 1;i <= 9;i += 2)
            {
                if (isPrime[temp * 10 + i] == 1 && col[temp * 10 + i] == 0)
                {
                    col[temp * 10 + i] = 1;
                    q.push(temp * 10 + i);
                    count1++;
                }
            }
            int shi = temp % 10;
            temp /= 10;
            for (int i = 0;i <= 9;i++)
            {
                if (isPrime[temp * 100 + i * 10 + ge] == 1 && col[temp * 100 + i * 10 + ge] == 0)
                {
                    col[temp * 100 + i * 10 + ge] = 1;
                    q.push(temp * 100 + i * 10 + ge);
                    count1++;
                }
            }
            int bai = temp % 10;
            temp /= 10;
            for (int i = 0;i <= 9;i++)
            {
                if (isPrime[temp * 1000 + i * 100 + shi * 10 + ge] == 1 && col[temp * 1000 + i * 100 + shi * 10 + ge] == 0)
                {
                    col[temp * 1000 + i * 100 + shi * 10 + ge] = 1;
                    q.push(temp * 1000 + i * 100 + shi * 10 + ge);
                    count1++;
                }
            }
            for (int i = 1;i <= 9;i++)
            {
                if (isPrime[i * 1000 + bai * 100 + shi * 10 + ge] == 1 && col[i * 1000 + bai * 100 + shi * 10 + ge] == 0)
                {
                    col[i * 1000 + bai * 100 + shi * 10 + ge] = 1;
                    q.push(i * 1000 + bai * 100 + shi * 10 + ge);
                    count1++;
                }
            }
            if (count2 == note[count])
            {

                count++;
                note[count] = count1;
            }
            count2++;

        }
        if(!isend)
        cout<<"Impossible"<<endl;
    }

}
