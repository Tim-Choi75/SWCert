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

#define MAX_N 10001
#define INF 999

int tc, n, d, c, target, start, cost;
int i, j, k;

typedef pair<int, int> pii;
vector <pii> v[MAX_N];
int times[MAX_N];


void dijkstra(int x) {

	priority_queue <pii, vector<pii>, greater<pii>> pq;
	times[x] = 0;	//자기자신을 0으로 설정
	
	pq.push(make_pair(0, x));

	while(!pq.empty()) {
		int t = pq.top().first;		//현재 시간
		int cnt = pq.top().second;		//현재 노드
	
		pq.pop();

		//최단 거리가 아닐경우엔 굳이 안해도 됨?
		if (times[cnt] < t)
			continue;

		for (i = 0; i < v[cnt].size(); i++) {
			int next = v[cnt][i].second;				//다음 노드
			int nextTime = v[cnt][i].first + t;	//현재 시간+ 가는시간

			if (times[next] > nextTime)
				times[next] = nextTime;
				pq.push(make_pair(nextTime, next));	//큐에 담음
		}
	
	}//while

	int com = 0, t = 0;
	for (i = 1; i <= n; i++) {
		com++;
		t = max(t, times[i]);
	}

	printf("%d %d\n", com, t);
}




int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_10282.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_11779.txt", "r", stdin);

	scanf("%d", &tc);

	for (i = 1; i <= tc; i++) {
		scanf("%d %d %d", &n, &d, &c);	//n:노드수, d: 의존성, c: 해킹당한 컴퓨터

		for (j = 1; j <= n; j++) {
			times[j] = INF;
		}

		for (j = 1; j <= d; j++) {
			scanf("%d %d %d", &target, &start, &cost);
			v[target].push_back(make_pair(cost, start));
		}

		dijkstra(c);		
	}

	return 0;
}