    #include <cstring>
    #include <cstdio>
    #include <algorithm>
    #include <cmath>
    #include <utility>
    #include <vector>

    using namespace std;

    struct sprinker
    {
        int pos;
        int radius;
    };
    sprinker s[10001];
    int res;
    bool cmp(pair<double,double> a,pair<double,double> b)
    {
        if(a.first != b.first )
            return a.first < b.first;
        else
            return (a.second - a.first > b.second - b.first);
    }
    int calc(int l,int w,int n)
    {
        res = 0;
        vector<pair<double,double> > vec;

        for(int i = 0;i < n;i++)
        {
            double r = sqrt(pow(s[i].radius,2) - pow((w*1.0/2),2));
            //printf("pow %lf\n",pow((w*1.0/2),2));
            double left = (double)(s[i].pos * 1.0 - r);
            double right = (double)(s[i].pos * 1.0 + r);
            if(left < -0.000000001)
                left = 0;
            if (right > l)
                right = l;
            vec.push_back(make_pair(left,right));
        }

        sort(vec.begin(),vec.end(),cmp);

        pair<double,double> cur = make_pair(0,0);
        int i = 0;
        double maxs = 0;
        int index;
        while(i <= n)
        {

            if(i == n)
            {
                if(maxs == 0)
                    return -1;
                else
                {
                    cur.second = vec[index].second;
                    maxs = 0;
                    res++;
                }
                if(cur.second == l)
                {
                    return res;
                }
            }
            if(cur.second < vec[i].second && cur.second >= vec[i].first && maxs < vec[i].second)
            {
                index = i;
                maxs = vec[i].second;
                i++;

            }
            else if(cur.second < vec[i].first)
            {
                if(maxs == 0)
                    return -1;
                else
                {
                    cur.second = vec[index].second;
                    maxs = 0;
                    res++;
                    if(cur.second == l)
                    {
                        return res;
                    }
                }
            }
            else
                i++;
        }
        return -1;

    }
    int main()
    {
        int n,l,w;
        while(scanf("%d",&n) != EOF)
        {
            scanf("%d%d",&l,&w);
            memset(s,0,sizeof(s));
            for(int i = 0;i < n;i++)
                scanf("%d%d",&s[i].pos,&s[i].radius);
            if(calc(l,w,n) == -1)
                printf("-1\n");
            else
                printf("%d\n",res);

        }
    }
