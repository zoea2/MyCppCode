#include <stdio.h>
int main()
{
 int n,i,j,k;
 int j1,k1;
 int c1,c2;
 int *array;   //array,���±��Ӧ����Ÿ��±��couple
 int cout;
 do{
  scanf("%d",&n);
  if(n==0) return 0;
  array=new int[2*n+1];
  array[0]=0;
  cout=0;   //�����
  for(i=0;i<n;i++)
  {
   scanf("%d%d",&c1,&c2);
   array[c1]=c2;
   array[c2]=c1;
  }
  for(i=1;i<=2*n;i++)
  {
   if(array[i]==0) continue;   //0,�����
   else
    if(array[i]-i!=1&&array[i]-i!=-1) //���������ڵ�,Ϊcouple
     continue;
    else
    {
     j=array[i];  //j,k,����˵�coupleλ�ü�¼
     array[i]=0;
     k=i;
     array[j]=0;
     cout++;
     j1=j;
     k1=k;
     do{    //����Ѱ��j,k���ߵ�����,�Ƿ����,Ϊ0,������������
      if(k<j)
      {
       do{
        k--;
        if(k==0)  k=2*n;
       }while(array[k]==0&&k!=j1);  //������һ��,�Ѿ�������
       do{
        j++;
        if(j==2*n+1) j=1;
       }while(array[j]==0&&j!=k1);
      }else{
       do{
        j--;
        if(j==0)  j=2*n;
       }while(array[j]==0&&j!=k1);
       do{
        k++;
        if(k==2*n+1) k=1;
       }while(array[k]==0&&k!=j1);
      }
      if(k==k1||j==j1)  break;  //������һ��,�Ѿ�������
      if(array[k]==j&&array[j]==k)  //������
      {
       cout++;
       array[k]=0;
       array[j]=0;
      }else
       break;
     }while(1);
    }
  }
  if(cout==n) printf("Yes\n");
  else  printf("No\n");
 }while(1);
}
