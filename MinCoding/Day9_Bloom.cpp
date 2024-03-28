// Bloom
//https://pro.mincoding.co.kr/enterprise/contest/sds/446/problem/DAY4_02
//https://pro.mincoding.co.kr/enterprise/contest/sds/446/announcements/10397
//https://eastc.tistory.com/entry/c-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B3%B5%EB%B6%80-9-BFS-%EB%84%93%EC%9D%B4-%EC%9A%B0%EC%84%A0-%ED%83%90%EC%83%89


#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define endl "\n"
#define MAX_N 100
#define X first
#define Y second

int height, width, stx, sty, N=5;
bool visited[MAX_N][MAX_N]={false};
int Graph[MAX_N][MAX_N];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
queue<pair<int,int> > Q;

int FloodFill() {
	int maxi=0;
	
	
	while(!Q.empty()) {
		pair<int,int> curr = Q.front();
		Q.pop();

		//
		if(Graph[curr.X][curr.Y] > maxi) {
			//cout <<"curr.X: "<< curr.X << " curr.Y: "<< curr.Y  <<  " Graph[curr.X][curr.Y]: "<< Graph[curr.X][curr.Y] <<  ">"  << maxi << endl;
			maxi=Graph[curr.X][curr.Y];
			//cout <<"After maxi: "<< maxi << endl;
		}
			
					
		for(int i=0; i<4; i++) {
			
			int nx=curr.X+dx[i];
			int ny=curr.Y+dy[i];
			
			//경계는 넘을수 없다 
			if(nx<0 || nx>=height || ny<0 || ny>=width)
				continue;
						
			//방문한적이 있으면 skip
			if(visited[nx][ny]==1)
				continue;
			
			//cout <<  "height: "<< height << " width: " << width << " nx: "<< nx << " ny: "<< ny << endl;

			visited[nx][ny]=1;
			//cout <<"curr.X: "<< curr.X << " curr.Y: "<< curr.Y  <<  " visited[curr.X][curr.Y]: "<< visited[curr.X][curr.Y] << endl;
			//cout <<"nx: "<< nx << " ny: "<< ny << " visited[nx][ny]: "<<visited[nx][ny] << endl;
			Graph[nx][ny]=Graph[curr.X][curr.Y]+1;
			//cout <<"New Value: "<< Graph[curr.X][curr.Y]+1 << endl;
			//cout <<"nx: "<< nx << " ny: "<< ny << " After Graph[nx][ny]: "<< Graph[nx][ny] << endl;
			
			//새로운곳을 방문하고 거리를 늘린다. 
			Q.push({nx, ny});
		}//for 
	}//while
	return maxi;
}//FloodFill

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> height >> width;
	
	for (int i = 0; i <2; i++) {
		cin >> stx >> sty;
		//cout << "stx: " << stx << " sty: " << sty << " called " << endl;
		
		Q.push({stx, sty});
		visited[stx][sty]=1;
		Graph[stx][sty]=1;
	}
	cout << FloodFill();
	return 0;
}

