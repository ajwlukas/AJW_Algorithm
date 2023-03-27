#include "pch.h"

/*
	https://www.acmicpc.net/problem/1316
	문제
	그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

	단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

	입력
	첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.

	출력
	첫째 줄에 그룹 단어의 개수를 출력한다.

	예제 입력 1
	3
	happy
	new
	year
	예제 출력 1
	3
	예제 입력 2
	4
	aba
	abab
	abcabc
	a
	예제 출력 2
	1
	예제 입력 3
	5
	ab
	aa
	aca
	ba
	bb
	예제 출력 3
	4
	예제 입력 4
	2
	yzyzy
	zyzyz
	예제 출력 4
	0
	예제 입력 5
	1
	z
	예제 출력 5
	1

*/
void 그룹단어체커()
{
	int N;//numofwords (1 ~ 100)

	cin >> N;

	string temp;

	getline(cin, temp);//개행문자가 남아있단다.

	vector<string> inputs(N);

	for (int i = 0; i < N; i++)
		getline(cin, inputs[i]);

	int ret = N;//num of group word

	for (int i = 0; i < N; i++)
	{
		set<char> checker;

		char before = '0';

		for (char a : inputs[i])
		{
			//if its first time
			if (checker.find(a) == checker.end())
				checker.insert(a);
			else
			{
				if (a != before)
				{
					ret--;
					break;
				}
			}

			before = a;
		}
	}

	cout << ret;
}

/*
	https://www.acmicpc.net/problem/2839

	문제
	상근이는 요즘 설탕공장에서 설탕을 배달하고 있다. 상근이는 지금 사탕가게에 설탕을 정확하게 N킬로그램을 배달해야 한다. 설탕공장에서 만드는 설탕은 봉지에 담겨져 있다. 봉지는 3킬로그램 봉지와 5킬로그램 봉지가 있다.

	상근이는 귀찮기 때문에, 최대한 적은 봉지를 들고 가려고 한다. 예를 들어, 18킬로그램 설탕을 배달해야 할 때, 3킬로그램 봉지 6개를 가져가도 되지만, 5킬로그램 3개와 3킬로그램 1개를 배달하면, 더 적은 개수의 봉지를 배달할 수 있다.

	상근이가 설탕을 정확하게 N킬로그램 배달해야 할 때, 봉지 몇 개를 가져가면 되는지 그 수를 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 N이 주어진다. (3 ≤ N ≤ 5000)

	출력
	상근이가 배달하는 봉지의 최소 개수를 출력한다. 만약, 정확하게 N킬로그램을 만들 수 없다면 -1을 출력한다.

	예제 입력 1
	18
	예제 출력 1
	4
	예제 입력 2
	4
	예제 출력 2
	-1
	예제 입력 3
	6
	예제 출력 3
	2
	예제 입력 4
	9
	예제 출력 4
	3
	예제 입력 5
	11
	예제 출력 5
	3
*/

void 설탕배달()
{
	int N;//weight (3~5000)

	cin >> N;

	int ret = 0;

	int remain = 0;

	int five = 0;

	int count = 0;

	bool flag = false;

	while (N >= 0)
	{
		if (N % 3 == 0)
		{
			five = count;
			remain = N;

			flag = true;
		}


		count++;
		N -= 5;

	}

	ret = flag ? five + remain / 3 : -1;

	cout << ret;
}

/*
	https://www.acmicpc.net/problem/1011

	문제
	우현이는 어린 시절, 지구 외의 다른 행성에서도 인류들이 살아갈 수 있는 미래가 오리라 믿었다. 그리고 그가 지구라는 세상에 발을 내려 놓은 지 23년이 지난 지금, 세계 최연소 ASNA 우주 비행사가 되어 새로운 세계에 발을 내려 놓는 영광의 순간을 기다리고 있다.

	그가 탑승하게 될 우주선은 Alpha Centauri라는 새로운 인류의 보금자리를 개척하기 위한 대규모 생활 유지 시스템을 탑재하고 있기 때문에, 그 크기와 질량이 엄청난 이유로 최신기술력을 총 동원하여 개발한 공간이동 장치를 탑재하였다. 하지만 이 공간이동 장치는 이동 거리를 급격하게 늘릴 경우 기계에 심각한 결함이 발생하는 단점이 있어서, 이전 작동시기에 k광년을 이동하였을 때는 k-1 , k 혹은 k+1 광년만을 다시 이동할 수 있다. 예를 들어, 이 장치를 처음 작동시킬 경우 -1 , 0 , 1 광년을 이론상 이동할 수 있으나 사실상 음수 혹은 0 거리만큼의 이동은 의미가 없으므로 1 광년을 이동할 수 있으며, 그 다음에는 0 , 1 , 2 광년을 이동할 수 있는 것이다. ( 여기서 다시 2광년을 이동한다면 다음 시기엔 1, 2, 3 광년을 이동할 수 있다. )



	김우현은 공간이동 장치 작동시의 에너지 소모가 크다는 점을 잘 알고 있기 때문에 x지점에서 y지점을 향해 최소한의 작동 횟수로 이동하려 한다. 하지만 y지점에 도착해서도 공간 이동장치의 안전성을 위하여 y지점에 도착하기 바로 직전의 이동거리는 반드시 1광년으로 하려 한다.

	김우현을 위해 x지점부터 정확히 y지점으로 이동하는데 필요한 공간 이동 장치 작동 횟수의 최솟값을 구하는 프로그램을 작성하라.

	입력
	입력의 첫 줄에는 테스트케이스의 개수 T가 주어진다. 각각의 테스트 케이스에 대해 현재 위치 x 와 목표 위치 y 가 정수로 주어지며, x는 항상 y보다 작은 값을 갖는다. (0 ≤ x < y < 231)

	출력
	각 테스트 케이스에 대해 x지점으로부터 y지점까지 정확히 도달하는데 필요한 최소한의 공간이동 장치 작동 횟수를 출력한다.

	예제 입력 1
	3
	0 3
	1 5
	45 50
	예제 출력 1
	3
	3
	4

	시작 : 1 : 34
	끝 : 1 : 57

	소요시간 : 23분
*/

void FlymetotheAlphaCentauri()
{
	int T;//num of test cases

	cin >> T;

	vector<pair<unsigned int, unsigned int>> xy(T);//(0 <= x < y < 2^31)

	int x = 0;

	int y = 0;

	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		xy[i] = make_pair(x, y);
	}

	vector<int> ret(T);

	for (int i = 0; i < T; i++)
	{
		auto p = xy[i];

		int remain = p.second - p.first;//remain distance

		int k = 1;

		int days = 0;//days to go

		while (remain > 0)
		{
			if (remain < k)
			{
				remain = 0;
				days++;
				break;
			}
			else if (remain >= k * 2)
			{
				remain -= k * 2;
				days += 2;
			}
			else//k <= remain < k * 2
			{
				remain -= k;
				days++;
			}

			k++;
		}

		ret[i] = days;
	}

	for (auto r : ret)
		cout << r << "\n";
}

/*
	https://www.acmicpc.net/problem/4948

	문제
베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.

이 명제는 조제프 베르트랑이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.

예를 들어, 10보다 크고, 20보다 작거나 같은 소수는 4개가 있다. (11, 13, 17, 19) 또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17,19, 23)

자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 케이스는 n을 포함하는 한 줄로 이루어져 있다.

입력의 마지막에는 0이 주어진다.

출력
각 테스트 케이스에 대해서, n보다 크고, 2n보다 작거나 같은 소수의 개수를 출력한다.

제한
1 ≤ n ≤ 123,456
예제 입력 1
1
10
13
100
1000
10000
100000
0
예제 출력 1
1
4
3
21
135
1033
8392

*/


