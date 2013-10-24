#include <stdio.h>
int main ()
{
    int n,m;
    int c1,c2;
    int j,k,j1,k1;
    for (;;)
    {
        scanf("%d",&n);
        if (n == 0)
           return 0;
        m = 2 * n;
        int count = 0;
        int couple[m+1];
        couple[0] = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&c1,&c2);
            couple[c1] = c2;
            couple[c2] = c1;
            }
        for (int i = 1;i <= m ;i++)
        {
            if (couple[i] == 0)
               continue;
            else if (couple[i] - i != 1 && couple[i] - i != -1)
                 continue;
            else
            {
                j = couple[i];
                couple[i] = 0;
                k = i;
                couple[j] = 0;
                j1 = j;
                k1 = k;
                count ++;
                for (; ;)
                {     if(k < j)
                      {
                           do
                           {
                               k--;
                               if (k == 0)
                               k = 2 * n;
                               }while(couple[k] == 0 && k != j1);
                           do{
                               j++;
                               if (j == 2 * n + 1)
                               j = 0;
                               }while(couple[j] == 0 && j != k1);
                               }
                      else 
                      {
                            do
                           {
                               j--;
                               if(j == 0)
                               j = 2 * n;
                               }while(couple[j] == 0 && j != k1);
                           do{
                               k++;
                               if(k == 2 * n + 1)
                               k = 1;
                               }while(couple[k] == 0 && k != j1);
                               }
                      if ( k == k1 ||  j == j1)
                         break;
                      if (couple[j] == k && couple[k] == j)
                      {
                                    couple[j] = 0;
                                    couple[k] = 0;
                                    count ++;
                                    } 
                      else 
                      break;     
                }
                }
                }
            if (count == n)
            printf("Yes\n");
            else
            printf("No\n");
            }
            return 0;
            }
        
