//����(BOJ) 18223 - �����̿� ���� �׸��� �ǿ�
//https://www.acmicpc.net/problem/18223
//Algo: Dijkstra
//Solve: https://jinho9610.tistory.com/33

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define isPrint 0

#define MAX_N	5001
#define INF 1000000000LL 

typedef pair<int, int> pii;
typedef long long ll;
vector<pii> v[MAX_N];

//������ ���� V�� ������ ���� E, �׸��� �ǿ찡 ��ġ�� ���� P
int V, E, P;
ll dist[MAX_N];
int visit[MAX_N], i;

//ChatGPT: chatgpt.com/s/t_68b41614dbe48191bc2b90a839f75326


void dijkstra(int st) {

	for (i = 1; i <= V; i++) {
		dist[i] = INF;
		visit[i] = 0;
	}

	//greater<pii> �켱���� ť�� ù ��° ���� �������� �ּ� ��
	priority_queue<pii, vector<pii>, greater<pii>> pq;	//check
	dist[st] = 0;
	pq.push({ 0, st });	//���, ����-check

	while (!pq.empty()) {

		ll nowCost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (visit[now] == 1)
			continue;
		if (isPrint) printf("now: %d, nowCost: %d\n", now, nowCost);

		visit[now] = 1;
		for (i = 0; i < v[now].size(); i++) {

			int next = v[now][i].first;
			ll nextCost = nowCost + v[now][i].second;
			if (isPrint) printf("[%d], next: %d, nextCost: %d\n", i, next, nextCost);

			if (dist[next] > nextCost) {

				if (isPrint) printf("IN next: %d, nextCost: %d\n", next, nextCost);
				dist[next] = nextCost;
				pq.push({ nextCost,  next});
			}

		}//for

	}//while

}


int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_18223.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_18223.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_18223_1.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_18223_CE.txt", "r", stdin);

	scanf("%d %d %d", &V, &E, &P);
	if (isPrint) printf("V: %d, E: %d, P: %d\n", V, E, P);

	int a, b, c;
	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });	//����� ����
	}

	dijkstra(1);

	for (i = 1; i <= V; i++) {
		if (isPrint) printf("%d ", dist[i]);
	}

	int dist_to_v = dist[V];
	int dist_to_p = dist[P];

	if (isPrint) printf("-------------------\n");
	if (isPrint) printf("dist_to_v: %d, dist_to_p: %d\n", dist_to_v, dist_to_p);

	dijkstra(P);
	int dist_from_p_to_v = dist[V];

	if (isPrint) printf("dist_from_p_to_v: %d\n", dist_from_p_to_v);

	//�ǿ�(P)�� ���İ��� ��ο� �ƴ� ����� �ִܰŸ��� ��
	if (dist_to_p + dist_from_p_to_v <= dist_to_v) {
		printf("SAVE HIM\n");
	}
	else {
		printf("GOOD BYE\n");
	}

	return 0;
}