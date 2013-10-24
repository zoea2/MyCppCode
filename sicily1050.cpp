#include <iostream>
#include <set>
#include <map>
using namespace std;
int time;
void dfs(int num,int end,set<int> colour,int number[],set<int> use,map<int,int>time1,map<int,int> father,int max,bool ha)
{
    colour.insert(num);
    time++;
    time1[num] = time;
    if (num == end)
    {
        ha = 1;
        return;
    }
    for (int i = 0;i < 5;i++)
    {
        if (use.find(number[i]) == use.end())
        {
            if(colour.find(num + number[i]) == colour.end())
            {
                use.insert(number[i]);
                father[num + number[i]] = num;
                if (max < num + number[i] && num + number[i] < end)
                max = num + number[i];
                dfs(num + number[i],end,colour,number,use,time1,father,max,ha);
                use.erase(number[i]);
            }
            if(colour.find(num - number[i]) == colour.end())
            {
                use.insert(number[i]);
                father[num - number[i]] = num;
                if (max < num - number[i] && num - number[i] < end)
                max = num - number[i];
                dfs(num - number[i],end,colour,number,use,time1,father,max,ha);
                use.erase(number[i]);
            }
            if(colour.find(num * number[i]) == colour.end())
            {
                use.insert(number[i]);
                father[num * number[i]] = num;
                if (max < num * number[i] && num * number[i] < end)
                max = num * number[i];
                dfs(num * number[i],end,colour,number,use,time1,father,max,ha);
                use.erase(number[i]);
            }
            if(colour.find(num % number[i] == 0 && num / number[i]) == colour.end())
            {
                use.insert(number[i]);
                father[num / number[i]] = num;
                if (max < num / number[i] && num / number[i] < end)
                max = num / number[i];
                dfs(num / number[i],end,colour,number,use,time1,father,max,ha);
                use.erase(number[i]);
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t)
    {
        t--;
        set<int> colour;
        set<int> use;
        map<int,int> father;
        map<int,int>time1;
        map<int,int>time2;
        int num[5],end;
        int max;
        bool ha = 0;
        for (int i = 0;i < 5;i++)
        {
            cin>>num[i];
        }
        cin>>end;
        time = 0;
        max = num[0];
        for (int i = 0;i < 5;i++)
        {
            if (colour.find(num[i]) == colour.end())
                dfs(num[i],end,colour,num,use,time1,father,max,ha);
        }
        if (ha)
        cout<<end<<endl;
        else
        cout<<max<<endl;
    }
}
