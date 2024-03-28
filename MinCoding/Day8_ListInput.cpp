//인접 행렬 List Input 
//https://pro.mincoding.co.kr/enterprise/contest/sds/446/problem/DAY3_02
//Algo: Vector
//https://ldgeao99.tistory.com/266
//https://developer-cat.tistory.com/17

#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int N, T;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> T;
	cout << N << "," << T << endl;
	//vector<int> vec(N,N);
	vector <vector<int> > vv(N, vector<int>(N, 0));
	
	int from, to;
	for(int i=0; i<T; i++) {
		cin >> from >> to;
		cout << from << "," << to << endl;
		vv[from][to]=1;
	}
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cout << vv[i][j] << " ";			
		}
		cout << endl;
	}
	
	return 0;
	
}
