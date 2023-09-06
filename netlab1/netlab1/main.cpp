/*
 * ���ϸ� : "netlab1"
 * ���α׷��� ���� �� �⺻ ��� :
 * 		-�����ϰ� TCP ������ ���� �� �ش� ������ �ݰ� �����ϴ� ����
 *
 * 		���α׷� �ۼ��� : õ���� (2023�� 9�� 7��)
 * 		���� Update : 2023�� 9�� 7��
 *
 * =================================================================================
 * ���α׷� ����/���� �̷�
 * =================================================================================
 * ���α׷� ����/�����۾���		����			����/���ϳ���
 * õ����						2023/09/07		���� ����,�ݱ� ���� ��� �ϼ�
 * */
#pragma comment(lib,"ws2_32.lib")
#include<WinSock2.h>
#include <stdio.h>
#include <WS2tcpip.h> //inet_pton �� ����ϱ� ���� ���

int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) //Winsock �ʱ�ȭ ��
	{
		printf("Error in starting up Winsock\n");
		return -1;//������ ���� ����
	}

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0); //���������� ����ϴ� ��ũ���� 

	SOCKADDR_IN myAddress; //�̸��� ����ֱ� ����
	ZeroMemory(&myAddress, sizeof(myAddress)); //0���� �ѹ� ����ϰ� �ʱ�ȭ
	myAddress.sin_family = AF_INET; //������ AF_INET�� ���
	myAddress.sin_port = 50000; //PORT��ȣ 
	inet_pton(AF_INET, "165.229.86.69", &(myAddress.sin_addr.s_addr)); //sin_addr�� ip�ּ�, inet_pton�Լ��� �̿��Ͽ� ip�ּ� ����
	//���ڿ��� ���ڷ� 
	bind(s, (SOCKADDR*)&myAddress, sizeof(myAddress));


	closesocket(s);//socket �ݱ�

	WSACleanup(); //Winsock ����

	return 0;
}