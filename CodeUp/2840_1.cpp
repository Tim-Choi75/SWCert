//CodeUp 2840 - R&# 가는길
//https://codeup.kr/problem.php?id=2840
//Algo: 다익스트라(dijkstra)
//풀이:

#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 10001
#define INF 987654321

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;


int map[MAX_N][MAX_N];
int dist[MAX_N];
int visit[MAX_N];
int n, m, i, j;

typedef pair<int, int> pii;

void init_array() {
	//배열을 초기화한다.
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i != j)
				map[i][j] = INF;
		}
	}

	for (i = 1; i <= n; i++)
		dist[i] = INF;

}

void dijkstra(int src) {
	priority_queue<pii, vector<pii>, greater<pii> > pq;

	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(visit[here]==1)
            continue;

        visit[here]=1;
        for(i=1; i<=n; i++) {
            if(dist[i] > dist[here]+map[here][i]) {
                dist[i] = dist[here]+map[here][i];
                pq.push(make_pair(dist[i], i));
            }
        }

	}

}
int main() {

	freopen("D:/Git/SWCert/input/CodeUp_2840.txt", "r", stdin);
	int a, b, c;

	scanf("%d %d", &n, &m);
	//printf("n: %d, m: %d", n, m);

	init_array();
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = c;
	}

	dijkstra(1);


    printf("answer %d", dist[n]);
	return 0;
}