#include <Winsock2.h>
#pragma comment(lib,”ws2_32.lib”);
int main(){
WORD wVersionRequested;
WSADATA wsaData;
wVersionRequested=MAKEWORD(2,2);
if(WSAStartup(wVersionRequested,&wsaData)!=0)
{
		//Winsock初始化错误
		return 0;
}
if(wsaData.wVersion!=wVersionRequested)
{
		//Winsock版本不匹配
		WSACleanup();
		return 0;
}
//说明WinsockDLL正确加载，可以执行以下代码

}
