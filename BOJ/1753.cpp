//https://www.acmicpc.net/problem/1753

#define  _CRT_SECURE_NO_WARNINGS

#define MAX_N  20001
#define INF 987654321

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std; 

int V, E, i, j;
int map[MAX_N][MAX_N];
int dist[MAX_N];
int visit[MAX_N];
typedef pair<int, int> pii;

void print_array() {
	
	for (i = 1; i <= V; i++) {
		for (j = 1; j <= V; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	printf("---------------------\n");
	for (i = 1; i <= V; i++)
		printf("%d ", dist[i]);

	printf("\n---------------------\n");

}

void init_array() {
		
	for (i = 1; i <= V; i++) {
		for (j = 1; j <= V; j++) {
			if(i!=j)
				map[i][j] = INF;
		}	
	}

	for (i = 1; i <= V; i++) {	
		dist[i] = INF;
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

		if(visit[next] == 1)
			continue;

		visit[next] = 1;

		for (i = 1; i <= V; i++) {
			if (dist[i] > dist[next] + map[next][i]) {
				dist[i] = dist[next] + map[next][i];
				pq.push(make_pair(dist[i], i));
			}//ifchrome://vivaldi-webui/startpage?section=Speed-dials&background-color=#2e2f37
		}//for
	}//while
}

int main() {

	freopen("D:/Git/SWCert/input/BOJ_1753.txt", "r", stdin);

	
	int st_node, a, b, c;
	scanf("%d %d", &V, &E);
	scanf("%d", &st_node);
	//printf("V: %d, E: %d, st_node: %d\n", V, E, st_node);
	init_array();

	for (i = 1; i <= E; i++) {
		scanf("%d %d %d", &a, &b, &c);		
		//printf("a: %d, b: %d, c: %d\n", a, b, c);
		map[a][b] = c;
	}
	
	//print_array();

	dijkstra(st_node);
	
	for (i = 1; i <= V; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}