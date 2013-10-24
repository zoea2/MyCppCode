#include <cstdio>
#include <set>
using namespace std;
int main()
{
   int n;
   int num;
   scanf("%d",&n);
   while (1)
   {
       multiset<int> set1;
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&num);
            set1.insert(num);
        }
       multiset<int>::iterator p;
       p = set1.begin();
       int temp = *p;
       int tempnum = set1.count(*p);
       printf("%d %d\n",temp,tempnum);
       for (p = set1.begin()++;p != set1.end();p++)
       {
           if (*p != temp)
           {
               temp = *p;
               printf("%d %d\n",*p,set1.count(*p));
           }
       }
       if (scanf("%d",&n))
       printf("\n");
       else
       break;

   }
   return 0;
}