void 베르트랑공준()
{
	int t = -1;

	vector<int> ns;//(1~123456)

	int max = 0;
	while (cin >> t, t)
	{
		ns.push_back(t);

		max = max > t ? max : t;
	}

	max *= 2;

	int size = ns.size();

	vector<int> ret(size, 0);

	set<int> primenumbers;

	for (int i = 2; i < max; i++)
		primenumbers.insert(i);

	for (int i = 2; i < sqrt(max); i++)
	{
		if (primenumbers.find(i) == primenumbers.end()) continue;

		int mul = i;

		while (mul * i <= max)
		{
			primenumbers.erase(mul * i);
			mul++;
		}
	}

	for (auto num : primenumbers)
	{
		for (int i = 0; i < size; i++)
		{
			if (ns[i] < num && 2 * ns[i] >= num)
				ret[i]++;
		}
	}

	for (auto i : ret)
		cout << i << "\n";

}

/*
	https://www.acmicpc.net/problem/1436

	문제
666은 종말을 나타내는 수라고 한다. 따라서, 많은 블록버스터 영화에서는 666이 들어간 제목을 많이 사용한다. 영화감독 숌은 세상의 종말 이라는 시리즈 영화의 감독이다. 조지 루카스는 스타워즈를 만들 때, 스타워즈 1, 스타워즈 2, 스타워즈 3, 스타워즈 4, 스타워즈 5, 스타워즈 6과 같이 이름을 지었고, 피터 잭슨은 반지의 제왕을 만들 때, 반지의 제왕 1, 반지의 제왕 2, 반지의 제왕 3과 같이 영화 제목을 지었다. 하지만 숌은 자신이 조지 루카스와 피터 잭슨을 뛰어넘는다는 것을 보여주기 위해서 영화 제목을 좀 다르게 만들기로 했다.

종말의 수란 어떤 수에 6이 적어도 3개 이상 연속으로 들어가는 수를 말한다. 제일 작은 종말의 수는 666이고, 그 다음으로 큰 수는 1666, 2666, 3666, .... 이다. 따라서, 숌은 첫 번째 영화의 제목은 "세상의 종말 666", 두 번째 영화의 제목은 "세상의 종말 1666"와 같이 이름을 지을 것이다. 일반화해서 생각하면, N번째 영화의 제목은 세상의 종말 (N번째로 작은 종말의 수) 와 같다.

숌이 만든 N번째 영화의 제목에 들어간 수를 출력하는 프로그램을 작성하시오. 숌은 이 시리즈를 항상 차례대로 만들고, 다른 영화는 만들지 않는다.

입력
첫째 줄에 N이 주어진다. N은 10,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 N번째 영화의 제목에 들어간 수를 출력한다.

예제 입력 1
2
예제 출력 1
1666
예제 입력 2
3
예제 출력 2
2666
예제 입력 3
6
예제 출력 3
5666
예제 입력 4
187
예제 출력 4
66666
예제 입력 5
500
예제 출력 5
166699


시작 2 : 10

끝 3 : 30
*/


void StringPlusPlus(string& str)
{
	bool carry = true;

	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (carry)
		{
			str[i]++;
			carry = false;
		}

		if (str[i] == '9' + 1)
		{
			str[i] = '0';
			carry = true;
		}
	}

	if (carry)
		str = "1" + str;

}

void 영화감독숌()
{

	int N;//(1 ~ 10000)

	cin >> N;

	/*
		666
		1666
		2666
		3666
		4666
		5666		6

		6660
		6661
		6662
		6663
		6664
		6665
		6666
		6667
		6668
		6669		10

		7666
		8666
		9666
		10666
		11666
		12666
		13666
		14666
		15666		9

		16660
		16661
		16662
		16663
		16664
		16665
		16666
		16667
		16668
		16669		10

		17666
		18666
		19666
		20666
		21666
		22666
		23666
		24666
		25666		9

		26660
		26661
		26662
		26663
		26664
		26665
		26666
		26667
		26668
		26669		10

		...

		65666

		66600
		...
		66699		100

		67666
		...
		75666		9

		76660
		...
		76669		10

		77666
		...

	*/

	string sss = "666";

	string headstring = "0";
	string tailstring = "0";


	int numOfTail = 0;

	int tail = 0;
	int sixInRow = 0;

	N--;
	while (N > 0)
	{
		StringPlusPlus(headstring);


		sixInRow = 0;//series of 6s from behind
		for (int i = headstring.length() - 1; i >= 0; i--)
		{
			if (headstring[i] - '0' == 6)
			{
				sixInRow++;
			}
			else
				break;
		}

		numOfTail = pow(10, sixInRow);

		tail = -1;
		while (numOfTail--)
		{
			tail++;
			N--;

			if (N <= 0)
				break;
		}

	}

	string t(sixInRow, '0');

	while (tail--)
		StringPlusPlus(t);

	headstring = headstring.substr(0, headstring.length() - sixInRow);

	string ret = headstring + "666" + t;


	cout << stoi(ret);
}

/*
	https://www.acmicpc.net/problem/9184

	문제
재귀 호출만 생각하면 신이 난다! 아닌가요?

다음과 같은 재귀함수 w(a, b, c)가 있다.

if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
	1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
	w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
	w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
	w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
위의 함수를 구현하는 것은 매우 쉽다. 하지만, 그대로 구현하면 값을 구하는데 매우 오랜 시간이 걸린다. (예를 들면, a=15, b=15, c=15)

a, b, c가 주어졌을 때, w(a, b, c)를 출력하는 프로그램을 작성하시오.

입력
입력은 세 정수 a, b, c로 이루어져 있으며, 한 줄에 하나씩 주어진다. 입력의 마지막은 -1 -1 -1로 나타내며, 세 정수가 모두 -1인 경우는 입력의 마지막을 제외하면 없다.

출력
입력으로 주어진 각각의 a, b, c에 대해서, w(a, b, c)를 출력한다.

제한
-50 ≤ a, b, c ≤ 50
예제 입력 1
1 1 1
2 2 2
10 4 6
50 50 50
-1 7 18
-1 -1 -1
예제 출력 1
w(1, 1, 1) = 2
w(2, 2, 2) = 4
w(10, 4, 6) = 523
w(50, 50, 50) = 1048576
w(-1, 7, 18) = 1

시작 1037
	 11 30
*/

//int coun = 0;

map<string, int> m;

int W(int a, int b, int c)
{
	string str = to_string(a) + "_" + to_string(b) + "_" + to_string(c);

	if (m.find(str) != m.end())
		return m[str];

	bool condition0 = a <= 0 || b <= 0 || c <= 0;//a,b,c 중 하나라도 0이거나 음수인 정수라면
	bool condition1 = a > 20 || b > 20 || c > 20;//a,b,c 중 하나라도 20 초과라면
	bool condition2 = a < b&& b < c;//a, b, c 순으로 증가 한다면

	if (condition0)
		return 1;
	else if (condition1)
	{
		if (m.find("20_20_20") != m.end())
			return m["20_20_20"];
		else
		{
			m["20_20_20"] = W(20, 20, 20);
			return m["20_20_20"];
		}
	}
	else if (condition2)
	{
		int plus[3][3] = { {0, 0, -1}, {0, -1, -1}, {0, -1, 0} };
		int ret[3] = {};

		for (int i = 0; i < 3; i++)
		{
			int newA = a + plus[i][0];
			int newB = b + plus[i][1];
			int newC = c + plus[i][2];

			string key = to_string(newA) + "_" + to_string(newB) + "_" + to_string(newC);

			auto ans = m.find(key);
			if (ans != m.end())
				ret[i] = ans->second;
			else
			{
				ret[i] = W(newA, newB, newC);
				m[key] = ret[i];
			}
		}

		return ret[0] + ret[1] - ret[2];
	}

	int plus[4][3] = { {-1, 0, 0}, {-1, -1, 0}, {-1, 0, -1}, {-1,-1,-1} };
	int ret[4] = {};

	for (int i = 0; i < 4; i++)
	{
		int newA = a + plus[i][0];
		int newB = b + plus[i][1];
		int newC = c + plus[i][2];


		string key = to_string(newA) + "_" + to_string(newB) + "_" + to_string(newC);

		auto ans = m.find(key);
		if (ans != m.end())
			ret[i] = ans->second;
		else
		{
			ret[i] = W(newA, newB, newC);
			m[key] = ret[i];
		}

	}

	return ret[0] + ret[1] + ret[2] - ret[3];
}

