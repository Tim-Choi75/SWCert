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

//N: 정점 갯수, E 간선의 갯수
int N, E, i;

int dijkstra(int st) {

	for(i=0; iM)


	return 
}

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1504.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1504.txt", "r", stdin);


	scanf("%d %d", &N, &E);

	//a: 시작, b: 도착, c:길이
	int a, b, c;
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	//v1, v2 거처야하는 정점
	int v1, v2, ans = 0;
	scanf("%d %d", &v1, &v2);

	printf("%d\n", dist[N]);

	return 0;
}