#include <iostream>
using namespace std;
int main()
{
    int num;
    cin>>num;
    double rabbit[200][2];
    for (int i = 0;i < num;i++)
    cin>>rabbit[i][0]>>rabbit[i][1];
    int count = 0;
    int max = 2;
    for (int i = 0;i < num;i++)
    {
        for (int j = 0;j < num;j++)
        {
            if (i != j)
            {
                if (rabbit[i][0] == rabbit[j][0])
                {
                    for (int k = 0;k < num;k++)
                    {
                        if (rabbit[k][0] == rabbit[i][0])
                        count++;
                    }
                }
                else if(rabbit[i][1] == rabbit[j][1])
                {
                    for (int k = 0;k < num;k++)
                    {
                        if (rabbit[k][1] == rabbit[i][1])
                        count++;
                    }
                }
                else
                {
                    for (int k = 0;k < num;k++)
                    {
                        if ((rabbit[k][1]-rabbit[i][1]) / (rabbit[j][1]-rabbit[i][1]) * 1.0 == 1.0 *(rabbit[k][0]-rabbit[i][0]) / (rabbit[j][0]-rabbit[i][0]))
                        count++;
                    }
                }

            }
        if (max < count)
            max = count;
        count = 0;
        }

    }
    cout<<max;
}
