//백준(BOJ) 5719 - 거의 최단 경로
//https://www.acmicpc.net/problem/5719
//Algo: Dijkstra
//Solve: https://www.youtube.com/watch?v=KnN0tjqaNZw&t


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

#define MAX_N	501
#define INF		1e9
#define pii pair<int, int>

using namespace std;


//장소의 수N(2 ≤ N ≤ 500,  도로의 수 M(1 ≤ M ≤ 104
int N, M;	//N 장소, M 도로
int S, D;	//S 시작, D 도착
int U, V, P;	//


vector<pii> v[MAX_N];
int visit[MAX_N];
priority_queue<pii> pq;
vector<pii> edge[MAX_N];	//인접 리스트
vector<int> suc[MAX_N];		//index정점을 오기전 전 정점을 저장하는 vector, 다익스트라 tracking

void dijktra(int st) {

	







}


int main() {


	freopen("D:/Git/SWCert/input/BOJ_5719.txt", "r", stdin);
	
	while (1) {
		scanf("%d %d", &N, &M);	//N 장소, M 도로
		
		if (N + M == 0)	
			break;

		scanf("%d %d", &S, &D);	//S 시작, D 도착
		S++; D++;	//1-base

		for (int i = 1; i <= M; i++) {
			scanf("%d %d %d", &U, &V, &P);	//U에서 V로 가는데 길이 P
			U++; V++; P++;	//1-base
			v[U].push_back({ V, P });
		}

		for(int i=1; i<=N; i++)
			visit[i]=INF;
		
		visit[S] = 0;
		pq.push({ -visit[S], S });
		
		while (!pq.empty()) {

			int cost = -pq.top().first;
			int now = pq.top().second;
			pq.pop();

			for (auto it : edge[now]) {
			//for(i=0; i<edge[now].size(); i++)
				if (visit[it.second] > cost + it.first) {
					//visit[it.second] 현재 저장되어있는, 다음정점까지의 가중치
					//cost + it.first 현재정점까지의 가중치 + 간선의 가중치
					visit[it.second] = cost + it.first;
					suc[it.second].clear();
					suc[it.second].push_back(now);					
				}
				else {
					suc[it.second].push_back(now);
				}
				pq.push({ -visit[it.second], it.second });
			}//for
			   			 
		}//while-pq
	
		del.push(ed);
		while (!de.empty()) {
			int now = del.front();
			del.pop()
		}
	
	}//while(1)
	
	
	




	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &U, &V, &P);

		v[U].push_back({ V, P });
	}

	dijktra(S);


	return 0;

}