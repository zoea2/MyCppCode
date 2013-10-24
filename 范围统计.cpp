#include <iostream>
#include <set>
#include <map>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, q, temp;
        scanf("%d", &n);
        set<int> number;
        int number1[100001];
        map<int, int> range1, range2;
        map<int, int>::iterator it;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            if (range2.find(temp) == range2.end())
                range2[temp] = 1;
            else
                range2[temp]++;
            number.insert(temp);
            number1[i] = temp;
        }
        sort(number1, number1 + n);
        for (int i = 0; i < n; i++)
        {
            range1[number1[i]] = i + 1;
        }
        scanf("%d", &q);
        int a, b, sum;
        while(q--)
        {
            int a1 = 0, b1 = 0;
            sum = 0;
            scanf("%d %d", &a, &b);
            if (number.count(a) == 1)
                a1 = 1;
            if (number.count(b) == 1)
                b1 = 1;
            if (a1 == 1 && a == b)
            {
                printf("%d\n", range2[a]);
                continue;
            }
            if (a1 == 0 && a == b)
            {
                printf("0\n");
                continue;
            }
            number.insert(a);
            number.insert(b);
            if (++number.find(a) == number.find(b) && a1 == 0 && b1 == 0)
            {
                printf("0\n");
                number.erase(a);
                number.erase(b);
                continue;
            }
            if (a1 == 0)
            {
                range1[a] = range1[*(++number.find(a))];
                range2[a] = range2[*(++number.find(a))];
            }
            if (b1 == 0)
            {
                range1[b] = range1[*(--number.find(b))];
                range2[b] = range2[*(--number.find(b))];
            }
            sum = range1[b] - range1[a] + range2[a];
            printf("%d\n", sum);
            if (a1 == 0)
                number.erase(a);
            if (b1 == 0)
                number.erase(b);
        }
    }

    return 0;
}
