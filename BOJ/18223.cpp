//백준(BOJ) 18223 - 민준이와 마산 그리고 건우
//https://www.acmicpc.net/problem/18223
//Algo: Dijkstra
//Solve: https://2jinishappy.tistory.com/244

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N	5001
#define INF		1e9

typedef pair<int, int> pii;
vector<pii> v[MAX_N];
int dist[MAX_N], i;


void dijkstra(int st) {

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	dist[st] = 0;
	pq.push({ st, 0 });

	while (!pq.empty()) {

		int now = pq.top().first;
		int nowCost = pq.top().second;
		printf("now: %d, nowCost: %d\n", now, nowCost);

		pq.pop();

		for (i = 0; i < v[now].size(); i++) {

			int next = v[now][i].first;
			int nextCost = nowCost + v[now][i].second;
			printf("[%d], next: %d, nextCost: %d\n", i, next, nextCost);

			if (dist[i] > nextCost) {

				printf("IN next: %d, nextCost: %d\n", next, nextCost);
				dist[i] = nextCost;
				pq.push({ next, nextCost });
			}

		}//for

	}//while

}


int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_18223.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_18223.txt", "r", stdin);

	//정점의 개수 V와 간선의 개수 E, 그리고 건우가 위치한 정점 P
	int V, E, P;
	scanf("%d %d %d", &V, &E, &P);
	printf("V: %d, E: %d, P: %d\n", V, E, P);

	int a, b, c;
	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	for (i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	dijkstra(1);

	for (i = 1; i <= V; i++) {
		printf("%d ", dist[i]);
	}

	return 0;
}