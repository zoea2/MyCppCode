#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
vector<int> vec[100001];
int ind[100001];
int q[100001];
void inline HeapInsert(int &n,int value)
{
    if (n == 0)
    q[++n] = value;
    else
    {
        q[++n] = value;
        int temp = value;
        int index = n;
        for (int i = n / 2;i > 0;i /= 2)
        {
            if (temp > q[i])
                break;
            else if (temp < q[i])
            {
                q[index] = q[i];
                index = i;
            }
        }
        q[index] = temp;
    }
}
void inline HeapDelete(int &n)
{
    if (n == 1)
    n--;
    else
    {
        q[1] = q[n--];
        int temp = q[1];
        int index = 1;
        for (int i = 2;i <= n;i*=2)
        {
            if (q[i] > q[i+1])
            i++;
            if (temp < q[i])
            break;
            else if (temp > q[i])
            {
                q[index] = q[i];
                index = i;
            }
        }
        q[index] = temp;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,x,y;
        scanf("%d%d",&n,&m);
        memset(ind,0,sizeof(ind));
        memset(vec,0,sizeof(vec));
        memset(q,0,sizeof(q));
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d",&x,&y);
            vec[x].push_back(y);
            ind[y]++;
        }
        int count = 0;
        for (int i = 1;i <= n;i++)
        {
            if (ind[i] == 0)
                HeapInsert(count,i);
        }
        while(count > 0)
        {
            int temp = q[1];
            HeapDelete(count);
            printf("%d ",temp);
            for (int i = 0;i < vec[temp].size();i++)
            {
                if (--ind[vec[temp][i]] == 0)
                    HeapInsert(count,vec[temp][i]);
            }
        }
        printf("\n");
    }
}
