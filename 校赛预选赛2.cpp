#include <iostream>
#include <stdio.h>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, x[50], y[50], color[50], f = 1;
        double area = 0;
        scanf("%d", &n);
        multimap<int, int> r;
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d %d %d", &x[i], &y[i], &temp);
            r.insert(std::pair<int, int>(temp, i));
        }
        multimap<int, int>::iterator it = r.end();
        it--;
        area += it->first * it->first * 3.141592653589793;
        color[it->second] = 1;                              //1 = black, 0 = white
        if (it != r.begin())
        {
            it--;
            f = 0;
        }
        for (; it != r.begin(); it--)
        {
            int cr = it->first, i = it->second, flag = 1;
            multimap<int, int>::iterator it1 = r.end();
            it1--;
            for (; it1 != it; it1--)
            {
                if ((x[i] - x[it1->second]) * (x[i] - x[it1->second]) + (y[i] - y[it1->second]) * (y[i] - y[it1->second]) < (it->first + it1->first) * (it->first + it1->first))
                {
                    if (color[it1->second] == 1)
                    {
                        area -= it->first * it->first * 3.141592653589793;
                        color[i] = 0;
                        flag = 0;
                        break;
                    }
                    else
                    {
                        area += it->first * it->first * 3.141592653589793;
                        color[i] = 1;
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag)
            {
                area += it->first * it->first *3.141592653589793;
                color[it->second] = 1;
            }
        }

        if (!f)
        {
            int cr = it->first, i = it->second, flag = 1;
            multimap<int, int>::iterator it1 = r.end();
            it1--;
            for (; it1 != it; it1--)
            {
                if ((x[i] - x[it1->second]) * (x[i] - x[it1->second]) + (y[i] - y[it1->second]) * (y[i] - y[it1->second]) < (it->first + it1->first) * (it->first + it1->first))
                {
                    if (color[it1->second] == 1)
                    {
                        area -= it->first * it->first * 3.141592653589793;
                        color[i] = 0;
                        flag = 0;
                        break;
                    }
                    else
                    {
                        area += it->first * it->first * 3.141592653589793;
                        color[i] = 1;
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag)
            {
                area += it->first * it->first * 3.141592653589793;
                color[it->second] = 1;
            }
        }

        cout << fixed << setprecision(3);
        cout << area << endl;
    }

    //system("pause");
    return 0;
}
