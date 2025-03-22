//CodeUp 2840 - R&E 가는길
//https://codeup.kr/problem.php?id=2840
//Algo: 다익스트라(dijkstra)
//풀이:

#define  _CRT_SECURE_NO_WARNINGS

#define MAX_N	10001
#define INF 987654321

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, i, j, a, b, c;
typedef pair<int, int> pii;
vector <pii> v[MAX_N];
int dist[MAX_N];

void dijkstra(int st) {
	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, st));
	dist[st] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;	//현재 비용
		int curr = pq.top().second;	//현재 정점
		
		printf("cost: %d, curr: %d\n", cost, curr);

		pq.pop();

		printf("v[curr].size(): %d\n", v[curr].size());
		for (i = 1; i < v[curr].size(); i++) {
			
			int next = v[curr][i].first;			//다음 정점
			int ncost = cost + v[curr][i].second;	//다음 비용

			printf("i:%d ncost: %d, next: %d\n", i, ncost, next);

			if (dist[next] > ncost) {
				printf("inside ncost: %d, next: %d\n", i, ncost, next);
				dist[next] = ncost;
				pq.push(make_pair(ncost, next));
			}
		}
	}

}

int main() {

	freopen("/Users/timchoi/Git/SWCert/CodeUp_2840.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/CodeUp_2840.txt", "r", stdin);

	scanf("%d %d", &n, &m);
	//printf("n: %d, m: %d\n", n, m);


	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		//printf("a: %d, b: %d, c: %d\n", a, b, c);

		v[a].push_back(make_pair(b, c));
	}

	for (i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	dijkstra(1);

	printf("answer: %d", dist[n]);

	return 0;
}