//https://www.acmicpc.net/problem/1753
//Algo: Dijkstra
//Solve: https://tinyurl.com/25celctn

#define  _CRT_SECURE_NO_WARNINGS

#define MAX_N  20001
#define INF 987654321


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K, i, j;
typedef pair<int, int> pii;
vector<pii> v[MAX_N];
int dist[MAX_N];

void dijkstra(int st) {

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, st });
	dist[st] = 0;

	while (!pq.empty()) {

		int cost = -pq.top().first;	//현재 비용
		int curr = pq.top().second; //현재 정점

		pq.pop();

		for (i = 1; i <= v[curr].size(); i++) {
			int next = v[curr][i].first;			//다음 정점
			int ncost = cost + v[curr][i].second;	//다음 비용

			if (ncost < dist[next]) {
				dist[next] = ncost;
				pq.push({ -dist[next], next });
			}//if
		}
	}//while

}


int main() {

	freopen("D:/Git/SWCert/input/BOJ_1753.txt", "r", stdin);

	int a, b, c;

	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	for (i = 1; i <= E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		//printf("a: %d, b: %d, c: %d\n", a, b, c);
		v[a].push_back(make_pair(b, c));
	}

	for (i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	dijkstra(K);

	for (i = 1; i <= V; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;

}