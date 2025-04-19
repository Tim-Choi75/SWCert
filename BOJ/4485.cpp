//백준 4485-녹색 옷 입은 애가 젤다지?
//https://www.acmicpc.net/problem/4485
//Algo: Dijkstra
//Solu: https://yabmoons.tistory.com/376
//		https://kau-algorithm.tistory.com/1206
#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 126
#define INF 1e9

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, i, j;
typedef pair<int, int> pii;
vector<pii> v[MAX_N];
int map[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
int tc = 1;

void dijkstra(int st) {


	priority_queue<pair<int, pii>> pq;
	pq.push(make_pair(-map[0][0], make_pair(0, 0)));

	dist[0][0]=map[0][0]

	while (!pq.empty()) {
		int now = pq.top().first;		//현재 비용
		int nowCost = pq.top().second;	//현재 정점
		printf("now: %d, nowCost: %d\n", now, nowCost);

		pq.pop();
		
		//printf("v.[now].size: %d", v[now].size());

		for (i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = nowCost + v[now][i].second;
			
			printf("now: %d, v.[now].size: %d, next: %d, nextCost: %d\n", now, v[now].size(), next, nextCost);

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push(make_pair(next, nextCost));
			}//if
		}//for
	}//while

}

int main()
{
	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_4485.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_4485.txt", "r", stdin);

	while (true) {

		scanf("%d", &N);
		printf("N: %d\n", N);

		if (N == 0)
			break;

		int rupee =0;
		//map배열 입력
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				scanf("%d", &rupee);
				map[i][j] = rupee;
			}
		}

		//dist배열 초기화
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				dist[i][j] = INF;
			}
		}

		dijkstra();

		printf("Problem %d: %d\n", tc, dist[N*N]);
		tc++;

	}


	return 0;
}