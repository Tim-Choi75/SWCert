//https://www.youtube.com/watch?v=w2hQaGzWYc8 

#define _CRT_SECURE_NO_WARINGS


#include <stdio.h>
#include <queue>
using namespace std;

#define MAX_N 10
#define INF 987654321

int N, E, i, j;
int map[MAX_N][MAX_N];
int dist[MAX_N];
int visit[MAX_N];
typedef pair<int, int> pii;

void init_array() {

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i != j)
				map[i][j] = INF;
		}
	}

	for (i = 1; i <= N; i++)
		dist[i] = INF;
}

void dijkstra(int src) {

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(0, src));

	dist[src] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int next = pq.top().second;

		pq.pop();

		if (visit[next] == 1)
			continue;

		visit[next] = 1;

		for (i = 1; i <= N; i++) {
			if (dist[i] > dist[next] + map[next][i]) {
				dist[i] = dist[next] + map[next][i];
				pq.push(make_pair(dist[i], i));
			}//if
		}//for
	}	
}

int main() {

	freopen("D:/Git/SWCert/input/DijkstraTest.txt", "r", stdin); 
	scanf("%d %d", &N, &E);	//N:노드수, E:간선수

	int a, b, c;
	
	init_array();

	for (i = 1; i <= E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = c;
	}

	dijkstra(1);


	return 0;
}