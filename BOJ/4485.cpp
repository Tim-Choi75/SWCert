//백준 4485-녹색 옷 입은 애가 젤다지?
//https://www.acmicpc.net/problem/4485
//Algo: Dijkstra
//Solu: https://yabmoons.tistory.com/388
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
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, -0};

int tc = 1, ans;

void dijkstra() {


	priority_queue<pair<int, pii>> pq;
	pq.push(make_pair(-map[0][0], make_pair(0, 0)));

	dist[0][0]=map[0][0];

	while (!pq.empty()) {
		int cost = pq.top().first;	
		int x = pq.top().second.first;		//현재 비용
		int y = pq.top().second.second;		//현재 정점
		printf("cost: %d, x: %d, y: %d\n", cost, x, y);

		pq.pop();
		
		//printf("v.[now].size: %d", v[now].size());

		for (i = 0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];

			if(nx>=0 && ny>=0 && nx<N && ny<N) {
				int nCost = cost + map[nx][ny];
				if(dist[nx][ny] > nCost) {
					dist[nx][ny]=nCost;
					pq.push(make_pair(-dist[nx][ny], make_pair(nx, ny)));
				}//if dist
			}//if nx 
		}//for i
	}//while
	ans=dist[N-1][N-1];
}

int main()
{
	freopen("/Users/timchoi/Git/SWCert/input/BOJ_4485.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_4485.txt", "r", stdin);

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

		printf("Problem %d: %d\n", tc, ans);
		tc++;

	}


	return 0;
}