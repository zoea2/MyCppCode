#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    string DNA[100];
    int num;
    cin>>t;
    int count;
    while(t)
    {
        t--;
        cin>>num;
        count = 0;
        for (int i = 0;i < num;i++)
            cin>>DNA[i];
        for (int i = 0;i < num;i++)
        {
            string match;
            if (!DNA[i].empty())
            {
                for (int k = 0;k < DNA[i].size();k++)
                {
                    if (DNA[i][k] == 'T')
                    match.append("A");
                    else if (DNA[i][k] == 'A')
                    match.append("T");
                    else if (DNA[i][k] == 'C')
                    match.append("G");
                    else if (DNA[i][k] == 'G')
                    match.append("C");
                }
                for (int j = i + 1;j < num;j++)
                {
                    if (match == DNA[j])
                    {
                        count++;
                        DNA[j].clear();
                        DNA[i].clear();
                        break;
                    }
                }
            }


        }
        cout<<count<<endl;
    }

}
