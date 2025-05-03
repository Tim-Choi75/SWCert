//백준(BOJ) 12834 - 주간 미팅
//https://www.acmicpc.net/problem/12834
//Algo: Dijkstra
//Solve: 

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N	101
#define INF		1e9

typedef pair<int, int> pii;
vector<pii> v[MAX_N];
int dist[MAX_N], i;
int N, V, E;	//기사단 팀원의 수 N, 장소의 수 V, 도로의 수 E
int A, B

void dijkstra(int st) {


}


int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_12834.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_12834.txt", "r", stdin);

	int A, B;	//KIST의 위치 A와 씨알푸드의 위치 B
	scanf("%d %d %d", &N, &V, &E);	//기사단 팀원의 수 N, 장소의 수 V, 도로의 수 E
	scanf("%d %d", &A, &B);


	return 0;
}