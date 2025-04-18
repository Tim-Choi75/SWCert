//백준(BOJ) 1446 - 지름길
//https://www.acmicpc.net/problem/1446
//Algo: Dijkstra
//Solve: 

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 10005
#define INF 1e9

typedef pair<int, int> pii;
vector<pii> v[MAX_N];
vector<int> dist(MAX_N, INF);

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1446.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1446.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_1446_1.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_1446_2.txt", "r", stdin);

	//N: 지름길 개수, D 고속도로 길이
	int N, D, i, j;
	scanf("%d %d", &N, &D);

	//from: 시작, to: 도착, cost:길이
	int from, to, cost;
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		if (to > D || to - from < cost)
			continue;

		v[from].push_back({ to, cost });
	}

	dist[0] = 0;

	for (i = 1; i <= D; i++) {
		dist[i] = dist[i - 1] + 1;
		for (j = 0; j < (int)v[i].size(); j++) {
			dist[i] = min(dist[i], dist[v[i][j].first] + v[i][j].second);
		}
	}

	printf("%d\n", dist[D]);

	return 0;
}