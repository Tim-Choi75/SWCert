//백준(BOJ) 11779 - 최소비용 구하기 2
//https://www.acmicpc.net/problem/11779
//Algo: Dijkstra
//DataStructure: Priority Queue
//Solu: https://www.youtube.com/watch?v=w2hQaGzWYc8&t=1125s
//Result:

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 27
#define INF 987654321

int n, m;
typedef pair<int, int> pii;
vector pii v[MAX_N];
int dist[MAX_N];

void dijkstra(int st) {

	priority_queue <pii, vector pii, greater pii> pq;

	pq.push(make_pair(0, st));

	while (!pq.empty()) {

		int cost = pq.top().first;	//현재 비용
		int curr = pq.top().next;	//현재 위치

		pq.pop();

		for (i = 1; i < v[curr].size(); i++) {

		}


	}





}




int main() {


	freopen("D:/Git/SWCert/input/BOJ_10779.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	int a, b, c;
	for (i = 1; i <= 8; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}

	int st_node, end_node;
	scanf("%d %d", &st_node, &end_node);

	dijkstra(st_node);

	return 0;
}