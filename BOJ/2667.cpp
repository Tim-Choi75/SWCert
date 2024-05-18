//백준 2667 - 단지번호 붙이기 
//https://www.acmicpc.net/problem/2667
//Algo: DFS

#include <iostream>
using namespace std;

#define MAX_N 26
#define endl "\n" 

int N, arr[MAX_N][MAX_N], visit[MAX_N][MAX_N];
int dx={0, 0, -1, 1};
int dy={-1, 1, 0, 0};

void DFS(int x, int y) {
	
	visit[x][y]=1;
	
	
}
int main() {
	cin >> N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> arr[i][j];
		}
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			DFS(i, j);
		}
	}
}
