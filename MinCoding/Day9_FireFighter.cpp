//FireFighter
//https://pro.mincoding.co.kr/enterprise/contest/sds/446/problem/DAY4_03
//https://blog.naver.com/not_layer/223032814137 <- �̰Ŷ� ���?
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
# ��
A ��ȭ��
$ �� 
_ �����
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
			
			//���� �Ѿ�� ����
			if(nx<0 || nx>=N || ny<0 || ny>=N)
				continue;
			
			//��(#)�� ��($)�� ������ �� �����ϴ�
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
	cin >> N;	//N*Nũ���� �� �Է�

	int x, y;		//�ҹ�� ��ġ
	int fx, fy;		//����ġ 
		
	//�� ���� �Է� 
	for(int i=0; i<N; i++)  {
		for(int j=0; j<N; j++) {
			cin >> arr[i][j];
			//���̳� ��ġ ���� 
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