void 신나는함수실행()

{
	vector<vector<int>> abcs;
	vector<int> rets;

	int a = 0, b = 0, c = 0;//(-50 ~ 50)

	while (true)
	{
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1) break;

		vector<int> abc = { a,b,c };
		abcs.emplace_back(abc);

		rets.push_back(W(a, b, c));
	}

	for (int i = 0; i < rets.size(); i++)
	{
		cout << "w(" << abcs[i][0] << ", " << abcs[i][1] << ", " << abcs[i][2] << ") = " << rets[i] << "\n";
	}

}


/*
	https://www.acmicpc.net/problem/9461

	문제
오른쪽 그림과 같이 삼각형이 나선 모양으로 놓여져 있다. 첫 삼각형은 정삼각형으로 변의 길이는 1이다. 그 다음에는 다음과 같은 과정으로 정삼각형을 계속 추가한다. 나선에서 가장 긴 변의 길이를 k라 했을 때, 그 변에 길이가 k인 정삼각형을 추가한다.

파도반 수열 P(N)은 나선에 있는 정삼각형의 변의 길이이다. P(1)부터 P(10)까지 첫 10개 숫자는 1, 1, 1, 2, 2, 3, 4, 5, 7, 9이다.

N이 주어졌을 때, P(N)을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. (1 ≤ N ≤ 100)

출력
각 테스트 케이스마다 P(N)을 출력한다.

예제 입력 1
2
6
12
예제 출력 1
3
16
*/


long long Wave(int i, vector<long long>& p)
{
	if (p[i] == -1)
	{
		p[i] = Wave(i - 1, p) + Wave(i - 5, p);
		return p[i];
	}
	else
		return p[i];
}

void 파도반수열()
{
	int T;//num of TestCases

	cin >> T;

	vector<int> N(T);//(1~100)

	int max = 0;

	for (int i = 0; i < T; i++)
	{
		cin >> N[i];

		max = max > N[i] ? max : N[i];
	}

	vector<long long> p = { 1,1,1,2,2 };

	p.resize(max, -1);

	Wave(max - 1, p);

	for (int i : N)
	{
		cout << p[i - 1] << "\n";
	}
}


/*
	https://www.acmicpc.net/problem/1149

	문제
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
입력
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

예제 입력 1
3
26 40 83
49 60 57
13 89 99
예제 출력 1
96
예제 입력 2
3
1 100 100
100 1 100
100 100 1
예제 출력 2
3
예제 입력 3
3
1 100 100
100 100 100
1 100 100
예제 출력 3
102
예제 입력 4
6
30 19 5
64 77 64
15 19 97
4 71 57
90 86 84
93 32 91
예제 출력 4
208
예제 입력 5
8
71 39 44
32 83 55
51 37 63
89 29 100
83 58 11
65 13 15
47 25 29
60 66 19
예제 출력 5
253

시작 2 22
끝 2 40
*/

void RGB거리()
{
	int N;//num of houses(2 ~ 1000)

	cin >> N;

	vector<vector<int>> costs(N);//(1~1000)

	vector<vector<int>> minimumCosts(N);

	for (auto& v : minimumCosts)
		v.resize(3);

	for (int i = 0; i < N; i++)
	{
		vector<int> cost(3);

		cin >> cost[0] >> cost[1] >> cost[2];

		costs[i] = cost;
	}

	for (int i = 0; i < N; i++)
	{
		if (i == 0)
			minimumCosts[0] = costs[0];
		else
		{
			minimumCosts[i][0] = min(minimumCosts[i - 1][1], minimumCosts[i - 1][2]);
			minimumCosts[i][0] += costs[i][0];
			minimumCosts[i][1] = min(minimumCosts[i - 1][0], minimumCosts[i - 1][2]);
			minimumCosts[i][1] += costs[i][1];
			minimumCosts[i][2] = min(minimumCosts[i - 1][0], minimumCosts[i - 1][1]);
			minimumCosts[i][2] += costs[i][2];

		}
	}
	vector<int> last = minimumCosts.back();

	int ret = min(last[0], min(last[1], last[2]));

	cout << ret;
}

/*

	https://www.acmicpc.net/problem/1932
	문제
			7
		  3   8
		8   1   0
	  2   7   4   4
	4   5   2   6   5
	위 그림은 크기가 5인 정수 삼각형의 한 모습이다.

	맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

	삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

	입력
	첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

	출력
	첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.

	예제 입력 1
	5
	7
	3 8
	8 1 0
	2 7 4 4
	4 5 2 6 5
	예제 출력 1
	30

	시작 2 45
	끝 2 58
*/

void 정수삼각형()
{
	int n;//size of pyramid(1 ~ 500)

	cin >> n;

	vector<vector<int>> addUp(n);

	for (int i = 0; i < n; i++)
	{
		vector<int>& floor = addUp[i];

		floor.resize(i + 1, 0);

		for (int& i : floor)
			cin >> i;
	}

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			continue;
		vector<int>& upperFloor = addUp[i - 1];
		vector<int>& addFloor = addUp[i];

		int width = addFloor.size();


		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				addFloor[0] += upperFloor[0];
			else if (j == width - 1)
				addFloor[j] += upperFloor[j - 1];
			else
				addFloor[j] += max(upperFloor[j], upperFloor[j - 1]);
		}
	}

	int m = 0;

	for (int i : addUp.back())
	{
		m = max(m, i);
	}

	cout << m;
}

/*
	https://www.acmicpc.net/problem/11047

	문제
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

출력
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.

예제 입력 1
10 4200
1
5
10
50
100
500
1000
5000
10000
50000
예제 출력 1
6
예제 입력 2
10 4790
1
5
10
50
100
500
1000
5000
10000
50000
예제 출력 2
12

3 19
3 26
*/


void 동전0()
{
	int N, K;//(N = 1 ~ 10, K = 1 ~ 100,000,000)(억)

	cin >> N >> K;

	vector<int> values(N);

	while (N--)
	{
		cin >> values[N];
	}

	int count = 0;
	int index = 0;

	while (K > 0)
	{
		if (K >= values[index])
		{
			K -= values[index];
			count++;
		}
		else
			index++;
	}

	cout << count;
}

/*
	https://www.acmicpc.net/problem/11399

	문제
인하은행에는 ATM이 1대밖에 없다. 지금 이 ATM앞에 N명의 사람들이 줄을 서있다. 사람은 1번부터 N번까지 번호가 매겨져 있으며, i번 사람이 돈을 인출하는데 걸리는 시간은 Pi분이다.

사람들이 줄을 서는 순서에 따라서, 돈을 인출하는데 필요한 시간의 합이 달라지게 된다. 예를 들어, 총 5명이 있고, P1 = 3, P2 = 1, P3 = 4, P4 = 3, P5 = 2 인 경우를 생각해보자. [1, 2, 3, 4, 5] 순서로 줄을 선다면, 1번 사람은 3분만에 돈을 뽑을 수 있다. 2번 사람은 1번 사람이 돈을 뽑을 때 까지 기다려야 하기 때문에, 3+1 = 4분이 걸리게 된다. 3번 사람은 1번, 2번 사람이 돈을 뽑을 때까지 기다려야 하기 때문에, 총 3+1+4 = 8분이 필요하게 된다. 4번 사람은 3+1+4+3 = 11분, 5번 사람은 3+1+4+3+2 = 13분이 걸리게 된다. 이 경우에 각 사람이 돈을 인출하는데 필요한 시간의 합은 3+4+8+11+13 = 39분이 된다.

줄을 [2, 5, 1, 4, 3] 순서로 줄을 서면, 2번 사람은 1분만에, 5번 사람은 1+2 = 3분, 1번 사람은 1+2+3 = 6분, 4번 사람은 1+2+3+3 = 9분, 3번 사람은 1+2+3+3+4 = 13분이 걸리게 된다. 각 사람이 돈을 인출하는데 필요한 시간의 합은 1+3+6+9+13 = 32분이다. 이 방법보다 더 필요한 시간의 합을 최소로 만들 수는 없다.

줄을 서 있는 사람의 수 N과 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어졌을 때, 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 사람의 수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄에는 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어진다. (1 ≤ Pi ≤ 1,000)

출력
첫째 줄에 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 출력한다.

예제 입력 1
5
3 1 4 3 2
예제 출력 1
32

3 28
3 35
*/

