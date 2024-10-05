//CodeUP 2062 - Up 2
//https://codeup.kr/problem.php?id=2062
//Algo: 
//Result: 

#include <iostream>
#include <queue>
#include <cstring>

#define MAX_N 100
#define endl "\n"
#define X first
#define Y second

using namespace std;

int m, n;


int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int arr[MAX_N+1][MAX_N+1] = { 0 };
int visited[MAX_N+1][MAX_N+1] = { 0 };
int flr[9];

int dfs(int num) {

	memset(visited, 0, sizeof(visited));

	int currCnt=0;
	for (int x= 0; x< m; x++) {
		for (int y = 0; y < n; y++) {
			//cout << "num: " << num << " x: " << x << " y: " << y << endl;
			
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				//경계를 넘으면 skip
				if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					continue;

				//-1은 갈수가 없고 이미 방문한곳이면 
				if (arr[nx][ny] == -1 || visited[nx][ny] == 1)
					continue;
				
				//cout << "After num: " << num << " nx: " << nx << " ny: " << ny << endl;
				
				//방문처리
				visited[nx][ny] = 1;

				//호출한 숫자와 동일하면
				if (arr[nx][ny] == num)
					currCnt++;


			}//for dir
			
		}//for y
	}//for x
	return currCnt;
}


int main() {


	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int maxCnt = 0;
	for (int i = 1; i <= 9; i++) {
		flr[i] = dfs(i);
		if(maxCnt <= flr[i])
			maxCnt = flr[i];

		if(flr[i] != 0)
			cout << i << " # " << maxCnt << endl;
			
	}
	

	return 0;
}
