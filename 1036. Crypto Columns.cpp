#include <iostream>
using namespace std;
char result[10][10];
int minindex[10];
int main()
{
    string key,message;
    for (;;)
    {
        cin>>key;
        if (key == "THEEND")
            return 0;
        cin>>message;
        int col = key.length();
        int row = message.length() / col;
        for (int i = 0;i < col;i++)
        {
            char min = key[0];
            minindex[i] = 0;
            for (int j = 1;j < col;j++)
            {
                if (min > key[j])
                {
                    minindex[i] = j;
                    min = key[j];
                }
            }
            key[minindex[i]] = 'a';
        }
        int count = 0;
        for (int i = 0;i < col;i++)
        {
            for (int j = 0;j < row;j++)
            {
                result[j][minindex[i]] = message[count];
                count ++;
            }
        }
        for (int i = 0;i < row;i++)
        {
            for (int j = 0;j < col;j++)
            {
                cout<<result[i][j];
            }
        }
        cout<<endl;
    }
}
