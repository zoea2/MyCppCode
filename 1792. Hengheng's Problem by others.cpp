#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;


struct T
{
    //sΪ��ʼʱ�䣬tΪ����ʱ��
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

       //�ȶ�ʱ�������
        sort(ti.begin(), ti.begin()+n,cmp);

       //��ǰ��ʼɨ��
        current=0;  //��ǰ�ҵ��������������ʱ���
        ans.s=0;       //ans��¼���ҵ���ʱ���
        ans.t=0;
        tail=0;    //��¼��ɨ���ʱ��ε�������ʱ��
        for (int i=0;i<n; ++i )
        {

            if (ti[i].s>tail)//ʱ��γ��ֿ�϶
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

    //�������ı�Ե���
        if (current<(1439-tail))
        {
            ans.s=tail;
            ans.t=1439;
        }

        //��ӡ��
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
