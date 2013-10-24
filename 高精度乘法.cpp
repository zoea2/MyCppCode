#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int a[105],b[105],c[100000],len,la,lb,i,j;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string n,m;
	cin>>n>>m;
	if(n == "0" || m == "0"){
		cout<<0<<endl;
		continue;
	}
	la=n.length();
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i = 1;i <= la;i++){
		a[i] = n[la-i] - '0';
	}
	lb=m.length();
	for(int i = 1;i <= lb;i++){
		b[i] = m[lb-i] - '0';
	}
	memset(c,0,sizeof(c));
	for(i=1;i<=la;i++)
		for(j=1;j<=lb;j++)
			c[i+j-1]=c[i+j-1]+a[i]*b[j];
	len=la+lb;
	for(i=1;i<=len;i++)
	{
		c[i+1]=c[i+1]+c[i]/10;
		c[i]=c[i]%10;
	}
	while(c[len]==0){len--;}
	long long s=c[len];
	while(s>0)
	{
		c[len]=s%10;
		s=s/10;
		len++;
	}
	for(i=len-1;i>=1;i--) {cout<<c[i];}
	cout<<endl;
}
	return 0;
}
