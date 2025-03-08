//https://www.acmicpc.net/problem/1916
//Algo: Dijkstra
//Solve: https://hagisilecoding.tistory.com/139

#define  _CRT_SECURE_NO_WARNINGS
#define MAX_N  1001
#define INF 987654321

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, i, j;
typedef pair<int, int> pii;
vector<pii> v[MAX_N];
int dist[MAX_N];

void dijkstra(int st) {


	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, st));
	dist[st] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;	//현재 비용
		int curr = pq.top().second; //현재 정점

		pq.pop();

		for (i = 1; i < v[curr].size(); i++) {
			int next = v[curr][i].first;			//다음 정점
			int ncost = cost + v[curr][i].second;	//다음 비용

			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push(make_pair(ncost, next));
			}//if
		}//for

	}//while
}

int main() {


	freopen("D:/Git/SWCert/input/BOJ_1916.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	int A, B, C, st_node, end_node;
	for (i = 1; i <= M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		//printf("a: %d, b: %d, c: %d\n", a, b, c);
		v[A].push_back(make_pair(B, C));
	}

	for (i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	scanf("%d %d", &st_node, &end_node);

	dijkstra(st_node);

	printf("%d\n", dist[end_node]);

	return 0;
}
