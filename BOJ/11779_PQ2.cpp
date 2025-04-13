//백준(BOJ) 11779 - 최소비용 구하기 2
//https://www.acmicpc.net/problem/11779
//Algo: Dijkstra
//DataStructure: Priority Queue
//Solve: https://bbeomgeun.tistory.com/112

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N	1001
#define INF		1e9

typedef pair<int, int> pii;
vector<vector <pii>> graph;

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_11779.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_11779.txt", "r", stdin);
	
	//n: 도시수, m: 버스수
	int n, m, i;
	scanf("%d %d", &n, &m);

	graph = vector<vector <pii>>(n + 1);
	vector<int> dist(n + 1, INF);

	//a: 출발, b: 도착, c:버스 비용
	int a, b, c;
	for (i = 0; i < m; i++) {

		scanf("%d %d %d", &a, &b, &c);
		//printf("a: %d, b: %d, c: %d\n", a, b, c);
		graph[a].push_back(make_pair(b, c));
	}

	//s: 시작, e: 종점
	int s, e;
	scanf("%d %d", &s, &e);
	
	printf("s: %d, e: %d\n", s, e);

	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(s, 0));
	dist[s] = 0;
	int route[MAX_N];

	while (!pq.empty()) {
		int now = pq.top().first;
		int nowCost = pq.top().second;

		printf("now: %d, nowCost: %d\n", now, nowCost);

		pq.pop();

		if (nowCost > dist[now])
			continue;

		for (i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextCost = nowCost + graph[now][i].second;
			printf("OUT now: %d, size: %d, next: %d, nextCost: %d\n", now, graph[now].size(), next, nextCost);

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				//printf("IN i; %d, next: %d, nextCost: %d\n", i, next, nextCost);
				pq.push(make_pair(next, nextCost));
				route[next] = now;
			}//if

		}//for i

	}//while

	for (i = s; i <= e; i++) {
		printf("%d ", dist[i]);
	}
	//printf("%d\n", dist[e-1]);
	return 0;


}