/* CodeUp 4421
https://codeup.kr/problem.php?id=4421
Algo: DFS
Solve: https://scarlettb.tistory.com/81
*/

#include <iostream>
using namespace std;
int N;
int data[25][25];
int check[25][25]={0};
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
vector<int> v;	//solve
int house = 1;	//solve
int label = 1;	//solve

int input() {

	cin >> N;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cin >> data[i][j];
		}
	}	
	
	return 0;
	
}

int dfs(int nowx, int nowy) {
	
	int nx, ny;
	int count = 1;
	check[nowx][nowy]=1;
	
	for(int i=0; i<4; i++) {
		nx=nowx+dx[i];
		ny=nowy+dy[i];
		
		if(nx<=N && nx>=1 && ny<=N && ny>=1) {
			if(check[nx][ny]==0 && data[nowx][nowy]==1) {
				dfs(nx, ny);
			}
		}
		
	}
	
	
	return 0;
}

int solve() {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(check[i][j]==0 && data[i][j]==1) {
				dfs(i,j);
				label++;
				v.push_back(house);
				house=0;
			}	
		}
	}
	return 0;
}

int main() {
	
	input();
	solve();

	sort(v.begin(), v.end());
	cout << label-1 << endl;
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << endl;
	}
	
	return 0;

}
