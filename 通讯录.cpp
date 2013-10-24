#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;
class persons
{
    public:
    string name;
    string telnum;
    string address;
    string email;
    persons()
    {
        name = "无";
        telnum = "无";
        address = "无";
        email = "无";
    }
};
void loading(vector<persons>& p)
{
    fstream inout;
    inout.open("联系人.bat",ios::in | ios::binary);
    persons temp;
    cout<<"\n\n\n\n\n\n\n\n\n"<<setw(37)<<"loading";
    for (int j = 0; j < 6;j++)
    {
        for (int i = 0;i < 50000000;i++)
        {
            ;
        }
        cout << ".";

    }
    while (!inout.eof())

    {
        inout >> temp.name >> temp.telnum >> temp.address >> temp.email;
        p.push_back(temp);
    }
    p.pop_back();
    cout<<endl<<setw(39)<<"complete!";
    for (int i = 0;i < 200000000;i++)
        {
            ;
        }
    cout<<endl<<setw(49)<<"Please press enter.";
    char a[100];
    cin.getline(a,100);
    system("cls");

}
void person(vector<persons>& p)
{

    fstream inout;
    cout<<"请输入联系人的姓名"<<endl;
    inout.open("联系人.bat",ios::out|ios::binary|ios::app);
    persons somebody;
    cin>>somebody.name;
    inout << somebody.name  << " ";
    cout<<"请输入该联系人的电话号码,不需要添加则填写\"无\""<<endl;
    cin>>somebody.telnum;
    inout << somebody.telnum << " ";
    cout<<"请输入该联系人的通信地址，不需要添加则填写\"无\""<<endl;

    cin>>somebody.address;
    inout << somebody.address << " ";

    cout<<"请输入该联系人的电子邮箱地址，不需要添加则填写\"无\""<<endl;

    cin>>somebody.email;
    inout << somebody.email << endl;
    inout.close();
    p.push_back(somebody);
    cout<<"添加成功！"<<endl;
    return;
}

void addi(vector<persons>& p)
{
    cout<<"请输入你要添加信息的联系人"<<endl;
    string tempname;
    cin>>tempname;
    int i = 0;
    for (;i < p.size();i++)
    {
        if(p[i].name == tempname)
        {
                 break;
        }
    }
    if (i == p.size())
    {
        cout<<"查无此人！"<<endl;
        return;
    }
    cout<<"请输入你要添加信息的信息类型"<<endl;
    cout<<"1.电话号码"<<endl<<"2.通信地址"<<endl<<"3.电子邮箱地址"<<endl;
    int tempi;
    cin>>tempi;
    if (tempi == 1)
    {
        if (p[i].telnum != "无")
        {
            cout<<"此信息已存在，若想修改，请使用修改功能"<<endl;
            return;
        }

    }
     if (tempi == 2)
    {
        if (p[i].address != "无")
        {
            cout<<"此信息已存在，若想修改，请使用修改功能"<<endl;
            return;
        }

    }
    if (tempi == 3)
    {
        if (p[i].email != "无")
        {
            cout<<"此信息已存在，若想修改，请使用修改功能"<<endl;
            return;
        }

    }
    cout<<"请输入你要添加的信息内容"<<endl;
    string tempc;
    cin>>tempc;
    fstream inout;
    switch(tempi)
    {
        case 1:
                inout.open("联系人.bat",ios::binary|ios::out);
                p[i].telnum = tempc;
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"添加成功！"<<endl;
                return;
        case 2:
                inout.open("联系人.bat",ios::binary|ios::out);
                p[i].address = tempc;
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"添加成功！"<<endl;
                return;
        case 3:
                inout.open("联系人.bat",ios::binary|ios::out);
                p[i].email = tempc;
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"添加成功！"<<endl;
                return;

    }


}
void modify(vector<persons>& p)
{
    cout<<"请输入你要修改信息的联系人"<<endl;
    string tempname;
    cin>>tempname;
    int i = 0;
    for (;i < p.size();i++)
    {
        if(p[i].name == tempname)
        {
                 break;
        }
    }
    if (i == p.size())
    {
        cout<<"查无此人！"<<endl;
        return;
    }
    cout<<left;
    cout<<setw(10)<<"姓名"<<setw(15)<<"电话号码"<<setw(20)<<"通信地址"<<"电子邮箱地址"<<endl;
    cout<<setw(10)<<p[i].name<<setw(15)<<p[i].telnum<<setw(20)<<p[i].address<<p[i].email<<endl;
    cout<<"请输入你要修改信息的信息类型"<<endl;
    cout<<"1.电话号码"<<endl<<"2.通信地址"<<endl<<"3.电子邮箱地址"<<endl;
    int tempi;
    cin>>tempi;
    cout<<"请输入你要修改后的信息内容"<<endl;
    string tempc;
    cin>>tempc;
    fstream inout;
    switch(tempi)
    {
        case 1:
                inout.open("联系人.bat",ios::binary|ios::out);
                p[i].telnum = tempc;
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"修改成功！"<<endl;
                return;
        case 2:
                inout.open("联系人.bat",ios::binary|ios::out);
                p[i].address = tempc;
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"修改成功！"<<endl;
                return;
        case 3:
                inout.open("联系人.bat",ios::binary|ios::out);
                p[i].email = tempc;
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"修改成功！"<<endl;
                return;

    }

}
void print(vector<persons>& p)
{
    cout<<left;
    cout<<setw(10)<<"姓名"<<setw(15)<<"电话号码"<<setw(20)<<"通信地址"<<"电子邮箱地址"<<endl;
    for(int i = 0;i < p.size();i++)
    cout<<setw(10)<<p[i].name<<setw(15)<<p[i].telnum<<setw(20)<<p[i].address<<p[i].email<<endl;
}
void clear(vector<persons>& p)
{
    fstream inout;
    inout.open("联系人.bat",ios::binary|ios::out);
    inout.close();
    p.clear();
    cout<<"删除成功!"<<endl;
}
void search(vector<persons>& p)
{
    cout<<"请输入你要查找的联系人姓名"<<endl;
    string tempname;
    cin>>tempname;
    for (int i = 0;i < p.size();i++)
    {
        if(p[i].name == tempname)
        {
                cout<<left;
                cout<<setw(10)<<"姓名"<<setw(15)<<"电话号码"<<setw(20)<<"通信地址"<<"电子邮箱地址"<<endl;
                cout<<setw(10)<<p[i].name<<setw(15)<<p[i].telnum<<setw(20)<<p[i].address<<p[i].email<<endl;
                return;
        }
    }
    cout<<"查无此人！"<<endl;
    return;

}
void delp(vector<persons>& p)
{
    cout<<"请输入你要删除的联系人姓名"<<endl;
    string tempname;
    cin>>tempname;
    int i = 0;
    for ( ; i < p.size();i++)
    {
        if (p[i].name == tempname)
            break;
    }

    if (i == p.size())
       {
           cout<<"查无此人！"<<endl;
           return;
       }
    for ( ; i < p.size() - 1;i++)
        p[i] = p[i+1];
    fstream inout;
    inout.open("联系人.bat",ios::binary|ios::out);
    for (int j = 0;j < p.size() - 1 ; j++)
        inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
    inout.close();
    p.pop_back();
    cout<<"删除成功！"<<endl;
    return;

}
void deli(vector<persons>& p)
{
    cout<<"请输入你要删除信息的联系人姓名"<<endl;
    string tempname;
    cin>>tempname;
    int i = 0;
    for ( ; i < p.size();i++)
    {
        if (p[i].name == tempname)
            break;
    }

    if (i == p.size())
       {
           cout<<"查无此人！"<<endl;
           return;
       }
    cout << "请输入你要删除的信息" << endl << "1.电话号码" << endl << "2.通信地址" << endl << "3.电子邮箱地址" << endl;
    int tempi;
    cin>>tempi;
    fstream inout;
    switch(tempi)
    {
        case 1:
                inout.open("联系人.bat",ios::binary|ios::out);
                p[i].telnum = "无";
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"删除该信息成功！"<<endl;
                return;
        case 2:
                inout.open("联系人.bat",ios::binary|ios::out);
                p[i].address = "无";
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"删除该信息成功！"<<endl;
                return;
        case 3:
                inout.open("联系人.bat",ios::binary|ios::out);
                p[i].email = "无";
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"删除该信息成功！"<<endl;
                return;

    }


    return;

}
void beifen(vector<persons>& p)
{
    cout<<"确认备份当前通讯录？"<<endl<<"1.确定"<<endl<<"2.返回"<<endl;
    int n;
    cin>>n;
    if (n == 2)
        return;
    fstream inout;
    inout.open("联系人2.bat",ios::out|ios::binary);
    for (int j = 0;j < p.size() ; j++)
        inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
    inout.close();
    cout<<"备份成功！"<<endl;
}

