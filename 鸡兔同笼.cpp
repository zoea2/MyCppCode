#include <iostream>
using namespace std;
int main(){
    int m[100],n[100];
    int a[100],b[100];
    int t = 0;
    for (int i = 0;i < 100; i++)
    {
        cin>>m[i]>>n[i];
        if (m[i] == 0 && n[i] == 0)
        break;
        t++;
        }
    for (int p = 0;p < t;p++)
    {
        int x,y;
        y = n[p]/2 - m[p];
        x = m[p] - y;
        a[p] = x;
        b[p] = y;
        }
    for (int k = 0;k < t;k++)
    if (a[k] < 0 || a[k] != static_cast<int>(a[k]) || b[k] < 0 || b[k] != static_cast<int>(b[k]))
    cout<<"No answer"<<endl;
    else
    cout<<a[k]<<" "<<b[k]<<endl;

    return 0;
}
