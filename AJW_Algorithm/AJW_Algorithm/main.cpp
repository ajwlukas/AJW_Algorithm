#include "pch.h"

//230309
void 사칙연산();
void 곱셈();
void 알람시계();
void 더하기사이클();

//230310
void 평균은넘겠지();
void 셀프넘버();
void 단어공부();
void 크로아티아알파벳();

#include <iostream>
#include "Timer\timer.h"

using namespace std;

int main()
{
	ajwCommon::Time::Create();

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true)
	{
		system("cls");

		ajwCommon::Time::Get()->StartCheckTime("Algo");

		///1일차
		//사칙연산();
		//곱셈();
		//알람시계();
		//더하기사이클();

		///2일차
		//평균은넘겠지();
		셀프넘버();
		//단어공부();
		//크로아티아알파벳();

		cout << "\n\n";

		cout << ajwCommon::Time::Get()->EndCheckTime("Algo") * 1000 << "ms\n";
		cout << ajwCommon::Time::Get()->EndCheckTime("Algo")  << "초\n";
		system("pause");
	}

	ajwCommon::Time::Delete();
	return 0;
}
