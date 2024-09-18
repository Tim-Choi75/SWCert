//https://www.youtube.com/watch?v=611B-9zk2o4
//https://m.blog.naver.com/ndb796/221234424646

#include <stdio.h>

int number=6;
int INF = 1000000000;

int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0},
}

bool v[6];
int d[6];

int getSmallIndex() {
	int min = INF;
	int index=0;
	for(int i=0; i<number; i++) {
		if(d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for(int i=0; i<number; i++) {
		d[i]=a[start][i];
	}
	v[start]=true;
}
