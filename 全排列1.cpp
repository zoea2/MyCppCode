#include <cstdio>
#include  <iostream>
#include <algorithm>
#include <cstring>
using namespace std;



inline void Swap(char& a,char& b) //�˴�Ϊ����,��������.�������ö�,�ʶ���Ϊ��������.
{
    int temp=a;
    a=b;
    b=temp;
}

void Perm(char list[],int k,int m,string a[],int & count) //k��ʾǰ׺��λ��,m��Ҫ���е���Ŀ.
{
if(k==m-1) //ǰ׺�����һ��λ��,��ʱ��ӡ������.
{

a[count] = list;
count++;
}
else
{
for(int i=k;i<m;i++)
{
Swap(list[k],list[i]); //����ǰ׺,ʹ֮������һ��ǰ׺.
Perm(list,k+1,m,a,count);
Swap(list[k],list[i]); //��ǰ׺������,��������һ����ǰ׺����.
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
