#include <iostream>
using namespace std;
int main()
{
    int t,n,a,b;
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        int box[n];
        for (int i = 0;i < n;i++)
            cin>>box[i];
        cin>>a>>b;
        cout<<box[a-1]+box[b-1]<<endl;
    }
}
