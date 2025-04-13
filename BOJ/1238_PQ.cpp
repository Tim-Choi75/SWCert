//BOJ 1238 - ��Ƽ
//https://www.acmicpc.net/problem/1238
//Algo: ���ͽ�Ʈ��(dijkstra)
//Ǯ��:https://howudong.tistory.com/284

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N	1001
#define INF		1e9

typedef pair<int, int> pii;


//N: ����, M: �ܹ��� ����, X: X���� �����ְ� X���� ���ƿ�
int N, M, X, i;
vector<pii> v[1001];	//������ ��������
int dist[1001][1001] = { 0, };	//�� �������� �ٸ��������� �ּ� �������



void dijkstra(int num) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[num][num] = 0;

	pq.push({num, 0});

	while (!pq.empty()) {
		int now = pq.top().first;
		int nowCost = pq.top().second;
		
		printf("num: %d, now: %d, nowCost: %d\n", num, now, nowCost);

		pq.pop();

		for (i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;					//����� ����
			int nextCost = nowCost+v[now][i].second;	//�����ð�+����� ����

			if (dist[num][next] > nextCost) {
				dist[num][next] = nextCost;
				pq.push({ next, nextCost });
			}//if

		}//for
	}//while
}

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1238.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1238.txt", "r", stdin);

	scanf("%d %d %d", &N, &M, &X);
	//printf("N: %d, M: %d, X: %d\n", N, M, X);

	//A->B������ T�ɸ�
	int A, B, T, i;
	for (i = 1; i <= M; i++) {
		scanf("%d %d %d", &A, &B, &T);
		v[A].push_back(make_pair(B, T));
	}

	fill(&dist[0][0], &dist[MAX_N][MAX_N], INF);
	
	for (i = 1; i <= N; i++)
		dijkstra(i);

	int ans = 0;
	for (i = 1; i <= N; i++)
		ans = max(ans, dist[i][X] + dist[X][i]);

	printf("%d\n", ans);

	return 0;
}