void daoru(vector<persons>& p)
{
    cout<<"确认导入备份通讯录？"<<endl<<"1.确定"<<endl<<"2.返回"<<endl;
    int n;
    cin>>n;
    if (n == 2)
        return;
    p.clear();
    fstream inout;
    inout.open("联系人2.bat",ios::in | ios::binary);
    persons temp;
    while (!inout.eof())

    {
        inout >> temp.name >> temp.telnum >> temp.address >> temp.email;
        p.push_back(temp);
    }
    p.pop_back();
    inout.close();
    inout.open("联系人.bat",ios::out|ios::binary);
    for (int j = 0;j < p.size() ; j++)
        inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
    inout.close();
    cout<<"导入成功！"<<endl;
}
void menu()
{
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t   请输入你要使用的功能对应的数字"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  1.添加联系人"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  2.添加信息"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  3.修改信息"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  4.查找已有联系人信息"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  5.显示所有联系人信息"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  6.删除所有联系人"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  7.删除给定联系人"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  8.删除给定联系人信息"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  9.备份该通讯录"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  10.导入备份通讯录"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  11.退出通讯录"<<endl;
}
int main()
{
    vector<persons> p;
    loading(p);
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t   请输入你要使用的功能对应的数字"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  1.添加联系人"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  2.添加信息"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  3.修改信息"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  4.查找已有联系人信息"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  5.显示所有联系人信息"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  6.删除所有联系人"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  7.删除给定联系人"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  8.删除给定联系人信息"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  9.备份该通讯录"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  10.导入备份通讯录"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  11.退出通讯录"<<endl;
    int order;

    while (cin>>order)
    {
        system("cls");
        menu();
        switch (order)
        {
        case 1:     person(p);
                    break;

        case 2:     addi(p);
                    break;

        case 3:     modify(p);
                    break;

        case 4:     search(p);
                    break;

        case 5:     print(p);
                    break;

        case 6:     clear(p);
                    break;

        case 7:     delp(p);
                    break;

        case 8:     deli(p);
                    break;

        case 9:     beifen(p);
                    break;

        case 10:    daoru(p);
                    break;

        case 11:    return 0;

        }
    }
}

