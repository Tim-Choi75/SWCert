//����(BOJ) 10282 - ��ŷ
//https://www.acmicpc.net/problem/10282
//Algo: Dijkstra
//DataStructure: Priority Queue
//Solu: https://howudong.tistory.com/261
//https://githubseob.tistory.com/263
//https://www.youtube.com/watch?v=E8gfQjMZySo

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <stack>
#pragma warning(disable:4244)

using namespace std;

#define MAX_N	100001
#define INF		1e9

int tc, n, d, c, a, b, s;
int i, j, k;
typedef pair<int, int> pii;

struct Edge {
	int node;
	int cost;
	Edge(int a, int b) {
		node = a;
		cost = b;
	}

	bool operator<(const Edge &b) const {
		return cost > b.cost;
	}

};




int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_10282.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_10282.txt", "r", stdin);

	priority_queue<Edge> Q;
	scanf("%d", &tc);
	printf("tc: %d\n", tc);
	vector<vector <pii>> graph;

	while (tc--) {
		//for (i = 1; i <= tc; i++) {
		scanf("%d %d %d", &n, &d, &c);	//n:����, d: ������, c: ��ŷ���� ��ǻ��
		printf("tc: %dth, n: %d, d: %d, c: %d\n", tc, n, d, c);	//n:����, d: ������, c: ��ŷ���� ��ǻ��

		/*
		for (j = 1; j <= n; j++) {
			dp[j] = INT32_MAX;
		}
		*/
		vector<int> dist(n + 1, INF);
		graph = vector<vector <pii>>(n + 1);

		//b�� �������� s�ʵڿ� a�� ������
		for (j = 1; j <= d; j++) {
			scanf("%d %d %d", &a, &b, &s);
			printf("a: %d, b: %d, s: %d\n", a, b, s);	//a:����, b: ������, s: ��ŷ���� ��ǻ
			graph[b].push_back(make_pair(a, s));
		}

		Q.push(Edge(c, 0));
		dist[c] = 0;

		while (!Q.empty()) {
			int now = Q.top().node;
			int nowCost = Q.top().cost;

			Q.pop();

			if (nowCost > dist[now])
				continue;

			for (unsigned i = 0; i < graph[now].size(); i++) {
				int next = graph[now][i].first;
				int nextCost = nowCost + graph[now][i].second;

				if (dist[next] > nextCost) {
					dist[next] = nextCost;
					Q.push(Edge(next, nextCost));
				}//if
			}//for
		}//while-PQ

		int com = 0, t = 0;
		for (i = 1; i <= n; i++) {
			if (dist[i] == INF)
				continue;

			com++;
			t = max(t, dist[i]);
			printf("%d %d\n", com, t);

		}

	}//while-tc

	return 0;
}