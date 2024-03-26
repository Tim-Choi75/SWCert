//백준 2606 - 바이러스
//https://www.acmicpc.net/problem/2606
//Algo: Union Find
//풀이: https://redcoder.tistory.com/65

#include <iostream>

using namespace std;

int ans=0;
int parent[101];

int Find(int x) {
	if(x == parent[x])
		return x;
	else {
		int p = Find(parent[x]);
		parent[x]=p;
		return p;
	}
}

void Union(int x, int y) {
	x= Find(x);	//x의 최상위 부모 
	y= Find(y); //y의 최상위 부모
	
	if(x != y) {
		parent[y]=x;	//y의 최상위 부모를 x로 저장한다 
	}
}

int solve(int virus, int n) {
 //Virus가 존재하는 집합의 원소 갯수 구하 기
 for(int i=2; i<=n; i++) {
 	if(Find(i) ==virus)
 	ans++;
 }
 return ans;	
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int n, m, a, b;
	cin >> n >> m;
	
	//초기화
	for(int i=1; i<=n; i++) {
		parent[i]=i;
	}
	
	while(m--) {
		cin >> a >> b;
		Union(a,b);
	} 
	
	int root=Find(1);
	cout << solve(root, n);
	
	return 0;

}
