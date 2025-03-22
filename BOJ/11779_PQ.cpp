//백준(BOJ) 11779 - 최소비용 구하기 2
//https://www.acmicpc.net/problem/11779
//Algo: Dijkstra
//DataStructure: Priority Queue
//Solu: https://www.youtube.com/watch?v=w2hQaGzWYc8&t=1125s
//Result:

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 27
#define INF 987654321

int n, m, i, j;
typedef pair<int, int> pii;
int map[MAX_N][MAX_N];
//vector <pii> v[MAX_N];
int dist[MAX_N];
int prev[MAX_N];	//경로 지정

void dijkstra(int st) {

	priority_queue <pii, vector <pii>, greater <pii>> pq;

	pq.push(make_pair(0, st));

	while (!pq.empty()) {

		int cost = pq.top().first;	//현재 비용
		int curr = pq.top().second;	//현재 위치

		pq.pop();

		for (i = 1; i < n; i++) {

			if (dist[i] > dist[curr] + map[curr][i]) {
				dist[i] = dist[curr] + map[curr][i]
				pq.push(make_pair(dist[i], i));
				prev[i] = curr;
			}//if

		}//for

	}//while
}




int main() {


	freopen("D:/Git/SWCert/input/BOJ_11779.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	int a, b, c;
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i != j)
				map[i][j] = INF;
		}
	}

	for (i = 1; i <= 8; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a][b]= c;
	}


	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		prev[i] = INF;
	}

	int st_node, end_node;
	scanf("%d %d", &st_node, &end_node);

	dijkstra(st_node);

	printf("%d\n", dist[end_node]);	//도착도시 최소비용

	return 0;
}