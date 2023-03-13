#include "pch.h"
#include <vector>

using namespace std;

/*
	https://www.acmicpc.net/problem/4344

	Date : 23.03.10

	문제
	대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.

	입력
	첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
	둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

	출력
	각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.

	예제 입력 1
	5
	5 50 50 70 80 100
	7 100 95 90 80 70 60 50
	3 70 90 80
	3 70 90 81
	9 100 99 98 97 96 95 94 93 91
	예제 출력 1
	40.000%
	57.143%
	33.333%
	66.667%
	55.556%
*/

#include <stdio.h>

void 평균은넘겠지()
{
	int C = 0;//num of testCases

	vector<int> N = {};//num of students 1~1000

	vector<vector<int>> scores = {};//0~100
	vector<float> averages = {};
	vector<int> goodStudentNum = {};//num of students who get score above average


	cin >> C;

	N.resize(C);
	scores.resize(C);
	averages.resize(C);
	goodStudentNum.resize(C);

	//입력
	for (int i = 0; i < C; i++)
	{
		cin >> N[i];

		scores[i].resize(N[i]);

		for (int j = 0; j < N[i]; j++)
			cin >> scores[i][j];
	}

	//평균 구하기
	float average = 0.0f;
	for (int i = 0; i < C; i++)//per testCase
	{
		for (int score : scores[i])
			average += score;

		averages[i] = average / (float)N[i];

		average = 0.0f;
	}

	//평균이 넘는지 체크
	for (int i = 0; i < C; i++)//per testCase
	{
		for (int score : scores[i])
		{
			if(score > averages[i])
				goodStudentNum[i]++;
		}
	}

	cout << fixed;
	cout.precision(3);
	//출력
	for (int i = 0; i < C; i++)
	{
		//printf("%.3f%%\n", goodStudentNum[i] / (float)N[i] * 100);
		cout << goodStudentNum[i] / (float)N[i] * 100 << "%\n";

	}
	cout.unsetf(ios::fixed);
}

/*
	https://www.acmicpc.net/problem/4673

	Date : 23.03.10

	문제
	셀프 넘버는 1949년 인도 수학자 D.R. Kaprekar가 이름 붙였다. 양의 정수 n에 대해서 d(n)을 n과 n의 각 자리수를 더하는 함수라고 정의하자. 예를 들어, d(75) = 75+7+5 = 87이다.
	양의 정수 n이 주어졌을 때, 이 수를 시작해서 n, d(n), d(d(n)), d(d(d(n))), ...과 같은 무한 수열을 만들 수 있다.
	예를 들어, 33으로 시작한다면 다음 수는 33 + 3 + 3 = 39이고, 그 다음 수는 39 + 3 + 9 = 51, 다음 수는 51 + 5 + 1 = 57이다. 이런식으로 다음과 같은 수열을 만들 수 있다.
	33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...
	n을 d(n)의 생성자라고 한다. 위의 수열에서 33은 39의 생성자이고, 39는 51의 생성자, 51은 57의 생성자이다. 생성자가 한 개보다 많은 경우도 있다. 예를 들어, 101은 생성자가 2개(91과 100) 있다.
	생성자가 없는 숫자를 셀프 넘버라고 한다. 100보다 작은 셀프 넘버는 총 13개가 있다. 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, 97
	10000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 출력하는 프로그램을 작성하시오.

	입력
	입력은 없다.

	출력
	10,000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 증가하는 순서로 출력한다.

	예제 입력 1
	예제 출력 1
	1
	3
	5
	7
	9
	20
	31
	42
	53
	64
	 |
	 |       <-- a lot more numbers
	 |
	9903
	9914
	9925
	9927
	9938
	9949
	9960
	9971
	9982
	9993
*/

//#include <unordered_map>
#include <map>
#include <string>

void 셀프넘버()
{
	map<int, int> numbers;//creature, numofCreators;

	for (int i = 0; i <= 10000; i++)
	{
		numbers[i] = 0;
	}

	for (int i = 0; i <= 10000; i++)
	{
		int creature = i;

		string numstring = to_string(i);

		for (char a : numstring)
		{
			int num = a - '0';
			creature += num;
		}

		numbers[creature]++;
	}

	for (auto number : numbers)
	{
		if (number.second == 0)
			cout << number.first << "\n";
	}
}
/*
	https://www.acmicpc.net/problem/1157

	Date : 23.03.10

	문제
	알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

	입력
	첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

	출력
	첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

	예제 입력 1
	Mississipi
	예제 출력 1
	?
	예제 입력 2
	zZa
	예제 출력 2
	Z
	예제 입력 3
	z
	예제 출력 3
	Z
	예제 입력 4
	baaa
	예제 출력 4
	A
*/

void 단어공부()
{
	map<char, int> alphabetCounts;//alpahbet, count

	string str = "";

	cin >> str;

	for (char c : str)
	{
		alphabetCounts[toupper(c)]++;
	}

	char max = '?';
	int maxCount = 0;

	for (auto alphabetCount : alphabetCounts)
	{
		if (alphabetCount.second > maxCount)
		{
			max = alphabetCount.first;
			maxCount = alphabetCount.second;
		}
		else if (alphabetCount.second == maxCount)
		{
			max = '?';
		}
	}

	cout << max;
}
/*
	https://www.acmicpc.net/problem/2941

	Date : 23.03.10

	문제
	예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 따라서, 다음과 같이 크로아티아 알파벳을 변경해서 입력했다.

	크로아티아 알파벳	변경
	č	c=
	ć	c-
	dž	dz=
	đ	d-
	lj	lj
	nj	nj
	š	s=
	ž	z=
	예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, k)로 이루어져 있다. 단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.
	dž는 무조건 하나의 알파벳으로 쓰이고, d와 ž가 분리된 것으로 보지 않는다. lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.

	입력
	첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 '-', '='로만 이루어져 있다.
	단어는 크로아티아 알파벳으로 이루어져 있다. 문제 설명의 표에 나와있는 알파벳은 변경된 형태로 입력된다.

	출력
	입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

	예제 입력 1
	ljes=njak
	예제 출력 1
	6
	예제 입력 2
	ddz=z=
	예제 출력 2
	3
	예제 입력 3
	nljj
	예제 출력 3
	3
	예제 입력 4
	c=c=
	예제 출력 4
	2
	예제 입력 5
	dz=ak
	예제 출력 5
	3
*/

#include "Timer\timer.h"
void 크로아티아알파벳()
{
	string croatian;//~100

	cin >> croatian;

	int len = croatian.length();
	int ret = len;

	for (int i = len; i > 0; i--)
	{
		char now = croatian[i];
		if (now == '=')
		{
			char before = croatian[i - 1];
			char beforebefore = i - 2 >= 0 ? croatian[i - 2] : '*';

			if (before == 's' || before == 'c')
			{
				ret--;
				i--;
			}
			else if (before == 'z')
			{
				ret--;
				i--;
				if (beforebefore == 'd')
				{
					ret--;
					i--;
				}
			}
		}
		else if (now == '-')
		{
			char before = croatian[i - 1];
			if (before == 'c' || before == 'd')
			{
				ret--;
				i--;
			}
		}
		else if (now == 'j')
		{
			char before = croatian[i - 1];
			if (before == 'n' || before == 'l')
			{
				ret--;
				i--;
			}
		}
	}
	
	cout << ret;
}