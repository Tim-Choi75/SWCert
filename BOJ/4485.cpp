//최단경로 
//https://www.acmicpc.net/problem/4485
//Algo: Dijkstra
//Solu:https://yabmoons.tistory.com/376
//Solve: https://codejin.tistory.com/230

#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 126
#define INF 1e9

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, i, j;
typedef pair<int, int> pii;
vector<pii> v[MAX_N];
int dist[MAX_N];
int tc = 1;

void dijkstra(int st) {

	for (i = 1; i <= N; i++) {
		dist[i] = INF;
	}


	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(st, 0));
	dist[st] = 0;

	while (!pq.empty()) {
		int now = pq.top().first;		//현재 비용
		int nowCost = pq.top().second;	//현재 정점

		pq.pop();
		
		//printf("v.[now].size: %d", v[now].size());

		for (i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = nowCost + v[now][i].second;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push(make_pair(next, nextCost));
			}//if
		}//for
	}//while

}

int main()
{
	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_4485.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_4485.txt", "r", stdin);

	while (true) {

		scanf("%d", &N);
		printf("N: %d\n", N);

		if (N == 0)
			break;

		int cost=0;
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				scanf("%d", &cost);
				//printf("a: %d, b: %d, c: %d\n", a, b, c);
				v[i].push_back(make_pair(j, cost));
			}
		}


		dijkstra(1);

		printf("Problem %d: %d\n", tc, dist[N*N]);
		tc++;

	}


	return 0;
}