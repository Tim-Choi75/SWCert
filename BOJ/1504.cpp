//����(BOJ) 1504 - Ư���� �ִ� ���
//https://www.acmicpc.net/problem/1504
//Algo: Dijkstra
//Solve: 

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N	801
#define INF		1e9

typedef pair<int, int> pii;
vector<pii> v[MAX_N];
vector<int> dist(MAX_N, INF);

//N: ���� ����, E ������ ����
int N, E, i;

int dijkstra(int st) {

	for(i=0; iM)


	return 
}

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1504.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1504.txt", "r", stdin);


	scanf("%d %d", &N, &E);

	//a: ����, b: ����, c:����
	int a, b, c;
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	//v1, v2 ��ó���ϴ� ����
	int v1, v2, ans = 0;
	scanf("%d %d", &v1, &v2);

	printf("%d\n", dist[N]);

	return 0;
}