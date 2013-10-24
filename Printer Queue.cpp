#include <cstdio>
#include <queue>
using namespace std;
struct job
{
    int index,pro;
    job(int i,int p)
    {
        index = i;
        pro = p;
    }
};
int heap0[101];
void HeapInsert(int value,int &n)
{
    if (n == 0)
    {
        heap0[++n] = value;
    }
    else
    {
        int index = ++n;
        for (int i = n / 2;i > 0;i /= 2)
        {
            if (value < heap0[i])    break;
            else if (value > heap0[i])
            {
                heap0[index] = heap0[i];
                index = i;
            }
        }
        heap0[index] = value;
    }
}
void HeapDelete(int &n)
{
    if (n == 1)
        n--;
    else
    {
        int temp = heap0[n--];
        int index = 1;
        for (int i = 2;i <= n;i*=2)
        {
            if (heap0[i] < heap0[i+1])
                i++;
            if (temp > heap0[i])    break;
            else if (temp < heap0[i])
            {
                heap0[index] = heap0[i];
                index = i;
            }
        }
        heap0[index] = temp;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        queue<job> j;
        int p;
        int counth = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%d",&p);
            j.push(job(i,p));
            HeapInsert(p,counth);
        }
        int count = 0;
        while(!j.empty())
        {
            job temp = j.front();
            j.pop();
            if (temp.pro < heap0[1])
                j.push(temp);
            else if (temp.pro == heap0[1])
            {
                count++;
                if (temp.index == m)
                {
                    printf("%d\n",count);
                    break;
                }
                HeapDelete(counth);
            }
        }
    }
}
