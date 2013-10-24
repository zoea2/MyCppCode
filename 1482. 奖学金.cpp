#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct student
{
    int snum;
    int sall;
    int schinese;
    int smath;
    int senglish;
};
bool cmp(student a,student b)
{
    if(a.sall != b.sall)
        return a.sall > b.sall;
    else
    {
        if(a.schinese != b.schinese)
            return a.schinese > b.schinese;
        else
            return a.snum < b.snum;
    }
}
int main()
{
    int n;
    cin>>n;
    while(1)
    {
        student stu[10000];
        for(int i = 0;i < n;i++)
        {
            cin >> stu[i].schinese >> stu[i].smath >> stu[i].senglish;
            stu[i].sall = stu[i].schinese + stu[i].smath + stu[i].senglish;
            stu[i].snum = i+1;
        }
        sort(stu,stu + n,cmp);
        for(int i = 0;i < 5;i++)
            cout << stu[i].snum << " " << stu[i].sall << endl;
        if(cin>>n)
            cout << endl ;
        else break;
    }
    return 0;
}
