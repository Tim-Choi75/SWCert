//백준 2667 - 단지번호 붙이기 
//https://www.acmicpc.net/problem/2667
//Algo: BFS
//https://velog.io/@yoohoo030/%EB%B0%B1%EC%A4%802667-%EB%8B%A8%EC%A7%80%EB%B2%88%ED%98%B8%EB%B6%99%EC%9D%B4%EA%B8%B0-C

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>	//sort
using namespace std;

#define MAX_N 26
#define endl "\n" 


int N, cnt, arr[MAX_N][MAX_N], visit[MAX_N][MAX_N];
vector<int> v;
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

void BFS(int x, int y) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	
	visit[x][y]=1;
	int cnt=0;
	cnt++;				
	while(!q.empty()) {
		int front_x=q.front().first;
		int front_y=q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx=front_x+dx[i];
			int ny=front_y+dy[i];
			
			if(nx<0 || nx>=N || ny<0 || ny>=N)
			continue;
			
			if(arr[nx][ny]==1 && visit[nx][ny]==0) {
				q.push(make_pair(nx, ny));
				visit[nx][ny]=1;
				cnt++;	
			}	
		}//for
	}//while
	v.push_back(cnt);
}

int main() {
	cin >> N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(arr[i][j]==1 && visit[i][j]==0) {
				
				BFS(i, j);
			}
				
		}
	}
	
	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++)
		cout << v[i] << endl;
}
