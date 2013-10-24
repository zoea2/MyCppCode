#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int par[3000];
    for (int i = 0;i < n;i++)
    cin>>par[i];
    int left[70000] = {0};
    int right[70000]={0};
    int father[70000]={0};
    right[par[n-1]] = par[n-2];
    father[par[n-2]] = par[n-1];
    int l;
    for (int i = 0;i < n;i++)
    {
        if (par[i] < par[n-1] && par[i+1]>par[n-1])
        {
            l = i;
            break;
        }
    }
    left[par[n-1]] = par[l];
    father[par[l]] = par[n-1];
    for (int i = l - 1;i >=0;i++)
    {
        int temp = left[par[n-1]];
        while(right[temp]!=0 || left[temp]!=0)
        {
            if (par[i] > temp && right[temp] == 0)
            {
                temp = right[temp];
                continue;
            }
            else if (par[i] < temp&&left[temp]!=0)
            {
                temp = left[temp];
                continue;
            }
            if (par[i] > temp && right[temp] == 0)
            {
                right[temp] = par[i];
                father[par[i]] = temp;
                break;
            }
            if (par[i] < temp && left[temp] == 0)
            {
            left[temp] = par[i];
            father[par[i]] = temp;
            break;
            }

        }
        if (par[i] > temp && right[temp] == 0)
        {
            right[temp] = par[i];
            father[par[i]] = temp;
            break;
        }
        if (par[i] < temp && left[temp] == 0)
        {
            left[temp] = par[i];
            father[par[i]] = temp;
            break;
        }
    }
    for (int i = 0;i < n;i++)
    {
        if (par[i] < par[n-1] && par[i+1]>par[n-1])
        {
            l = i;
            break;
        }
    }
    left[par[n-1]] = par[l];
    father[par[l]] = par[n-1];
    for (int i = n-2;i > l;i++)
    {
        int temp = right[par[n-1]];
        while(right[temp]!=0 || left[temp]!=0)
        {
            if (par[i] > temp && right[temp] == 0)
            {
                temp = right[temp];
                continue;

            }
            else if (par[i] < temp&&left[temp]!=0)
            {
                temp = left[temp];
                continue;
            }
            if (par[i] > temp && right[temp] == 0)
            {
                right[temp] = par[i];
                father[par[i]] = temp;
                break;
            }
            if (par[i] < temp && left[temp] == 0)
            {
            left[temp] = par[i];
            father[par[i]] = temp;
            break;
            }

        }
        if (par[i] > temp && right[temp] == 0)
        {
            right[temp] = par[i];
            father[par[i]] = temp;
            break;
        }
        if (par[i] < temp && left[temp] == 0)
        {
            left[temp] = par[i];
            father[par[i]] = temp;
            break;
        }
    }
    int temp0 = right[par[n-1]];
    while(right[temp0]!=0 || left[temp0]!=0)
    {
        if (right[temp0]!= 0)
        {
            temp0 = right[temp0];
            continue;
        }
        if (left[temp0] != 0)
        {
            temp0 = left[temp0];
            continue;
        }
    }
    cout<<temp0<<" ";
    while(father[temp0]!= par[n-1])
    {
        if (left[father[temp0]]!=0&&left[father[temp0]]!=temp0)
        {
            while(right[temp0]!=0 || left[temp0]!=0)
            {
                if (right[temp0]!= 0)
                {
                    temp0 = right[temp0];
                    continue;
                }
                if (left[temp0] != 0)
                {
                    temp0 = left[temp0];
                    continue;
                }
            }
            cout<<temp0<<" ";
        }
        else
        {
            cout<<father[temp0]<<" ";
            temp0 = father[temp0];
        }
    }

}
