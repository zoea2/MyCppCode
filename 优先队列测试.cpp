#include <queue>
#include <iostream>
using namespace std;
class edge
{
    public:
    int source;
    int end;
    int weight;
    edge()
    {

    }
    edge(int a,int b,int c)
    {
        source = a;
        end = b;
        weight = c;
    }

};
class cmp
{
    public:
    bool operator() (const edge& a,const edge& b)   const
    {
        return a.weight > b.weight;
    }
};
int main()
{
    edge e[4];
    e[0].weight = 2;
    e[1].weight = 1;
    e[3].weight = 100;
    e[2].weight = 20;
    priority_queue< edge, vector<edge>,cmp >first(e,e+4);
    while(!first.empty())
    {
        edge temp = first.top();
        first.pop();
        cout<<temp.weight<<endl;
    }

}
