//최단경로 
//https://www.acmicpc.net/problem/4485
//Algo: Dijkstra
//Solu:https://yabmoons.tistory.com/376
//Solve: https://codejin.tistory.com/230

#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 126
#define INF 987654321

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, i, j;
typedef pair<int, int> pii;
vector<pii> v[MAX_N];
int dist[MAX_N];

void dijkstra(int st) {

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, st));
	dist[st] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;	//현재 비용
		int curr = pq.top().second;	//현재 정점

		pq.pop();
		
		printf("v.[curr].size: %d", v[curr].size());

		for (i = 1; i < v[curr].size(); i++) {
			int next = v[curr][i].first;
			int ncost = cost + v[curr][i].second;

			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push(make_pair(ncost, next));
			}//if
		}//for
	}//while

}

int main()
{

	//freopen("D:/Git/SWCert/input/BOJ_4485.txt", "r", stdin);

	while (true) {

		scanf("%d", &N);
		printf("N: %d", N);

		if (N == 0)
			break;

		int a, b, c;
		for (i = 1; i <= N; i++) {
			for (i = j; j <= N; j++) {
				scanf("%d %d %d", &a, &b, &c);
				//printf("a: %d, b: %d, c: %d\n", a, b, c);
				v[a].push_back(make_pair(b, c));
			}
		}

		for (i = 1; i <= N; i++) {
			dist[i] = INF;
		}

		dijkstra(0);

		printf("%d\n", dist[N*N]);

	}


	return 0;
}