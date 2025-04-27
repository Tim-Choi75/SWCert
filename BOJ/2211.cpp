//백준(BOJ) 2211 - 네트워크 복구
//https://www.acmicpc.net/problem/2211
//Algo: Dijkstra
//Solve: 

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define isPrint 0

#define MAX_N	1001
#define INF		1e9

typedef pair<int, int> pii;
vector<pii> v[MAX_N];

//컴퓨터 개수 N와 회선의 개수 M
int N, M;
int dist[MAX_N], visit[MAX_N], i;


void dijkstra(int st) {

	for (i = 1; i <= V; i++) {
		dist[i] = INF;
		visit[i] = 0;
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[st] = 0;
	pq.push({ st, 0 });

	while (!pq.empty()) {

		int now = pq.top().first;
		int nowCost = pq.top().second;
		pq.pop();

		if (visit[now] == 1)
			continue;
		if (isPrint) printf("now: %d, nowCost: %d\n", now, nowCost);

		visit[now] = 1;
		for (i = 0; i < v[now].size(); i++) {

			int next = v[now][i].first;
			int nextCost = nowCost + v[now][i].second;
			if (isPrint) printf("[%d], next: %d, nextCost: %d\n", i, next, nextCost);

			if (dist[next] > nextCost) {

				if (isPrint) printf("IN next: %d, nextCost: %d\n", next, nextCost);
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}

		}//for

	}//while

}


int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_2211.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_2211.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	if (isPrint) printf("V: %d, E: %d, P: %d\n", V, E, P);

	//A에서 B로 통신시간C
	int A, B, C;
	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &A, &B, &C);
		v[A].push_back({ B, C });
		v[B].push_back({ A, C });	//양방향 간선
	}

	dijkstra(1);

	for (i = 1; i <= V; i++) {
		if (isPrint) printf("%d ", dist[i]);
	}

	int dist_to_v = dist[V];
	int dist_to_p = dist[P];

	if (isPrint) printf("-------------------\n");
	if (isPrint) printf("dist_to_v: %d, dist_to_p: %d\n", dist_to_v, dist_to_p);

	dijkstra(P);
	int dist_from_p_to_v = dist[V];

	if (isPrint) printf("dist_from_p_to_v: %d\n", dist_from_p_to_v);

	//건우(P)를 거쳐가는 경로와 아닌 경로의 최단거리를 비교
	if (dist_to_p + dist_from_p_to_v <= dist_to_v) {
		printf("SAVE HIM\n");
	}
	else {
		printf("GOOD BYE\n");
	}

	return 0;
}