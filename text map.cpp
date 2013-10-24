#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string,string>map1;
    map1.insert(map<string,string>::value_type("sdfs", "John Smith"));
     map1.insert(map<string, string>::value_type("101", "Peter King"));
    map1.insert(map<string, string>::value_type("102", "Jane Smith"));
    map1.insert(map<string, string>::value_type("103", "Jeff Reed"));
    map1["sdf"]="sdfsdfsd";
    cout<< "Initial contents in map1:\n";
    map<string,string>::iterator p;
    for (p = map1.begin(); p != map1.end(); p++)
        cout << p->first << " " << p->second << endl;

}
