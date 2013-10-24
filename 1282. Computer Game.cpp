#include <iostream>
using namespace std;
void pronext(int s[],int next[])
{
    next[1] = 0;
    int i = 1;int j = 0;
    while(i <= s[0])
    {
        if (j == 0 || s[i] == s[j])
        {
            i++;j++;
            if (s[i] != s[j])
            next[i] = j;
            else
            next[i] = next[j];
        }
        else
        j = next[j];
    }
}
void kmp(int s1[],int s2[],int next[])
{
    int j = 1,i = 1;
    while(i <= s1[0] && j <= s2[0])
    {
        if (j == 0 ||s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        j = next[j];
    }
    if (j > s2[0])
    cout<<i-j<<endl;
    else
    cout<<"no solution"<<endl;
}
int main()
{
    int n,m;
    while(cin>>n)
    {
        int s1[n+1];
        s1[0] = 0;
        for (int i =1;i <= n;i++)
        {
            cin>>s1[i];
            s1[0]++;
        }
        cin>>m;
        int s2[m+1];
        s2[0] = 0;
        for (int i =1;i <= m;i++)
        {
            cin>>s2[i];
            s2[0]++;
        }
        int next[m+1];
        pronext(s1,next);
        kmp(s2,s1,next);

    }
}
