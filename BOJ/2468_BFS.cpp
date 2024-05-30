//백준 2468 - 안전 영역 
//https://www.acmicpc.net/problem/2468
//Algo: BFS
//2667과 비슷 
//Solve: https://scarlettb.tistory.com/104

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_N 101

using namespace std;

int N, cnt, maxHeight=-1;
int arr[MAX_N][MAX_N], map[MAX_N][MAX_N];
int visit[MAX_N][MAX_N];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
queue<pair<int, int> > q;
vector<int> v;

void BFS(int x, int y) {
	 visit[x][y]=1;
	 q.push(make_pair(x, y));
	 
	 while(!q.empty()) {
	 	x=q.front().first;
	 	y=q.front().second;
	 	q.pop();
	 	
	 	for(int i=0; i<4; i++) {
	 		int nx=x+dx[i];
	 		int ny=y+dy[i];
	 		
	 		if(nx<0 || nx>=N || ny<0 || ny>=N)
	 			continue;

			if(map[nx][ny]==1 && visit[nx][ny]==0) {	 			
	 			visit[nx][ny]=1;
	 			q.push(make_pair(nx, ny));
	 		}
		 }
	 }
	 
}

void reset() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			map[i][j]=0;
			visit[i][j]=0;
		}
	}	
}


int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> arr[i][j];
			if(arr[i][j] > maxHeight)
				maxHeight=arr[i][j];
		}
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(arr[i][j] > maxHeight)
				map[i][j]=1;
			else
				map[i][j]=0;	 
		}
	}
	
	for(int h=0; h<maxHeight; h++) {
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(map[i][j]==1 && visit[i][j]==0) {
					BFS(i, j);
					cnt++;				
				}
			}
		}
		v.push_back(cnt);
		
		reset();
	}//for h
	
	sort(v.begin(), v.end());
	cout << v[v.size()-1];
	
	return 0;
}