#include <algorithm>

void ATM()
{
	int N;//(1~1000)

	cin >> N;

	vector<int> times(N);

	while (N--)
		cin >> times[N];

	sort(times.begin(), times.end());

	int ret = 0;

	for (int i = 0; i < times.size(); i++)
		ret += times[i] * (times.size() - i);

	cout << ret;
}

/*
	https://www.acmicpc.net/problem/1037

	문제
양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다. 어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N의 진짜 약수의 개수가 주어진다. 이 개수는 50보다 작거나 같은 자연수이다. 둘째 줄에는 N의 진짜 약수가 주어진다. 1,000,000보다 작거나 같고, 2보다 크거나 같은 자연수이고, 중복되지 않는다.

출력
첫째 줄에 N을 출력한다. N은 항상 32비트 부호있는 정수로 표현할 수 있다.

예제 입력 1
2
4 2
예제 출력 1
8
예제 입력 2
1
2
예제 출력 2
4
예제 입력 3
6
3 4 2 12 6 8
예제 출력 3
24
예제 입력 4
14
14 26456 2 28 13228 3307 7 23149 8 6614 46298 56 4 92596
예제 출력 4
185192

 11 31
 11 36
*/

void 약수()
{
	int N;//num of dividers

	cin >> N;

	int max = 0;
	int min = INT_MAX;

	while (N--)
	{
		int temp;

		cin >> temp;

		max = max > temp ? max : temp;
		min = min < temp ? min : temp;
	}

	cout << max * min;
}

/*
	https://www.acmicpc.net/problem/2609
문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

예제 입력 1
24 18
예제 출력 1
6
72

11 37
11 56
*/

void 최대공약수와최소공배수()
{
	int A, B;

	map<int, int> primeNumbersA;
	map<int, int> primeNumbersB;

	cin >> A >> B;


	for (int i = 2; i <= A; i++)
	{
		while (A % i == 0)
		{
			A /= i;
			primeNumbersA[i]++;
		}
	}

	for (int i = 2; i <= B; i++)
	{
		while (B % i == 0)
		{
			B /= i;
			primeNumbersB[i]++;
		}
	}

	int commonDivider = 1;
	int commonMultiplier = 1;

	set<int> allNums;

	for (auto n : primeNumbersA)
		allNums.insert(n.first);

	for (auto n : primeNumbersB)
		allNums.insert(n.first);

	for (auto n : allNums)
	{
		if (primeNumbersA.find(n) != primeNumbersA.end() &&
			primeNumbersB.find(n) != primeNumbersB.end())
		{
			commonDivider *= pow(n, min(primeNumbersA[n], primeNumbersB[n]));
			commonMultiplier *= pow(n, max(primeNumbersA[n], primeNumbersB[n]));
		}
		else
		{
			commonMultiplier *= pow(n, max(primeNumbersA[n], primeNumbersB[n]));
		}
	}

	cout << commonDivider << "\n" << commonMultiplier;

}

/*
	https://www.acmicpc.net/problem/1934

	문제
두 자연수 A와 B에 대해서, A의 배수이면서 B의 배수인 자연수를 A와 B의 공배수라고 한다. 이런 공배수 중에서 가장 작은 수를 최소공배수라고 한다. 예를 들어, 6과 15의 공배수는 30, 60, 90등이 있으며, 최소 공배수는 30이다.

두 자연수 A와 B가 주어졌을 때, A와 B의 최소공배수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다. 둘째 줄부터 T개의 줄에 걸쳐서 A와 B가 주어진다. (1 ≤ A, B ≤ 45,000)

출력
첫째 줄부터 T개의 줄에 A와 B의 최소공배수를 입력받은 순서대로 한 줄에 하나씩 출력한다.

예제 입력 1
3
1 45000
6 10
13 17
예제 출력 1
45000
30
221

1 15
1 25
*/

void 최소공배수()
{
	int T;//(1~1000) num of testCases

	cin >> T;


	vector<int> rets(T);

	for (int i = 0; i < T; i++)
	{
		int A, B;

		cin >> A >> B;

		set<int> s;//all numbers include least once

		map<int, int> mA;
		map<int, int> mB;

		for (int i = 2; i <= A; i++)
		{
			while (A % i == 0)
			{
				A /= i;
				mA[i]++;

				s.insert(i);
			}

			if (A == 1) break;
		}

		for (int i = 2; i <= B; i++)
		{
			while (B % i == 0)
			{
				B /= i;
				mB[i]++;

				s.insert(i);
			}

			if (B == 1) break;
		}

		int ret = 1;

		for (int n : s)
		{
			ret *= pow(n, max(mA[n], mB[n]));
		}

		rets[i] = ret;
	}

	for (int n : rets)
	{
		cout << n << "\n";
	}

}

/*
	https://www.acmicpc.net/problem/11050

	문제
자연수
\(N\)과 정수
\(K\)가 주어졌을 때 이항 계수
\(\binom{N}{K}\)를 구하는 프로그램을 작성하시오.

입력
첫째 줄에
\(N\)과
\(K\)가 주어진다. (1 ≤
\(N\) ≤ 10, 0 ≤
\(K\) ≤
\(N\))

출력

\(\binom{N}{K}\)를 출력한다.

예제 입력 1
5 2
예제 출력 1
10

1 27
1 34
*/

long long Factorial(long long n)
{
	if (n == 1 || n == 0) return 1;

	return n * Factorial(n - 1);
}

void 이항계수1()
{
	int N, K;//N(1~10), K(0~N);

	cin >> N >> K;

	int ret = 1;

	int div = Factorial(K);

	while (K)
	{
		K--;
		ret *= N--;
	}

	ret /= div;

	cout << ret;
}

/*
	https://www.acmicpc.net/problem/1010

	문제
재원이는 한 도시의 시장이 되었다. 이 도시에는 도시를 동쪽과 서쪽으로 나누는 큰 일직선 모양의 강이 흐르고 있다. 하지만 재원이는 다리가 없어서 시민들이 강을 건너는데 큰 불편을 겪고 있음을 알고 다리를 짓기로 결심하였다. 강 주변에서 다리를 짓기에 적합한 곳을 사이트라고 한다. 재원이는 강 주변을 면밀히 조사해 본 결과 강의 서쪽에는 N개의 사이트가 있고 동쪽에는 M개의 사이트가 있다는 것을 알았다. (N ≤ M)

재원이는 서쪽의 사이트와 동쪽의 사이트를 다리로 연결하려고 한다. (이때 한 사이트에는 최대 한 개의 다리만 연결될 수 있다.) 재원이는 다리를 최대한 많이 지으려고 하기 때문에 서쪽의 사이트 개수만큼 (N개) 다리를 지으려고 한다. 다리끼리는 서로 겹쳐질 수 없다고 할 때 다리를 지을 수 있는 경우의 수를 구하는 프로그램을 작성하라.



입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 그 다음 줄부터 각각의 테스트케이스에 대해 강의 서쪽과 동쪽에 있는 사이트의 개수 정수 N, M (0 < N ≤ M < 30)이 주어진다.

출력
각 테스트 케이스에 대해 주어진 조건하에 다리를 지을 수 있는 경우의 수를 출력한다.

예제 입력 1
3
2 2
1 5
13 29
예제 출력 1
1
5
67863915

1 38
2 00

*/

