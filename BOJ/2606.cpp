//���� 2606 - ���̷���
//https://www.acmicpc.net/problem/2606
//Algo: Union Find
//Ǯ��: https://redcoder.tistory.com/65

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
	x= Find(x);	//x�� �ֻ��� �θ� 
	y= Find(y); //y�� �ֻ��� �θ�
	
	if(x != y) {
		parent[y]=x;	//y�� �ֻ��� �θ� x�� �����Ѵ� 
	}
}

int solve(int virus, int n) {
 //Virus�� �����ϴ� ������ ���� ���� ���� ��
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
	
	//�ʱ�ȭ
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
