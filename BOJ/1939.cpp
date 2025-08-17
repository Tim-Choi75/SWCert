//���� 1939 - �߷�����
//https://www.acmicpc.net/problem/1939
//Algo: Dijkstra
//Solve: https://stritegdc.tistory.com/198
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define pii pair<int, int>
#define MAX_N	10001
#define INF	1e9;

//N(2 �� N �� 10,000), M(1 �� M �� 100,000)�� �־�����. ���� M
int N, M;

vector<pii> node[MAX_N];
int weight[MAX_N];

void dijkstra(int st) {

	for (int i = 1; i <= N; i++) {
		weight[i] = -1;
	}

	weight[st] = 1000000000;
	priority_queue<pii> pq;	//�� ���� �̵����� �ű� �� �ִ� ��ǰ���� �߷��� �ִ�
	pq.push({ st, 1000000000 });	//index, cost

	while (!pq.empty()) {
		int now = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (weight[now] > cost)
			continue;

		for (int i = 0; i < node[now].size(); i++) {
			int next = node[now][i].first;
			int next_cost = min(node[now][i].second, cost);	//check
			if (weight[next] < next_cost) {
				weight[next] = next_cost;
				pq.push({ next, next_cost });
			}
		}
	}//while

}

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1238.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1939.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	int A, B, C; //A���� B�� ���� �߷� C(1 �� C �� 1,000,000,000)
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		node[A].push_back({ B, C });
		node[B].push_back({ A, C });	//�����
	}

	int U, V;	//U->V �������� �̵�
	scanf("%d %d", &U, &V);
	dijkstra(U);

	printf("%d\n", weight[V]);

	return 0;
}
