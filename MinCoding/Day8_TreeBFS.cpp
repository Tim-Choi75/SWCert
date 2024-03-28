//트리 BFS
//https://pro.mincoding.co.kr/enterprise/contest/sds/446/problem/DAY3_03

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define endl "\n"
#define MAX_N 100

int D[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int N, Board[MAX_N][MAX_N];

void bfs(int node) {
	
	bool visited[MAX_N]={false};

	queue<int> myqueue;
	visited[node]=true;
	myqueue.push(node);

	while(!myqueue.empty()) {
		int curr = myqueue.front();
		myqueue.pop();
		
		cout << curr << " ";
		
		for(int next=0; next<N; next++) {
			if(visited[next]==0 && Board[curr][next]==1) {
				visited[next]=true;
				myqueue.push(next);
			}
		}//for
	}//while
			
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N;
	memset(Board, 0, sizeof(Board));
	
	int row, col;
	//노드값 입력 
	for(int i=0; i<4; i++) {
		cin >> row >> col;
		Board[row][col] = Board[col][row]=1;	
	}

	//행렬 정보 입력 
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> Board[i][j];
	
	bfs(0);
	
	return 0;
}
