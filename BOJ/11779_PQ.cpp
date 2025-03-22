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
#include <stack>

using namespace std;

#define MAX_N 27
#define INF 987654321

int n, m, i, j;
typedef pair<int, int> pii;
int map[MAX_N][MAX_N];
//vector <pii> v[MAX_N];
int dist[MAX_N];
int route[MAX_N];	//경로 지정
stack<int> st;

void dijkstra(int st) {

	priority_queue <pii, vector <pii>, greater <pii>> pq;

	pq.push(make_pair(0, st));

	while (!pq.empty()) {

		int cost = pq.top().first;	//현재 비용
		int curr = pq.top().second;	//현재 위치

		pq.pop();

		for (i = 1; i < n; i++) {

			if (dist[i] > dist[curr] + map[curr][i]) {
				dist[i] = dist[curr] + map[curr][i];
				pq.push(make_pair(dist[i], i));
				route[i] = curr;
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
		route[i] = INF;
	}

	int st_node, end_node;
	scanf("%d %d", &st_node, &end_node);

	dijkstra(st_node);
	route[st_node] = 0;

	for (i = end_node; i != st_node; i = route[i])
		st.push(i);
	st.push(st_node);


	printf("%d\n", dist[end_node]);	//최소비용
	printf("%d\n", st.size());		//방문도시수

	while (!st.empty()) {
		printf("%d\n", st.top());
		st.pop();
	}

	return 0;
}