#include "pch.h"

/*
	https://www.acmicpc.net/problem/2606

	Date : 23.03.13

	문제
	신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

	예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.



	어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

	입력
	첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

	출력
	1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

	예제 입력 1
	7
	6
	1 2
	2 3
	1 5
	5 2
	5 6
	4 7
	예제 출력 1
	4
*/

#include <vector>
#include <set>

using namespace std;

class Com
{
public:
	Com(int serialNum) : serialNum(serialNum) {}

	void Connect(Com* other)
	{
		connects.insert(other);
		other->connects.insert(this);
	}

	void GetAllConnectees(set<int>& input)
	{
		if (input.find(serialNum) != input.end()) return;

		input.insert(serialNum);

		for (auto connect : connects)
			connect->GetAllConnectees(input);
	}

	int serialNum;
	set<Com*> connects;
};

void 바이러스()
{
	int comNum;//num of Computers( <= 100)
	int pairNum;//num of Connections;

	cin >> comNum >> pairNum;

	vector<Com*> coms(comNum);

	set<int> group;//connected with com1

	for (int i = 0; i < comNum; i++)
	{
		coms[i] = new Com(i);
	}

	int A, B;
	//connect
	for (int i = 0; i < pairNum; i++)
	{
		cin >> A >> B;

		int a = A - 1;
		int b = B - 1;

		coms[a]->Connect(coms[b]);
	}

	coms[0]->GetAllConnectees(group);

	cout << group.size() - 1;



	for (auto com : coms)
	{
		delete com;
	}
}

/*
	https://www.acmicpc.net/problem/7576

	Date : 23.03.13

	문제
	철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.



	창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

	토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

	입력
	첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

	토마토가 하나 이상 있는 경우만 입력으로 주어진다.

	출력
	여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.

	예제 입력 1
	6 4
	0 0 0 0 0 0
	0 0 0 0 0 0
	0 0 0 0 0 0
	0 0 0 0 0 1
	예제 출력 1
	8
	예제 입력 2
	6 4
	0 -1 0 0 0 0
	-1 0 0 0 0 0
	0 0 0 0 0 0
	0 0 0 0 0 1
	예제 출력 2
	-1
	예제 입력 3
	6 4
	1 -1 0 0 0 0
	0 -1 0 0 0 0
	0 0 0 0 -1 0
	0 0 0 0 -1 1
	예제 출력 3
	6
	예제 입력 4
	5 5
	-1 1 0 0 0
	0 -1 -1 -1 0
	0 -1 -1 -1 0
	0 -1 -1 -1 0
	0 0 0 0 0
	예제 출력 4
	14
	예제 입력 5
	2 2
	1 -1
	-1 1
	예제 출력 5
	0
*/

void 토마토()
{
	int M, N;
	cin >> M >> N;

	int whole = M * N;

	vector<vector<int>> tomatoes(N);//row

	vector<pair<int, int>> ripens;

	for (auto& t : tomatoes)
		t.resize(M);

	int ripenCount = 0;
	int day = 0;

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			int t = 0;
			cin >> t;

			tomatoes[row][col] = t;

			if (t == 1)
			{
				ripens.push_back(make_pair(row, col));
				ripenCount++;
			}
			else if (t == -1)
			{
				whole--;
			}
		}
	}

	vector<pair<int, int>> newRipens = {};
	while (true)
	{
		for (auto r : ripens)
		{
			int row = r.first;
			int col = r.second;

			int left = col - 1;
			int right = col + 1;
			int up = row - 1;
			int down = row + 1;

			if (left >= 0)
			{
				int& state = tomatoes[row][left];

				if (state == 0)
				{
					state = 1;
					newRipens.push_back(make_pair(row, left));
					ripenCount++;
				}
			}
			if (right <= M - 1)
			{
				int& state = tomatoes[row][right];

				if (state == 0)
				{
					state = 1;
					newRipens.push_back(make_pair(row, right));
					ripenCount++;
				}
			}
			if (up >= 0)
			{
				int& state = tomatoes[up][col];

				if (state == 0)
				{
					state = 1;
					newRipens.push_back(make_pair(up, col));
					ripenCount++;
				}
			}
			if (down <= N - 1)
			{
				int& state = tomatoes[down][col];

				if (state == 0)
				{
					state = 1;
					newRipens.push_back(make_pair(down, col));
					ripenCount++;
				}
			}
		}
		if (newRipens.empty())
		{
			if (ripenCount < whole)
				day = -1;
			break;
		}

		day++;
		ripens = newRipens;
		newRipens.clear();
	}

	cout << day;

}

/*
	https://www.acmicpc.net/problem/1003

	Date : 23.03.13

	문제
	다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.

	int fibonacci(int n) {
		if (n == 0) {
			printf("0");
			return 0;
		} else if (n == 1) {
			printf("1");
			return 1;
		} else {
			return fibonacci(n‐1) + fibonacci(n‐2);
		}
	}
	fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.

	fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
	fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
	두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
	fibonacci(0)은 0을 출력하고, 0을 리턴한다.
	fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
	첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
	fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
	1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 테스트 케이스의 개수 T가 주어진다.

	각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

	출력
	각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.

	예제 입력 1
	3
	0
	1
	3
	예제 출력 1
	1 0
	0 1
	1 2
	예제 입력 2
	2
	6
	22
	예제 출력 2
	5 8
	10946 17711
*/

int fibonacci(vector<int>& fibonnaccis, int n)
{
	if (fibonnaccis[n] != -1) return fibonnaccis[n];

	fibonnaccis[n] = fibonacci(fibonnaccis, n - 1) + fibonacci(fibonnaccis, n - 2);
	return fibonnaccis[n];
}

void 피보나치함수()
{
	//호출횟수		0	1
	//f(0)			1	0
	//f(1)			0	1
	//f(2)			1	1 == f(0) + f(1)
	//f(3)			1	2 == f(1) + f(2)
	//f(4)			2	3 == f(2) + f(3)
	//f(5)			3	5 == f(4) + f(5)

	//An = An-1 + An-2

	int T;//num of testCases

	cin >> T;

	vector<int> cases(T);

	int max = 1;
	for (int i = 0; i < T; i++)
	{
		int temp;
		cin >> temp;
		cases[i] = temp;

		max = max > temp ? max : temp;
	}

	vector<int> fibonnaccis(max + 1, -1);

	fibonnaccis[0] = 0;
	fibonnaccis[1] = 1;


	fibonacci(fibonnaccis, max);

	for (auto c : cases)
	{
		int zero = 0;
		if (c >= 1)
			zero = fibonnaccis[c - 1];
		else
			zero = 1;
		int one = fibonnaccis[c];

		cout << zero << " " << one << "\n";
	}

}

/*
	https://www.acmicpc.net/problem/11053

	Date : 23.03.13

	문제
	수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

	예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

	입력
	첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

	둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

	출력
	첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

	예제 입력 1
	6
	10 20 10 30 20 50
	예제 출력 1
	4
*/


#include <map>

void 가장긴증가하는부분수열()
{
	int N;//sizeof수열

	cin >> N;

	int temp;

	vector<int> v;

	cin >> temp;
	N--;

	v.push_back(temp);

	while (N--)
	{
		cin >> temp;

		if (temp > v.back())
			v.push_back(temp);
		else
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] >= temp)
				{
					v[i] = temp;
					break;
				}
			}
		}
	}

	cout << v.size();

}

/*
	10
	900
	10
	50
	20
	1
	2
	3
	90
	5
	6
*/