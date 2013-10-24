#include <iostream>
using namespace std;
int index = -1;
bool isRe(int count,char a[],int count1)
{
    int i = count - 1;
    for (int j = 0;j < count1 ;j++)
    {
        if (a[i-j] == '(')
        {
            if (a[i+j+1] != ')')
            {
                index = i+j+1;
                return false;
            }
        }
        if (a[i-j] == '[')
        {
            if (a[i+j+1] != ']')
            {
                index = i+j+1;
                return false;
            }
        }
         if (a[i-j] == '{')
        {
            if (a[i+j+1] != '}')
            {
                index = i+j+1;
                return false;
            }
        }
    }
    return true;
}
bool isRE(int t,int count,char a[])
{
    int count1 = 0,count2;
    bool fal = true,fal1 = true;

    while (count < t)
    {
        count1 = 0;
        count2 = count;
        for (int i = count2 ;i < t;i++)
        {
            if (i == count2 && (a[i] == ')' || a[i] == ']' || a[i] == '}'))
            {
                return false;
            }
            if (a[i] == '(' || a[i] == '[' || a[i] == '{')
            {
                count++;
                count1++;
            }
            else if (a[i] == ')' || a[i] == ']' || a[i] == '}')
            {
                if(!isRe(count,a,count1))
                {
                    if (index == count)
                    {
                        return false;
                    }
                    else
                    {
                        isRE(t,count,a);
                    }

                }

                else if (count+count1== t)
                return true;

            }
        }
        count += count1;

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
        int count = 0;
        if (isRE(t,count,a))
        {
            cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;

    }


}