void 다리놓기()
{
	int T;//num of testCases

	cin >> T;

	vector<long long> rets;

	while (T--)
	{
		int N, M;//(0 < N <= M < 30)

		cin >> N >> M;


		//mCn

		long long ret = 1;

		int temp = N;
		for (int i = 0; i < temp; i++)
		{
			ret *= M--;

			while (ret % N == 0 && N > 1)
				ret /= N--;
		}

		while (N)
			ret /= N--;

		rets.push_back(ret);
	}


	for (long long ret : rets)
		cout << ret << "\n";


}

/*
	https://www.acmicpc.net/problem/10828

	문제
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

예제 입력 1
14
push 1
push 2
top
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
top
예제 출력 1
2
2
0
2
1
-1
0
1
-1
0
3
예제 입력 2
7
pop
top
push 123
top
pop
top
pop
예제 출력 2
-1
-1
123
123
-1
-1

2 19
2 40
*/

#include <stack>
#include <sstream>

void 스택()
{
	int N;//num of orders(1 ~ 10000)

	cin >> N;

	string temp;
	getline(cin, temp);

	enum class ORDER
	{
		PUSH,
		TOP,
		SIZE,
		EMPTY,
		POP,
	};

	queue<ORDER> orders;
	queue<int> nums;

	while (N--)
	{
		string buffer;
		getline(cin, buffer);

		if (buffer == "") break;

		stringstream ss(buffer);

		while (true)
		{
			string buffer;
			getline(ss, buffer, ' ');

			if (buffer == "") break;

			if (isdigit(buffer[0]))
				nums.push(stoi(buffer));
			else
			{
				if (buffer == "push")
					orders.push(ORDER::PUSH);
				else if (buffer == "pop")
					orders.push(ORDER::POP);
				else if (buffer == "size")
					orders.push(ORDER::SIZE);
				else if (buffer == "empty")
					orders.push(ORDER::EMPTY);
				else
					orders.push(ORDER::TOP);
			}
		}

	}

	stack<int> s;

	while (!orders.empty())
	{
		ORDER o = orders.front();
		orders.pop();

		switch (o)
		{
		case ORDER::PUSH:
		{
			s.push(nums.front());
			nums.pop();
		}
		break;
		case ORDER::TOP:
		{
			if (s.empty())
				cout << "-1" << "\n";
			else
				cout << s.top() << "\n";
		}
		break;
		case ORDER::SIZE:
		{
			cout << s.size() << "\n";
		}
		break;
		case ORDER::EMPTY:
		{
			cout << s.empty() << "\n";
		}
		break;
		case ORDER::POP:
		{
			if (s.empty())
				cout << "-1" << "\n";
			else
			{
				cout << s.top() << "\n";
				s.pop();
			}
		}
		break;
		default:
			break;
		}
	}
}

/*
	https://www.acmicpc.net/problem/10773

	문제
나코더 기장 재민이는 동아리 회식을 준비하기 위해서 장부를 관리하는 중이다.

재현이는 재민이를 도와서 돈을 관리하는 중인데, 애석하게도 항상 정신없는 재현이는 돈을 실수로 잘못 부르는 사고를 치기 일쑤였다.

재현이는 잘못된 수를 부를 때마다 0을 외쳐서, 가장 최근에 재민이가 쓴 수를 지우게 시킨다.

재민이는 이렇게 모든 수를 받아 적은 후 그 수의 합을 알고 싶어 한다. 재민이를 도와주자!

입력
첫 번째 줄에 정수 K가 주어진다. (1 ≤ K ≤ 100,000)

이후 K개의 줄에 정수가 1개씩 주어진다. 정수는 0에서 1,000,000 사이의 값을 가지며, 정수가 "0" 일 경우에는 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.

정수가 "0"일 경우에 지울 수 있는 수가 있음을 보장할 수 있다.

출력
재민이가 최종적으로 적어 낸 수의 합을 출력한다. 최종적으로 적어낸 수의 합은 231-1보다 작거나 같은 정수이다.

예제 입력 1
4
3
0
4
0
예제 출력 1
0
예제 입력 2
10
1
3
5
4
0
0
7
0
0
6
예제 출력 2
7

2 44
2 48
*/

void 제로()
{
	int K;//(1 ~ 100000)

	cin >> K;

	int ret = 0;
	stack<int> s;


	while (K--)
	{
		int temp;

		cin >> temp;

		if (temp)
		{
			ret += temp;
			s.push(temp);
		}
		else
		{
			ret -= s.top();
			s.pop();

		}
	}

	cout << ret;
}

/*
	https://www.acmicpc.net/problem/9012

	문제
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.

여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.

입력
입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 데이터로 주어진다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다.

출력
출력은 표준 출력을 사용한다. 만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다.

예제 입력 1
6
(())())
(((()())()
(()())((()))
((()()(()))(((())))()
()()()()(()()())()
(()((())()(
예제 출력 1
NO
NO
YES
NO
YES
NO
예제 입력 2
3
((
))
())(()
예제 출력 2
NO
NO
NO

2 50

2 51 ~ 3 03 휴식

3 03
3 09

*/

void 괄호()
{
	int T;//num of testCases

	cin >> T;

	vector<string> rets;

	while (T--)
	{
		string temp;

		cin >> temp;

		stack<char> s;

		rets.push_back("YES");

		for (char a : temp)
		{
			if (a == '(')
				s.push(a);
			else
			{
				if (s.empty())
				{
					rets.back() = "NO";
					break;
				}
				else
					s.pop();
			}
		}

		if (!s.empty())
			rets.back() = "NO";

	}

	for (auto ret : rets)
		cout << ret << "\n";
}

/*
	https://www.acmicpc.net/problem/18258
	문제
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 2,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

예제 입력 1
15
push 1
push 2
front
back
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
front
예제 출력 1
1
2
2
0
1
2
-1
0
1
-1
0
3

3 10
4 09
*/

#include <stdio.h>
#include <deque>

