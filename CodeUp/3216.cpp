//CodeUp 3216 - 최단 경로 출력
//https://codeup.kr/problem.php?id=3216
//Algo: 다익스트라(dijkstra)
//Solve:
//https://www.youtube.com/watch?v=w2hQaGzWYc8&t=594

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

#define MAX_N 27
#define INF 987654321


int N, M, i, j, index = 0;
int map[MAX_N][MAX_N];
int dist[MAX_N];
int visit[MAX_N];
int route[MAX_N];   //경로 저장

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
	route[index] = src;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;

		printf("cost: %d, here: %d\n", cost, here);

		pq.pop();

		if (visit[here] == 1)
			continue;

		visit[here] = 1;
		//index++;
		//route[index] = here;

		for (i = 1; i <= N; i++) {
			if (dist[i] > dist[here] + map[here][i]) {
				index++;
				route[index] = i;
				dist[i] = dist[here] + map[here][i];
				pq.push(make_pair(dist[i], i));
			}//if
		}//for

	}//while

}

int main() {



	freopen("D:/Git/SWCert/input/CodeUp_3216.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	printf("N: %d, M: %d\n", N, M);

	char nd1, nd2, st_nodec, fn_nodec;
	int c, st_node, fn_node;

	init_array();

	for (i = 1; i <= M; i++) {

		//scanf("%c %c %d", &nd1, &nd2, &c);
		cin >> nd1 >> nd2 >> c;
		printf("i: %d, nd1: %c, nd2: %c, c: %d\n", i, nd1, nd2, c);
		map[(int)nd1 - 64][(int)nd2 - 64] = c;
		map[(int)nd2 - 64][(int)nd1 - 64] = c;

	}

	//scanf("%c %c", &st_nodec, &fn_nodec);
	cin >> st_nodec >> fn_nodec;
	st_node = (int)st_nodec - 64;
	fn_node = (int)fn_nodec - 64;

	printf("st_nodec: %c, fn_nodec: %c\n", st_nodec, fn_nodec);
	printf("st_node: %d, fn_node: %d\n", st_node, fn_node);
	
	dijkstra(st_node);
	printf("%d\n", dist[fn_node]);

	printf("index: %d\n", index);
	for (i = 1; i <= index; i++)
		printf("%c\n", route[i]);
		

	return 0;
}