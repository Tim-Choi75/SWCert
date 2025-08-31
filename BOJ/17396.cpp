//백준(BOJ) 17396 - 백도어
//https://www.acmicpc.net/problem/17396
//Algo: Dijkstra
//Solve: https://junseok.tistory.com/286

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N	100001
#define LL long long int
#define lpi pair<LL, int>
#define INF 1e18

int N, M;	//N: 분기점, M: 길의수 (1 ≤ N ≤ 100,000, 1 ≤ M ≤ 300,000)
int view[MAX_N];
vector<lpi> connect[MAX_N];
LL dist[MAX_N];
priority_queue<lpi> pq;

//ChatGPT chatgpt.com/c/68b37e7e-8f08-8324-bb54-38f091fe30f8


void reset_distance() {

	for(int i=1; i<=N; i++)
		dist[i]=INF;
}

void dijkstra() {
	dist[1]=0;
	pq.push({-0, 1});

	while(!pq.empty()) {
		LL cost = -pq.top().first;
		int x = pq.top().second;

		pq.pop();
		if(dist[x] < cost)
			continue;

		for(int i=0; i<connect[x].size(); i++) {
			int xx = connect[x][i].first;
			int n_cost = connect[x][i].second;

			if(dist[xx] > dist[x] + n_cost) {
				dist[xx] = dist[x] + n_cost;
				pq.push({-dist[xx], xx});
			}

		}

	}//while

}

void solve() {

	reset_distance();
	dijkstra();
	
	if(dist[N] == INF)
		printf("-1\n");
	else
		printf("%lld\n", dist[N]);

}


int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_17396.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_17396.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_17396_1.txt", "r", stdin);

	//(1 ≤ N ≤ 100,000, 1 ≤ M ≤ 300,000)
	scanf("%d %d", &N, &M);

	for (int i = 1; i <=N; i++)	
		scanf("%d", &view[i]);	//1이면 상대방에 보임, 0이면 안보임

	int a, b, t;	//a->b로 갈때 t시간
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &t);
		
		//1이면 보이므로 q
		if ((a != N && view[a + 1] == 1) || (b != N && view[b + 1] == 1))
			continue;
		
		connect[a + 1].push_back({ b + 1, t });
		connect[b + 1].push_back({ a + 1, t });
	}

	solve();


	return 0;
}