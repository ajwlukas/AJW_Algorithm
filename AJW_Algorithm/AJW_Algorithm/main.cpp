#include "pch.h"

//Day1
void ��Ģ����();
void ����();
void �˶��ð�();
void ���ϱ����Ŭ();

//Day2
void ������Ѱ���();
void �����ѹ�();
void �ܾ����();
void ũ�ξ�Ƽ�ƾ��ĺ�();

//Day3
void �����̴¿ö󰡰�ʹ�();
void ACMȣ��();
void �Ҽ����ϱ�();

//Day4
void �ϳ���ž�̵�����();
void ��ǥ�����ϱ�2();
void �����ڸ���();

//Day5
void ������������();
void ���ü���();
void ȸ���ϴ�ť();

//Day6
void ���̷���();
void �丶��();
void �Ǻ���ġ�Լ�();
void ����������ϴºκм���();

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
		//�Ҽ����ϱ�();

		//4����
		//�ϳ���ž�̵�����();
		//��ǥ�����ϱ�2();
		�����ڸ���();

		//5����
		//������������();
		//���ü���();
		//ȸ���ϴ�ť();

		//6����
		//���̷���();
		//�丶��();
		//�Ǻ���ġ�Լ�();
		//����������ϴºκм���();

		cout << "\n\n";

		cout << ajwCommon::Time::Get()->EndCheckTime("Algo") * 1000 << "ms\n";
		cout << ajwCommon::Time::Get()->EndCheckTime("Algo")  << "��\n";
		system("pause");
	}

	ajwCommon::Time::Delete();
	return 0;
}
