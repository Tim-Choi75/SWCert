#include <iostream>
#define MAX 101
#define endl "\n"
using namespace std;

int N, M, cnt, answer=10001;
int arr[MAX][MAX], visit[MAX][MAX];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

void DFS(int row, int col) {
	
	
	if(row==N && col==M) {
		if(cnt < answer)
			answer=cnt;
		
		return;
	}
	
	visit[row][col]=1;
	cout << "[" << row << "," << col << "]" <<  "->";
	for(int i=0; i<4; i++) {
		int nowx=row+dx[i];
		int nowy=col+dy[i];
		
		if(nowx < 1 || nowx >= MAX || nowy < 1 || nowy >= MAX)
			continue;
		
		if(arr[nowx][nowy] == 1 && visit[nowx][nowy] == 0) {
			cout << "[" << nowx << "," << nowy << "]" <<  "->";
			cnt++;
			DFS(nowx, nowy);
		}

	}//for

}//DFS





int main() {
	
	cin >> N >> M;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	cnt=1;
	DFS(1, 1);
	cout << answer;
	return 0;	
}