void 큐2()
{
	int N;//num of Orders(1~2,000,000)

	cin >> N;

	queue<int> q;

	int tail = -1;

	while (N--)
	{
		string buffer;

		cin >> buffer;

		if (buffer == "push")
		{
			cin >> buffer;
			int n = stoi(buffer);
			q.push(n);
			tail = n;
		}
		else if (buffer == "pop")
		{
			if (q.empty())
				cout << "-1" << "\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (buffer == "size")
		{
			cout << q.size() << "\n";
		}
		else if (buffer == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (buffer == "front")
		{
			if (q.empty())
				cout << "-1" << "\n";
			else
				cout << q.front() << "\n";
		}
		else if (buffer == "back")
		{
			if (q.empty())
				cout << "-1" << "\n";
			else
				cout << tail << "\n";
		}
	}
}

/*

	https://www.acmicpc.net/problem/1260
	문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

예제 입력 1
4 5 1
1 2
1 3
1 4
2 4
3 4
예제 출력 1
1 2 4 3
1 2 3 4
예제 입력 2
5 5 3
5 4
5 2
1 2
3 4
3 1
예제 출력 2
3 1 2 5 4
3 1 4 2 5
예제 입력 3
1000 1 1000
999 1000
예제 출력 3
1000 999
1000 999


10 42
10 59
*/

void DFS(int point, vector<vector<int>>& connections, vector<bool>& checkDFS)
{
	if (checkDFS[point]) return;

	checkDFS[point] = true;

	cout << point << " ";

	for (int n : connections[point])
		DFS(n, connections, checkDFS);
}

void BFS(int point, vector<vector<int>>& connections, vector<bool>& checkBFS)
{
	queue<int> q;

	q.push(point);
	checkBFS[point] = true;

	while (!q.empty())
	{
		cout << q.front() << " ";

		for (int n : connections[q.front()])
		{
			if (!checkBFS[n])
			{
				q.push(n);
				checkBFS[n] = true;
			}
		}

		q.pop();
	}

}

void DFS와BFS()
{
	int N;//(1 ~ 1000)
	int M;//(1 ~ 10000)

	int V;//Start Point

	cin >> N >> M >> V;

	vector<vector<int>> connections(N + 1);

	vector<bool> checkDFS(N + 1, false);
	vector<bool> checkBFS(N + 1, false);

	while (M--)
	{
		int A, B;

		cin >> A >> B;

		connections[A].push_back(B);
		connections[B].push_back(A);
	}

	for (auto& c : connections)
		sort(c.begin(), c.end());

	DFS(V, connections, checkDFS);
	cout << "\n";
	BFS(V, connections, checkBFS);



}

/*
	https://www.acmicpc.net/problem/2108


	문제
수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 단, N은 홀수이다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

출력
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.

예제 입력 1
5
1
3
8
-2
2
예제 출력 1
2
2
1
10
예제 입력 2
1
4000
예제 출력 2
4000
4000
4000
0
예제 입력 3
5
-1
-2
-3
-1
-2
예제 출력 3
-2
-2
-1
2
예제 입력 4
3
0
0
-1
예제 출력 4
0
0
0
1

11 16
11 55

*/

void 통계학()
{
	int N;//num of digits(1 ~ 500,000) N % 2 == 1

	cin >> N;

	vector<int> numbers;
	map<int, int> m;

	numbers.reserve(N);

	int total = 0;

	int maximum = INT_MIN;

	int minimum = INT_MAX;

	int mostFrequent = -1;

	vector<int> v = {};

	for (int i = 0; i < N; i++)
	{
		int num;

		cin >> num;

		total += num;

		int mostCount = m[mostFrequent];

		m[num]++;

		if (mostCount < m[num])
		{
			v.clear();
			v.push_back(num);

			mostFrequent = num;
		}
		else if (mostCount == m[num])
		{
			v.push_back(num);
			mostFrequent = num;
		}

		maximum = max(maximum, num);
		minimum = min(minimum, num);

		numbers.push_back(num);
	}

	sort(numbers.begin(), numbers.end());
	sort(v.begin(), v.end());

	cout.setf(ios::fixed);
	cout.precision(0);

	//산술평균
	float a = round(total / (float)N);
	a = a == -0 ? 0 : a;

	cout << a << "\n";

	//중앙값
	cout << numbers[N / 2] << "\n";

	//최빈값
	if (v.size() > 1)
		cout << v[1] << "\n";
	else
		cout << mostFrequent << "\n";

	//범위
	cout << maximum - minimum;
}

/*
	https://www.acmicpc.net/problem/2630
	문제
아래 <그림 1>과 같이 여러개의 정사각형칸들로 이루어진 정사각형 모양의 종이가 주어져 있고, 각 정사각형들은 하얀색으로 칠해져 있거나 파란색으로 칠해져 있다. 주어진 종이를 일정한 규칙에 따라 잘라서 다양한 크기를 가진 정사각형 모양의 하얀색 또는 파란색 색종이를 만들려고 한다.



전체 종이의 크기가 N×N(N=2k, k는 1 이상 7 이하의 자연수) 이라면 종이를 자르는 규칙은 다음과 같다.

전체 종이가 모두 같은 색으로 칠해져 있지 않으면 가로와 세로로 중간 부분을 잘라서 <그림 2>의 I, II, III, IV와 같이 똑같은 크기의 네 개의 N/2 × N/2색종이로 나눈다. 나누어진 종이 I, II, III, IV 각각에 대해서도 앞에서와 마찬가지로 모두 같은 색으로 칠해져 있지 않으면 같은 방법으로 똑같은 크기의 네 개의 색종이로 나눈다. 이와 같은 과정을 잘라진 종이가 모두 하얀색 또는 모두 파란색으로 칠해져 있거나, 하나의 정사각형 칸이 되어 더 이상 자를 수 없을 때까지 반복한다.

위와 같은 규칙에 따라 잘랐을 때 <그림 3>은 <그림 1>의 종이를 처음 나눈 후의 상태를, <그림 4>는 두 번째 나눈 후의 상태를, <그림 5>는 최종적으로 만들어진 다양한 크기의 9장의 하얀색 색종이와 7장의 파란색 색종이를 보여주고 있다.



입력으로 주어진 종이의 한 변의 길이 N과 각 정사각형칸의 색(하얀색 또는 파란색)이 주어질 때 잘라진 하얀색 색종이와 파란색 색종이의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 전체 종이의 한 변의 길이 N이 주어져 있다. N은 2, 4, 8, 16, 32, 64, 128 중 하나이다. 색종이의 각 가로줄의 정사각형칸들의 색이 윗줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다. 하얀색으로 칠해진 칸은 0, 파란색으로 칠해진 칸은 1로 주어지며, 각 숫자 사이에는 빈칸이 하나씩 있다.

출력
첫째 줄에는 잘라진 햐얀색 색종이의 개수를 출력하고, 둘째 줄에는 파란색 색종이의 개수를 출력한다.

예제 입력 1
8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
예제 출력 1
9
7

2 00
2 33
*/

bool CheckClear(vector<vector<bool>>& paper)
{
	int size = paper.size();

	if (size == 1) return true;

	bool init = paper[0][0];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (paper[i][j] != init) return false;
		}
	}

	return true;
}

vector<vector<vector<bool>>> DividePaper(vector<vector<bool>>& paper)
{
	int size = paper.size();

	int half = size / 2;

	int add[4][2] = { {0,0},{0,half},{half,0},{half,half} };

	vector<vector<vector<bool>>> papers(4);

	for (int i = 0; i < 4; i++)
	{
		int x = add[i][0];
		int y = add[i][1];

		vector<vector<bool>>& piece = papers[i];
		piece.resize(half);

		for (int j = 0; j < half; j++)
		{
			vector<bool>& line = piece[j];
			line.resize(half);
			for (int k = 0; k < half; k++)
			{
				line[k] = paper[j + x][k + y];
			}
		}
	}

	return papers;
}

void 색종이만들기()
{
	int N;//한 변의 길이 (2, 4, 8, 16, 32, 64, 128)

	cin >> N;

	vector<vector<bool>> wholePaper(N);

	//input;
	for (int i = 0; i < N; i++)
	{
		vector<bool>& line = wholePaper[i];
		line.resize(N);

		for (int j = 0; j < N; j++)
		{
			int b;
			cin >> b;
			line[j] = b;
		}
	}

	queue<vector<vector<bool>>> q;

	q.push(wholePaper);

	int white = 0;
	int blue = 0;

	while (!q.empty())
	{
		vector<vector<bool>> p = q.front();
		q.pop();

		if (!CheckClear(p))
		{
			auto papers = DividePaper(p);

			for (auto paper : papers)
				q.push(paper);
		}
		else
		{
			if (p[0][0] == 1)
				blue++;
			else
				white++;
		}
	}

	cout << white << "\n" << blue;
}

/*
	https://www.acmicpc.net/problem/15650
	문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

예제 입력 1
3 1
예제 출력 1
1
2
3
예제 입력 2
4 2
예제 출력 2
1 2
1 3
1 4
2 3
2 4
3 4
예제 입력 3
4 4
예제 출력 3
1 2 3 4

2 35

21분

2 56
3 00

50분

3 50

*/

