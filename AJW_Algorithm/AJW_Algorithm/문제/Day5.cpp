#include "pch.h"

/*
	https://www.acmicpc.net/problem/4949

	Date : 23.03.

	����
	����� ������ �� �����־�� �Ѵ�. ��� ��, ���� ��� �׸��� ���� ��ȣ�� ������ ��ȣó�� ���̴�.

	�������� �ӹ��� � ���ڿ��� �־����� ��, ��ȣ���� ������ �� ������ �ִ��� �Ǵ��ϴ� ���α׷��� ¥�� ���̴�.

	���ڿ��� ���ԵǴ� ��ȣ�� �Ұ�ȣ("()") �� ���ȣ("[]")�� 2�����̰�, ���ڿ��� ������ �̷�� ������ �Ʒ��� ����.

	��� ���� �Ұ�ȣ("(")�� ������ �Ұ�ȣ(")")�͸� ¦�� �̷�� �Ѵ�.
	��� ���� ���ȣ("[")�� ������ ���ȣ("]")�͸� ¦�� �̷�� �Ѵ�.
	��� ������ ��ȣ���� �ڽŰ� ¦�� �̷� �� �ִ� ���� ��ȣ�� �����Ѵ�.
	��� ��ȣ���� ¦�� 1:1 ��Ī�� �����ϴ�. ��, ��ȣ �ϳ��� �� �̻��� ��ȣ�� ¦�������� �ʴ´�.
	¦�� �̷�� �� ��ȣ�� ���� ��, �� ���̿� �ִ� ���ڿ��� ������ ������ �Ѵ�.
	�����̸� ���� ���ڿ��� �־����� �� �������� ���ڿ����� �ƴ����� �Ǵ��غ���.

	�Է�
	�� ���ڿ��� ������ ���ڸ� �����ϰ� ���� ���ĺ�, ����, �Ұ�ȣ("( )"), ���ȣ("[ ]")�� �̷���� ������, ����(".")���� ������, ���̴� 100���ں��� �۰ų� ����.

	�Է��� ������������ �� �������� ���� �ϳ�(".")�� ���´�.
	���
	�� �ٸ��� �ش� ���ڿ��� ������ �̷�� ������ "yes"��, �ƴϸ� "no"�� ����Ѵ�.

	���� �Է� 1
	So when I die (the [first] I will see in (heaven) is a score list).
	[ first in ] ( first out ).
	Half Moon tonight (At least it is better than no Moon at all].
	A rope may form )( a trail in a maze.
	Help( I[m being held prisoner in a fortune cookie factory)].
	([ (([( [ ] ) ( ) (( ))] )) ]).
	 .
	.
	���� ��� 1
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

void ������������()
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

	����
	���� (stack)�� �⺻���� �ڷᱸ�� �� �ϳ���, ��ǻ�� ���α׷��� �ۼ��� �� ���� �̿�Ǵ� �����̴�. ������ �ڷḦ �ִ� (push) �Ա��� �ڷḦ �̴� (pop) �Ա��� ���� ���� ���߿� �� �ڷᰡ ���� ���� ������ (LIFO, Last in First out) Ư���� ������ �ִ�.

	1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν�, �ϳ��� ������ ���� �� �ִ�. �̶�, ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ű���� �Ѵٰ� ����. ������ ������ �־����� �� ������ �̿��� �� ������ ���� �� �ִ��� ������, �ִٸ� � ������ push�� pop ������ �����ؾ� �ϴ����� �˾Ƴ� �� �ִ�. �̸� ����ϴ� ���α׷��� �ۼ��϶�.

	�Է�
	ù �ٿ� n (1 �� n �� 100,000)�� �־�����. ��° �ٺ��� n���� �ٿ��� ������ �̷�� 1�̻� n������ ������ �ϳ��� ������� �־�����. ���� ���� ������ �� �� ������ ���� ����.

	���
	�Էµ� ������ ����� ���� �ʿ��� ������ �� �ٿ� �� ���� ����Ѵ�. push������ +��, pop ������ -�� ǥ���ϵ��� �Ѵ�. �Ұ����� ��� NO�� ����Ѵ�.

	���� �Է� 1
	8
	4
	3
	6
	8
	7
	5
	2
	1
	���� ��� 1
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
	���� �Է� 2
	5
	1
	2
	5
	3
	4
	���� ��� 2
	NO
*/
void ���ü���()
{
	int n;//(1~100000)
	//���� ���� ������ �� �� ������ ���� ����.

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

	����
	�����̴� N���� ���Ҹ� �����ϰ� �ִ� ����� ��ȯ ť�� ������ �ִ�. �����̴� �� ť���� �� ���� ���Ҹ� �̾Ƴ����� �Ѵ�.

	�����̴� �� ť���� ������ ���� 3���� ������ ������ �� �ִ�.

	ù ��° ���Ҹ� �̾Ƴ���. �� ������ �����ϸ�, ���� ť�� ���Ұ� a1, ..., ak�̾��� ���� a2, ..., ak�� ���� �ȴ�.
	�������� �� ĭ �̵���Ų��. �� ������ �����ϸ�, a1, ..., ak�� a2, ..., ak, a1�� �ȴ�.
	���������� �� ĭ �̵���Ų��. �� ������ �����ϸ�, a1, ..., ak�� ak, a1, ..., ak-1�� �ȴ�.
	ť�� ó���� ���ԵǾ� �ִ� �� N�� �־�����. �׸��� �����̰� �̾Ƴ����� �ϴ� ������ ��ġ�� �־�����. (�� ��ġ�� ���� ó�� ť������ ��ġ�̴�.) �̶�, �� ���Ҹ� �־��� ������� �̾Ƴ��µ� ��� 2��, 3�� ������ �ּڰ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� ť�� ũ�� N�� �̾Ƴ����� �ϴ� ���� ���� M�� �־�����. N�� 50���� �۰ų� ���� �ڿ����̰�, M�� N���� �۰ų� ���� �ڿ����̴�. ��° �ٿ��� �����̰� �̾Ƴ����� �ϴ� ���� ��ġ�� ������� �־�����. ��ġ�� 1���� ũ�ų� ����, N���� �۰ų� ���� �ڿ����̴�.

	���
	ù° �ٿ� ������ ������ ����Ѵ�.

	���� �Է� 1
	10 3
	1 2 3
	���� ��� 1
	0
	���� �Է� 2
	10 3
	2 9 5
	���� ��� 2
	8
	���� �Է� 3
	32 6
	27 16 30 11 6 23
	���� ��� 3
	59
	���� �Է� 4
	10 10
	1 6 3 2 7 9 8 4 10 5
	���� ��� 4
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

void ȸ���ϴ�ť()
{
	int N;//sizeofQueue(1 ~ 50)
	int M;//�̾Ƴ����ϴ� ����(M <+ N)

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