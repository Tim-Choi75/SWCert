//백준(BOJ) 1504 - 특정한 최단 경로
//https://www.acmicpc.net/problem/1504
//Algo: Dijkstra
//Solve: 

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N	801
#define INF		1e9

typedef pair<int, int> pii;
vector<pii> v[MAX_N];
vector<int> dist(MAX_N, INF);

int N, E, i;	//N: 정점 갯수, E 간선의 갯수

int dijkstra(int st) {

	for (i = 0; i < N; i++) {
		dist[i] = INF;
	}
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ st, 0 });
	dist[st] = 0;


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
			}
		}
	}//while


	return dist[N];
}

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1504.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1504.txt", "r", stdin);
	scanf("%d %d", &N, &E);	//N: 정점 갯수, E 간선의 갯수

	//a: 시작, b: 도착, c:길이
	int a, b, c;
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });		//양방향
	}

	int v1, v2;	//반드시 거쳐야하는 정점

	printf("%d\n", dijkstra(1));

	return 0;
}