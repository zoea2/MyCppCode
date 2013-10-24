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
   //str[0]=’T’;则会引起错误，不能修改只读数据段中的内容
           printf("%s\n",str);
           return 0;
}
