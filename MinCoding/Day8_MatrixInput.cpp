//인접 행렬 Matrix Input 
//https://pro.mincoding.co.kr/enterprise/contest/sds/446/problem/DAY3_01


#include <iostream>
#define endl "\n"

using namespace std;

int N, T, arr[10000][10000]= {0, };
int r, c;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> T;
	


	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			arr[i][j]=0;		
		}
	}
	
	for(int i=0; i<T; i++) {
		cin >> r >> c;
		//cout << r << "," << c << endl;
		
		arr[r][c]=1;
		//arr[c][r]=1;
	}

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cout << arr[i][j] << " ";			
		}
		cout << endl;
	}
	
	return 0;
	
}
