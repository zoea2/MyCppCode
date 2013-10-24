#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int intlist[100002];
int main()
{
    int t,n;
    scanf("%d",&t);
    char s[100002];
    while(t--)
    {
        scanf("%s",&s);
        scanf("%d",&n);
        int temp;

        //printf("sdfsdf");
        getchar();
        if(n == 0)
        {
            getchar();
            getchar();
        }
        for(int i = 0;i < n;i++)
        {
            temp = 0;
            char tempc;
            while(1)
            {
                scanf("%c",&tempc);
                //printf("1\n");
                if(tempc >= '0' && tempc <= '9')
                {
                    temp *= 10;
                    temp += tempc - '0';
                }
                else if(tempc == ',' || tempc == ']')
                {
                    intlist[i] = temp;
                    break;
                }
            }
        }
        //for(int i = 0;i < n;i++)
        //printf("%d ",intlist[i]);
        //printf("\n");
        int len = strlen(s);
        bool error = false;
        bool reverse = false;
        int head = 0;
        int tail = n-1;
        for(int i = 0;i < len;i++)
        {
            if(!error)
            {
                if(s[i] == 'R')
                {
                    if(reverse)
                    reverse = false;
                    else
                    reverse = true;
                }
                else if(s[i] == 'D')
                {
                    if(head > tail)
                        error = true;
                    else
                    {
                        if(reverse)
                        tail--;
                        else
                        head++;
                    }
                }
            }
            else
            break;
        }
        if(error)
        printf("error\n");
        else
        {
            printf("[");
            if(reverse)
            {
                for(int i = tail;i >= head;i--)
                {
                    if(i != head)
                    printf("%d,",intlist[i]);
                    else
                    printf("%d",intlist[i]);
                }
            }
            else
            {
                for(int i = head;i <= tail;i++)
                {
                    if(i != tail)
                    printf("%d,",intlist[i]);
                    else
                    printf("%d",intlist[i]);
                }
            }
            printf("]\n");
        }

    }
}
