#include <Winsock2.h>
#pragma comment(lib,��ws2_32.lib��);
int main(){
WORD wVersionRequested;
WSADATA wsaData;
wVersionRequested=MAKEWORD(2,2);
if(WSAStartup(wVersionRequested,&wsaData)!=0)
{
		//Winsock��ʼ������
		return 0;
}
if(wsaData.wVersion!=wVersionRequested)
{
		//Winsock�汾��ƥ��
		WSACleanup();
		return 0;
}
//˵��WinsockDLL��ȷ���أ�����ִ�����´���

}
