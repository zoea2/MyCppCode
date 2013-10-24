#include <stdio.h>
int main()
{
 int n,i,j,k;
 int j1,k1;
 int c1,c2;
 int *array;   //array,在下标对应处存放该下标的couple
 int cout;
 do{
  scanf("%d",&n);
  if(n==0) return 0;
  array=new int[2*n+1];
  array[0]=0;
  cout=0;   //配对数
  for(i=0;i<n;i++)
  {
   scanf("%d%d",&c1,&c2);
   array[c1]=c2;
   array[c2]=c1;
  }
  for(i=1;i<=2*n;i++)
  {
   if(array[i]==0) continue;   //0,已配对
   else
    if(array[i]-i!=1&&array[i]-i!=-1) //两者是相邻的,为couple
     continue;
    else
    {
     j=array[i];  //j,k,配对了的couple位置记录
     array[i]=0;
     k=i;
     array[j]=0;
     cout++;
     j1=j;
     k1=k;
     do{    //继续寻早j,k两边的两个,是否配对,为0,跳过继续查找
      if(k<j)
      {
       do{
        k--;
        if(k==0)  k=2*n;
       }while(array[k]==0&&k!=j1);  //搜索了一轮,已经结束了
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
      if(k==k1||j==j1)  break;  //搜索了一轮,已经结束了
      if(array[k]==j&&array[j]==k)  //配对情况
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
