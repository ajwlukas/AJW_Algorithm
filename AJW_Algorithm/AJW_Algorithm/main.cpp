#include "pch.h"

//230309
void ��Ģ����();
void ����();
void �˶��ð�();
void ���ϱ����Ŭ();

//230310
void ������Ѱ���();
void �����ѹ�();
void �ܾ����();
void ũ�ξ�Ƽ�ƾ��ĺ�();

void �����̴¿ö󰡰�ʹ�();
void ACMȣ��();
void �Ҽ����ϱ�();

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

		ajwCommon::Time::Get()->StartCheckTime("Algo");//�Է½ð��� ���� ����;

		///1����
		//��Ģ����();
		//����();
		//�˶��ð�();
		//���ϱ����Ŭ();

		///2����
		//������Ѱ���();
		//�����ѹ�();
		//�ܾ����();
		//ũ�ξ�Ƽ�ƾ��ĺ�();

		//3����
		//�����̴¿ö󰡰�ʹ�();
		//ACMȣ��();
		�Ҽ����ϱ�();

		cout << "\n\n";

		cout << ajwCommon::Time::Get()->EndCheckTime("Algo") * 1000 << "ms\n";
		cout << ajwCommon::Time::Get()->EndCheckTime("Algo")  << "��\n";
		system("pause");
	}

	ajwCommon::Time::Delete();
	return 0;
}
