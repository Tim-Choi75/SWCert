//����(BOJ) 5719 - ���� �ִ� ���
//https://www.acmicpc.net/problem/5719
//Algo: Dijkstra
//Solve: https://www.youtube.com/watch?v=KnN0tjqaNZw&t


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

#define MAX_N	501
#define pii pair<int, int>

using namespace std;


//����� ��N(2 �� N �� 500,  ������ �� M(1 �� M �� 104
int N, M;	//N ���, M ����
int S, D;	//S ����, D ����
int U, V, P;	//


vector<pii> v[MAX_N];
int visit[MAX_N];
priority_queue<pii> pq;
vector<pii> edge[MAX_N];	//���� ����Ʈ
vector<int> suc[MAX_N];		//index������ ������ �� ������ �����ϴ� vector, ���ͽ�Ʈ�� tracking

void dijktra(int st) {

	







}


int main() {


	freopen("D:/Git/SWCert/input/BOJ_5719.txt", "r", stdin);
	
	while (1) {
		scanf("%d %d", &N, &M);	//N ���, M ����
		
		if (N + M == 0)	
			break;

		scanf("%d %d", &S, &D);	//S ����, D ����
		S++; D++;	//1-base

		for (int i = 1; i <= M; i++) {
			scanf("%d %d %d", &U, &V, &P);	//U���� V�� ���µ� ���� P
			U++; V++; P++;	//1-base
			v[U].push_back({ V, P });
		}

		for(int )
	
	
	
	
	
	}//while
	
	
	




	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &U, &V, &P);

		v[U].push_back({ V, P });
	}

	dijktra(S);


	return 0;

}