#include <iostream>
using namespace std;


int main()
{
    int t;
    cin>>t;
    int n;
    unsigned int num;

    while(t--)
    {
        int count = 0;
        cin>>n>>num;
        for(int i = 1;i * (i+1)<2 * num;i++ )
        {
            if ((num-i*(i+1)/2) % (i+1) == 0)
            count++;
        }
        cout<<n<<" "<<count<<endl;
    }
}
