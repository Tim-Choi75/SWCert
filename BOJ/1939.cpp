//���� 1939 - �߷�����
//https://www.acmicpc.net/problem/1939
//Algo: Dijkstra
//Solve: https://stritegdc.tistory.com/198


#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define pii pair<int, int>

//N(2 �� N �� 10,000), M(1 �� M �� 100,000)�� �־�����. ���� M
int N, M;

vector<pii> node[10001];

int main() {

	scanf("%d %d", &N, &M);

	int A, B, C; //A���� B�� ���� �߷� C
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		node[A].push_back({ B, C });
		node[B].push_back({ A, C });
	}

	int U, V;	//U->V �������� �̵�

	return 0;
}
