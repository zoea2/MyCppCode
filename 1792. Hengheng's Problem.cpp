#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string begin[100];
    string end[100];
    int time[24][60];
    int bhour , bminute ,ehour ,eminute;
    while(n != 0)
    {
        for (int i = 0;i < 24;i++)
        {
            for (int j = 0;j < 60;j++)
                time[i][j] = 0;
        }
        for (int i = 0;i < n;i++)
            cin>>begin[i]>>end[i];

        char temp;
        for(int t = 0;t < n;t++)
        {
            bhour = 0;
            bminute = 0;
            ehour = 0;
            eminute = 0;
            for (int i = 0;i < 2;i++)
            {
                temp = begin[t][i];
                bhour = bhour * 10 + (temp - '0');
            }
            for (int i = 3;i < 5;i++)
            {
                temp = begin[t][i];
                bminute = bminute * 10 + (temp - '0');
            }
            for (int i = 0;i < 2;i++)
            {
                temp = end[t][i];
                ehour = ehour * 10 + (temp - '0');
            }
            for (int i = 3;i < 5;i++)
            {
                temp = end[t][i];
                eminute = eminute * 10 + (temp - '0');
            }
            for (int i = bhour;i <= ehour;i++)
            {
                if (i == bhour && i == ehour)
                {
                    for (int j = bminute;j < eminute;j++)
                    time[i][j] = 1;

                }
                else if (i == bhour && i != ehour)
                {
                    for (int j = bminute;j < 60;j++)
                    time[i][j] = 1;

                }
                else if(i == ehour)
                {
                    for (int j = 0;j < eminute ;j++)
                    time[i][j] = 1;
                }
                else
                {
                    for(int j = 0;j < 60;j++)
                    time[i][j] = 1;
                }
            }

        }
        int count = 0;
        int max = 0,maxbh = 0,maxeh = 0,maxbm = 0,maxem = 0;
        int a[100],b[100],c[100],d[100],count1 = 0;
        for (int i = 0;i < 24;i++)
        {
            for (int j = 0;j < 60;j++)
            {

                if (time[i][j] == 0)
                {
                    if (j == 0 && i == 0)
                    {
                            a[count1] = 0;
                            b[count1] = 0;
                            count++;
                    }
                    else if (j == 0 && i != 0)
                    {
                        if(time[i-1][59] == 1)
                        {
                            a[count1] = i;
                            b[count1] = j;
                            count++;
                        }
                    }
                    else if(time[i][j-1] == 1)
                    {
                            a[count1] = i;
                            b[count1] = j;
                            count++;
                    }
                    else if (i == 23 && j == 59)
                    {
                        if (max < count)
                        {
                            max = count;
                            maxbh = a[count1];
                            maxbm = b[count1];
                            maxeh = i;
                            maxem = j;
                        }
                        count1++;
                    }
                    else
                    count++;
                }
                else if (time[i][j] == 1 )
                {
                    if (j == 0 && i != 0)
                    {
                        if(time[i-1][59] == 0)
                        {
                            c[count1] = i;
                            d[count1] = j;

                            if (max < count)
                            {
                                max = count;
                                maxbh = a[count1];
                                maxbm = b[count1];
                                maxeh = c[count1];
                                maxem = d[count1];
                            }
                            count1++;
                            count = 0;
                        }
                    }
                    else if(time[i][j-1] == 0)
                    {
                            c[count1] = i;
                            d[count1] = j;

                            if (max < count)
                            {
                                max = count;
                                maxbh = a[count1];
                                maxbm = b[count1];
                                maxeh = c[count1];
                                maxem = d[count1];
                            }
                            count1++;
                            count = 0;
                    }


                }

            }
        }


        if (max == 0)
        printf("Poor Hengheng\n");
        else
        printf("%02d:%02d %02d:%02d\n",maxbh,maxbm,maxeh,maxem);
        cin>>n;
    }
}
