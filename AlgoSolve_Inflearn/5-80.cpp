#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

struct Edge {
	int vex;
	int dis;
	Edge(int a, int b) {
		vex = a;
		dis = b;
	}

	bool operator<(const Edge &b) const {
	return dis > b.dis;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/timchoi/Git/SWCert/input/AlgoSolve_5-80.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/AlgoSolve_5-80.txt", "r", stdin);

	priority_queue<Edge> Q;
	vector<pair<int, int>> graph[30];
	int i, n, m, a, b, c;

	cin >> n >> m;
	vector<int> dist(n + 1, INF);
	for (i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	Q.push(Edge(1, 0));
	dist[1] = 0;
	while (!Q.empty()) {
		int now = Q.top().vex;
		int nowDist = Q.top().dis;

		Q.pop();

		if (nowDist > dist[now])
			continue;

		for (i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nexDist = nowDist + graph[now][i].second;

			if (dist[next] > nexDist) {
				dist[next] = nexDist;
				Q.push(Edge(next, nexDist));
			}//if
		}//for
	}//while

	for (i = 2; i <= n; i++) {
		if (dist[i] != INF)
			cout << i << " : " << dist[i] << endl;
		else
			cout << i << " : impossible" << endl;
	}

	return 0;
}