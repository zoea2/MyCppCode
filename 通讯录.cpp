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
        name = "��";
        telnum = "��";
        address = "��";
        email = "��";
    }
};
void loading(vector<persons>& p)
{
    fstream inout;
    inout.open("��ϵ��.bat",ios::in | ios::binary);
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
    cout<<"��������ϵ�˵�����"<<endl;
    inout.open("��ϵ��.bat",ios::out|ios::binary|ios::app);
    persons somebody;
    cin>>somebody.name;
    inout << somebody.name  << " ";
    cout<<"���������ϵ�˵ĵ绰����,����Ҫ�������д\"��\""<<endl;
    cin>>somebody.telnum;
    inout << somebody.telnum << " ";
    cout<<"���������ϵ�˵�ͨ�ŵ�ַ������Ҫ�������д\"��\""<<endl;

    cin>>somebody.address;
    inout << somebody.address << " ";

    cout<<"���������ϵ�˵ĵ��������ַ������Ҫ�������д\"��\""<<endl;

    cin>>somebody.email;
    inout << somebody.email << endl;
    inout.close();
    p.push_back(somebody);
    cout<<"��ӳɹ���"<<endl;
    return;
}

void addi(vector<persons>& p)
{
    cout<<"��������Ҫ�����Ϣ����ϵ��"<<endl;
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
        cout<<"���޴��ˣ�"<<endl;
        return;
    }
    cout<<"��������Ҫ�����Ϣ����Ϣ����"<<endl;
    cout<<"1.�绰����"<<endl<<"2.ͨ�ŵ�ַ"<<endl<<"3.���������ַ"<<endl;
    int tempi;
    cin>>tempi;
    if (tempi == 1)
    {
        if (p[i].telnum != "��")
        {
            cout<<"����Ϣ�Ѵ��ڣ������޸ģ���ʹ���޸Ĺ���"<<endl;
            return;
        }

    }
     if (tempi == 2)
    {
        if (p[i].address != "��")
        {
            cout<<"����Ϣ�Ѵ��ڣ������޸ģ���ʹ���޸Ĺ���"<<endl;
            return;
        }

    }
    if (tempi == 3)
    {
        if (p[i].email != "��")
        {
            cout<<"����Ϣ�Ѵ��ڣ������޸ģ���ʹ���޸Ĺ���"<<endl;
            return;
        }

    }
    cout<<"��������Ҫ��ӵ���Ϣ����"<<endl;
    string tempc;
    cin>>tempc;
    fstream inout;
    switch(tempi)
    {
        case 1:
                inout.open("��ϵ��.bat",ios::binary|ios::out);
                p[i].telnum = tempc;
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"��ӳɹ���"<<endl;
                return;
        case 2:
                inout.open("��ϵ��.bat",ios::binary|ios::out);
                p[i].address = tempc;
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"��ӳɹ���"<<endl;
                return;
        case 3:
                inout.open("��ϵ��.bat",ios::binary|ios::out);
                p[i].email = tempc;
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"��ӳɹ���"<<endl;
                return;

    }


}
void modify(vector<persons>& p)
{
    cout<<"��������Ҫ�޸���Ϣ����ϵ��"<<endl;
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
        cout<<"���޴��ˣ�"<<endl;
        return;
    }
    cout<<left;
    cout<<setw(10)<<"����"<<setw(15)<<"�绰����"<<setw(20)<<"ͨ�ŵ�ַ"<<"���������ַ"<<endl;
    cout<<setw(10)<<p[i].name<<setw(15)<<p[i].telnum<<setw(20)<<p[i].address<<p[i].email<<endl;
    cout<<"��������Ҫ�޸���Ϣ����Ϣ����"<<endl;
    cout<<"1.�绰����"<<endl<<"2.ͨ�ŵ�ַ"<<endl<<"3.���������ַ"<<endl;
    int tempi;
    cin>>tempi;
    cout<<"��������Ҫ�޸ĺ����Ϣ����"<<endl;
    string tempc;
    cin>>tempc;
    fstream inout;
    switch(tempi)
    {
        case 1:
                inout.open("��ϵ��.bat",ios::binary|ios::out);
                p[i].telnum = tempc;
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"�޸ĳɹ���"<<endl;
                return;
        case 2:
                inout.open("��ϵ��.bat",ios::binary|ios::out);
                p[i].address = tempc;
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"�޸ĳɹ���"<<endl;
                return;
        case 3:
                inout.open("��ϵ��.bat",ios::binary|ios::out);
                p[i].email = tempc;
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"�޸ĳɹ���"<<endl;
                return;

    }

}
void print(vector<persons>& p)
{
    cout<<left;
    cout<<setw(10)<<"����"<<setw(15)<<"�绰����"<<setw(20)<<"ͨ�ŵ�ַ"<<"���������ַ"<<endl;
    for(int i = 0;i < p.size();i++)
    cout<<setw(10)<<p[i].name<<setw(15)<<p[i].telnum<<setw(20)<<p[i].address<<p[i].email<<endl;
}
void clear(vector<persons>& p)
{
    fstream inout;
    inout.open("��ϵ��.bat",ios::binary|ios::out);
    inout.close();
    p.clear();
    cout<<"ɾ���ɹ�!"<<endl;
}
void search(vector<persons>& p)
{
    cout<<"��������Ҫ���ҵ���ϵ������"<<endl;
    string tempname;
    cin>>tempname;
    for (int i = 0;i < p.size();i++)
    {
        if(p[i].name == tempname)
        {
                cout<<left;
                cout<<setw(10)<<"����"<<setw(15)<<"�绰����"<<setw(20)<<"ͨ�ŵ�ַ"<<"���������ַ"<<endl;
                cout<<setw(10)<<p[i].name<<setw(15)<<p[i].telnum<<setw(20)<<p[i].address<<p[i].email<<endl;
                return;
        }
    }
    cout<<"���޴��ˣ�"<<endl;
    return;

}
void delp(vector<persons>& p)
{
    cout<<"��������Ҫɾ������ϵ������"<<endl;
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
           cout<<"���޴��ˣ�"<<endl;
           return;
       }
    for ( ; i < p.size() - 1;i++)
        p[i] = p[i+1];
    fstream inout;
    inout.open("��ϵ��.bat",ios::binary|ios::out);
    for (int j = 0;j < p.size() - 1 ; j++)
        inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
    inout.close();
    p.pop_back();
    cout<<"ɾ���ɹ���"<<endl;
    return;

}
void deli(vector<persons>& p)
{
    cout<<"��������Ҫɾ����Ϣ����ϵ������"<<endl;
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
           cout<<"���޴��ˣ�"<<endl;
           return;
       }
    cout << "��������Ҫɾ������Ϣ" << endl << "1.�绰����" << endl << "2.ͨ�ŵ�ַ" << endl << "3.���������ַ" << endl;
    int tempi;
    cin>>tempi;
    fstream inout;
    switch(tempi)
    {
        case 1:
                inout.open("��ϵ��.bat",ios::binary|ios::out);
                p[i].telnum = "��";
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"ɾ������Ϣ�ɹ���"<<endl;
                return;
        case 2:
                inout.open("��ϵ��.bat",ios::binary|ios::out);
                p[i].address = "��";
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"ɾ������Ϣ�ɹ���"<<endl;
                return;
        case 3:
                inout.open("��ϵ��.bat",ios::binary|ios::out);
                p[i].email = "��";
                for (int j = 0;j < p.size() ; j++)
                inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
                inout.close();
                cout<<"ɾ������Ϣ�ɹ���"<<endl;
                return;

    }


    return;

}
void beifen(vector<persons>& p)
{
    cout<<"ȷ�ϱ��ݵ�ǰͨѶ¼��"<<endl<<"1.ȷ��"<<endl<<"2.����"<<endl;
    int n;
    cin>>n;
    if (n == 2)
        return;
    fstream inout;
    inout.open("��ϵ��2.bat",ios::out|ios::binary);
    for (int j = 0;j < p.size() ; j++)
        inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
    inout.close();
    cout<<"���ݳɹ���"<<endl;
}

