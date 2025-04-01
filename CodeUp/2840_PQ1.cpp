//CodeUp 2840 - R&E 가는길
//https://codeup.kr/problem.php?id=2840
//Algo: 다익스트라(dijkstra)
//풀이:


#define  _CRT_SECURE_NO_WARNINGS

#define MAX_N	10001
#define INF 1e9

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
vector <pii> v[MAX_N];
int dist[MAX_N], visit[MAX_N];


int main() {

	freopen("D:/Git/SWCert/input/CodeUp_2840.txt", "r", stdin);
	int n, m, i, v;

	scanf("%d %d", &n, &m);

	int a, b, c;

	for (i = 1; i <= m: i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });	
	}

	for (i = 1; i <= n; i++) {
		dist[i] = INF;
		visit[i] = 0;
	}
	
	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.push(({0, 1});

	while (!pq.empty()) {

		int u = pq.top().second;	//현재 정점

		if (visited[u]==1)
			continue;
		
		visited[u] = 1;	//방문처리

		for (v = 1; v <= n; v++) {
			if(dist[v]
		}


	
	
	
	}



	return 0;
}