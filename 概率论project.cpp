#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <map>
using namespace std;
double str2num(string s)                              //���ַ���ת����˫������ֵ
{
        double num;
        stringstream ss(s);
        ss>>num;
        return num;
}
int main()
{
    ifstream input;
    input.open("mobile_phone_user_network.txt");  //�򿪴�����ݵ��ļ�
    double time[600];
    int age[600];
    int career[600];
    char temp0[1000];
    input.getline(temp0,1000);   //��ǰ���̧ͷ�����п��ж���
    input.getline(temp0,1000);
    input.getline(temp0,1000);
    input.get();
    string temp;
    for (int i = 0;i < 600;i++)
    {
        for (int j = 0;j < 4;j++)                 //������Ч��Ϣ
        {
            input.getline(temp0,1000,'\t');       //����ÿ������֮�����Ʊ��������������趨�����Ʊ��ֹͣ����û����Ϣ������ط�Ҳ���Ʊ������Ҳ��ֹͣ����ʱ�����һ�����ַ���
        }
        input.getline(temp0,1000,'\t');
        temp = temp0;
        if (isdigit(temp[0]))
        {
            age[i] = str2num(temp);      //��������ַ���������������֣���ת���ַ������ݣ���ʱ�������Ǹ��û�������
                    }
        input.getline(temp0,1000,'\t');
        input.getline(temp0,1000,'\t');
        temp = temp0;
        if (isdigit(temp[0]))
        {
            career[i] = str2num(temp);   //��������ַ���������������֣���ת���ַ������ݣ���ʱ�������Ǹ��û���ְҵ����
        }
        for (int j = 0;j < 17;j++)
        {
            input.getline(temp0,1000,'\t');

        }
        input.getline(temp0,1000);
        temp = temp0;
        time[i] = str2num(temp);     //��������ַ�������ת���ַ������ݣ���Ϊ����ʱ����һ���������ݣ������ж��Ƿ�Ϊ�գ���ʱ�������Ǹ��û�������ʱ��
        time[i] *= 60;               //������ʱ��ת��Ϊ����Ϊ��λ
        time[i] = int (time[i]);     //ȡ��
    }
    input.close();
    ofstream output1,output2,output3;
    output1.open("probability_onlinetime.txt");
    output2.open("probability_for_under45yearsold.txt");
    output3.open("probability_for_teacher.txt");
    for (int i = 0;i < 600;i++)
    {
        output1<<time[i]<<endl;      //����ļ����������û�������ʱ��
        if (age[i] <= 45&&age[i]!=0)
        output2<<time[i]<<endl;   //����ļ������������45����û�������ʱ��
        if(career[i]==56)
        output3<<time[i]<<endl;    //����ļ�����ְҵΪ��ʦ���û�������ʱ��
    }
    output1.close();
    output2.close();
    output3.close();
}
