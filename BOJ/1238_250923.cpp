//백준(BOJ) 1238 - 파티
//https://www.acmicpc.net/problem/1238
//Algo: 다익스트라
//Solve: https://howudong.tistory.com/284
//       https://chatgpt.com/c/68d62743-3fe0-8320-b12e-39eab1b7d322

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//마을 N개(1 ≤ N ≤ 1, 000), 도로 M개(1 ≤ M ≤ 10, 000)

#define MAX_N 1001
#define INF 1e9
#define pii pair<int, int>
vector<pii> v[MAX_N];
int dist[MAX_N][MAX_N];	//각 정점에서 다른정점으로 이동 최소비용

int N, M, X;	//마을, 도로, 파티장소

void dijkstra(int num) {


	for (int i = 1; i <= N; i++)		
		dist[num][i] = INF;

	//거리에 대해 내림차순 정렬(거리가 짧은것부터 뽑힘)
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[num][num] = 0;	//마을 0에서 0으로 이동하는 비용
	pq.push({ 0, num });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (cost > dist[num][x])	//이미 더 짧은경로가 있으면 스킵
			continue;

		for (int i = 0; i < v[x].size(); i++) {

			int nx = v[x][i].first;       // 연결된 마을
			int ncost = cost + v[x][i].second; // 누적 비용


			if (dist[num][nx] > ncost) {
				dist[num][nx] = ncost;
				pq.push({ ncost, nx });
			}
		}

	}//while
}//dijkstra

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1238.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1238.txt", "r", stdin);

	scanf("%d %d %d", &N, &M, &X);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });
	}

	//모든 정점에 대해서 다익스트라 수행
	for (int i = 1; i <= N; i++)
		dijkstra(i);

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i][X] == INF || dist[X][i] == INF)
			continue;
		ans = max(ans, dist[i][X] + dist[X][i]);
	}
		

	printf("%d\n", ans);
	return 0;
}