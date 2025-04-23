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

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1504.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1504.txt", "r", stdin);

	//N: 지름길 개수, D 고속도로 길이
	int N, E, i;
	scanf("%d %d", &N, &E);

	//a: 시작, b: 도착, c:길이
	int a, b, c;
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });
	}

	//v1, v2 거처야하는 정점
	int v1, v2;
	scanf("%d %d", &v1, &v2);
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