//백준(BOJ) 14284 - 간선 이어가기2
//https://www.acmicpc.net/problem/14284
//Algo: Dijkstra
//DataStructure: Priority Queue


#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>


using namespace std;
typedef pair<int, int> pii;

#define MAX_N	50001
#define INF		1e9

int dist[MAX_N];
vector <pii> v[MAX_N];

int n, m, i, s, t;

void dijkstra(int st) {


	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ st, 0 });

	while (!pq.empty()) {
		int now = pq.top().first;
		int nowCost = pq.top().second;

		//printf("now: %d, nowCost: %d\n", now, nowCost);
		pq.pop();

		if(dist[now] < nowCost)
			continue;
		
		if(now ==t) {
			printf("%d\n", nowCost);
			return;
		}
			

		for (i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = nowCost+ v[now][i].second;
			//printf("v[now].size(): %d, next: %d, nextCost: %d\n", v[now].size(), next, nextCost);

			if (dist[next] > nextCost) {
				//printf("In next: %d, nextCost: %d\n", next, nextCost);

				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}//if
		}//for
	}//while


}


int main() {

	freopen("/Users/timchoi/Git/SWCert/input/BOJ_14284.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_14284.txt", "r", stdin);

	scanf("%d %d", &n, &m);
	//printf("n: %d, m: %d\n", n, m);

	int a, b, c;
	for (i = 1; i <= m; i++) {

		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });
	}

	for (i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	//s: 시작, e: 도착
	scanf("%d %d", &s, &t);
	dijkstra(s);

	//printf("%d\n", dist[t]);

	return 0;
}