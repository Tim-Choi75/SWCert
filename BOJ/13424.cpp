//백준(BOJ) 13424 - 서강그라운드
//https://www.acmicpc.net/problem/13424
//Algo: Dijkstra
//Solve: 

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N	101
#define INF		1e9
#define isPrint	1

typedef pair<int, int> pii;
vector<pii> v[MAX_N];
int dist[MAX_N];
int friends[MAX_N];
int answer[MAX_N];
int T, N, M, K, ans;   //N개의 방, M개의 길, K: 친구수


void init_Dist() {
	if (isPrint) printf("init_Dist()\n");
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
}


void dijkstra(int st) {
	init_Dist();
	priority_queue <pii, vector<pii>, greater<pii> > pq;

	dist[st] = 0;
	pq.push({ st, 0 });
	while (!pq.empty()) {
		int now = pq.top().first;
		int nowCost = pq.top().second;
		pq.pop();
		if (isPrint) printf("now: %d, nowCost: %d\n", now, nowCost);


		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = nowCost + v[now][i].second;

			//if (isPrint) printf("v.size: %d, next: %d, nextCost: %d\n", v[now].size(), next, nextCost);

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				//answer[next] += nextCost;
				pq.push({ next, nextCost });
				if (isPrint) printf("In next: %d, nextCost: %d\n", next, nextCost);
			}
		}
	}

}

void input() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_13424_1.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_13424_1.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_13424_2.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_13424.txt", "r", stdin);

	scanf("%d", &T);
	int a, b, c, num;
	while (T--) {
		scanf("%d %d", &N, &M);	//N개의 방, M개의 길
		if (isPrint) printf("N: %d, M: %d\n", N, M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &a, &b, &c);
			v[a].push_back({ b, c });
			v[b].push_back({ a, c });
		}//for
	}//while

	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &num);
		friends[i] = num;
		dijkstra(num);

		for (int i = 1; i <= N; i++) {
			answer[i] += dist[i];
		}

	}


	int minVal = answer[0];
	int maxVal = answer[0];
	
	
	for (int i = 1; i <= N; i++) {
		printf("%d ", answer[i]);
	}
	

	printf("\n");
	for (int i = 1; i <= N; i++) {
		minVal = min(minVal, answer[i]);
		maxVal = max(maxVal, answer[i]);
	}

	if (isPrint) printf("minVal: %d, maxVal: %d\n", minVal, maxVal);
	
	/*
	for(int i=0; i<K; i++) {
		dijkstra(friends[i]);
	}
	*/
	

}//input

void solve() {

	if (isPrint) printf("solve()\n");
	printf("%d\n", ans);
}


int main() {

	input();
	//dijkstra();
	solve();
	return 0;
}