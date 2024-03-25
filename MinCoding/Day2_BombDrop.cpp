//∆¯≈∫≈ı«œ
//https://pro.mincoding.co.kr/enterprise/contest/sds/445/problem/DAY2_01

#include <iostream>
#include <algorithm>

using namespace std;

char arr[4][5]={0,};
int dy[8]={-1,1,0,0,-1,-1,1,1};
int dx[8]={0,0,-1,1,-1,1,-1,1};

int x,x1,y,y1,nx,ny;


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	for(int i=0; i<4; i++) {
		for(int j=0; j<5; j++) {
			arr[i][j] = '_';	
		}
	}


	for(int i=0; i<2; i++) {
		cin >> y;
		cin >> x;
		
		for(int i=0; i<8; i++) {
			nx = x+dx[i];
			ny = y+dy[i];
			
			if(nx>=5 || nx<0 || ny>=4 || ny<0)
				continue;			
			
			arr[ny][nx]='#';
		}
	}
	
	for(int i=0; i<4; i++) {
		for(int j=0; j<5; j++) {
			cout << arr[i][j] <<" ";	
		}
		cout <<"\n";
	}
	
	
	return 0;
}
