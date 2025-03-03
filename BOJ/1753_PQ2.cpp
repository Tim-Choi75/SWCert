//https://www.acmicpc.net/problem/1753
//Solve: https://yabmoons.tistory.com/376

#define  _CRT_SECURE_NO_WARNINGS

#define MAX_N  20001
#define INF 987654321

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int V, E, i, j, st_node;
int map[MAX_N][MAX_N];
int dist[MAX_N];
int visit[MAX_N];
typedef pair<int, int> pii;
vector<pair<int, int>> Vertex[MAX_N];

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

void input() {

	int a, b, c;
	scanf("%d %d", &V, &E);
	scanf("%d", &st_node);
	//printf("V: %d, E: %d, st_node: %d\n", V, E, st_node);
	
	for (i = 1; i <= E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		//printf("a: %d, b: %d, c: %d\n", a, b, c);
		Vertex[a].push_back(make_pair(b, c));
	}

	for (i = 1; i <= V; i++) {
		dist[i] = INF;
	}

}

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, st_node));
	dist[st_node] = 0;

	while (!pq.empty()) {

		int cost = -pq.top().first;
		int curr = pq.top().second;

		pq.pop();

		//printf("vector size: %d\n", Vertex[curr].size());
		for (unsigned i = 1; i <= Vertex[curr].size(); i++) {
			int next = Vertex[curr][i].first;
			int n_cost = Vertex[curr][i].second;

			if (dist[next] > cost + n_cost) {
				dist[next] = cost + n_cost;
				pq.push(make_pair(-dist[next], next));
			}//if
			
		}//for
	}//while
}

int main() {

	freopen("D:/Git/SWCert/input/BOJ_1753.txt", "r", stdin);

	input();

	dijkstra();

	for (i = 1; i <= V; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}