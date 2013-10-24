#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;


struct T
{
    //s为开始时间，t为结束时间
    int s,t;
};

bool cmp(const T &a, const T &b)
{
    if ( a.s==b.s)
        return a.t<b.t;
    else
        return  a.s<b.s;
}

int main()
{

    vector<T> ti;
    ti.resize(105);

    int t,n,current,tail;
    t=0;
    int h1,h2,m1,m2;
    T ans;

    while( scanf("%d", &n), n!=0 )
    {
        for (int i=0;i<n; ++i)
        {

            scanf("%d:%d%d:%d", &h1, &m1, &h2, &m2);
            ti[i].s=h1*60+m1;
            ti[i].t=h2*60+m2;

        }

       //先对时间段排序
        sort(ti.begin(), ti.begin()+n,cmp);

       //从前开始扫描
        current=0;  //当前找到的最大连续空闲时间段
        ans.s=0;       //ans记录已找到的时间段
        ans.t=0;
        tail=0;    //记录已扫描的时间段的最大结束时间
        for (int i=0;i<n; ++i )
        {

            if (ti[i].s>tail)//时间段出现空隙
            {
                if (current< ti[i].s-tail)
                {
                    ans.s=tail;
                    ans.t=ti[i].s;
                    current=ti[i].s-tail;
                }
                tail=ti[i].t;
            }
            else if( tail<ti[i].t )
            {
                tail=ti[i].t;
            }

        }

    //处理最后的边缘情况
        if (current<(1439-tail))
        {
            ans.s=tail;
            ans.t=1439;
        }

        //打印答案
        if (ans.t-ans.s==0)
            printf("Poor Hengheng\n");
        else
        {
            printf("%02d:%02d ",ans.s/60, ans.s%60);

            printf("%02d:%02d\n",ans.t/60, ans.t%60);
        }

    }

    return 0;
}
