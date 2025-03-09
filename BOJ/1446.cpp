//https://www.acmicpc.net/problem/1446
//Algo: Dijkstra
//Solve: 

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 13
#define INF 987654321

int N, D, i;
typedef pair<int, int>pii;
vector<pii> v[MAX_N];
int dist[MAX_N];

void dijkstra(int st) {

	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, st));
	dist[st] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;	//현재 비용
		int curr = pq.top().second;	//현재 정점

		pq.pop();
		
		for (i = 1; i < v[curr].size(); i++) {
			int next = v[curr][i].first;	//다음 정점
			int ncost = cost + v[curr][i].second;	//다음 정점

			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push(make_pair(ncost, next));
			}//if
		}//for
	}

}

int main() {
	
	freopen("D:/Git/SWCert/input/BOJ_1446.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_1446_1.txt", "r", stdin);
	
	scanf("%d %d", &N, &D);
	printf("N: %d, D: %d\n", N, D);

	int a, b, c;

	for (i = 0; i < N; i++) {
		scanf("%d %d %d", &a, &b, &c);

		if (b > D) {
			printf("a: %d, b: %d, c: %d, D: %d\n", a, b, c, D);
			continue;
		}
		
		v[a].push_back(make_pair(b, c));
	}

	for (i = 0; i < N; i++) {
		dist[i] = INF;
	}

	dijkstra(0);
	printf("%d\n", dist[N-1]);

}