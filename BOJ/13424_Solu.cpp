//백준(BOJ) 13424 - 서강그라운드
//https://www.acmicpc.net/problem/13424
//Algo: Dijkstra
//Solve: https://velog.io/@soosungp33/BOJ-13424%EB%B2%88-%EB%B9%84%EB%B0%80-%EB%AA%A8%EC%9E%84C

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
int T, N, M, K;   //N개의 방, M개의 길, K: 친구수
int dist[MAX_N];
int ans[MAX_N];
vector<pii> arr[MAX_N];

void dijkstra(int st) {

	priority_queue <pii, vector<pii>, greater<pii> > pq;

	pq.push({ st, 0 });
	while (!pq.empty()) {
		int now = pq.top().first;
		int nowCost = pq.top().second;
		pq.pop();
		if (isPrint) printf("now: %d, nowCost: %d\n", now, nowCost);


		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int nextCost = nowCost + arr[now][i].second;
			if (isPrint) printf("i: %d, next: %d, nextCost: %d\n", i, next, nextCost);

			if (dist[next] > nextCost) {
				if (isPrint) printf("IN next: %d, nextCost: %d\n", next, nextCost);
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
	}//while


	if (isPrint) printf("st: %d, N: %d\n", st, N);
	for (int i = 1; i <= N; i++) {
		ans[i] += dist[i];
		if (isPrint) printf("%d ", dist[i]);
	}
	
}

void input() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_13424.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_13424.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_13424_1.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_13424_2.txt", "r", stdin);

	scanf("%d", &T);
	int a, b, c, num;
	//while (T--) {
	for (int tc = 0; tc < T; tc++) {
		scanf("%d %d", &N, &M);	//N개의 방, M개의 길
		if (isPrint) printf("tc: %d, N: %d, M: %d\n", tc, N, M);		
		
		for (int i = 0; i < MAX_N; i++)
			ans[i] = 0;

		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &a, &b, &c);
			arr[a].push_back({ b, c });
			arr[b].push_back({ a, c });
		}

		scanf("%d", &K);
		for (int i = 0; i < K; i++) {
			scanf("%d", &num);
			if (isPrint) printf("num: %d\n", num);

			for (int j = 0; j < MAX_N; j++) 
				dist[j] = INF;
			
			dijkstra(num);
		}

	}//while

}//input

void solve() {

	int result = -1;
	int num;
	for (int i = 1; i <= N; i++) {
		if (result == -1 || ans[i] < result) {
			result = ans[i];
			num = i;
		}
	}

	printf("%d\n", num);
}


int main() {

	input();	
	solve();
	return 0;
}