void daoru(vector<persons>& p)
{
    cout<<"ȷ�ϵ��뱸��ͨѶ¼��"<<endl<<"1.ȷ��"<<endl<<"2.����"<<endl;
    int n;
    cin>>n;
    if (n == 2)
        return;
    p.clear();
    fstream inout;
    inout.open("��ϵ��2.bat",ios::in | ios::binary);
    persons temp;
    while (!inout.eof())

    {
        inout >> temp.name >> temp.telnum >> temp.address >> temp.email;
        p.push_back(temp);
    }
    p.pop_back();
    inout.close();
    inout.open("��ϵ��.bat",ios::out|ios::binary);
    for (int j = 0;j < p.size() ; j++)
        inout << p[j].name << " " << p[j].telnum << " " << p[j].address << " "<< p[j].email << endl;
    inout.close();
    cout<<"����ɹ���"<<endl;
}
void menu()
{
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t   ��������Ҫʹ�õĹ��ܶ�Ӧ������"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  1.�����ϵ��"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  2.�����Ϣ"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  3.�޸���Ϣ"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  4.����������ϵ����Ϣ"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  5.��ʾ������ϵ����Ϣ"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  6.ɾ��������ϵ��"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  7.ɾ��������ϵ��"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  8.ɾ��������ϵ����Ϣ"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  9.���ݸ�ͨѶ¼"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  10.���뱸��ͨѶ¼"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  11.�˳�ͨѶ¼"<<endl;
}
int main()
{
    vector<persons> p;
    loading(p);
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t   ��������Ҫʹ�õĹ��ܶ�Ӧ������"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  1.�����ϵ��"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  2.�����Ϣ"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  3.�޸���Ϣ"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  4.����������ϵ����Ϣ"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  5.��ʾ������ϵ����Ϣ"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  6.ɾ��������ϵ��"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  7.ɾ��������ϵ��"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  8.ɾ��������ϵ����Ϣ"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  9.���ݸ�ͨѶ¼"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  10.���뱸��ͨѶ¼"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t  11.�˳�ͨѶ¼"<<endl;
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

