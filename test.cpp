#include<stdio.h>
char  *returnStr()
{
           char *p = "tigerjibo";
           return  p;
}
int  main()
{
           char*str;
           str =returnStr();
           char* str5 = new char[15];
           str5[5] = 'w';
           str5[6] = '\0';
           printf("%s\n",str5);
           //str[5] = 's';
   //str[0]=��T��;���������󣬲����޸�ֻ�����ݶ��е�����
           printf("%s\n",str);
           return 0;
}
