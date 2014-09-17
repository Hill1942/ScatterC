// Socket1.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<winsock.h>
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
#define WSWENS MAKEWORD(2,0)
int _tmain(int argc, _TCHAR* argv[])
{
	sockaddr_in sin;
	WSADATA wsadata;
	//WSAStartup()的调用方和Windows Sockets DLL互相通知对方它们可以支持的最高版本,
	//并且互相确认对方的最高版本是可接受的. 在WSAStartup()函数的入口,
	//Windows Sockets DLL检查了应用程序所需的版本.如果版本高于DLL支持的最低版本,
	//则调用成功并且DLL在wHighVersion中返回它所支持的最高版本,
	//在 wVersion中返回它的高版本和wVersionRequested中的较小者.
	//然后Windows Sockets DLL就会假设应用程序将使用wVersion.
	if(WSAStartup(WSWENS,&wsadata)!=0)
	
		cout<<"startup failed"<<endl;
	
	SOCKET s = socket(PF_INET,SOCK_STREAM,0);
	// memset 是对一段内存空间全部设置为某个字符
	memset(&sin,0,sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(80);
	//sin.sin_addr.S_un.S_addr=inet_addr("203.208.37.99");
	hostent* hptr = gethostbyname("www.google.cn");
	// 将有参数的string内容copy到左边参数
	memcpy(&sin.sin_addr.S_un.S_addr,hptr->h_addr,hptr->h_length);
	printf("IP address:%d.%d.%d.%d/n",sin.sin_addr.S_un.S_un_b.s_b1,
		sin.sin_addr.S_un.S_un_b.s_b2,
		sin.sin_addr.S_un.S_un_b.s_b3,
		sin.sin_addr.S_un.S_un_b.s_b4);
	// 将sockaddr_in transfer to sockaddr
	if(connect(s,(sockaddr*)&sin,sizeof(sin)))
	{
		cout<<"connect failed"<<endl;
		return 0;
	}
	else
	{
		cout<<"connect success"<<endl;
	}
	char buffersend[]="GET/HTTP1.1/nHOST:www.google.cn/nconnection:close/n/n";
	send(s,buffersend,strlen(buffersend),0);
	/*string ss;
	int len = recv(s,const_cast<char*>(ss.c_str()),2000,0);*/
	char bufferecv[10240];
	int len=recv(s,bufferecv,10240,0);
	printf("the length of page is %d/n", len);
	if(len==-1)
	{
		cout<<"receive failed"<<endl;
		return -1;
	}
	else 
		cout<<"receive success"<<endl;
	for (int i = 0; i < len; i++)
		printf("%c",bufferecv[i]);
	WSACleanup();
	closesocket(s);
	return 0;
} 