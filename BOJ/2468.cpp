//백준 2468 - 안전 영역 
//https://www.acmicpc.net/problem/2468
//Algo: 
//2667과 비슷 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 101
#define endl "\n" 

int N, cnt, maxN=1; 
int arr[MAX_N][MAX_N], visit[MAX_N][MAX_N];
int dx[4]={0, 0, -1, 1};
int dy[4]={0, 0, -1, 1};
vector<int> v;

void DFS(int x, int y, int h) {
	
	visit[x][y]=1;
	
	for(int i=0; i<4; i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx<0 || nx>=N || ny<0 || ny>=N )
			continue;
		
		if(arr[nx][ny]>h && visit[nx][ny]==0) {
			visit[nx][ny]=1;
			cnt++;
			DFS(nx,ny,h);
		}
	}

}


int main() {
	
	cin >> N;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> arr[i][j];
			if(arr[i][j]>=maxN)
				maxN=arr[i][j];	
		}
	}
	
	//cout << "maxN: " << maxN;
		
	for(int h=1; h<=maxN-1; h++) {//1부터 최대높이-1까지 
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(arr[i][j]>h && visit[i][j]==0) {
					cnt=1;
					DFS(i,j,h);		
					v.push_back(cnt);
				}
			}
		}		
	}
	
	cout << "vector size: "<< v.size() << endl;
		
	for(int i=0; i<v.size(); i++)
		cout << v[i] <<" ";
	
	cout << endl;	
	int max=*max_element(v.begin(), v.end());
	cout << max;
	
	return 0;
} 
