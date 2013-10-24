#include <cstdio>
using namespace std;
int count = 1;
void print(int n,int c,int result[][750])
{

    int temp = (c - n) / 2;
    if (n == 1)
        result [temp][temp] = count;
    else
    {
        for (int j = temp ;j < c - temp ;j++)
        {
            result[temp][j] = count;
            count++;
        }
        for (int j = temp + 1;j < c - temp;j++)
        {
            result[j][temp + n - 1] = count;
            count ++;
        }
        for (int j = temp + n - 2;j >= temp;j--)
        {
            result[temp + n - 1][j] = count;
            count++;
        }
        for (int j = temp + n - 2;j > temp;j--)
        {
            result[j][temp] = count;
            count++;
        }

    }
    if(n - 2 > 0)
    print(n - 2,n,result);


}

int main()
{
    int n;
    scanf("%d",&n);
   int result[n][750];
    print(n,n,result);
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n - 1;j++)
        printf("%d ",result[i][j]);
        printf("%d\n",result[i][n-1]);
    }

}
