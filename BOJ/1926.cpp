//백준 1926 그림

//https://www.acmicpc.net/problem/1926
//https://novlog.tistory.com/entry/BFS-1-Flood-Fill-Algorithm-feat-BOJ-1926-%EA%B7%B8%EB%A6%BC

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second
#define MAX_N 500+1
#define endl "\n"

int n, m;
int board[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main() {
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> board[i][j];
		}
	}
	
	int num=0;	//그림의 갯수
	int mx=0;	//그림의 최대 넓이
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(board[i][j] == 0 || visited[i][j] == 1)
				continue;
				
			num++;
			queue<pair<int,int> > Q;
			Q.push({i, j});
			visited[i][j]=1;
			
			int area=0;
			while(!Q.empty()) {
				area++;
				//curr: 현재 탐색하고있는 칸 가리킴
				pair<int, int> curr = Q.front();
				Q.pop();
				
				for(int dir=0; dir<4; dir++) {
					int nx=curr.X+dx[dir];
					int ny=curr.Y+dy[dir];
					
					if(nx<0 || nx>=n || ny<0 || ny>=m)
						continue;
					
					if(board[nx][ny] == 0 || visited[nx][ny] == 1)
						continue;
					
					visited[nx][ny] = 1;
					Q.push({nx, ny});
				}//for dir
				mx = max(mx, area);
			}//while
		}//for j
	}//for i
	
	cout << num << endl << mx;
	
	
	return 0;
	
}
