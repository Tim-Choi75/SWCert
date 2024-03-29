//CodeUP 1512 숫자 등고선 
//https://codeup.kr/problem.php?id=1512
//Algo: Flood Fill
//Result: My Source

#include <iostream>
#include <queue>

#define MAX_N 100
#define  endl "\n"
#define X first
#define Y second

using namespace std;

int N, X, Y;


int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int arr[MAX_N+1][MAX_N+1]={0};
int visited[MAX_N+1][MAX_N+1]={0};

int floodFill(int stx, int sty) {
	queue<pair<int,int> > Q;
	
	arr[stx][sty]=1;
	visited[stx][sty]=1;
	Q.push({stx, sty});
	
	//cout << "dfs called stx:  " << stx << " sty: " << sty << endl;
	
	while(!Q.empty()) {
		pair<int, int> curr = Q.front();
		Q.pop();
		
		for(int i=0; i<4; i++) {
			int nx=curr.X+dx[i];
			int ny=curr.Y+dy[i];
			
			
			if(nx<0 || nx>=N || ny<0 || ny>=N)
				continue;
			
			if(visited[nx][ny]==1)
				continue;
			
			
			arr[nx][ny]=arr[curr.X][curr.Y]+1;
			//cout << "arr[" << curr.X << "]" << "[" << curr.Y << "]=" << arr[curr.X][curr.Y] << "->" << endl;
			//cout << "After arr[" << nx << "]" << "[" << ny <<"]=" << arr[nx][ny] <<  endl;
			visited[nx][ny]=1;
			Q.push({nx, ny});
		}//for		
	}//while
	
	return -1;
	
}

int main() {
	
	cin >> N;
		
	int x, y;
	cin >> x >> y;
	floodFill(x-1, y-1);
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}	
	
	return 0;
}
