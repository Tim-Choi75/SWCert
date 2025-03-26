//����(BOJ) 10282 - ��ŷ
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
	times[x] = 0;	//�ڱ��ڽ��� 0���� ����
	
	pq.push(make_pair(0, x));

	while(!pq.empty()) {
		int t = pq.top().first;		//���� �ð�
		int cnt = pq.top().second;		//���� ���
	
		pq.pop();

		//�ִ� �Ÿ��� �ƴҰ�쿣 ���� ���ص� ��?
		if (times[cnt] < t)
			continue;

		for (i = 0; i < v[cnt].size(); i++) {
			int next = v[cnt][i].second;				//���� ���
			int nextTime = v[cnt][i].first + t;	//���� �ð�+ ���½ð�

			if (times[next] > nextTime)
				times[next] = nextTime;
				pq.push(make_pair(nextTime, next));	//ť�� ����
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
		scanf("%d %d %d", &n, &d, &c);	//n:����, d: ������, c: ��ŷ���� ��ǻ��

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