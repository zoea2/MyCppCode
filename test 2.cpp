#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAX=1000000;

int main()
{
     int i=0,j=0,n=sqrt(MAX)+1;
     int a[MAX+1]={0};

     for(i=2;i<=n;i++)  //É¸Ñ¡Ñ­»·
       for(j=2;j<=MAX/i;j++)
           a[j*i]=1;


     for(i=2;i<=MAX;i++)
        if(a[i]==0)
        {
          cout.width(10);
          cout<<i<<" ";
        }

     return 0;

}
