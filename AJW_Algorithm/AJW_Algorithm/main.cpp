#include "pch.h"

//Day1
void 사칙연산();
void 곱셈();
void 알람시계();
void 더하기사이클();

//Day2
void 평균은넘겠지();
void 셀프넘버();
void 단어공부();
void 크로아티아알파벳();

//Day3
void 달팽이는올라가고싶다();
void ACM호텔();
void 소수구하기();

//Day4
void 하노이탑이동순서();
void 좌표정렬하기2();
void 나무자르기();

//Day5
void 균형잡힌세상();
void 스택수열();
void 회전하는큐();

//Day6
void 바이러스();
void 토마토();
void 피보나치함수();
void 가장긴증가하는부분수열();
void 가장긴증가하는부분수열심화();

void 그룹단어체커();
void 설탕배달();
void FlymetotheAlphaCentauri();
void 베르트랑공준();
void 영화감독숌();
void 신나는함수실행();
void 파도반수열();
void RGB거리();
void 정수삼각형();
void 동전0();
void ATM();
void 약수();
void 최대공약수와최소공배수();
void 최소공배수();
void 이항계수1();
void 다리놓기();
void 스택();
void 제로();
void 괄호();
void 큐2();
void DFS와BFS();
void 통계학();
void 색종이만들기();
void N과M2();
void NQueen();
void 계단오르기();
void 터렛();
void 블랙잭();
void 분해합();
void 잃어버린괄호();
void 요세푸스문제0();
void 쿼드트리();
void 가장긴바이토닉부분수열();
void 단지번호붙이기();
void 최단경로();



#include <iostream>
#include "Timer\timer.h"

using namespace std;

int main()
{
	ajwCommon::Time::Create();

	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	while (true)
	{
		system("cls");

		ajwCommon::Time::Get()->StartCheckTime("Algo");//입력시간을 생각 못함;

		///1일차
		//사칙연산();
		//곱셈();
		//알람시계();
		//더하기사이클();

		///2일차
		//평균은넘겠지();
		//셀프넘버();
		//단어공부();
		//크로아티아알파벳();

		//3일차
		//달팽이는올라가고싶다();
		//ACM호텔();
		//소수구하기();

		//4일차
		//하노이탑이동순서();
		//좌표정렬하기2();
		//나무자르기();

		//5일차
		//균형잡힌세상();
		//스택수열();
		//회전하는큐();

		//6일차
		//바이러스();
		//토마토();
		//피보나치함수();
		//가장긴증가하는부분수열();
		//가장긴증가하는부분수열심화();

		/// 2주차

		그룹단어체커();
		//설탕배달();
		//FlymetotheAlphaCentauri();
		//베르트랑공준();
		//영화감독숌();
		//신나는함수실행();
		//파도반수열();
		//RGB거리();
		//정수삼각형();
		//동전0();
		//ATM();
		//약수();
		//최대공약수와최소공배수();
		//최소공배수();
		//이항계수1();
		//다리놓기();
		//스택();
		//제로();
		//괄호();
		//큐2();
		//DFS와BFS();
		//통계학();
		//색종이만들기();
		//N과M2();
		//NQueen();
		//계단오르기();
		//터렛();
		//블랙잭();
		//분해합();
		//잃어버린괄호();
		//요세푸스문제0();
		//쿼드트리();
		//가장긴바이토닉부분수열();
		//단지번호붙이기();
		//최단경로();

		cout << "\n\n";

		cout << ajwCommon::Time::Get()->EndCheckTime("Algo") * 1000 << "ms\n";
		cout << ajwCommon::Time::Get()->EndCheckTime("Algo") << "초\n";
		system("pause");
	}

	ajwCommon::Time::Delete();
	return 0;
}
