//백준(BOJ) 1854 - K번째 최단경로 찾기
//https://www.acmicpc.net/problem/1854
//Algo: Dijkstra
//Solve: 

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N	1001
#define INF		1e9

typedef pair<int, int> pii;
vector<pii> v[MAX_N];
int dist[MAX_N], i;


void dijkstra(int st) {

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	pq.push({ st, 0 });

	while (!pq.empty()) {

		int now = pq.top().first;
		int nowCost = pq.top().second;

		pq.pop();

		for (i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = v[now][i].second;


			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}//for
	}
}


int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1854.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1854.txt", "r", stdin);

	//n:도시, m: 도로, k:번째 최단 경로
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	//a: 시작, b: 도착, c:시간
	int a, b, c;
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });
	}


	for (i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	//1에서 i로 가는 k번째 최단 경로 소요시간 출력
	dijkstra(1);

	for (i = 1; i <= n; i++) {
		printf("%d ", dist[i]);
	}

	return 0;
}