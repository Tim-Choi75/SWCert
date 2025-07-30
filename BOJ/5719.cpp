//백준(BOJ) 5719 - 거의 최단 경로
//https://www.acmicpc.net/problem/5719
//Algo: Dijkstra
//Solve: https://tin9-d-d-blog.tistory.com/295


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//장소의 수 N (2 ≤ N ≤ 500)
//도로의 수 M (1 ≤ M ≤ 10000)

#define MAX_N 500
#define MAX_M 1000

int N, N, S, D;	


void input() {


	scanf("%d %d", &N, &M);
	scanf("%d %d", &S, &D);	//S: 시작, D: 도착

	int U, V, P;	//U에서 V로 가는 도로의 길이가 P라
	for (int i = 0; i < MAX_N; i++) {


	}


}

int main() {

	
	freopen("D:/Git/SWCert/input/BOJ_5719.txt", "r", stdin);


	input();

	return 0;
}