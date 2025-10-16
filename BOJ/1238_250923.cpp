//����(BOJ) 1238 - ��Ƽ
//https://www.acmicpc.net/problem/1238
//Algo: ���ͽ�Ʈ��
//Solve: https://howudong.tistory.com/284
//       https://chatgpt.com/c/68d62743-3fe0-8320-b12e-39eab1b7d322

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//���� N��(1 �� N �� 1, 000), ���� M��(1 �� M �� 10, 000)

#define MAX_N 1001
#define INF 1e9
#define pii pair<int, int>
vector<pii> v[MAX_N];
int dist[MAX_N][MAX_N];	//�� �������� �ٸ��������� �̵� �ּҺ��

int N, M, X;	//����, ����, ��Ƽ���

void dijkstra(int num) {


	for (int i = 1; i <= N; i++)		
		dist[num][i] = INF;

	//�Ÿ��� ���� �������� ����(�Ÿ��� ª���ͺ��� ����)
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[num][num] = 0;	//���� 0���� 0���� �̵��ϴ� ���
	pq.push({ 0, num });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (cost > dist[num][x])	//�̹� �� ª����ΰ� ������ ��ŵ
			continue;

		for (int i = 0; i < v[x].size(); i++) {

			int nx = v[x][i].first;       // ����� ����
			int ncost = cost + v[x][i].second; // ���� ���


			if (dist[num][nx] > ncost) {
				dist[num][nx] = ncost;
				pq.push({ ncost, nx });
			}
		}

	}//while
}//dijkstra

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1238.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1238.txt", "r", stdin);

	scanf("%d %d %d", &N, &M, &X);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });
	}

	//��� ������ ���ؼ� ���ͽ�Ʈ�� ����
	for (int i = 1; i <= N; i++)
		dijkstra(i);

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i][X] == INF || dist[X][i] == INF)
			continue;
		ans = max(ans, dist[i][X] + dist[X][i]);
	}
		

	printf("%d\n", ans);
	return 0;
}