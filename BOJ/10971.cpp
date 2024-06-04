//백준 10971 - 외판원 순회2 
//https://www.acmicpc.net/problem/10971
//https://www.acmicpc.net/workbook/view/1833
//Algo: DFS
//Solve: https://m.blog.naver.com/zbqmgldjfh/222431111013

#include <iostream>

using namespace std;

#define MAX_N 11
#define endl "\n" 

int N;
int arr[MAX_N][MAX_N], 
bool visit[MAX_N][MAX_N];
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

void DFS(int x, int y, int h) {
	
	visit[x][y]=1;
	
	for(int i=0; i<4; i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx<0 || nx>=N || ny<0 || ny>=N )
			continue;
		
		if(arr[nx][ny]>h && visit[nx][ny]==0) {
			cout << "->BFS h: "<< h <<"->[" << nx << "]" << "[" << ny << "]: "<< arr[nx][ny];
			visit[nx][ny]=1;
			//cnt++;
			DFS(nx, ny, h);
		}
	}

}


int main() {
	
	cin >> N;
	//input
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> arr[i][j];
		}
	}
	
	for(int i=1; i<=N; i++) {
		
	}
	
	return 0;
} 
