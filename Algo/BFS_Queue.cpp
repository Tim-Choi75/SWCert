// BFS
//https://www.youtube.com/watch?v=RxT7F6YA3TI


#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define endl "\n"
#define MAX_N 10

int N, E;
int Graph[MAX_N][MAX_N];

void bfs(int node) {
	
	bool visited[MAX_N]={false};
	
	queue<int> myqueue;
	visited[node]=true;
	myqueue.push(node);
	
	while(!myqueue.empty()) {
		int curr = myqueue.front();
		myqueue.pop();
		
		cout << curr << " ";
		
		for(int next=0; next<N; next++) {
			if(visited[next]==0 && Graph[curr][next]==1) {
				visited[next]=true;
				myqueue.push(next);
			}
		}//for
	}//while
}//bfs

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N >> E;
	memset(Graph, 0, sizeof(Graph));
	
	for(int i=0; i<E; i++) {
		int u, v;
		cin >> u >> v;
		Graph[u][v]=Graph[v][u]=1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {	
			cout << Graph[i][j] <<" ";
		}
		cout << endl;
	}
	
	bfs(0);
	
	return 0;
}
