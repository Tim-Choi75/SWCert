//백준(BOJ) 5719 - 거의 최단 경로
//https://www.acmicpc.net/problem/5719
//Algo: Dijkstra
//Solve: 


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

#define MAX_N	501
#define pii pair<int, int>

using namespace std;


//장소의 수N(2 ≤ N ≤ 500,  도로의 수 M(1 ≤ M ≤ 104
int N, M;	//N 장소, M 도로
int S, D;	//S 시작, D 도착
int U, V, P;	//


vector<pii> v[MAX_N];

void dijktra(int st) {

	priority_queue<pii, vector<pii>, greater<pii>> pq;







}


int main() {


	freopen("D:/Git/SWCert/input/BOJ_5719.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	scanf("%d %d", &S, &D);

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &U, &V, &P);

		v[U].push_back({ V, P });
	}

	dijktra(S);


	return 0;

}