//����(BOJ) 17396 - �鵵��
//https://www.acmicpc.net/problem/17396
//Algo: Dijkstra
//Solve: 

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N	100001
#define ll long long
#define lpi pair<ll, int>

int N, M;	//N: �б���, M: ���Ǽ� (1 �� N �� 100,000, 1 �� M �� 300,000)
int view[MAX_N];
vector<lpi> connect[MAX_N];
int dist[MAX_N];
priority_queue<lpi> pq;

void solve() {

	dist[1] = 0;








}


int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1854.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_17396.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_17396_1.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)	
		scanf("%d %d", &view[i]);	//1�̸� ���濡 ����, 0�̸� �Ⱥ���

	int a, b, t;	//a->b�� ���� t�ð�
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &t);

		if (view[a + 1] == 1 || view[y + 1] == 1)
			continue;
		
		connect[a + 1].push_back({ b + 1, t });
		connect[b + 1].push_back({ a + 1, t });
	}

	solve();


	return 0;
}