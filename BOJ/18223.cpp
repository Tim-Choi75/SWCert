//백준(BOJ) 18223 - 민준이와 마산 그리고 건우
//https://www.acmicpc.net/problem/18223
//Algo: Dijkstra
//Solve: https://jinho9610.tistory.com/33

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define isPrint 1

#define MAX_N	5001
#define INF		1e9

typedef pair<int, int> pii;
vector<pii> v[MAX_N];
int dist[MAX_N], visit[MAX_N], i;


void dijkstra(int st) {

	priority_queue<pii, vector<pii>, greater<pii>> pq;	
	dist[st] = 0;
	pq.push({ st, 0 });

	while (!pq.empty()) {

		int now = pq.top().first;
		int nowCost = pq.top().second;
		pq.pop();

		if (visit[now] == 1)
			continue;
		//if(isPrint) printf("now: %d, nowCost: %d\n", now, nowCost);
		
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

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_18223.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_18223.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_18223_1.txt", "r", stdin);

	//정점의 개수 V와 간선의 개수 E, 그리고 건우가 위치한 정점 P
	int V, E, P;
	scanf("%d %d %d", &V, &E, &P);
	if (isPrint) printf("V: %d, E: %d, P: %d\n", V, E, P);

	int a, b, c;
	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });	//양방향 간선
	}

	for (i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	dijkstra(1);
	int dist_to_v = dist[V];
	int dist_to_p = dist[P];

	dijkstra(P);
	int dist_from_p_to_v = dist[V];

	//건우(P)를 거쳐가는 경로와 아닌 경로의 최단거리를 비교
	if (dist_to_p + dist_from_p_to_v <= dist_to_v) {
		printf("SAVE HIM\n");
	}
	else {
		printf("GOOD BYE\n");
	}

	/*
	printf("-----------\n");
	for (i = 1; i <= V; i++) {		
		printf("%d ", dist[i]);
	}
	*/
		
	return 0;
}