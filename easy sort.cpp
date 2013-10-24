#include <iostream>
using namespace std;
void * sorts(int *answer,int &m);

int main(){
    int t,m = 0;
    int *answer = new int[1000] ;
    cin>>t;
    for (int a = 0;a < t;a++)
        sorts(answer,m);

    for (int b = 0;b < m;b++)
        cout<<answer[b]<<endl;



    return 0;
}
void * sorts(int *answer,int &m)
{
     int n;
    cin>>n;
    int *number = new int[n];
    for (int i = 0;i < n;i++)
    cin>>number[i];
    for (int i = n-1;i >= 1;i--){
			int currentMax = number[0];

			int currentMaxIndex = 0;
			for (int j = 1;j <= i;j++)
			{
				if (currentMax < number[j])
				{

					currentMax = number[j];
					currentMaxIndex = j;
				}
			}
			if (currentMaxIndex != i)	{
				number[currentMaxIndex] = number[i];
				number[i] = currentMax;}
            }







    for (int p = 0;p < n;p++)
    {answer[m] = number[p];
    m++;
}
   return 0;

}
