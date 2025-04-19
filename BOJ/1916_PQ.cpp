//백준 1916 - 최소비용 구하기
//https://www.acmicpc.net/problem/1916
//Algo: Dijkstra

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 1001
#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

vector<pii> v[MAX_N];
int dist[MAX_N], i;

void dijkstra(int st) {

	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.push({ st, 0 });

	while (!pq.empty()) {

		int now = pq.top().first;
		int nowCost = pq.top().second;

		pq.pop();

		for (i = 0; i < v[now].size(); i++) {

			int next = v[now][i].first;
			int nextCost = nowCost+v[now][i].second;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}//if		
		
		}//for
	}//while
}

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1916.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1916.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_1916_CE.txt", "r", stdin);	//CE_반례(CounterExample)

	//N: 도시, M: 버스
	int N, M;
	scanf("%d %d", &N, &M);

	int a, b, c;
	for (i = 1; i <= M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });
	}

	int from, to;
	scanf("%d %d", &from, &to);

	for (i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	dijkstra(from);

	printf("%d\n", dist[to]);

	return 0;
}