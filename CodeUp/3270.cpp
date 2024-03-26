//CodeUp 3270 - 중립국 1
//https://codeup.kr/problem.php?id=3270
//Algo: Union Find
//풀이:

#include <iostream>

using namespace std;

int N, M;
int parent[1001];

int Find(int now) {
	if(now == parent[now])
		return now;

	return parent[now] = Find(parent[now]);
}

void Union(int A, int B) {
	int root_A = Find(A);
	int root_B = Find(B);
	
	if(root_A != root_B) {
		parent[root_B] = root_A;
	}
	
	return;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;	
	
	//초기화 
	for(int i=0; i<N; i++) {
		parent[i]=i;
	}
	
	int a,b;
	for(int i=0; i<M; i++) {
		cin >> a >> b;
		Union(a, b);
	}
	
	for(int i=0; i<N; i++) {
		//cout << Find(parent[i]) << " ";
		cout << Find(i) << " ";
	}
	
	return 0;
}
