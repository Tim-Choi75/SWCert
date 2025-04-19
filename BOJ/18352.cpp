//백준(BOJ) 18352 - 특정 거리의 도시
//https://www.acmicpc.net/problem/18352
//Algo: Dijkstra
//Solve: https://tinyurl.com/29qc4bje

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 300001
#define INF 1e9

using namespace std;
typedef pair<int, int> pii;


int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_18352.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_18352.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_18352_1.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_18352_2.txt", "r", stdin);

	//도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발도시 X
	int N, M, K, X, i;

	scanf("%d %d %d %d", &N, &M, &K, &X);
	printf("N: %d, M: %d, K: %d, X: %d\n", N, M, K, X);

	vector<int> v[MAX_N];
	vector<int> dist(N + 1, INF);	//거리벡터 초기화

	int from, to;
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &from, &to);
		v[from].push_back(to);
	}

	queue<int> q;
	q.push(X);

	dist[X] = 0;
	pq.push(X);

	while (!q.empty()) {

		int now = q.front();
		q.pop();

		for (i = 0; i < v[now].size(); i++) {
			int next = v[now][i]			

			if (dist[next] > dist[now]+1) {
				dist[next] > dist[now] + 1;
				q.push(next);
			}//if
		}//for
	}//while

	int cnt = -1;
	for (i = 1; i <= N; i++) {
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