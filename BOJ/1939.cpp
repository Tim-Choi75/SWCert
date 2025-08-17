//백준 1939 - 중량제한
//https://www.acmicpc.net/problem/1939
//Algo: Dijkstra
//Solve: https://stritegdc.tistory.com/198


#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define pii pair<int, int>

//N(2 ≤ N ≤ 10,000), M(1 ≤ M ≤ 100,000)이 주어진다. 다음 M
int N, M;

vector<pii> node[10001];

int main() {

	scanf("%d %d", &N, &M);

	int A, B, C; //A에서 B로 가는 중량 C
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		node[A].push_back({ B, C });
		node[B].push_back({ A, C });
	}

	int U, V;	//U->V 공장으로 이동

	return 0;
}
