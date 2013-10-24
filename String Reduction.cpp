#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string s1,s2,s3;
    while(t)
    {
        t--;

        cin>>s1>>s2>>s3;
        while(s1.find(s2) != -1)
        {

            int index = s1.find(s2);

            s1.replace(index,s2.length(),s3);
        }
        cout<<s1<<endl;
    }
}
