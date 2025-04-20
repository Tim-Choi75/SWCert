//백준(BOJ) 5972 - 택배 배송
//https://www.acmicpc.net/problem/5972
//Algo: Dijkstra
//DataStructure: Priority Queue
//Solu: 

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

#define MAX_N	50001
#define INF		1e9

vector<pii> v[MAX_N];
int cost[MAX_N];

//N: 헛간, M: 소들 길, C:소의 수
int N, M, i;

void dijkstra(int st) {

	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.push({ st, 0 });
	cost[st] = 0;

	while (!pq.empty()) {
		int now = pq.top().first;
		int nowCost = pq.top().second;

		printf("now: %d, nowCost: %d\n", now, nowCost);

		pq.pop();

		for (i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = nowCost+ v[now][i].second;

			printf("v[now].size(): %d, next: %d, nextCost: %d\n", v[now].size(), next, nextCost);

			if (cost[next] > nextCost) {
				cost[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
	}
}


int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_5972.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_5972.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	int A, B, C;
	for (i = 1; i <= M; i++) {
		
		scanf("%d %d %d", &A, &B, &C);
		v[A].push_back({ B, C });
		v[B].push_back({ A, C });
	}

	for (i = 0; i < N; i++) {
		cost[i] = INF;
	}

	dijkstra(1);

	printf("%d\n", cost[N]);

	return 0;
}