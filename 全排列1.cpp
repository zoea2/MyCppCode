#include <cstdio>
#include  <iostream>
#include <algorithm>
#include <cstring>
using namespace std;



inline void Swap(char& a,char& b) //此处为引用,交换函数.函数调用多,故定义为内联函数.
{
    int temp=a;
    a=b;
    b=temp;
}

void Perm(char list[],int k,int m,string a[],int & count) //k表示前缀的位置,m是要排列的数目.
{
if(k==m-1) //前缀是最后一个位置,此时打印排列数.
{

a[count] = list;
count++;
}
else
{
for(int i=k;i<m;i++)
{
Swap(list[k],list[i]); //交换前缀,使之产生下一个前缀.
Perm(list,k+1,m,a,count);
Swap(list[k],list[i]); //将前缀换回来,继续做上一个的前缀排列.
}
}
}


int main()
{

    int jiecheng[8] = {1,2,6,24,120,720,5040,40320};
    char list[9];
    cin>>list;
    int n = strlen(list);
    string a[jiecheng[n-1]];
    int count = 0;
    Perm(list,0,n,a,count);
    sort(a,a+jiecheng[n-1]);
    for (int i = 0;i < jiecheng[n-1];i++)
    cout<<a[i]<<endl;
}
