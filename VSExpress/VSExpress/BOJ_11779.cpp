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
using namespace std;

#define MAX_N 27
#define INF 987654321

int n, m, i, j;
int map[MAX_N][MAX_N];
int dist[MAX_N];
int visit[MAX_N];
int prev_node[MAX_N];
typedef pair<int, int> pii;

void init_array() {

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if(i!=j)
				map[i][j] = INF;
		}
	}

	for (i = 1; i <= n; i++) {
		dist[i] = INF;
		prev_node[i] = -1;
	}
		
}

void dijkstra(int src) {

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int next = pq.top().second;

		pq.pop();

		if (visit[next] == 1)
			continue;
		
		visit[next] = 1;

		for (i = 1; i <= n; i++) {
			if (dist[i] > dist[next] + map[next][i]) {
				prev_node[i] = next;
				dist[i] = dist[next] + map[next][i];
				pq.push(make_pair(dist[i], i));
				
			}
		}//for i

	}//while

}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("D:/Git/SWCert/input/BOJ_11779.txt", "r", stdin);

	scanf("%d %d", &n, &m);
	
	int a, b, c, start, end;
	init_array();

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = c;
	}
	
	scanf("%d %d", &start, &end);

	dijkstra(start);

	//최소 비용
	printf("%d\n", dist[end]);

	//경로 출력
	int curr = end;
	while (curr != -1) {
		printf("%d <", curr);
		curr = prev_node[curr];
	}
	
	return 0;
}