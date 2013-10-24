#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
    string s;
    multimap<string,int> m;
    for (int i = 0;i < 6;i++)
    {
        cin>>s;
        m.insert(pair<string,int>(s,1));
    }
    multimap<string,int>::iterator it1 = m.begin();
    multimap<string,int>::iterator it2 = m.begin();
    multimap<string,int>::iterator it3 = m.begin();
    string temp[3];
    multiset<string> ms;
    bool flag = false;
    for (it1 = m.begin() ;it1 != m.end();it1++)
    {

        for (it2 = m.begin();it2!= m.end();it2++)
        {

            for (it3 = m.begin();it3!=m.end();it3++)
            {
                if(it1 == it2 || it2 == it3 || it1 == it3)
                    continue;
                it1->second--;
                it2->second--;
                it3->second--;
                //temp.clear();
                for (int i = 0;i < 3;i++)
                {
                    temp[i].clear();
                }
                int i = 0;
                for (;i < 3;i++)
                {
                    temp[i].append(1,(*it1).first[i]);
                    temp[i].append(1,(*it2).first[i]);
                    temp[i].append(1,(*it3).first[i]);
                    if(m.count(temp[i]) > 0)
                    {
                        pair <multimap<string,int>::iterator, multimap<string,int>::iterator> ret;
                        ret = m.equal_range(temp[i]);
                        for (multimap<string,int>::iterator it = ret.first;it != ret.second;it++)
                        {
                            if(it->second > 0)
                            {
                                flag = true;
                                it->second--;
                                break;
                            }
                        }
                        if(flag == false)
                        {
                            temp[i].clear();
                            break;
                        }
                        flag = false;
                    }
                    else
                    break;
                }
                if(i == 3)
                {
                    //flag = true;
                    ms.insert(it1->first);
                    ms.insert(it2->first);
                    ms.insert(it3->first);
                    for(multiset<string>::iterator i = ms.begin();i != ms.end();i++)
                        cout<<(*i)<<endl;
                    return 0;
                }
                for (i = 0;i < 3;i++)
                {
                    if (!temp[i].empty())
                    {
                        multimap<string,int>::iterator it = m.find(temp[i]);
                        if(it != m.end())
                            it->second++;
                    }
                }
                it3->second++;
                it2->second++;
                it1->second++;
            }

        }

    }
    cout<<"0"<<endl;
}
