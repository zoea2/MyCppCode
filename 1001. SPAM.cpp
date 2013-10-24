#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int l = s.length();
        for (int i = 0;i < l;i++)
        {
            int j = 0,k = 0;
            if (s[i] == '@'&&i != 0 && i != l-1)
            {
                int j = i,k = i;
                while(isalnum(s[j])||s[j] == '_'||s[j] == '-'||s[j] == '.' ||j == i)
                {
                    if (s[j] == '.'&&(s[j-1] == '.'||s[j-1]=='@'||((!isalnum(s[j-1]))&&s[j-1]!='-'&&s[j-1]!='_')))
                    {
                        break;
                    }
                    j--;
                }
                j++;
                while(isalnum(s[k])||s[k] == '_'||s[k] == '-'||s[k] == '.' ||k == i)
                {
                    if (s[k] == '.'&&(s[k+1] == '.'||s[k+1]=='@'||(!isalnum(s[k+1])&&s[k+1]!='-'&&s[k+1]!='_')))
                        break;
                    k++;
                }
                k--;
                if (k != i && j != i)
                {
                    for (int q = j;q <=k;q++)
                    cout<<s[q];
                    cout<<endl;
                }
            }
        }
    }
}
