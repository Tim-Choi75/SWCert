//CodeUp 2840 - R&E 가는길
//https://codeup.kr/problem.php?id=2840
//Algo: 다익스트라(dijkstra)
//풀이://https://www.youtube.com/watch?v=611B-9zk2o4&t=84s


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
	int n, m, i;

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

	
	pq.push(({ 0, 1 });
	dist[1] = 0;
	priority_queue <pii, vector<pii>, greater<pii>> pq;

	while (!pq.empty()) {
		
		int cost = pq.top().first;	//현재 시간
		int curr = pq.top().second;	//현재 정점

		pq.pop();

		//최단 거리가 아닌 경우는 skip		
		if (dist[curr] < cost)
			continue;

		for (i = 1; i < v[curr].size(); i++) {
			//선택된 노드의 인접 노드
			int next = v[curr][i].first;
			//선택된 노드 거쳐서 인접노트고 가는 비용
			int nextCost = cost + v[curr][i].second;
			if(nextCost)
		}


	
	
	
	}



	return 0;
}