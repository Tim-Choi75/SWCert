//https://www.acmicpc.net/problem/18352

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

#define MAX_N   300001
#define 1e9     1e9 

int main() {


	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_18352.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_18352.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_18352_1.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_18352_2txt", "r", stdin);

	//도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
	int N, M, K, X;
	scanf("%d %d %d %d", &N, &M, &K, &X);

	int A, B;

	vector<int> v[MAX_N];
	int dist[MAX_N];
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);
		v[A].push_back(B);
	}

	priority_queue<pii> pq;
	pq.push({ X, 0 })
		for (int i = 1; i <= N; i++) {
			dist[i] = INF;
		}

	dist[X] = 0;

	while (!pq.empty()) {
		int now = pq.top().first;
		int nowCost = pq.top().second;
		pq.pop();

		if (dist[now] < nowCost) //이 코드의 의미
			continue;

		if (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			int nextCost = nowCost + 1;


			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}

	}//while


	int cnt = -1;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			printf("%d\n", i);
			cnt++;
		}
		else {
			printf("%d\n", cnt);
		}
	}

	return 0;
}