#include "pch.h"

/*
	https://www.acmicpc.net/problem/4949

	Date : 23.03.

	문제
	세계는 균형이 잘 잡혀있어야 한다. 양과 음, 빛과 어둠 그리고 왼쪽 괄호와 오른쪽 괄호처럼 말이다.

	정민이의 임무는 어떤 문자열이 주어졌을 때, 괄호들의 균형이 잘 맞춰져 있는지 판단하는 프로그램을 짜는 것이다.

	문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류이고, 문자열이 균형을 이루는 조건은 아래와 같다.

	모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
	모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
	모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
	모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
	짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
	정민이를 도와 문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지를 판단해보자.

	입력
	각 문자열은 마지막 글자를 제외하고 영문 알파벳, 공백, 소괄호("( )"), 대괄호("[ ]")로 이루어져 있으며, 온점(".")으로 끝나고, 길이는 100글자보다 작거나 같다.

	입력의 종료조건으로 맨 마지막에 온점 하나(".")가 들어온다.
	출력
	각 줄마다 해당 문자열이 균형을 이루고 있으면 "yes"를, 아니면 "no"를 출력한다.

	예제 입력 1
	So when I die (the [first] I will see in (heaven) is a score list).
	[ first in ] ( first out ).
	Half Moon tonight (At least it is better than no Moon at all].
	A rope may form )( a trail in a maze.
	Help( I[m being held prisoner in a fortune cookie factory)].
	([ (([( [ ] ) ( ) (( ))] )) ]).
	 .
	.
	예제 출력 1
	yes
	yes
	no
	no
	no
	yes
	yes
*/

#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <assert.h>

using namespace std;

bool CheckBalanced(const string& input)
{
	stack<char> stck;

	for (const char a : input)
	{
		switch (a)
		{
		case '(':
			stck.push('(');
			break;
		case '[':
			stck.push('[');
			break;
		case ')':
		{
			if (stck.empty()) return false;

			if (stck.top() == '(')
				stck.pop();
			else
				return false;
		}
			break;
		case ']' :
		{
			if (stck.empty()) return false;

			if (stck.top() == '[')
				stck.pop();
			else
				return false;
		}
			break;
		default:
			//assert(false);
			break;
		}
	}

	if (!stck.empty()) return false;

	return true;
}

void 균형잡힌세상()
{
	vector<string> rets;

	string buffer = {};
	while (getline(cin, buffer), buffer != ".")
	{
		if (CheckBalanced(buffer))
			rets.push_back("yes");
		else
			rets.push_back("no");
	}

	for (auto ret : rets)
		cout << ret << "\n";

}


/*
	https://www.acmicpc.net/problem/1874

	Date : 23.03.

	문제
	스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다. 스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.

	1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는 프로그램을 작성하라.

	입력
	첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다. 물론 같은 정수가 두 번 나오는 일은 없다.

	출력
	입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.

	예제 입력 1
	8
	4
	3
	6
	8
	7
	5
	2
	1
	예제 출력 1
	+
	+
	+
	+
	-
	-
	+
	+
	-
	+
	+
	-
	-
	-
	-
	-
	예제 입력 2
	5
	1
	2
	5
	3
	4
	예제 출력 2
	NO
*/
void 스택수열()
{
	int n;//(1~100000)
	//물론 같은 정수가 두 번 나오는 일은 없다.

	cin >> n;

	stack<int> origin;
	vector<int> answer(n);
	vector<char> ret;

	stack<int> stck;

	for (int i = 0; i < n; i++)
	{
		cin >> answer[i];
	}

	for (int i = n; i >= 1; i--)
	{
		origin.push(i);
	}

	int count = 0;

	while (true)
	{
		if (!stck.empty() && stck.top() == answer[count])
		{
			ret.push_back('-');

			stck.pop();
			count++;

			if (count == n)
			{

				for (auto r : ret)
				{
					cout << r << "\n";
				}
				break;
			}
		}
		else
		{
			if (origin.empty())
			{
				cout << "NO";
				break;
			}
			stck.push(origin.top());
			ret.push_back('+');
			origin.pop();
		}
	}

}
/*
	https://www.acmicpc.net/problem/1021

	Date : 23.03.

	문제
	지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다. 지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.

	지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.

	첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
	왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
	오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
	큐에 처음에 포함되어 있던 수 N이 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. (이 위치는 가장 처음 큐에서의 위치이다.) 이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

	입력
	첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다. N은 50보다 작거나 같은 자연수이고, M은 N보다 작거나 같은 자연수이다. 둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다. 위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.

	출력
	첫째 줄에 문제의 정답을 출력한다.

	예제 입력 1
	10 3
	1 2 3
	예제 출력 1
	0
	예제 입력 2
	10 3
	2 9 5
	예제 출력 2
	8
	예제 입력 3
	32 6
	27 16 30 11 6 23
	예제 출력 3
	59
	예제 입력 4
	10 10
	1 6 3 2 7 9 8 4 10 5
	예제 출력 4
	14
*/

class Node
{
public:
	Node(int data) : data(data) {}

	int data;

	Node* next;
	Node* before;
};

class CircleQueue
{
public:

	int OptimizedRotate(int find)
	{
		Node* temp = current;

		int countR = 0;

		while (temp->data != find)
		{
			temp = temp->next;
			countR++;
		}

		int countL = 0;

		temp = current;

		while (temp->data != find)
		{
			temp = temp->before;
			countL++;
		}

		if (countR <= countL)
		{
			for (int i = 0; i < countR; i++)
				RoatateR();
		}
		else
		{
			for (int i = 0; i < countL; i++)
				RoatateL();
		}

		return min(countL, countR);
	}


	void RoatateR()
	{
		tail = current;
		current = current->next;
	}

	void RoatateL()
	{
		current = tail;
		tail = tail->before;
	}

	void Push(Node* node)
	{
		if (!current)
		{
			current = node;
			tail = node;
		}


		node->before = tail;
		node->next = current;

		current->before = node;
		tail->next = node;
		tail = node;
	}

	void Pop()
	{
		Node* temp = current;
		//Node* next = current->next;
		Node* before = current->before;

		current = current->next;

		current->before = before;

		before->next = current;

		delete temp;
	}

	void Clear()
	{
		while (current)
		{
			Pop();
		}
	}

	Node* current = nullptr;

	//Node* head;
	Node* tail = nullptr;
};

void 회전하는큐()
{
	int N;//sizeofQueue(1 ~ 50)
	int M;//뽑아내려하는 갯수(M <+ N)

	cin >> N >> M;

	vector<int> locations(M);//(1 <= location <= N)

	for (int i = 0; i < M; i++)
	{
		cin >> locations[i];
	}

	CircleQueue q;

	for (int i = 0; i < N; i++)
	{
		q.Push(new Node(i + 1));
	}

	int ret = 0;

	for (int i = 0; i < M; i++)
	{
		ret += q.OptimizedRotate(locations[i]);

		q.Pop();
	}
	cout << ret;
}