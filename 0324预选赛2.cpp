#include <iostream>
using namespace std;
bool isRe(int count,char a[],int count1)
{
    int i = count - 1;
    for (int j = 0;j < count1 ;j++)
    {
        if (a[i-j] == '(')
        {
            if (a[i+j+1] != ')')
            {
                return false;
            }
        }
        if (a[i-j] == '[')
        {
            if (a[i+j+1] != ']')
            {
                return false;
            }
        }
         if (a[i-j] == '{')
        {
            if (a[i+j+1] != '}')
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int t;
    while(cin>>t)
    {
        char a[t];
        for (int i = 0;i < t;i++)
        cin>>a[i];
        if (t % 2 != 0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int count = 0,count1,count2;
        bool fal = true;
        while (count < t)
        {
            count1 = 0;
            count2 = count;
            for (int i = count;i < t;i++)
            {
                if (i == count2 && (a[i] == ')' || a[i] == ']' || a[i] == '}'))
                {
                    fal = false;

                    break;
                }
                if (a[i] == '(' || a[i] == '[' || a[i] == '{')
                {
                    count++;
                    count1++;
                }
                else if (a[i] == ')' || a[i] == ']' || a[i] == '}')
                {

                    break;
                }
            }
            if (fal == false)
                break;
            if (!isRe(count,a,count1))
            {

                break;
            }
            count += count1;
        }
        if (fal)
        {
            if (isRe(count,a,count1))
            {

                cout<<"YES"<<endl;
            }
            else
            cout<<"NO"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
}
