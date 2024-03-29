//FireFighter
//https://pro.mincoding.co.kr/enterprise/contest/sds/446/problem/DAY4_03
//https://blog.naver.com/not_layer/223032814137 <- 이거랑 비슷?
//https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

#define MAX_N 20
#define endl "\n"

struct Node {
    int x,y;
    int distance;
};

/*
# 벽
A 소화기
$ 불 
_ 빈공간
*/

int N;
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

char arr[MAX_N+1][MAX_N+1]={0};
int  used[MAX_N+1][MAX_N+1]={0};
int  fused[MAX_N+1][MAX_N+1]={0};

int flodFill(int stx, int sty, int visited[][]) {
	queue <Node> q;
	q.push({stx, sty, 0});
	
	//cout << "flodFill stx: " << stx << " sty: " << sty << endl;
	while(!q.empty()) {
		Node now = q.front();
		q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int nx=now.x+dx[dir];
			int ny=now.y+dy[dir];
			
			//경계는 넘어갈수 없다
			if(nx<0 || nx>=N || ny<0 || ny>=N)
				continue;
			
			//벽(#)과 불($)은 지나갈 수 없습니다
			if(arr[nx][ny]=='#' || arr[nx][ny]=='$')
				continue;
				
			//cout << "nx: " << nx << " ny: " << ny << endl;
			
			if(arr[nx][ny]=='A') {
				//cout << "Matched nx: " << nx << " ny: " << ny << endl;
				fireFlodFill(nx, ny);
				break; 
			}

			used[nx][ny]=1;
			q.push({nx, ny, now.distance+1});

		}
	}
	
	return -1;
}

int main() {
	cin >> N;	//N*N크기의 맵 입력

	int x, y;		//소방관 위치
	int fx, fy;		//불위치 
		
	//맵 정보 입력 
	for(int i=0; i<N; i++)  {
		for(int j=0; j<N; j++) {
			cin >> arr[i][j];
			//불이난 위치 저장 
			if(arr[i][j]=='$') {
				fx=i;
				fy=j;
			}
		}
	}


	/*
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	*/
	

	cin >> x >> y;
	cout << flodFill(x, y, used[][]);
	cout << flodFill(fx, fy, fused[][]);
	
}
