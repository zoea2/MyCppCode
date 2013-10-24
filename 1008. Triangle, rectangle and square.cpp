#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char graph[100][100];
int visit[101][101]={0};
int dic[16] = {0,-1,0,1,1,0,-1,0,1,-1,1,1,-1,-1,-1,1};
int main()
{
        int m,n;
        cin>>m>>n;
        while(m != 0 || n != 0)
        {
                //cout<<m<<n<<endl;
                memset(graph,0,sizeof(graph));
                memset(visit,0,sizeof(visit));
                bool is = false;
                for (int i = 0;i < m;i++)
                {
                    for (int j = 0;j < n;j++)
                    cin>>graph[i][j];
                }
                int countt = 0,countr = 0,counts = 0;
                //cout<<"fuck"<<endl;
                int tempi,tempj;
                for (int i = 0;i < m;i++)
                {
                        for (int j = 0;j < n;j++)
                        {
                                //cout<<graph[i][j]<<endl;
                                int a,b,c,d,count = 0;
                                is = false;
                                if (graph[i][j] == '1'&&visit[i][j]==0)
                                {



                                        tempi = i;tempj = j;
                                        //cout<<tempi<<"i"<<" "<<tempj<<"j"<<endl;
                                        visit[tempi][tempj] = 1;
                                        int tempd;
                                        for (int k = 0; k < 16;k += 2)
                                        {
                                                if (tempi + dic[k] >= 0 && tempj + dic[k+1] >= 0 && tempi + dic[k] < m&&tempj + dic[k+1] < n&&graph[tempi + dic[k]][tempj + dic[k+1]] == '1'&&visit[i + dic[k]][j + dic[k+1]] == 0)
                                                {

                                                                tempd = k;
                                                                int countn = 1;
                                                                //visit[tempi + dic[k]][tempj + dic[k+1]] = 1;
                                                                while(tempi + dic[tempd] >= 0 && tempj + dic[tempd+1] >= 0 && tempi + dic[tempd] < m&&tempj + dic[tempd+1] < n&&graph[tempi + dic[tempd]][tempj + dic[tempd+1]] == '1'&&visit[tempi + dic[tempd]][tempj + dic[tempd+1]] == 0)
                                                                {

                                                                        tempi = tempi + dic[tempd];
                                                                        tempj = tempj + dic[tempd+1];
                                                                        countn++;
                                                                        visit[tempi][tempj] = 1;
                                                                        //cout<<tempi<<"tempi"<<" "<<tempj<<"tempj"<<endl;
                                                                }
                                                                a = countn;
                                                                count++;
                                                                break;


                                                }
                                        }
                                        //cout<<"done1"<<endl;
                                        if (graph[tempi][tempj] == '1')
                                        {
                                        int tempd;
                                        visit[tempi][tempj] = 1;
                                        //cout<<"12"<<endl;
                                        for (int k = 0; k < 16;k += 2)
                                        {
                                                if (tempi + dic[k] >= 0 && tempj + dic[k+1] >= 0 && tempi + dic[k] <m&&tempj + dic[k+1] < n)
                                                {
                                                        if (graph[tempi + dic[k]][tempj + dic[k+1]] == '1'&&visit[tempi + dic[k]][tempj + dic[k+1]] == 0)
                                                        {
                                                                tempd = k;
                                                                int countn = 1;
                                                                //visit[i + dic[k]][j + dic[k+1]] = 1;
                                                                while(tempi + dic[tempd] >= 0 && tempj + dic[tempd+1] >= 0 && tempi + dic[tempd] < m&&tempj + dic[tempd+1] < n&&graph[tempi + dic[tempd]][tempj + dic[tempd+1]] == '1'&&visit[tempi + dic[tempd]][tempj + dic[tempd+1]] == 0)
                                                                {

                                                                        tempi = tempi + dic[tempd];
                                                                        tempj = tempj + dic[tempd+1];
                                                                        countn++;
                                                                        visit[tempi][tempj] = 1;
                                                                        //cout<<tempi<<"tempi"<<" "<<tempj<<"tempj"<<endl;

                                                                }
                                                                b = countn;
                                                                count++;
                                                                break;
                                                        }
                                                }
                                        }


                                }
                                //cout<<"done2"<<endl;
                                if (graph[tempi][tempj] == '1')
                                {
                                        int tempd;
                                        visit[tempi][tempj] = 1;
                                        for (int k = 0; k < 16;k += 2)
                                        {
                                                if (tempi + dic[k] >= 0 && tempj + dic[k+1] >= 0 && tempi + dic[k] < m&&tempj + dic[k+1] < n)
                                                {
                                                        if (graph[tempi + dic[k]][tempj + dic[k+1]] == '1'&&visit[tempi + dic[k]][tempj + dic[k+1]] == 0)
                                                        {
                                                                tempd = k;
                                                                //tempi = i;tempj = j;
                                                                int countn = 1;
                                                                //visit[i + dic[k]][j + dic[k+1]] = 1;
                                                                while(tempi + dic[tempd] >= 0 && tempj + dic[tempd+1] >= 0 && tempi + dic[tempd] < m&&tempj + dic[tempd+1] < n&&graph[tempi + dic[tempd]][tempj + dic[tempd+1]] == '1'&&visit[tempi + dic[tempd]][tempj + dic[tempd+1]] == 0)
                                                                {

                                                                        tempi = tempi + dic[tempd];
                                                                        tempj = tempj + dic[tempd+1];
                                                                        countn++;
                                                                        visit[tempi][tempj] = 1;
                                                                        //cout<<tempi<<"tempi"<<" "<<tempj<<"tempj"<<endl;
                                                                }
                                                                c = countn;
                                                                count++;
                                                                if (tempi + dic[tempd] == i && tempj + dic[tempd+1] == j)
                                                                is = true;
                                                                break;
                                                        }
                                                }
                                        }


                                }
                                //cout<<"done3"<<endl;
                                if (!is)
                                {
                                    if (graph[tempi][tempj] == '1')
                                {
                                        count++;
                                        int tempd;
                                        visit[tempi][tempj] = 1;
                                        for (int k = 0; k < 16;k += 2)
                                        {
                                                if (tempi + dic[k] >= 0 && tempj + dic[k+1] >= 0 && tempi + dic[k] < m&&tempj + dic[k+1] < n)
                                                {
                                                        if (graph[tempi + dic[k]][tempj + dic[k+1]] == '1'&&visit[tempi + dic[k]][tempj + dic[k+1]] == 0)
                                                        {
                                                                tempd = k;
                                                                //tempi = i;tempj = j;
                                                                int countn = 1;
                                                                //visit[i + dic[k]][j + dic[k+1]] = 1;
                                                                while(tempi + dic[tempd] >= 0 && tempj + dic[tempd+1] >= 0 && tempi + dic[tempd] < m&&tempj + dic[tempd+1] < n&&graph[tempi + dic[tempd]][tempj + dic[tempd+1]] == '1'&&visit[tempi + dic[tempd]][tempj + dic[tempd+1]] == 0)
                                                                {

                                                                        tempi = tempi + dic[tempd];
                                                                        tempj = tempj + dic[tempd+1];
                                                                        countn++;
                                                                        visit[tempi][tempj] = 1;
                                                                        //cout<<tempi<<"tempi"<<" "<<tempj<<"tempj"<<endl;

                                                                }
                                                                d = countn;


                                                                break;
                                                        }
                                                }
                                        }


                                }
                                //cout<<"done4"<<endl;
                                }

                                }



                                if (count == 3)
                                countt++;
                                else if (count == 4)
                                {
                                    if (b == c)
                                    counts++;
                                    else
                                    countr++;
                                }

                        //cout<<i<<" "<<j<<endl;
                        }
                }
                cout<<"Triangle: "<<countt<<", Rectangle: "<<countr<<", Square: "<<counts<<endl;
                scanf("%d%d",&m,&n);
        }
}
