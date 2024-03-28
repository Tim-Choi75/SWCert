//BFS-최단거리 문제 
//https://www.youtube.com/watch?v=RxT7F6YA3TI


#include <iostream>
#include <queue>

using namespace std;

#define endl "\n"
#define MAX_N 10

/* Input
5
0 0 0 0 0
0 1 1 1 1
0 0 0 0 0
1 1 1 1 0
0 0 0 0 0
0 1 4 2
※0,1 시작점-> 4,2 도착점 
*/

struct Point {
	int row, col, dist;
	 
};

int D[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int N, Board[MAX_N][MAX_N];

int bfs(int srcRow, int srcCol, int dstRow, int dstCol ) {
	bool visited[MAX_N][MAX_N]={false};
	queue<Point> myqueue;
	
	visited[srcRow][srcCol]=true;
	
	myqueue.push({srcRow, srcCol, 0});
	
	while(!myqueue.empty()) {
		Point curr=myqueue.front();
		myqueue.pop();
		
		cout << curr.row <<","<< curr.col <<"->";
		
		//목적지에 도착시 
		if(curr.row == dstRow && curr.col == dstCol)
			return curr.dist;
		
		for(int i=0; i<4; i++) {
			int nr=curr.row+D[i][0];
			int nc=curr.col+D[i][1];
			
			//경계는 넘을수 없다 
			if(nr<0 || nr>N-1 || nc<0 || nc>N-1)
				continue;
			
			//방문한적이 있고 갈수 없는 길이면 skip
			if(visited[nr][nc]==1 || Board[nr][nc]==1)
				continue;
			
			//새로운곳을 방문하고 거리를 늘린다. 
			visited[nr][nc]=true;
			myqueue.push({nr, nc, curr.dist+1});
			
			cout << nr <<","<< nc<< ", Dist: "<< curr.dist+1 << endl;
			
		}//for 
	}//while
	return -1;
}//bfs

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {	
			cin >> Board[i][j];
		}
	}
	
	int srcRow, srcCol, dstRow, dstCol;
	cin >> srcRow >> srcCol >>  dstRow >> dstCol;
	
	cout << bfs(srcRow, srcCol, dstRow, dstCol);
	
	return 0;
}
