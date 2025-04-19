//백준(BOJ) 18352 - 특정 거리의 도시
//https://www.acmicpc.net/problem/18352
//Algo: Dijkstra
//Solve: https://tinyurl.com/29qc4bje
		 https://go2gym365.tistory.com/210

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

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_18352.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_18352.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_18352_1.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_18352_2.txt", "r", stdin);

	//도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발도시 X
	int N, M, K, X, i;

	scanf("%d %d %d %d", &N, &M, &K, &X);
	//printf("N: %d, M: %d, K: %d, X: %d\n", N, M, K, X);

	vector<int> v[MAX_N];

	int dist[MAX_N];	//거리벡터 초기화
	for (i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	int from, to;
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &from, &to);
		v[from].push_back(to);
	}

	priority_queue<pii> pq;
	pq.push({ X, 0 });

	dist[X] = 0;
	
	while (!pq.empty()) {

		int now = pq.top().first;
		int nowCost = pq.top().second;

		pq.pop();

		if (dist[now] < nowCost)
			continue;


		for (i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			int nextCost = nowCost + 1;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}//if
		}//for
	}//while

	int cnt = -1;
	for (i = 1; i <= N; i++) {
		if (dist[i] == K) {
			printf("%d\n", i);
			cnt++;
		}
		else {
			printf("%d\n", cnt);
		}			
	}

	return 0;
}