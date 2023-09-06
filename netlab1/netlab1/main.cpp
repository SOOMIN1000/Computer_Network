/*
 * 파일명 : "netlab1"
 * 프로그램의 목적 및 기본 기능 :
 * 		-간단하게 TCP 소켓을 생성 후 해당 소켓을 닫고 종료하는 연습
 *
 * 		프로그램 작성자 : 천수민 (2023년 9월 7일)
 * 		최종 Update : 2023년 9월 7일
 *
 * =================================================================================
 * 프로그램 수정/보완 이력
 * =================================================================================
 * 프로그램 수정/보완작업자		일자			수정/보완내용
 * 천수민						2023/09/07		소켓 생성,닫기 종료 기능 완성
 * */
#pragma comment(lib,"ws2_32.lib")
#include<WinSock2.h>
#include <stdio.h>
#include <WS2tcpip.h> //inet_pton 을 사용하기 위한 헤더

int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) //Winsock 초기화 및
	{
		printf("Error in starting up Winsock\n");
		return -1;//오류에 의한 종료
	}

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0); //내부적으로 사용하는 디스크립터 

	SOCKADDR_IN myAddress; //이름을 담아주기 위함
	ZeroMemory(&myAddress, sizeof(myAddress)); //0으로 한번 깔끔하게 초기화
	myAddress.sin_family = AF_INET; //무조건 AF_INET을 사용
	myAddress.sin_port = 50000; //PORT번호 
	inet_pton(AF_INET, "165.229.86.69", &(myAddress.sin_addr.s_addr)); //sin_addr이 ip주소, inet_pton함수를 이용하여 ip주소 설정
	//문자열을 숫자로 
	bind(s, (SOCKADDR*)&myAddress, sizeof(myAddress));


	closesocket(s);//socket 닫기

	WSACleanup(); //Winsock 정리

	return 0;
}