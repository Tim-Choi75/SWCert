//백준(BOJ) 10282 - 해킹
//https://www.acmicpc.net/problem/10282
//Algo: Dijkstra
//DataStructure: Priority Queue
//Solu: https://howudong.tistory.com/261
//

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

#define MAX_N	100001
#define INF		1e9

int tc, n, d, c, a, b, s;
int i, j, k;

struct Edge {
	int vex;
	int cost;
	Edge(int a, int b) {
		vex = a;
		cost = b;
	}

	bool operator<(const Edge &b) const {
		return dis > b.dis;
	}

};
typedef pair<int, int> pii;
int dp[MAX_N];



int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_10282.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_10282.txt", "r", stdin);

	priority_queue<Edge> Q;
	vector <pii> v[MAX_N];
	scanf("%d", &tc);
	//printf("tc: %d\n", tc);

	while(tc--) {
	//for (i = 1; i <= tc; i++) {
		scanf("%d %d %d", &n, &d, &c);	//n:노드수, d: 의존성, c: 해킹당한 컴퓨터
		//printf("i:%dth, n: %d, d: %d, c: %d\n", i, n, d, c);	//n:노드수, d: 의존성, c: 해킹당한 컴퓨터

		/*
		for (j = 1; j <= n; j++) {
			dp[j] = INT32_MAX;
		}
		*/
		fill(dp, dp + MAX_N, INT32_MAX);

		//b가 감염된후 s초뒤에 a도 감염됨
		for (j = 1; j <= d; j++) {
			scanf("%d %d %d", &a, &b, &s);
			v[b].push_back(make_pair(a, s));
		}

		
	}//while

	return 0;
}