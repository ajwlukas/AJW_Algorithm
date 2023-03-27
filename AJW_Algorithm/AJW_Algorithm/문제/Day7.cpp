#include "pch.h"

/*
	https://www.acmicpc.net/problem/1316
	����
	�׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�. ���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ����, kin�� k, i, n�� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������, aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴϴ�.

	�ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� �ܾ��� ���� N�� ���´�. N�� 100���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� �ܾ ���´�. �ܾ�� ���ĺ� �ҹ��ڷθ� �Ǿ��ְ� �ߺ����� ������, ���̴� �ִ� 100�̴�.

	���
	ù° �ٿ� �׷� �ܾ��� ������ ����Ѵ�.

	���� �Է� 1
	3
	happy
	new
	year
	���� ��� 1
	3
	���� �Է� 2
	4
	aba
	abab
	abcabc
	a
	���� ��� 2
	1
	���� �Է� 3
	5
	ab
	aa
	aca
	ba
	bb
	���� ��� 3
	4
	���� �Է� 4
	2
	yzyzy
	zyzyz
	���� ��� 4
	0
	���� �Է� 5
	1
	z
	���� ��� 5
	1

*/
void �׷�ܾ�üĿ()
{
	int N;//numofwords (1 ~ 100)

	cin >> N;

	string temp;

	getline(cin, temp);//���๮�ڰ� �����ִܴ�.

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

	����
	����̴� ���� �������忡�� ������ ����ϰ� �ִ�. ����̴� ���� �������Կ� ������ ��Ȯ�ϰ� Nų�α׷��� ����ؾ� �Ѵ�. �������忡�� ����� ������ ������ ����� �ִ�. ������ 3ų�α׷� ������ 5ų�α׷� ������ �ִ�.

	����̴� ������ ������, �ִ��� ���� ������ ��� ������ �Ѵ�. ���� ���, 18ų�α׷� ������ ����ؾ� �� ��, 3ų�α׷� ���� 6���� �������� ������, 5ų�α׷� 3���� 3ų�α׷� 1���� ����ϸ�, �� ���� ������ ������ ����� �� �ִ�.

	����̰� ������ ��Ȯ�ϰ� Nų�α׷� ����ؾ� �� ��, ���� �� ���� �������� �Ǵ��� �� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� N�� �־�����. (3 �� N �� 5000)

	���
	����̰� ����ϴ� ������ �ּ� ������ ����Ѵ�. ����, ��Ȯ�ϰ� Nų�α׷��� ���� �� ���ٸ� -1�� ����Ѵ�.

	���� �Է� 1
	18
	���� ��� 1
	4
	���� �Է� 2
	4
	���� ��� 2
	-1
	���� �Է� 3
	6
	���� ��� 3
	2
	���� �Է� 4
	9
	���� ��� 4
	3
	���� �Է� 5
	11
	���� ��� 5
	3
*/

void �������()
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

	����
	�����̴� � ����, ���� ���� �ٸ� �༺������ �η����� ��ư� �� �ִ� �̷��� ������ �Ͼ���. �׸��� �װ� ������� ���� ���� ���� ���� �� 23���� ���� ����, ���� �ֿ��� ASNA ���� ����簡 �Ǿ� ���ο� ���迡 ���� ���� ���� ������ ������ ��ٸ��� �ִ�.

	�װ� ž���ϰ� �� ���ּ��� Alpha Centauri��� ���ο� �η��� �����ڸ��� ��ô�ϱ� ���� ��Ը� ��Ȱ ���� �ý����� ž���ϰ� �ֱ� ������, �� ũ��� ������ ��û�� ������ �ֽű������ �� �����Ͽ� ������ �����̵� ��ġ�� ž���Ͽ���. ������ �� �����̵� ��ġ�� �̵� �Ÿ��� �ް��ϰ� �ø� ��� ��迡 �ɰ��� ������ �߻��ϴ� ������ �־, ���� �۵��ñ⿡ k������ �̵��Ͽ��� ���� k-1 , k Ȥ�� k+1 ���⸸�� �ٽ� �̵��� �� �ִ�. ���� ���, �� ��ġ�� ó�� �۵���ų ��� -1 , 0 , 1 ������ �̷л� �̵��� �� ������ ��ǻ� ���� Ȥ�� 0 �Ÿ���ŭ�� �̵��� �ǹ̰� �����Ƿ� 1 ������ �̵��� �� ������, �� �������� 0 , 1 , 2 ������ �̵��� �� �ִ� ���̴�. ( ���⼭ �ٽ� 2������ �̵��Ѵٸ� ���� �ñ⿣ 1, 2, 3 ������ �̵��� �� �ִ�. )



	������� �����̵� ��ġ �۵����� ������ �Ҹ� ũ�ٴ� ���� �� �˰� �ֱ� ������ x�������� y������ ���� �ּ����� �۵� Ƚ���� �̵��Ϸ� �Ѵ�. ������ y������ �����ؼ��� ���� �̵���ġ�� �������� ���Ͽ� y������ �����ϱ� �ٷ� ������ �̵��Ÿ��� �ݵ�� 1�������� �Ϸ� �Ѵ�.

	������� ���� x�������� ��Ȯ�� y�������� �̵��ϴµ� �ʿ��� ���� �̵� ��ġ �۵� Ƚ���� �ּڰ��� ���ϴ� ���α׷��� �ۼ��϶�.

	�Է�
	�Է��� ù �ٿ��� �׽�Ʈ���̽��� ���� T�� �־�����. ������ �׽�Ʈ ���̽��� ���� ���� ��ġ x �� ��ǥ ��ġ y �� ������ �־�����, x�� �׻� y���� ���� ���� ���´�. (0 �� x < y < 231)

	���
	�� �׽�Ʈ ���̽��� ���� x�������κ��� y�������� ��Ȯ�� �����ϴµ� �ʿ��� �ּ����� �����̵� ��ġ �۵� Ƚ���� ����Ѵ�.

	���� �Է� 1
	3
	0 3
	1 5
	45 50
	���� ��� 1
	3
	3
	4

	���� : 1 : 34
	�� : 1 : 57

	�ҿ�ð� : 23��
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

	����
����Ʈ�� ������ ������ �ڿ��� n�� ���Ͽ�, n���� ũ��, 2n���� �۰ų� ���� �Ҽ��� ��� �ϳ� �����Ѵٴ� ������ ��� �ִ�.

�� ������ ������ ����Ʈ���� 1845�⿡ �����߰�, ������Ƽ ü������� 1850�⿡ �����ߴ�.

���� ���, 10���� ũ��, 20���� �۰ų� ���� �Ҽ��� 4���� �ִ�. (11, 13, 17, 19) ��, 14���� ũ��, 28���� �۰ų� ���� �Ҽ��� 3���� �ִ�. (17,19, 23)

�ڿ��� n�� �־����� ��, n���� ũ��, 2n���� �۰ų� ���� �Ҽ��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�. �� ���̽��� n�� �����ϴ� �� �ٷ� �̷���� �ִ�.

�Է��� ���������� 0�� �־�����.

���
�� �׽�Ʈ ���̽��� ���ؼ�, n���� ũ��, 2n���� �۰ų� ���� �Ҽ��� ������ ����Ѵ�.

����
1 �� n �� 123,456
���� �Է� 1
1
10
13
100
1000
10000
100000
0
���� ��� 1
1
4
3
21
135
1033
8392

*/


void ����Ʈ������()
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

	����
666�� ������ ��Ÿ���� ����� �Ѵ�. ����, ���� ��Ϲ����� ��ȭ������ 666�� �� ������ ���� ����Ѵ�. ��ȭ���� ���� ������ ���� �̶�� �ø��� ��ȭ�� �����̴�. ���� ��ī���� ��Ÿ��� ���� ��, ��Ÿ���� 1, ��Ÿ���� 2, ��Ÿ���� 3, ��Ÿ���� 4, ��Ÿ���� 5, ��Ÿ���� 6�� ���� �̸��� ������, ���� �轼�� ������ ������ ���� ��, ������ ���� 1, ������ ���� 2, ������ ���� 3�� ���� ��ȭ ������ ������. ������ ���� �ڽ��� ���� ��ī���� ���� �轼�� �پ�Ѵ´ٴ� ���� �����ֱ� ���ؼ� ��ȭ ������ �� �ٸ��� ������ �ߴ�.

������ ���� � ���� 6�� ��� 3�� �̻� �������� ���� ���� ���Ѵ�. ���� ���� ������ ���� 666�̰�, �� �������� ū ���� 1666, 2666, 3666, .... �̴�. ����, ���� ù ��° ��ȭ�� ������ "������ ���� 666", �� ��° ��ȭ�� ������ "������ ���� 1666"�� ���� �̸��� ���� ���̴�. �Ϲ�ȭ�ؼ� �����ϸ�, N��° ��ȭ�� ������ ������ ���� (N��°�� ���� ������ ��) �� ����.

���� ���� N��° ��ȭ�� ���� �� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� �� �ø�� �׻� ���ʴ�� �����, �ٸ� ��ȭ�� ������ �ʴ´�.

�Է�
ù° �ٿ� N�� �־�����. N�� 10,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� N��° ��ȭ�� ���� �� ���� ����Ѵ�.

���� �Է� 1
2
���� ��� 1
1666
���� �Է� 2
3
���� ��� 2
2666
���� �Է� 3
6
���� ��� 3
5666
���� �Է� 4
187
���� ��� 4
66666
���� �Է� 5
500
���� ��� 5
166699


���� 2 : 10

�� 3 : 30
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

void ��ȭ������()
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

	����
��� ȣ�⸸ �����ϸ� ���� ����! �ƴѰ���?

������ ���� ����Լ� w(a, b, c)�� �ִ�.

if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
	1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
	w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
	w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
	w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
���� �Լ��� �����ϴ� ���� �ſ� ����. ������, �״�� �����ϸ� ���� ���ϴµ� �ſ� ���� �ð��� �ɸ���. (���� ���, a=15, b=15, c=15)

a, b, c�� �־����� ��, w(a, b, c)�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� �� ���� a, b, c�� �̷���� ������, �� �ٿ� �ϳ��� �־�����. �Է��� �������� -1 -1 -1�� ��Ÿ����, �� ������ ��� -1�� ���� �Է��� �������� �����ϸ� ����.

���
�Է����� �־��� ������ a, b, c�� ���ؼ�, w(a, b, c)�� ����Ѵ�.

����
-50 �� a, b, c �� 50
���� �Է� 1
1 1 1
2 2 2
10 4 6
50 50 50
-1 7 18
-1 -1 -1
���� ��� 1
w(1, 1, 1) = 2
w(2, 2, 2) = 4
w(10, 4, 6) = 523
w(50, 50, 50) = 1048576
w(-1, 7, 18) = 1

���� 1037
	 11 30
*/

//int coun = 0;

map<string, int> m;

int W(int a, int b, int c)
{
	string str = to_string(a) + "_" + to_string(b) + "_" + to_string(c);

	if (m.find(str) != m.end())
		return m[str];

	bool condition0 = a <= 0 || b <= 0 || c <= 0;//a,b,c �� �ϳ��� 0�̰ų� ������ �������
	bool condition1 = a > 20 || b > 20 || c > 20;//a,b,c �� �ϳ��� 20 �ʰ����
	bool condition2 = a < b&& b < c;//a, b, c ������ ���� �Ѵٸ�

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

void �ų����Լ�����()

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

	����
������ �׸��� ���� �ﰢ���� ���� ������� ������ �ִ�. ù �ﰢ���� ���ﰢ������ ���� ���̴� 1�̴�. �� �������� ������ ���� �������� ���ﰢ���� ��� �߰��Ѵ�. �������� ���� �� ���� ���̸� k�� ���� ��, �� ���� ���̰� k�� ���ﰢ���� �߰��Ѵ�.

�ĵ��� ���� P(N)�� ������ �ִ� ���ﰢ���� ���� �����̴�. P(1)���� P(10)���� ù 10�� ���ڴ� 1, 1, 1, 2, 2, 3, 4, 5, 7, 9�̴�.

N�� �־����� ��, P(N)�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, N�� �־�����. (1 �� N �� 100)

���
�� �׽�Ʈ ���̽����� P(N)�� ����Ѵ�.

���� �Է� 1
2
6
12
���� ��� 1
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

void �ĵ��ݼ���()
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

	����
RGB�Ÿ����� ���� N�� �ִ�. �Ÿ��� �������� ��Ÿ�� �� �ְ�, 1�� ������ N�� ���� ������� �ִ�.

���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ؾ� �Ѵ�. ������ ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �־����� ��, �Ʒ� ��Ģ�� �����ϸ鼭 ��� ���� ĥ�ϴ� ����� �ּڰ��� ���غ���.

1�� ���� ���� 2�� ���� ���� ���� �ʾƾ� �Ѵ�.
N�� ���� ���� N-1�� ���� ���� ���� �ʾƾ� �Ѵ�.
i(2 �� i �� N-1)�� ���� ���� i-1��, i+1�� ���� ���� ���� �ʾƾ� �Ѵ�.
�Է�
ù° �ٿ� ���� �� N(2 �� N �� 1,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� �� ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� 1�� ������ �� �ٿ� �ϳ��� �־�����. ���� ĥ�ϴ� ����� 1,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ��� ���� ĥ�ϴ� ����� �ּڰ��� ����Ѵ�.

���� �Է� 1
3
26 40 83
49 60 57
13 89 99
���� ��� 1
96
���� �Է� 2
3
1 100 100
100 1 100
100 100 1
���� ��� 2
3
���� �Է� 3
3
1 100 100
100 100 100
1 100 100
���� ��� 3
102
���� �Է� 4
6
30 19 5
64 77 64
15 19 97
4 71 57
90 86 84
93 32 91
���� ��� 4
208
���� �Է� 5
8
71 39 44
32 83 55
51 37 63
89 29 100
83 58 11
65 13 15
47 25 29
60 66 19
���� ��� 5
253

���� 2 22
�� 2 40
*/

void RGB�Ÿ�()
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
	����
			7
		  3   8
		8   1   0
	  2   7   4   4
	4   5   2   6   5
	�� �׸��� ũ�Ⱑ 5�� ���� �ﰢ���� �� ����̴�.

	�� ���� 7���� �����ؼ� �Ʒ��� �ִ� �� �� �ϳ��� �����Ͽ� �Ʒ������� ������ ��, �������� ���õ� ���� ���� �ִ밡 �Ǵ� ��θ� ���ϴ� ���α׷��� �ۼ��϶�. �Ʒ����� �ִ� ���� ���� ������ ���õ� ���� �밢�� ���� �Ǵ� �밢�� �����ʿ� �ִ� �� �߿����� ������ �� �ִ�.

	�ﰢ���� ũ��� 1 �̻� 500 �����̴�. �ﰢ���� �̷�� �ִ� �� ���� ��� �����̸�, ������ 0 �̻� 9999 �����̴�.

	�Է�
	ù° �ٿ� �ﰢ���� ũ�� n(1 �� n �� 500)�� �־�����, ��° �ٺ��� n+1��° �ٱ��� ���� �ﰢ���� �־�����.

	���
	ù° �ٿ� ���� �ִ밡 �Ǵ� ��ο� �ִ� ���� ���� ����Ѵ�.

	���� �Է� 1
	5
	7
	3 8
	8 1 0
	2 7 4 4
	4 5 2 6 5
	���� ��� 1
	30

	���� 2 45
	�� 2 58
*/

void �����ﰢ��()
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

	����
�ر԰� ������ �ִ� ������ �� N�����̰�, ������ ������ �ſ� ���� ������ �ִ�.

������ ������ ����ؼ� �� ��ġ�� ���� K�� ������� �Ѵ�. �̶� �ʿ��� ���� ������ �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� N �� 10, 1 �� K �� 100,000,000)

��° �ٺ��� N���� �ٿ� ������ ��ġ Ai�� ������������ �־�����. (1 �� Ai �� 1,000,000, A1 = 1, i �� 2�� ��쿡 Ai�� Ai-1�� ���)

���
ù° �ٿ� K���� ����µ� �ʿ��� ���� ������ �ּڰ��� ����Ѵ�.

���� �Է� 1
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
���� ��� 1
6
���� �Է� 2
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
���� ��� 2
12

3 19
3 26
*/


void ����0()
{
	int N, K;//(N = 1 ~ 10, K = 1 ~ 100,000,000)(��)

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

	����
�������࿡�� ATM�� 1��ۿ� ����. ���� �� ATM�տ� N���� ������� ���� ���ִ�. ����� 1������ N������ ��ȣ�� �Ű��� ������, i�� ����� ���� �����ϴµ� �ɸ��� �ð��� Pi���̴�.

������� ���� ���� ������ ����, ���� �����ϴµ� �ʿ��� �ð��� ���� �޶����� �ȴ�. ���� ���, �� 5���� �ְ�, P1 = 3, P2 = 1, P3 = 4, P4 = 3, P5 = 2 �� ��츦 �����غ���. [1, 2, 3, 4, 5] ������ ���� ���ٸ�, 1�� ����� 3�и��� ���� ���� �� �ִ�. 2�� ����� 1�� ����� ���� ���� �� ���� ��ٷ��� �ϱ� ������, 3+1 = 4���� �ɸ��� �ȴ�. 3�� ����� 1��, 2�� ����� ���� ���� ������ ��ٷ��� �ϱ� ������, �� 3+1+4 = 8���� �ʿ��ϰ� �ȴ�. 4�� ����� 3+1+4+3 = 11��, 5�� ����� 3+1+4+3+2 = 13���� �ɸ��� �ȴ�. �� ��쿡 �� ����� ���� �����ϴµ� �ʿ��� �ð��� ���� 3+4+8+11+13 = 39���� �ȴ�.

���� [2, 5, 1, 4, 3] ������ ���� ����, 2�� ����� 1�и���, 5�� ����� 1+2 = 3��, 1�� ����� 1+2+3 = 6��, 4�� ����� 1+2+3+3 = 9��, 3�� ����� 1+2+3+3+4 = 13���� �ɸ��� �ȴ�. �� ����� ���� �����ϴµ� �ʿ��� �ð��� ���� 1+3+6+9+13 = 32���̴�. �� ������� �� �ʿ��� �ð��� ���� �ּҷ� ���� ���� ����.

���� �� �ִ� ����� �� N�� �� ����� ���� �����ϴµ� �ɸ��� �ð� Pi�� �־����� ��, �� ����� ���� �����ϴµ� �ʿ��� �ð��� ���� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����� �� N(1 �� N �� 1,000)�� �־�����. ��° �ٿ��� �� ����� ���� �����ϴµ� �ɸ��� �ð� Pi�� �־�����. (1 �� Pi �� 1,000)

���
ù° �ٿ� �� ����� ���� �����ϴµ� �ʿ��� �ð��� ���� �ּڰ��� ����Ѵ�.

���� �Է� 1
5
3 1 4 3 2
���� ��� 1
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

	����
��� A�� N�� ��¥ ����� �Ƿ���, N�� A�� ����̰�, A�� 1�� N�� �ƴϾ�� �Ѵ�. � �� N�� ��¥ ����� ��� �־��� ��, N�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� ��¥ ����� ������ �־�����. �� ������ 50���� �۰ų� ���� �ڿ����̴�. ��° �ٿ��� N�� ��¥ ����� �־�����. 1,000,000���� �۰ų� ����, 2���� ũ�ų� ���� �ڿ����̰�, �ߺ����� �ʴ´�.

���
ù° �ٿ� N�� ����Ѵ�. N�� �׻� 32��Ʈ ��ȣ�ִ� ������ ǥ���� �� �ִ�.

���� �Է� 1
2
4 2
���� ��� 1
8
���� �Է� 2
1
2
���� ��� 2
4
���� �Է� 3
6
3 4 2 12 6 8
���� ��� 3
24
���� �Է� 4
14
14 26456 2 28 13228 3307 7 23149 8 6614 46298 56 4 92596
���� ��� 4
185192

 11 31
 11 36
*/

void ���()
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
����
�� ���� �ڿ����� �Է¹޾� �ִ� ������� �ּ� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �� ���� �ڿ����� �־�����. �� ���� 10,000������ �ڿ����̸� ���̿� �� ĭ�� ������ �־�����.

���
ù° �ٿ��� �Է����� �־��� �� ���� �ִ�������, ��° �ٿ��� �Է����� �־��� �� ���� �ּ� ������� ����Ѵ�.

���� �Է� 1
24 18
���� ��� 1
6
72

11 37
11 56
*/

void �ִ��������ּҰ����()
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

	����
�� �ڿ��� A�� B�� ���ؼ�, A�� ����̸鼭 B�� ����� �ڿ����� A�� B�� �������� �Ѵ�. �̷� ����� �߿��� ���� ���� ���� �ּҰ������� �Ѵ�. ���� ���, 6�� 15�� ������� 30, 60, 90���� ������, �ּ� ������� 30�̴�.

�� �ڿ��� A�� B�� �־����� ��, A�� B�� �ּҰ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����. ��° �ٺ��� T���� �ٿ� ���ļ� A�� B�� �־�����. (1 �� A, B �� 45,000)

���
ù° �ٺ��� T���� �ٿ� A�� B�� �ּҰ������ �Է¹��� ������� �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1
3
1 45000
6 10
13 17
���� ��� 1
45000
30
221

1 15
1 25
*/

void �ּҰ����()
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

	����
�ڿ���
\(N\)�� ����
\(K\)�� �־����� �� ���� ���
\(\binom{N}{K}\)�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ�
\(N\)��
\(K\)�� �־�����. (1 ��
\(N\) �� 10, 0 ��
\(K\) ��
\(N\))

���

\(\binom{N}{K}\)�� ����Ѵ�.

���� �Է� 1
5 2
���� ��� 1
10

1 27
1 34
*/

long long Factorial(long long n)
{
	if (n == 1 || n == 0) return 1;

	return n * Factorial(n - 1);
}

void ���װ��1()
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

	����
����̴� �� ������ ������ �Ǿ���. �� ���ÿ��� ���ø� ���ʰ� �������� ������ ū ������ ����� ���� �帣�� �ִ�. ������ ����̴� �ٸ��� ��� �ùε��� ���� �ǳʴµ� ū ������ �ް� ������ �˰� �ٸ��� ����� ����Ͽ���. �� �ֺ����� �ٸ��� ���⿡ ������ ���� ����Ʈ��� �Ѵ�. ����̴� �� �ֺ��� ����� ������ �� ��� ���� ���ʿ��� N���� ����Ʈ�� �ְ� ���ʿ��� M���� ����Ʈ�� �ִٴ� ���� �˾Ҵ�. (N �� M)

����̴� ������ ����Ʈ�� ������ ����Ʈ�� �ٸ��� �����Ϸ��� �Ѵ�. (�̶� �� ����Ʈ���� �ִ� �� ���� �ٸ��� ����� �� �ִ�.) ����̴� �ٸ��� �ִ��� ���� �������� �ϱ� ������ ������ ����Ʈ ������ŭ (N��) �ٸ��� �������� �Ѵ�. �ٸ������� ���� ������ �� ���ٰ� �� �� �ٸ��� ���� �� �ִ� ����� ���� ���ϴ� ���α׷��� �ۼ��϶�.



�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� ���� T�� �־�����. �� ���� �ٺ��� ������ �׽�Ʈ���̽��� ���� ���� ���ʰ� ���ʿ� �ִ� ����Ʈ�� ���� ���� N, M (0 < N �� M < 30)�� �־�����.

���
�� �׽�Ʈ ���̽��� ���� �־��� �����Ͽ� �ٸ��� ���� �� �ִ� ����� ���� ����Ѵ�.

���� �Է� 1
3
2 2
1 5
13 29
���� ��� 1
1
5
67863915

1 38
2 00

*/

void �ٸ�����()
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

	����
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� �ټ� �����̴�.

push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1
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
���� ��� 1
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
���� �Է� 2
7
pop
top
push 123
top
pop
top
pop
���� ��� 2
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

void ����()
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

	����
���ڴ� ���� ����̴� ���Ƹ� ȸ���� �غ��ϱ� ���ؼ� ��θ� �����ϴ� ���̴�.

�����̴� ����̸� ���ͼ� ���� �����ϴ� ���ε�, �ּ��ϰԵ� �׻� ���ž��� �����̴� ���� �Ǽ��� �߸� �θ��� ��� ġ�� �Ͼ�����.

�����̴� �߸��� ���� �θ� ������ 0�� ���ļ�, ���� �ֱٿ� ����̰� �� ���� ����� ��Ų��.

����̴� �̷��� ��� ���� �޾� ���� �� �� ���� ���� �˰� �;� �Ѵ�. ����̸� ��������!

�Է�
ù ��° �ٿ� ���� K�� �־�����. (1 �� K �� 100,000)

���� K���� �ٿ� ������ 1���� �־�����. ������ 0���� 1,000,000 ������ ���� ������, ������ "0" �� ��쿡�� ���� �ֱٿ� �� ���� �����, �ƴ� ��� �ش� ���� ����.

������ "0"�� ��쿡 ���� �� �ִ� ���� ������ ������ �� �ִ�.

���
����̰� ���������� ���� �� ���� ���� ����Ѵ�. ���������� ��� ���� ���� 231-1���� �۰ų� ���� �����̴�.

���� �Է� 1
4
3
0
4
0
���� ��� 1
0
���� �Է� 2
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
���� ��� 2
7

2 44
2 48
*/

void ����()
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

	����
��ȣ ���ڿ�(Parenthesis String, PS)�� �� ���� ��ȣ ��ȣ�� ��(�� �� ��)�� ������ �����Ǿ� �ִ� ���ڿ��̴�. �� �߿��� ��ȣ�� ����� �ٸ��� ������ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(Valid PS, VPS)�̶�� �θ���. �� ���� ��ȣ ��ȣ�� �� ��( )�� ���ڿ��� �⺻ VPS �̶�� �θ���. ���� x �� VPS ��� �̰��� �ϳ��� ��ȣ�� ���� ���ο� ���ڿ� ��(x)���� VPS �� �ȴ�. �׸��� �� VPS x �� y�� ����(concatenation)��Ų ���ο� ���ڿ� xy�� VPS �� �ȴ�. ���� ��� ��(())()���� ��((()))�� �� VPS ������ ��(()(��, ��(())()))�� , �׸��� ��(()�� �� ��� VPS �� �ƴ� ���ڿ��̴�.

�������� �Է����� �־��� ��ȣ ���ڿ��� VPS ���� �ƴ����� �Ǵ��ؼ� �� ����� YES �� NO �� ��Ÿ����� �Ѵ�.

�Է�
�Է� �����ʹ� ǥ�� �Է��� ����Ѵ�. �Է��� T���� �׽�Ʈ �����ͷ� �־�����. �Է��� ù ��° �ٿ��� �Է� �������� ���� ��Ÿ���� ���� T�� �־�����. �� �׽�Ʈ �������� ù° �ٿ��� ��ȣ ���ڿ��� �� �ٿ� �־�����. �ϳ��� ��ȣ ���ڿ��� ���̴� 2 �̻� 50 �����̴�.

���
����� ǥ�� ����� ����Ѵ�. ���� �Է� ��ȣ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(VPS)�̸� ��YES��, �ƴϸ� ��NO���� �� �ٿ� �ϳ��� ���ʴ�� ����ؾ� �Ѵ�.

���� �Է� 1
6
(())())
(((()())()
(()())((()))
((()()(()))(((())))()
()()()()(()()())()
(()((())()(
���� ��� 1
NO
NO
YES
NO
YES
NO
���� �Է� 2
3
((
))
())(()
���� ��� 2
NO
NO
NO

2 50

2 51 ~ 3 03 �޽�

3 03
3 09

*/

void ��ȣ()
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
	����
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 2,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1
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
���� ��� 1
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

void ť2()
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
	����
�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�.

�Է�
ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����. ���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. � �� ���� ���̿� ���� ���� ������ ���� �� �ִ�. �Է����� �־����� ������ ������̴�.

���
ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. V���� �湮�� ���� ������� ����ϸ� �ȴ�.

���� �Է� 1
4 5 1
1 2
1 3
1 4
2 4
3 4
���� ��� 1
1 2 4 3
1 2 3 4
���� �Է� 2
5 5 3
5 4
5 2
1 2
3 4
3 1
���� ��� 2
3 1 2 5 4
3 1 4 2 5
���� �Է� 3
1000 1 1000
999 1000
���� ��� 3
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

void DFS��BFS()
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


	����
���� ó���ϴ� ���� ����п��� ����� �߿��� ���̴�. ����п��� N���� ���� ��ǥ�ϴ� �⺻ ��谪���� ������ ���� �͵��� �ִ�. ��, N�� Ȧ����� ��������.

������ : N���� ������ ���� N���� ���� ��
�߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
�ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����
N���� ���� �־����� ��, �� ���� �⺻ ��谪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 500,000)�� �־�����. ��, N�� Ȧ���̴�. �� ���� N���� �ٿ��� �������� �־�����. �ԷµǴ� ������ ������ 4,000�� ���� �ʴ´�.

���
ù° �ٿ��� �������� ����Ѵ�. �Ҽ��� ���� ù° �ڸ����� �ݿø��� ���� ����Ѵ�.

��° �ٿ��� �߾Ӱ��� ����Ѵ�.

��° �ٿ��� �ֺ��� ����Ѵ�. ���� �� ���� ������ �ֺ� �� �� ��°�� ���� ���� ����Ѵ�.

��° �ٿ��� ������ ����Ѵ�.

���� �Է� 1
5
1
3
8
-2
2
���� ��� 1
2
2
1
10
���� �Է� 2
1
4000
���� ��� 2
4000
4000
4000
0
���� �Է� 3
5
-1
-2
-3
-1
-2
���� ��� 3
-2
-2
-1
2
���� �Է� 4
3
0
0
-1
���� ��� 4
0
0
0
1

11 16
11 55

*/

void �����()
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

	//������
	float a = round(total / (float)N);
	a = a == -0 ? 0 : a;

	cout << a << "\n";

	//�߾Ӱ�
	cout << numbers[N / 2] << "\n";

	//�ֺ�
	if (v.size() > 1)
		cout << v[1] << "\n";
	else
		cout << mostFrequent << "\n";

	//����
	cout << maximum - minimum;
}

/*
	https://www.acmicpc.net/problem/2630
	����
�Ʒ� <�׸� 1>�� ���� �������� ���簢��ĭ��� �̷���� ���簢�� ����� ���̰� �־��� �ְ�, �� ���簢������ �Ͼ������ ĥ���� �ְų� �Ķ������� ĥ���� �ִ�. �־��� ���̸� ������ ��Ģ�� ���� �߶� �پ��� ũ�⸦ ���� ���簢�� ����� �Ͼ�� �Ǵ� �Ķ��� �����̸� ������� �Ѵ�.



��ü ������ ũ�Ⱑ N��N(N=2k, k�� 1 �̻� 7 ������ �ڿ���) �̶�� ���̸� �ڸ��� ��Ģ�� ������ ����.

��ü ���̰� ��� ���� ������ ĥ���� ���� ������ ���ο� ���η� �߰� �κ��� �߶� <�׸� 2>�� I, II, III, IV�� ���� �Ȱ��� ũ���� �� ���� N/2 �� N/2�����̷� ������. �������� ���� I, II, III, IV ������ ���ؼ��� �տ����� ���������� ��� ���� ������ ĥ���� ���� ������ ���� ������� �Ȱ��� ũ���� �� ���� �����̷� ������. �̿� ���� ������ �߶��� ���̰� ��� �Ͼ�� �Ǵ� ��� �Ķ������� ĥ���� �ְų�, �ϳ��� ���簢�� ĭ�� �Ǿ� �� �̻� �ڸ� �� ���� ������ �ݺ��Ѵ�.

���� ���� ��Ģ�� ���� �߶��� �� <�׸� 3>�� <�׸� 1>�� ���̸� ó�� ���� ���� ���¸�, <�׸� 4>�� �� ��° ���� ���� ���¸�, <�׸� 5>�� ���������� ������� �پ��� ũ���� 9���� �Ͼ�� �����̿� 7���� �Ķ��� �����̸� �����ְ� �ִ�.



�Է����� �־��� ������ �� ���� ���� N�� �� ���簢��ĭ�� ��(�Ͼ�� �Ǵ� �Ķ���)�� �־��� �� �߶��� �Ͼ�� �����̿� �Ķ��� �������� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� ��ü ������ �� ���� ���� N�� �־��� �ִ�. N�� 2, 4, 8, 16, 32, 64, 128 �� �ϳ��̴�. �������� �� �������� ���簢��ĭ���� ���� ���ٺ��� ���ʷ� ��° �ٺ��� ������ �ٱ��� �־�����. �Ͼ������ ĥ���� ĭ�� 0, �Ķ������� ĥ���� ĭ�� 1�� �־�����, �� ���� ���̿��� ��ĭ�� �ϳ��� �ִ�.

���
ù° �ٿ��� �߶��� ���� �������� ������ ����ϰ�, ��° �ٿ��� �Ķ��� �������� ������ ����Ѵ�.

���� �Է� 1
8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
���� ��� 1
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

void �����̸����()
{
	int N;//�� ���� ���� (2, 4, 8, 16, 32, 64, 128)

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
	����
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
�� ������ ���������̾�� �Ѵ�.
�Է�
ù° �ٿ� �ڿ��� N�� M�� �־�����. (1 �� M �� N �� 8)

���
�� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�. �ߺ��Ǵ� ������ ���� �� ����ϸ� �ȵǸ�, �� ������ �������� �����ؼ� ����ؾ� �Ѵ�.

������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.

���� �Է� 1
3 1
���� ��� 1
1
2
3
���� �Է� 2
4 2
���� ��� 2
1 2
1 3
1 4
2 3
2 4
3 4
���� �Է� 3
4 4
���� ��� 3
1 2 3 4

2 35

21��

2 56
3 00

50��

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

void N��M2()
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

void N��M2�ٽ�()
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
	����
N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�.

N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (1 �� N < 15)

���
ù° �ٿ� �� N���� ���� ������ �� ���� ���� ����� ���� ����Ѵ�.

���� �Է� 1
8
���� ��� 1
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
		//�Ʒ�
		for (int col = x, row = y; row < N; row++)
		{
			if (!board[row][col])
			{
				board[row][col] = true;
				ret.push_back(make_pair(row, col));
			}
		}


		//�� �밢
		for (int col = x, row = y; row < N && col >= 0; row++, col--)
		{
			if (!board[row][col])
			{
				board[row][col] = true;
				ret.push_back(make_pair(row, col));
			}
		}

		//��밢
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
	����
��� ������ ������ ��� �Ʒ� ���������� ��� ����⿡ ��ġ�� ���������� ���� �����̴�. <�׸� 1>�� ���� ������ ��ܿ��� ������ ������ ���� �ִµ� ����� ������ �� ��ܿ� ���� �ִ� ������ ��� �ȴ�.



<�׸� 1>

���� ��� <�׸� 2>�� ���� �������������� ù ��°, �� ��°, �� ��°, ���� ��° ����� ��� �������� �����ϸ� �� ������ 10 + 20 + 25 + 20 = 75���� �ȴ�.



<�׸� 2>

��� ������ ���� ������ ���� ��Ģ�� �ִ�.

����� �� ���� �� ��ܾ� �Ǵ� �� ��ܾ� ���� �� �ִ�. ��, �� ����� �����鼭 �̾ ���� ����̳�, ���� ���� ������� ���� �� �ִ�.
���ӵ� �� ���� ����� ��� ��Ƽ��� �� �ȴ�. ��, �������� ��ܿ� ���Ե��� �ʴ´�.
������ ���� ����� �ݵ�� ��ƾ� �Ѵ�.
���� ù ��° ����� ��� �̾� �� ��° ����̳�, �� ��° ������� ���� �� �ִ�. ������, ù ��° ����� ��� �̾� �� ��° ������� �ö󰡰ų�, ù ��°, �� ��°, �� ��° ����� �����ؼ� ��� ���� ���� ����.

�� ��ܿ� ���� �ִ� ������ �־��� �� �� ���ӿ��� ���� �� �ִ� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ù° �ٿ� ����� ������ �־�����.

��° �ٺ��� �� �ٿ� �ϳ��� ���� �Ʒ��� ���� ��ܺ��� ������� �� ��ܿ� ���� �ִ� ������ �־�����. ����� ������ 300������ �ڿ����̰�, ��ܿ� ���� �ִ� ������ 10,000������ �ڿ����̴�.

���
ù° �ٿ� ��� ������ ���ӿ��� ���� �� �ִ� �� ������ �ִ��� ����Ѵ�.

���� �Է� 1
6
10
20
15
25
10
20
���� ��� 1
75

11 31

11 51(�޽�)

13 00
13 26
*/

void ��ܿ�����()
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
	����
�������� ���ȯ�� �ͷ��� �ٹ��ϴ� �����̴�. ������ ���� ���簨�� ��� �α����� �������� �ʴ´�. ������ �������� ���ȯ�� �����̴�.



�̼����� �������� ���ȯ���� ����� ����(�����)�� ��ġ�� ����϶�� ����� ���ȴ�. �������� ���ȯ�� ���� �ڽ��� �ͷ� ��ġ���� ���� �������� �Ÿ��� ����ߴ�.

�������� ��ǥ (x1, y1)�� ���ȯ�� ��ǥ (x2, y2)�� �־�����, �������� ����� �������� �Ÿ� r1�� ���ȯ�� ����� �������� �Ÿ� r2�� �־����� ��, ������� ���� �� �ִ� ��ǥ�� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ������ ���� �̷���� �ִ�.

�� �ٿ� x1, y1, r1, x2, y2, r2�� �־�����. x1, y1, x2, y2�� -10,000���� ũ�ų� ����, 10,000���� �۰ų� ���� �����̰�, r1, r2�� 10,000���� �۰ų� ���� ���� �ƴ� �����̴�.

���
�� �׽�Ʈ ���̽����� ������� ���� �� �ִ� ��ġ�� ���� ����Ѵ�. ���� ������� ���� �� �ִ� ��ġ�� ������ ���Ѵ��� ��쿡�� -1�� ����Ѵ�.

���� �Է� 1
3
0 0 13 40 0 37
0 0 3 0 7 4
1 1 1 1 1 5
���� ��� 1
2
1
0

1 28
1 47
*/

void �ͷ�() 
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

		//���ɿ�
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
	����
ī���뿡�� ���� �α� �ִ� ���� ������ ��Ģ�� ����� ����. ī���� ���� 21�� ���� �ʴ� �ѵ� ������, ī���� ���� �ִ��� ũ�� ����� �����̴�. ������ ī���븶�� �پ��� ������ �ִ�.

�ѱ� �ְ��� ���� ��� �������� ���ο� ���� ��Ģ�� ����� ���, â���̿� �����Ϸ��� �Ѵ�.

������ ������ ���迡�� �� ī�忡�� ���� ������ ���� �ִ�. �� ����, ������ N���� ī�带 ��� ���ڰ� ���̵��� �ٴڿ� ���´�. �׷� �Ŀ� ������ ���� M�� ũ�� ��ģ��.

���� �÷��̾�� ���ѵ� �ð� �ȿ� N���� ī�� �߿��� 3���� ī�带 ���� �Ѵ�. ���� ���� �����̱� ������, �÷��̾ �� ī���� ���� M�� ���� �����鼭 M�� �ִ��� ������ ������ �Ѵ�.

N���� ī�忡 ���� �ִ� ���ڰ� �־����� ��, M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ���� ���� ����Ͻÿ�.

�Է�
ù° �ٿ� ī���� ���� N(3 �� N �� 100)�� M(10 �� M �� 300,000)�� �־�����. ��° �ٿ��� ī�忡 ���� �ִ� ���� �־�����, �� ���� 100,000�� ���� �ʴ� ���� �����̴�.

���� M�� ���� �ʴ� ī�� 3���� ã�� �� �ִ� ��츸 �Է����� �־�����.

���
ù° �ٿ� M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ���� ����Ѵ�.

���� �Է� 1
5 21
5 6 7 8 9
���� ��� 1
21
���� �Է� 2
10 500
93 181 245 214 315 36 185 138 216 295
���� ��� 2
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
	
	void ����()
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
	����
� �ڿ��� N�� ���� ��, �� �ڿ��� N�� �������� N�� N�� �̷�� �� �ڸ����� ���� �ǹ��Ѵ�. � �ڿ��� M�� �������� N�� ���, M�� N�� �����ڶ� �Ѵ�. ���� ���, 245�� �������� 256(=245+2+4+5)�� �ȴ�. ���� 245�� 256�� �����ڰ� �ȴ�. ����, � �ڿ����� ��쿡�� �����ڰ� ���� ���� �ִ�. �ݴ��, �����ڰ� ���� ���� �ڿ����� ���� �� �ִ�.

�ڿ��� N�� �־����� ��, N�� ���� ���� �����ڸ� ���س��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� N(1 �� N �� 1,000,000)�� �־�����.

���
ù° �ٿ� ���� ����Ѵ�. �����ڰ� ���� ��쿡�� 0�� ����Ѵ�.

���� �Է� 1
216
���� ��� 1
198

2 29
2 42
*/

void ������() 
{
	int N;//1~1,000,000(�鸸)

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

	����
�����̴� ����� +, -, �׸��� ��ȣ�� ������ ���� �������. �׸��� ���� �����̴� ��ȣ�� ��� ������.

�׸��� ���� �����̴� ��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ������� �Ѵ�.

��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ����� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� �־�����. ���� ��0��~��9��, ��+��, �׸��� ��-�������� �̷���� �ְ�, ���� ó���� ������ ���ڴ� �����̴�. �׸��� �����ؼ� �� �� �̻��� �����ڰ� ��Ÿ���� �ʰ�, 5�ڸ����� ���� ���ӵǴ� ���ڴ� ����. ���� 0���� ������ �� �ִ�. �Է����� �־����� ���� ���̴� 50���� �۰ų� ����.

���
ù° �ٿ� ������ ����Ѵ�.

���� �Է� 1
55-50+40
���� ��� 1
-35
���� �Է� 2
10+20+30+40
���� ��� 2
100
���� �Է� 3
00009-00009
���� ��� 3
0

2 55
3 12

*/

void �Ҿ������ȣ() 
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
	����
�似Ǫ�� ������ ������ ����.

1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, ���� ���� K(�� N)�� �־�����. ���� ������� K��° ����� �����Ѵ�. �� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������. �� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�. ������ ������� ���ŵǴ� ������ (N, K)-�似Ǫ�� �����̶�� �Ѵ�. ���� ��� (7, 3)-�似Ǫ�� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.

N�� K�� �־����� (N, K)-�似Ǫ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �� ĭ�� ���̿� �ΰ� ������� �־�����. (1 �� K �� N �� 1,000)

���
������ ���� �似Ǫ�� ������ ����Ѵ�.

���� �Է� 1
7 3
���� ��� 1
<3, 6, 2, 7, 5, 1, 4>

3 13
*/

void �似Ǫ������0() 
{
	int N, K;// (1 �� K �� N �� 1,000)

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
	����
��� ������ �����Ͽ� ǥ���ϴ� ������ ������ ���� Ʈ��(Quad Tree)��� ����� �ִ�. �� ���� ��Ÿ���� 0�� ���� ���� ��Ÿ���� 1�θ� �̷���� ����(2���� �迭)���� ���� ������ ������ �� ���� ���� ����������, ���� Ʈ�������� �̸� �����Ͽ� ������ ǥ���� �� �ִ�.

�־��� ������ ��� 0���θ� �Ǿ� ������ ���� ����� "0"�� �ǰ�, ��� 1�θ� �Ǿ� ������ ���� ����� "1"�� �ȴ�. ���� 0�� 1�� ���� ������ ��ü�� �� ���� ��Ÿ������ ���ϰ�, ���� ��, ������ ��, ���� �Ʒ�, ������ �Ʒ�, �̷��� 4���� �������� ������ �����ϰ� �Ǹ�, �� 4���� ������ ������ ����� ���ʴ�� ��ȣ �ȿ� ��� ǥ���Ѵ�



�� �׸����� ������ ������ �������� �迭�� ���� ���ڷ� �־�����, �� ������ ���� Ʈ�� ������ �̿��Ͽ� �����ϸ� "(0(0011)(0(0111)01)1)"�� ǥ���ȴ�. N ��N ũ���� ������ �־��� ��, �� ������ ������ ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� ������ ũ�⸦ ��Ÿ���� ���� N �� �־�����. N �� ������ 2�� �������� �־�����, 1 �� N �� 64�� ������ ������. �� ��° �ٺ��ʹ� ���� N�� ���ڿ��� N�� ���´�. �� ���ڿ��� 0 �Ǵ� 1�� ���ڷ� �̷���� ������, ������ �� ������ ��Ÿ����.

���
������ ������ ����� ����Ѵ�.

���� �Է� 1
8
11110000
11110000
00011100
00011100
11110000
11110000
11110011
11110011
���� ��� 1
((110(0101))(0010)1(0001))
*/

void ����Ʈ��() {}

/*
	https://www.acmicpc.net/problem/11054
	����
���� S�� � �� Sk�� �������� S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN�� �����Ѵٸ�, �� ������ ������� �����̶�� �Ѵ�.

���� ���, {10, 20, 30, 25, 20}�� {10, 20, 30, 40}, {50, 40, 25, 10} �� ������� ����������,  {1, 2, 3, 2, 1, 2, 3, 2, 1}�� {10, 20, 30, 40, 20, 30} �� ������� ������ �ƴϴ�.

���� A�� �־����� ��, �� ������ �κ� ���� �� ������� �����̸鼭 ���� �� ������ ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� A�� ũ�� N�� �־�����, ��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� N �� 1,000, 1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� �κ� ���� �߿��� ���� �� ������� ������ ���̸� ����Ѵ�.

���� �Է� 1
10
1 5 2 1 4 3 4 5 2 1
���� ��� 1
7
*/

void ����������кκм���() {}

/*
	https://www.acmicpc.net/problem/2667
	����
<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����. ö���� �� ������ ������ ����� ���� ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�. ���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�. �밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. <�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�. ������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�, �� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.

���
ù ��° �ٿ��� �� �������� ����Ͻÿ�. �׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.

���� �Է� 1
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
���� ��� 1
3
7
8
9
*/

void ������ȣ���̱�() {}

/*
	https://www.acmicpc.net/problem/1753
	����
����׷����� �־����� �־��� ���������� �ٸ� ��� ���������� �ִ� ��θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, ��� ������ ����ġ�� 10 ������ �ڿ����̴�.

�Է�
ù° �ٿ� ������ ���� V�� ������ ���� E�� �־�����. (1 �� V �� 20,000, 1 �� E �� 300,000) ��� �������� 1���� V���� ��ȣ�� �Ű��� �ִٰ� �����Ѵ�. ��° �ٿ��� ���� ������ ��ȣ K(1 �� K �� V)�� �־�����. ��° �ٺ��� E���� �ٿ� ���� �� ������ ��Ÿ���� �� ���� ���� (u, v, w)�� ������� �־�����. �̴� u���� v�� ���� ����ġ w�� ������ �����Ѵٴ� ���̴�. u�� v�� ���� �ٸ��� w�� 10 ������ �ڿ����̴�. ���� �ٸ� �� ���� ���̿� ���� ���� ������ ������ ���� ������ �����Ѵ�.

���
ù° �ٺ��� V���� �ٿ� ����, i��° �ٿ� i�� ���������� �ִ� ����� ��ΰ��� ����Ѵ�. ������ �ڽ��� 0���� ����ϰ�, ��ΰ� �������� �ʴ� ��쿡�� INF�� ����ϸ� �ȴ�.

���� �Է� 1
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
���� ��� 1
0
2
3
7
INF
*/

void �ִܰ��() {}
