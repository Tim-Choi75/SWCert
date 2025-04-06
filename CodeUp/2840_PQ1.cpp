//CodeUp 2840 - R&E ���±�
//https://codeup.kr/problem.php?id=2840
//Algo: ���ͽ�Ʈ��(dijkstra)
//Ǯ��://https://www.youtube.com/watch?v=611B-9zk2o4&t=84s


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
int dist[MAX_N];

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

	freopen("D:/Git/SWCert/input/CodeUp_2840.txt", "r", stdin);
	int n, m, i;

	scanf("%d %d", &n, &m);

	int a, b, c;
	priority_queue<Edge> Q;
	vector<pii> graph[MAX_N];
	   
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		printf("a: %d, b: %d, c: %d\n", a, b, c);
		v[a].push_back({ b, c });	
	}

	vector<int> dist(n + 1, INF);

	Q.push(Edge(1, 0));
	dist[1] = 0;

	while (!Q.empty()) {
		
		int now		= Q.top().node;	//���� ����
		int nowCost	= Q.top().cost;	//���� �ð�

		printf("now: %d, nowCost: %d\n", now, nowCost);
		Q.pop();

		//�ִ� �Ÿ��� �ƴ� ���� skip		
		if (nowCost < dist[now])
			continue;

		for (i = 0; i < graph[now].size(); i++) {
			//���õ� ����� ���� ���
			int next = graph[now][i].first;
			//���õ� ��� ���ļ� ������Ʈ�� ���� ���
			int nextCost = nowCost + graph[now][i].second;
			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				Q.push(Edge(next, nextCost));
			}
		}//for

	}//while

	printf("dist: %d\n", dist[n]);
	return 0;
}