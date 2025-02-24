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
int prev[MAX_N];
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
		prev[i] = INF;
	}
		
}

void dijkstra(int src) {

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;

		pq.pop();

		if (visit[here] == 1)
			continue;
		
		visit[here] = 1;

		for (i = 1; i <= n; i++) {
			if (dist[i] > dist[here] + map[here][i]) {
				dist[i] = dist[here] + map[here][i];
				pq.push(make_pair(dist[i], i));
				prev[i] = here;
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
	
	//최소 비용  도시 수
	int curr = end;	
	while (curr != -1) {		
		curr = prev[curr];
	}

	printf("%d\n", prev.size());
	
	//도시  순서대로 출력
	for(i=)



	return 0;
}