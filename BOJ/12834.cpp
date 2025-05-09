//����(BOJ) 12834 - �ְ� ����
//https://www.acmicpc.net/problem/12834
//Algo: Dijkstra
//Solve: https://littlesam95.tistory.com/102

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N	101
#define INF		1e9
#define isPrint	0

typedef pair<int, int> pii;
vector<pii> v[MAX_N];
int dist[MAX_N], i;
int house[MAX_N];	//N���� �� ��ġ
int N, V, E;	//���� ������ �� N, ����� �� V, ������ �� E
int A, B, ans = 0;	//KIST�� ��ġ A�� ����Ǫ���� ��ġ B

void init_Dist() {
	if (isPrint) printf("init_Dist()\n");
	for (i = 1; i <= V; i++) {
		dist[i] = INF;
	}
}


void dijkstra() {

	for (int i = 1; i <= N; i++) {

		if (isPrint) printf("dijkstra() N: %d, i: %d, house[i]: %d\n", N, i, house[i]);

		init_Dist();
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		dist[house[i]] = 0;
		pq.push({ house[i], 0 });

		while (!pq.empty()) {
			int now = pq.top().first;
			int cost = pq.top().second;

			if (isPrint) printf("now: %d, cost: %d\n", now, cost);

			pq.pop();

			if (dist[now] < cost) {
				continue;
			}

			if (isPrint) printf("v[now].size(): %d\n", v[now].size());
			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i].first;
				int nextCost = cost + v[now][i].second;

				if (dist[next] > nextCost) {
					dist[next] = nextCost;
					pq.push({ next, nextCost });
				}
			}
		}//while

		if (isPrint) printf("A: %d, B: %d\n", A, B);

		int KIST_dist = dist[A];
		int CRFood_dist = dist[B];

		if (isPrint) printf("KIST_dist: %d, CRFood_dist: %d\n", KIST_dist, CRFood_dist);

		if (KIST_dist == INF) {
			KIST_dist = -1;
		}

		if (CRFood_dist == INF) {
			CRFood_dist = -1;
		}

		ans += (KIST_dist + CRFood_dist);

	}//for

}

void input() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_12834.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_12834.txt", "r", stdin);

	int num;
	scanf("%d %d %d", &N, &V, &E);	//���� ������ �� N, ����� �� V, ������ �� E
	scanf("%d %d", &A, &B);			//KIST�� ��ġ A�� ����Ǫ���� ��ġ B
	if (isPrint) printf("N: %d, V: %d, E: %d A: %d, B: %d\n", N, V, E, A, B);

	for (int i = 1; i <= N; i++) {		//N���� �� ��ġ ����
		scanf("%d", &num);
		house[i] = num;
	}

	int a, b, l;	//a,b: ������ �糡, l: ���� ����
	for (int i = 1; i <= E; i++) {	//���� �� ����
		scanf("%d %d %d", &a, &b, &l);
		if (isPrint) printf("a: %d, b: %d, l: %d\n", a, b, l);
		v[a].push_back({ b, l });
		v[b].push_back({ a, l });
	}
}

void solve() {
	if (isPrint) printf("solve()\n");
	printf("%d\n", ans);
}


int main() {

	input();
	dijkstra();
	solve();
	return 0;
}