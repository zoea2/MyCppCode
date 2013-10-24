#include<iostream>
using namespace std;
int main()
{
    int row,col;
    cin>>row>>col;
    if ((col-1+(row-1)*col)%2==0)
    cout<<"[second]=:]";
    else
    cout<<"[:=[first]";
}
