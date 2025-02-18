//CodeUp 3216 - 최단 경로 출력
//https://codeup.kr/problem.php?id=3216
//Algo: 다익스트라(dijkstra)
//Solve:
//https://www.youtube.com/watch?v=w2hQaGzWYc8&t=491s

#include <stdio.h>
#include <queue>
using namespace std;

#define MAX_N 27
#define INF 987654321

int N, M, i, j;
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
		int here = pq.top().second;

		printf("cost: %d, here: %d\n", cost, here);

		pq.pop();

		if (visit[here] == 1)
			continue;

		visit[here] = 1;

		for (i = 1; i <= N; i++) {
			if (dist[i] > dist[here] + map[here][i]) {
				dist[i] = dist[here] + map[here][i];
				pq.push(make_pair(dist[i], i));
			}//if
		}//for

	}

}

int main() {
	
	freopen("D:/Git/SWCert/input/CodeUp_3216.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	printf("N: %d, M: %d\n", N, M);

	char nd1, nd2, st_nodec, fn_nodec;
	int c, st_node, fn_node;

	init_array();

	for (i = 1; i <= M; i++) {
		
		scanf("%c %c %d", &nd1, &nd2, &c);
		printf("nd1: %c, nd2: %c, c: %d\n", nd1, nd2, c);

		map[(int)nd1 - 65][(int)nd2 - 65] = c;
		map[(int)nd2 - 65][(int)nd1 - 65] = c;

	}
	
	scanf("%c %c", &st_nodec, &fn_nodec);
	st_node = (int)st_nodec - 65;
	fn_node = (int)fn_nodec - 65;
	
	printf("st_node: %d, fn_node: %d\n", st_node, fn_node);

	dijkstra(st_node);

	printf("%d\n", dist[fn_node]);

	return 0;
}