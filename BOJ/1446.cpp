//https://www.acmicpc.net/problem/1446
//Algo: Dijkstra
//Solve: 

#define  _CRT_SECURE_NO_WARNINGS

#define MAX_N  13
#define INF 987654321


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, D, K, i, j;
typedef pair<int, int> pii;
vector<pii> v[MAX_N];
int dist[MAX_N];

void dijkstra(int st) {

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, st));
	dist[st] = 0;

	while (!pq.empty()) {

		int cost = pq.top().first;
		int curr = pq.top().second;

		pq.pop();

		for (unsigned int i = 0; i <= v[curr].size(); i++) {
			int ncost = cost + v[curr][i].first;
			int next = v[curr][i].second;

			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push(make_pair(ncost, next));
			}//if
		}//for
	
	}//while

}

int main() {

	freopen("D:/Git/SWCert/input/BOJ_1446.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_1446_1.txt", "r", stdin);

	scanf("%d %d", &V, &D);

	int a, b, c;
	for (i = 1; i <= D; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}

	for (i = 0; i < V; i++) {
		dist[i]=INF;
	}

	dijkstra(0);

	printf("%d", dist[V-1]);

	return 0;
}