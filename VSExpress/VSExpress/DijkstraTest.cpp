//https://www.youtube.com/watch?v=w2hQaGzWYc8 

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 10
#define INF 987654321

int N, E, i, j;
int map[MAX_N][MAX_N];
int dist[MAX_N];
int visit[MAX_N];
int prev_node[MAX_N];	//reverse
typedef pair<int, int> pii;

void init_array() {

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i != j)
				map[i][j] = INF;
		}
	}

	for (i = 0; i < N; i++) {
		dist[i] = INF;
		prev_node[i] = -1;
	}
		
}

void dijkstra(int src) {

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(0, src));
	//printf("src: %d\n", src);

	dist[src] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int next = pq.top().second;
		
		//printf("cost: %d, next: %d\n", cost, next);
		
		pq.pop();

		if (visit[next] == 1)
			continue;

		visit[next] = 1;

		for (i = 0; i < N; i++) {
			printf("i: %d, dist[%d]: %d, next: %d, dist[next]: %d, map[next][i]: %d\n", i, i, dist[i], next, dist[next], map[next][i]);
			if (dist[i] > dist[next] + map[next][i]) {
				prev_node[i] = next;
				//printf("updated i: %d, next: %d\n", i, next);
				dist[i] = dist[next] + map[next][i];
				pq.push(make_pair(dist[i], i));
			}//if
		}//for
	}	
}

int main() {

	freopen("D:/Git/SWCert/input/DijkstraTest.txt", "r", stdin); 
	scanf("%d %d", &N, &E);	//N:노드수, E:간선수

	//printf("N: %d, E: %d\n", N, E);

	int a, b, c;
	
	init_array();

	for (i = 1; i <= E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		printf("a: %d, b: %d, c: %d\n", a, b, c);

		map[a][b] = c;
	}

	dijkstra(0);
	
	
	//거리 출력
	for (i = 0; i < N; i++)
		printf("%d ", dist[i]);

	//경로 출력
	int curr = 5;
	while (curr != -1) {
		//printf("%d < ", curr);
		curr = prev_node[curr];
	}
	
	int prev_node_size = sizeof(prev_node) / sizeof(prev_node[0]);

	//printf("prev_node size: %d\n", sizeof(prev_node)/sizeof(prev_node[0]);

	reverse(begin(prev_node), end(prev_node));

	for (i = 0; i < prev_node_size; i++)
		printf("%d ", curr);

	return 0;
}