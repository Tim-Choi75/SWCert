//����(BOJ) 12834 - �ְ� ����
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
int N, V, E;	//���� ������ �� N, ����� �� V, ������ �� E
int A, B

void dijkstra(int st) {


}


int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_12834.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_12834.txt", "r", stdin);

	int A, B;	//KIST�� ��ġ A�� ����Ǫ���� ��ġ B
	scanf("%d %d %d", &N, &V, &E);	//���� ������ �� N, ����� �� V, ������ �� E
	scanf("%d %d", &A, &B);


	return 0;
}