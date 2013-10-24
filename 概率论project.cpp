#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <map>
using namespace std;
double str2num(string s)                              //将字符串转换成双精度数值
{
        double num;
        stringstream ss(s);
        ss>>num;
        return num;
}
int main()
{
    ifstream input;
    input.open("mobile_phone_user_network.txt");  //打开存放数据的文件
    double time[600];
    int age[600];
    int career[600];
    char temp0[1000];
    input.getline(temp0,1000);   //把前面的抬头跟两行空行读掉
    input.getline(temp0,1000);
    input.getline(temp0,1000);
    input.get();
    string temp;
    for (int i = 0;i < 600;i++)
    {
        for (int j = 0;j < 4;j++)                 //读掉无效信息
        {
            input.getline(temp0,1000,'\t');       //由于每个数据之间用制表符隔开，因此我设定读到制表符停止，若没有信息，这个地方也有制表符，它也会停止，此时会读入一个空字符串
        }
        input.getline(temp0,1000,'\t');
        temp = temp0;
        if (isdigit(temp[0]))
        {
            age[i] = str2num(temp);      //将读入的字符串数据如果是数字，则转成字符型数据，此时的数据是该用户的年龄
                    }
        input.getline(temp0,1000,'\t');
        input.getline(temp0,1000,'\t');
        temp = temp0;
        if (isdigit(temp[0]))
        {
            career[i] = str2num(temp);   //将读入的字符串数据如果是数字，则转成字符型数据，此时的数据是该用户的职业类型
        }
        for (int j = 0;j < 17;j++)
        {
            input.getline(temp0,1000,'\t');

        }
        input.getline(temp0,1000);
        temp = temp0;
        time[i] = str2num(temp);     //将读入的字符串数据转成字符型数据，因为上网时长这一栏都有数据，则不用判断是否为空，此时的数据是该用户的上网时长
        time[i] *= 60;               //将上网时长转化为以秒为单位
        time[i] = int (time[i]);     //取整
    }
    input.close();
    ofstream output1,output2,output3;
    output1.open("probability_onlinetime.txt");
    output2.open("probability_for_under45yearsold.txt");
    output3.open("probability_for_teacher.txt");
    for (int i = 0;i < 600;i++)
    {
        output1<<time[i]<<endl;      //这个文件输入所有用户的上网时长
        if (age[i] <= 45&&age[i]!=0)
        output2<<time[i]<<endl;   //这个文件输入年龄低于45岁的用户的上网时长
        if(career[i]==56)
        output3<<time[i]<<endl;    //这个文件输入职业为教师的用户的上网时长
    }
    output1.close();
    output2.close();
    output3.close();
}
