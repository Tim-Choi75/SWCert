//백준 2667 - 단지번호 붙이기 
//https://www.acmicpc.net/problem/2667
//Algo: DFS
//https://www.acmicpc.net/submit/2667/7481967

#include <iostream>
#include <algorithm>	//sort
using namespace std;

#define MAX_N 26
#define endl "\n" 

int N, arr[MAX_N][MAX_N], visit[MAX_N][MAX_N];
int dx={0, 0, -1, 1};
int dy={-1, 1, 0, 0};

void DFS(int x, int y) {
	
	visit[x][y]=1;
	
	for(int i=0; i<4; i++) {https://www.acmicpc.net/problem/2667
		int nx=x+dx[i];
		int ny=y+dy[i];
	
		if(nx<0 || nx>=N || ny<0 || ny>=N)
			continue;
	
		if(arr[nx][ny]!=0 && visit[nx][ny]!=1) {
			cnt++;
			DFS(nx, ny, cnt+1);
		}
	}
	
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
			if(arr[i][j]!=0)
				DFS(i, j);
		}
	}
}
