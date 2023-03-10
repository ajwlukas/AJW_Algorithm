#include "pch.h"


/*
	https://www.acmicpc.net/problem/11729

	Date : 23.03.13

	문제
	세 개의 장대가 있고 첫 번째 장대에는 반경이 서로 다른 n개의 원판이 쌓여 있다. 각 원판은 반경이 큰 순서대로 쌓여있다. 이제 수도승들이 다음 규칙에 따라 첫 번째 장대에서 세 번째 장대로 옮기려 한다.

	한 번에 한 개의 원판만을 다른 탑으로 옮길 수 있다.
	쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다.
	이 작업을 수행하는데 필요한 이동 순서를 출력하는 프로그램을 작성하라. 단, 이동 횟수는 최소가 되어야 한다.

	아래 그림은 원판이 5개인 경우의 예시이다.



	입력
	첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 20)이 주어진다.

	출력
	첫째 줄에 옮긴 횟수 K를 출력한다.

	두 번째 줄부터 수행 과정을 출력한다. 두 번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 빈칸을 사이에 두고 출력하는데, 이는 A번째 탑의 가장 위에 있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻이다.

	예제 입력 1 
	3
	예제 출력 1 
	7
	1 3
	1 2
	3 2
	1 3
	2 1
	2 3
	1 3
*/

#include <iostream>

using namespace std;


void Move(int num, int from, int temp, int dest)
{
	if (num == 0) return;

	if (num == 1)
	{
		cout << from << " " << dest << "\n";
		
		return;
	}

	Move(num - 1, from, dest, temp);
	Move(1, from, temp, dest);
	Move(num - 1, temp, from, dest);
	//Move 1
	
	//1 3

	//Move 2

	//1 2
	// 
	//1 3
	// 
	//2 3

	//Move 3

	//1 3
	//1 2
	//3 2
	// 
	//1 3
	//
	//2 1
	//2 3
	//1 3
}

int Count(int num)
{
	if (num == 0) return 0;
	if (num == 1) return 1;

	return 2 * Count(num - 1) + 1;
}

void 하노이탑이동순서()
{
	int N;//(1~10)

	cin >> N;

	cout << Count(N) << "\n";

	Move(N, 1, 2, 3);
}

/*
	https://www.acmicpc.net/problem/11651

	Date : 23.03.13

	문제
	2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

	입력
	첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

	출력
	첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.

	예제 입력 1
	5
	0 4
	1 2
	1 -1
	2 2
	3 3
	예제 출력 1
	1 -1
	1 2
	2 2
	3 3
	0 4
*/

#include <map>
#include <set>

void 좌표정렬하기2()
{
	map<int, set<int>> points;

	int pointsNum;

	cin >> pointsNum;

	int x = 0, y = 0;
	for (int i = 0; i < pointsNum; i++)
	{
		cin >> x >> y;

		points[y].insert(x);
	}

	for (auto point : points)
	{
		y = point.first;

		for (auto row : point.second)
		{
			x = row;

			cout << x << " " << y << "\n";
		}
	}
}

/*
	https://www.acmicpc.net/problem/2805

	Date : 23.03.13

	문제
	상근이는 나무 M미터가 필요하다. 근처에 나무를 구입할 곳이 모두 망해버렸기 때문에, 정부에 벌목 허가를 요청했다. 정부는 상근이네 집 근처의 나무 한 줄에 대한 벌목 허가를 내주었고, 상근이는 새로 구입한 목재절단기를 이용해서 나무를 구할것이다.

	목재절단기는 다음과 같이 동작한다. 먼저, 상근이는 절단기에 높이 H를 지정해야 한다. 높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다. 그 다음, 한 줄에 연속해있는 나무를 모두 절단해버린다. 따라서, 높이가 H보다 큰 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않을 것이다. 예를 들어, 한 줄에 연속해있는 나무의 높이가 20, 15, 10, 17이라고 하자. 상근이가 높이를 15로 지정했다면, 나무를 자른 뒤의 높이는 15, 15, 10, 15가 될 것이고, 상근이는 길이가 5인 나무와 2인 나무를 들고 집에 갈 것이다. (총 7미터를 집에 들고 간다) 절단기에 설정할 수 있는 높이는 양의 정수 또는 0이다.

	상근이는 환경에 매우 관심이 많기 때문에, 나무를 필요한 만큼만 집으로 가져가려고 한다. 이때, 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M이 주어진다. (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)

	둘째 줄에는 나무의 높이가 주어진다. 나무의 높이의 합은 항상 M보다 크거나 같기 때문에, 상근이는 집에 필요한 나무를 항상 가져갈 수 있다. 높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0이다.

	출력
	적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.

	예제 입력 1
	4 7
	20 15 10 17
	예제 출력 1
	15
	예제 입력 2
	5 20
	4 42 40 26 46
	예제 출력 2
	36
*/

#include <vector>
#include <algorithm>

void 나무자르기()
{
	long long N, M;//나무의 수(1 ~ 1000000)백만, 가져가려는 나무의 길이(2000000000)20억
	vector<long long> heights;//(1~1000000000)10억

	cin >> N >> M;

	heights.resize(N);

	//큰 순서대로 정렬
	for (long long i = 0; i < N; i++)
		cin >> heights[i];
	sort(heights.begin(), heights.end(),greater<long long>());


	//다음 나무와의 키 차이
	vector<long long> diffs(heights.size());
	for (long long i = 0; i < heights.size() - 1; i++)
		diffs[i] = heights[i] - heights[i + 1];

	diffs.back() = heights.back();

	long long total = 0;
	long long height = heights[0];//자를 높이 초깃값 = 제일 큰나무

	for (long long i = 0; i < diffs.size(); i++)
	{
		total += (i + 1) * diffs[i];
		height -= diffs[i];
		if (total >= M)
		{
			long long diff = (total - M) / (i + 1);
			height += diff;

			cout << height;
			break;
		}
	}


}