void GetSequence(int start, int end, int depth, int depthLimit, vector<int> v, vector<vector<int>>& vs)
{
	for (int i = start; i <= end - depthLimit + depth; i++)
	{
		vector<int> temp = v;

		temp.push_back(i);

		if (temp.size() >= depthLimit)
			vs.push_back(temp);

		else
			GetSequence(i + 1, end, depth + 1, depthLimit, temp, vs);
	}
}

void N과M2()
{
	int N, M;//(1 <= M <= N <= 8)
	//m = length of sequence
	//n = 1~n
	cin >> N >> M;

	vector<vector<int>> v;

	GetSequence(1, N, 1, M, vector<int>(), v);

	/*for (int i = 0; i < N - 3; i++)
	{
		for (int j = i + 1; j < N - 2; j++)
		{
			for (int k = j + 1; k < N - 1; k++)
			{
				for (int l = k + 1; l < N; l++)
				{
					{i, j, k, l};
				}
			}
		}
	}*/


	for (auto a : v)
	{
		for (int n : a)
		{
			cout << n << " ";
		}
		cout << "\n";
	}

}

void Seq(int num, int upto, int cnt, vector<int>& v, int depth)
{
	if (cnt == depth)
	{
		for (int n : v)
			cout << n << " ";
		cout << "\n";
	}

	for (int i = num; i <= upto; i++)
	{
		v.push_back(i);

		Seq(i + 1, upto, cnt + 1, v, depth);

		v.pop_back();
	}
}

void N과M2다시()
{
	int N, M;//(1 <= M <= N <= 8)
	//m = length of sequence
	//n = 1~n
	cin >> N >> M;

	vector<int> v;
	Seq(1, N, 0, v, M);

}

/*
	https://www.acmicpc.net/problem/9663
	문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

예제 입력 1
8
예제 출력 1
92

10 51
11 26

*/

namespace NQ
{

	int N;//(1 ~ 15)

	vector<vector<bool>> board;

	int ret = 0;


	vector<pair<int, int>> Fill(int x, int y)
	{
		vector<pair<int, int>> ret = {};
		//아래
		for (int col = x, row = y; row < N; row++)
		{
			if (!board[row][col])
			{
				board[row][col] = true;
				ret.push_back(make_pair(row, col));
			}
		}


		//왼 대각
		for (int col = x, row = y; row < N && col >= 0; row++, col--)
		{
			if (!board[row][col])
			{
				board[row][col] = true;
				ret.push_back(make_pair(row, col));
			}
		}

		//우대각
		for (int col = x, row = y; row < N && col < N; row++, col++)
		{
			if (!board[row][col])
			{
				board[row][col] = true;
				ret.push_back(make_pair(row, col));
			}
		}

		return ret;
	}

	void Solution(int depth)
	{
		if (depth == N)
		{
			ret++;
			return;
		}

		for (int i = 0; i < N; i++)
		{
			vector<pair<int, int>> temp = {};
			if (!board[depth][i])
			{
				temp = Fill(i, depth);
			}
			else
				continue;

			Solution(depth + 1);


			for (auto t : temp)
			{
				board[t.first][t.second] = false;
			}
		}
	}


	void NQueen()
	{

		cin >> N;

		board.resize(N);

		for (int i = 0; i < N; i++)
			board[i].resize(N, false);

		Solution(0);

		cout << ret;

	}
}

/*
	https://www.acmicpc.net/problem/2579
	문제
계단 오르기 게임은 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임이다. <그림 1>과 같이 각각의 계단에는 일정한 점수가 쓰여 있는데 계단을 밟으면 그 계단에 쓰여 있는 점수를 얻게 된다.



<그림 1>

예를 들어 <그림 2>와 같이 시작점에서부터 첫 번째, 두 번째, 네 번째, 여섯 번째 계단을 밟아 도착점에 도달하면 총 점수는 10 + 20 + 25 + 20 = 75점이 된다.



<그림 2>

계단 오르는 데는 다음과 같은 규칙이 있다.

계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
마지막 도착 계단은 반드시 밟아야 한다.
따라서 첫 번째 계단을 밟고 이어 두 번째 계단이나, 세 번째 계단으로 오를 수 있다. 하지만, 첫 번째 계단을 밟고 이어 네 번째 계단으로 올라가거나, 첫 번째, 두 번째, 세 번째 계단을 연속해서 모두 밟을 수는 없다.

각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.

입력
입력의 첫째 줄에 계단의 개수가 주어진다.

둘째 줄부터 한 줄에 하나씩 제일 아래에 놓인 계단부터 순서대로 각 계단에 쓰여 있는 점수가 주어진다. 계단의 개수는 300이하의 자연수이고, 계단에 쓰여 있는 점수는 10,000이하의 자연수이다.

출력
첫째 줄에 계단 오르기 게임에서 얻을 수 있는 총 점수의 최댓값을 출력한다.

예제 입력 1
6
10
20
15
25
10
20
예제 출력 1
75

11 31

11 51(휴식)

13 00
13 26
*/

void 계단오르기()
{
	int N;//num of stairs
	cin >> N;

	vector<int> stairs(N);

	for (int i = 0; i < N; i++)
		cin >> stairs[i];

	vector<vector<int>> scoreBoard(N);//pair : first stair in row, second score

	for (int i = 0; i < N; i++)
		scoreBoard[i].resize(2);


	scoreBoard[0][0] = stairs[0];


	if (N > 1)
	{
		scoreBoard[1][0] = stairs[1];
		scoreBoard[1][1] = stairs[0] + stairs[1];
	}

	for (int i = 2; i < N; i++)
	{
		const vector<int>& before = scoreBoard[i - 1];

		scoreBoard[i][1] = before[0] + stairs[i];

		const vector<int>& beforeBefore = scoreBoard[i - 2];

		scoreBoard[i][0] = beforeBefore[0] > beforeBefore[1] ? beforeBefore[0] : beforeBefore[1];

		scoreBoard[i][0] += stairs[i];
	}

	cout << max(scoreBoard[N - 1][0], scoreBoard[N - 1][1]);

}

/*
	https://www.acmicpc.net/problem/1002
	문제
조규현과 백승환은 터렛에 근무하는 직원이다. 하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 다음은 조규현과 백승환의 사진이다.



이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.

조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고, 조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때, 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 이루어져 있다.

한 줄에 x1, y1, r1, x2, y2, r2가 주어진다. x1, y1, x2, y2는 -10,000보다 크거나 같고, 10,000보다 작거나 같은 정수이고, r1, r2는 10,000보다 작거나 같은 음이 아닌 정수이다.

출력
각 테스트 케이스마다 류재명이 있을 수 있는 위치의 수를 출력한다. 만약 류재명이 있을 수 있는 위치의 개수가 무한대일 경우에는 -1을 출력한다.

예제 입력 1
3
0 0 13 40 0 37
0 0 3 0 7 4
1 1 1 1 1 5
예제 출력 1
2
1
0

1 28
1 47
*/

void 터렛() 
{
	int T;//num of TestCase

	cin >> T;

	while (T--)
	{
		int x1, y1, r1, x2, y2, r2;

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;


		float distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

		float shrt = min(r1, r2);
		float lng = max(r1, r2);

		//동심원
		if (!distance)
		{
			if (shrt == lng)
				cout << "-1" << "\n";
			else
				cout << "0" << "\n";
		}
		else if (distance + shrt < lng)
			cout << "0" << "\n";
		else if (distance + shrt == lng)
			cout << "1" << "\n";
		else if (distance < shrt + lng)
			cout << "2" << "\n";
		else if (distance == shrt + lng)
			cout << "1" << "\n";
		else if (distance > shrt + lng)
			cout << "0" << "\n";

	}


}

