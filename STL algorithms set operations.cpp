// Problem#: 6412
// Submission#: 1653156
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Integer
{
public:
    int a;
    bool operator<(const Integer &b) const;

};
bool Integer::operator<(const Integer &b) const
{
        if (this->a > b.a)
        return true;
        else
        return false;
}
bool compare(int c,int b)
{
    return c > b;
}
int main()
{
    Integer arr[5];
    for (int i = 0;i < 5;i++)
    cin>>arr[i].a;
    cout<<(arr[0]<arr[1]);
    sort(arr,arr + 5);
    for (int i = 0;i < 5;i++)
    cout<<arr[i].a<<" ";
    cout<<endl;
    //sort(arr,arr+5,compare);
    for (int i = 0;i < 5;i++)
    cout<<arr[i].a<<" ";
}
