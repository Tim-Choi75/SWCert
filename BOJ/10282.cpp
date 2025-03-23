//백준(BOJ) 10282 - 해킹
//https://www.acmicpc.net/problem/10282
//Algo: Dijkstra
//DataStructure: Priority Queue
//Solu: 
//

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

#define MAX_N 10001
#define INF 987654321

int tc, n, d, c, a, b, s;
int i, j, k;

typedef pair<int, int> pii;
int map[MAX_N][MAX_N];
//vector <pii> v[MAX_N];
int times[MAX_N];

void dijkstra(int st) {


}




int main() {

	freopen("/Users/timchoi/Git/SWCert/input/BOJ_10282.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_11779.txt", "r", stdin);

	scanf("%d", &tc);

	for (i = 1; i < tc; i++) {
		scanf("%d %d %d", &n, &d, &c);	//n:노드수, d: 의존성, c: 해킹당한 컴퓨터

		for (j = 1; j <= n; j++) {
			times[j] = INF;
		}

		for (j = 1; j <= n; j++) {
			for (k = 1; k <= n; k++) {
				if (j != k)
					map[j][k] = INF;
			}
		}

		for (j = 1; j <= d; j++) {
			scanf("%d %d %d", &a, &b, &s);
			map[a][b] = s;
		}
	}

	return 0;
}