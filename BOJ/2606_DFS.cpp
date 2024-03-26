//���� 2606 - ���̷���
//https://www.acmicpc.net/problem/2606
//Algo: DFS
//Ǯ��: https://gimmesome.tistory.com/68

#include <iostream>

using namespace std;
const int MAX=100+1;

int N, P;	//N: ��ǻ�ͼ�, P: ��ǻ�ͽּ� 
int adjacent[MAX][MAX];	//1�̸� ������ �ǹ�
bool visited[MAX];
int cnt;

void DFS(int v) {
	cnt++;
	for(int i=1; i<=N; i++) {
		//����Ǿ��ְ� �湮���� ���� ����϶� 
		if(adjacent[v][i]==1 && visited[i]==0) {
			visited[i]=1;
			DFS(i);
		}
	}
}

int main () {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N >> P;
	
	for(int i=0; i<P; i++) {
		int from, to;
		cin >> from >> to;
		adjacent[from][to]=1;
		adjacent[to][from]=1;
	}
	
	visited[1]=1;
	DFS(1);
	
	cout << cnt-1;
	
	return 0;
	
}//main
