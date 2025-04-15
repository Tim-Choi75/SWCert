//����(BOJ) 18352 - Ư�� �Ÿ��� ����
//https://www.acmicpc.net/problem/18352
//Algo: Dijkstra
//Solve: 

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 300001
#define INF 1e9

using namespace std;
typedef pair<int, int> pii;


int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_18532.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_18532.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_18532_1.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_18532_2.txt", "r", stdin);

	//������ ���� N, ������ ���� M, �Ÿ� ���� K, ��ߵ��� X
	int N, M, K, X, i;

	scanf("%d %d %d %d", &N, &M, &K, &X);

	vector<pii> v[N];
	vector<int> dist(N + 1, INF);	//�Ÿ����� �ʱ�ȭ

	int from, to;
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &from, &to);
		v[from].push_back({ to, 1 });
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	dist[1] = 0;
	pq.push({ 1, 0 });

	while (!pq.empty()) {

		int now = pq.top().first;
		int nowCost = pq.top().second;

		pq.pop();

		for (i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = nowCost + v[now][i].second;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}//if
		}//for
	}//while

	for (i = 1; i <= N; i++) {
		if (dist[i] == K)
			printf("%d\n", i);
	}

	return 0;
}