/*
	https://www.acmicpc.net/problem/2798
	문제
카지노에서 제일 인기 있는 게임 블랙잭의 규칙은 상당히 쉽다. 카드의 합이 21을 넘지 않는 한도 내에서, 카드의 합을 최대한 크게 만드는 게임이다. 블랙잭은 카지노마다 다양한 규정이 있다.

한국 최고의 블랙잭 고수 김정인은 새로운 블랙잭 규칙을 만들어 상근, 창영이와 게임하려고 한다.

김정인 버전의 블랙잭에서 각 카드에는 양의 정수가 쓰여 있다. 그 다음, 딜러는 N장의 카드를 모두 숫자가 보이도록 바닥에 놓는다. 그런 후에 딜러는 숫자 M을 크게 외친다.

이제 플레이어는 제한된 시간 안에 N장의 카드 중에서 3장의 카드를 골라야 한다. 블랙잭 변형 게임이기 때문에, 플레이어가 고른 카드의 합은 M을 넘지 않으면서 M과 최대한 가깝게 만들어야 한다.

N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구해 출력하시오.

입력
첫째 줄에 카드의 개수 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000)이 주어진다. 둘째 줄에는 카드에 쓰여 있는 수가 주어지며, 이 값은 100,000을 넘지 않는 양의 정수이다.

합이 M을 넘지 않는 카드 3장을 찾을 수 있는 경우만 입력으로 주어진다.

출력
첫째 줄에 M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력한다.

예제 입력 1
5 21
5 6 7 8 9
예제 출력 1
21
예제 입력 2
10 500
93 181 245 214 315 36 185 138 216 295
예제 출력 2
497

2 07
2 27
*/

namespace blck
{
	int ret = 0;
	int addUp = 0;
	int N;//(3~100)
	int M;//(10~300000)
	vector<int> cards;

	void Solution(int index, int cardCount)
	{

		for (int i = index; i < N; i++)
		{
			addUp += cards[i];

			if (addUp > M)
			{
				addUp -= cards[i];
				continue;
			}
			else if (cardCount == 2 && addUp <= M)
			{
				ret = max(ret, addUp);
				addUp -= cards[i];
				return;
			}

			Solution(i + 1, cardCount + 1);

			addUp -= cards[i];
		}
	}
	
	void 블랙잭()
	{
		cin >> N >> M;
	
		cards.resize(N);
	
		for (int i = 0; i < N; i++)
			cin >> cards[i];
	
		sort(cards.begin(), cards.end(), greater<int>());
	
		Solution(0, 0);

		cout << ret;
	}
	

}

/*
	https://www.acmicpc.net/problem/2231
	문제
어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다. 어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다. 예를 들어, 245의 분해합은 256(=245+2+4+5)이 된다. 따라서 245는 256의 생성자가 된다. 물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다. 반대로, 생성자가 여러 개인 자연수도 있을 수 있다.

자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

출력
첫째 줄에 답을 출력한다. 생성자가 없는 경우에는 0을 출력한다.

예제 입력 1
216
예제 출력 1
198

2 29
2 42
*/

void 분해합() 
{
	int N;//1~1,000,000(백만)

	cin >> N;

	int len = log10(N) + 1;

	int ret = 0;

	for (int i = N - 9 * len; i <= N; i++)
	{
		int add = i;
		int temp = i;

		for (int j = 0; j < len; j++)
		{
			add += temp % 10;
			temp /= 10;
		}

		if (add == N)
		{
			ret = i;
			break;
		}
	}

	cout << ret;
}

/*
	https://www.acmicpc.net/problem/1541

	문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다.

예제 입력 1
55-50+40
예제 출력 1
-35
예제 입력 2
10+20+30+40
예제 출력 2
100
예제 입력 3
00009-00009
예제 출력 3
0

2 55
3 12

*/

void 잃어버린괄호() 
{
	string equation;

	cin >> equation;

	string temp = "";

	int ret = 0;

	int itemp = 0;

	char last = '0';

	for (int i = equation.length() - 1; i >= 0; i--)
	{
		char& a = equation[i];
		if (a != '+' && a != '-')
			temp = a + temp;
		else if (a == '-')
		{
			last = a;

			itemp += stoi(temp);
			temp.clear();
			
			ret -= itemp;
			itemp = 0;
		}
		else if (a == '+')
		{
			last = a;

			itemp += stoi(temp);
			temp.clear();
		}
	}

	if (last == '+')
		ret += itemp;

	ret += stoi(temp);

	cout << ret;
}

/*
	https://www.acmicpc.net/problem/11866
	문제
요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 1,000)

출력
예제와 같이 요세푸스 순열을 출력한다.

예제 입력 1
7 3
예제 출력 1
<3, 6, 2, 7, 5, 1, 4>

3 13
*/

void 요세푸스문제0() 
{
	int N, K;// (1 ≤ K ≤ N ≤ 1,000)

	cin >> N >> K;

	vector<bool> isDead(N, false);
	vector<int> rets;

	rets.reserve(N);
	
	int index = 0;
	int count = 0;

	while (true)
	{
		if (!isDead[index])
			count++;

		if (count == K)
		{
			count = 0;

			isDead[index] = true;
			rets.push_back(index + 1);

			if (rets.size() == N) break;
		}

		index = index + 1 >= N ? 0 : index + 1;


	}

	cout << "<";

	for (int i = 0; i < rets.size() - 1; i++)
		cout << rets[i] << ", ";

	cout << rets.back() << ">";
}

/*
	https://www.acmicpc.net/problem/1992
	문제
흑백 영상을 압축하여 표현하는 데이터 구조로 쿼드 트리(Quad Tree)라는 방법이 있다. 흰 점을 나타내는 0과 검은 점을 나타내는 1로만 이루어진 영상(2차원 배열)에서 같은 숫자의 점들이 한 곳에 많이 몰려있으면, 쿼드 트리에서는 이를 압축하여 간단히 표현할 수 있다.

주어진 영상이 모두 0으로만 되어 있으면 압축 결과는 "0"이 되고, 모두 1로만 되어 있으면 압축 결과는 "1"이 된다. 만약 0과 1이 섞여 있으면 전체를 한 번에 나타내지를 못하고, 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래, 이렇게 4개의 영상으로 나누어 압축하게 되며, 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표현한다



위 그림에서 왼쪽의 영상은 오른쪽의 배열과 같이 숫자로 주어지며, 이 영상을 쿼드 트리 구조를 이용하여 압축하면 "(0(0011)(0(0111)01)1)"로 표현된다. N ×N 크기의 영상이 주어질 때, 이 영상을 압축한 결과를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 영상의 크기를 나타내는 숫자 N 이 주어진다. N 은 언제나 2의 제곱수로 주어지며, 1 ≤ N ≤ 64의 범위를 가진다. 두 번째 줄부터는 길이 N의 문자열이 N개 들어온다. 각 문자열은 0 또는 1의 숫자로 이루어져 있으며, 영상의 각 점들을 나타낸다.

출력
영상을 압축한 결과를 출력한다.

예제 입력 1
8
11110000
11110000
00011100
00011100
11110000
11110000
11110011
11110011
예제 출력 1
((110(0101))(0010)1(0001))
*/

void 쿼드트리() {}

/*
	https://www.acmicpc.net/problem/11054
	문제
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

예제 입력 1
10
1 5 2 1 4 3 4 5 2 1
예제 출력 1
7
*/

void 가장긴바이토닉부분수열() {}

/*
	https://www.acmicpc.net/problem/2667
	문제
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.



입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

예제 입력 1
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
예제 출력 1
3
7
8
9
*/

void 단지번호붙이기() {}

/*
	https://www.acmicpc.net/problem/1753
	문제
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.

입력
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1 ≤ V ≤ 20,000, 1 ≤ E ≤ 300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 둘째 줄에는 시작 정점의 번호 K(1 ≤ K ≤ V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

출력
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.

예제 입력 1
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
예제 출력 1
0
2
3
7
INF
*/

void 최단경로() {}
