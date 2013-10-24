#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
struct card
{
   bool up;
   int num;
};
deque<card> crow;
int main()
{
    int n,q,count = 0;
    scanf("%d",&n);
    while(n != 0)
    {
        count++;
        char t;
        stack<card> left;
        stack<card> right;
        crow.clear();
        getchar();
        for(int i = 1;i <= n;i++)
        {
            scanf("%c",&t);
            //cout<<t<<endl;
            card temp0;
            temp0.num = i;
            if(t == 'U')
            temp0.up = true;
            else if (t == 'D')
            temp0.up = false;
            crow.push_back(temp0);
        }
        card temp0 = crow.front();
        crow.pop_front();
        left.push(temp0);
        temp0 = crow.back();
        crow.pop_back();
        right.push(temp0);
        getchar();
        for(int i = 1;i < n-1;i++)
        {
            scanf("%c",&t);
            //cout<<t<<endl;
            if(t == 'R')
            {
                temp0 = crow.back();
                crow.pop_back();
                stack<card> temp;
                temp.push(temp0);
                while(!right.empty())
                {
                    temp0 = right.top();
                    if(temp0.up)
                        temp0.up = false;
                    else
                        temp0.up = true;
                    temp.push(temp0);
                    right.pop();
                }
                right = temp;
            }
            else if(t == 'L')
            {
                temp0 = crow.front();
                crow.pop_front();
                stack<card> temp;
                temp.push(temp0);
                while(!left.empty())
                {
                    temp0 = left.top();
                    if(temp0.up)
                        temp0.up = false;
                    else
                        temp0.up = true;
                    temp.push(temp0);
                    left.pop();
                }
                left = temp;
            }
        }
        scanf("%c",&t);
        //cout<<t<<endl;
        vector<card>res;
        if(t == 'R')
        {
            stack<card> temp;
            while(!right.empty())
            {
                temp0 = right.top();
                if(temp0.up)
                    temp0.up = false;
                else
                    temp0.up = true;
                temp.push(temp0);
                right.pop();
            }
            while(!temp.empty())
            {
                temp0 = temp.top();
                res.push_back(temp0);
                temp.pop();
            }
            while(!left.empty())
            {
                temp0 = left.top();
                res.push_back(temp0);
                left.pop();
            }
        }
        else if(t == 'L')
        {
            stack<card> temp;
            while(!left.empty())
            {
                temp0 = left.top();
                if(temp0.up)
                    temp0.up = false;
                else
                    temp0.up = true;
                temp.push(temp0);
                left.pop();
            }
            while(!temp.empty())
            {
                temp0 = temp.top();
                res.push_back(temp0);
                temp.pop();
            }
            while(!right.empty())
            {
                temp0 = right.top();
                res.push_back(temp0);
                right.pop();
            }
        }
        scanf("%d",&q);
        int text;
        printf("Pile %d\n",count);
        while(q--)
        {
            scanf("%d",&text);
            if(res[text-1].up)
            printf("Card %d is a face up %d.\n",text,res[text-1].num);
            else
            printf("Card %d is a face down %d.\n",text,res[text-1].num);
        }
        scanf("%d",&n);

    }
}

