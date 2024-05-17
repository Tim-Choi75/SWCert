#include <iostream>
#include <queue>

#define X first
#define Y second
#define MAX 101
#define endl "\n"
using namespace std;
//https://www.acmicpc.net/problem/2178
//https://luv-n-interest.tistory.com/875

int n, m, answer=10001;
string arr[MAX];
int visit[MAX][MAX];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};


int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<pair<int, int> > Q;
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			visit[i][j]=1;
		}
	}
	
	visit[0][0]=0;
	Q.push({0,0});
	
	while(!Q.empty()) {
		pair<int, int> cur=Q.front();
		Q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int nx=cur.X+dx[dir];
			int ny=cur.Y+dy[dir];
			
			
			if(nx<0 || nx>=n || ny<0 || ny>=m)
				continue;
				
			if(visit[nx][ny]==1 || arr[nx][ny]!='1')
				continue;
			
			visit[nx][ny]=visit[cur.X][cur.Y]+1;
			Q.push({nx, ny});
		}//for dir

	}//while
	
	cout << visit[n-1][m-1]+1;
	
	return 0;	
}
