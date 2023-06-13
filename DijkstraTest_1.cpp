/* https://www.youtube.com/watch?v=w2hQaGzWYc8 */

#include <iostream>
#include <queue>

using namespace std;

#define INF 987654321
#define MAX_N 10

typedef pair<int, int> pii;

int N, E;
int Graph[MAX_N][MAX_N], Dist[MAX_N];

void dijkstra(int src) {
	priority_queue< pii, vector<pii>, greater<pii> > pq;
	bool visited[MAX_N] = {false};
	
	for(int i=0; i<N; i++)
		Dist[i]=INF;
	
	Dist[src]=0;
	
	pq.push(make_pair(0, src));
	
	while(!pq.empty()) {
		int u = pq.top().second;
		pq.top();
		if(visited[u]) 
			continue;
			
		visited[u] = true;
		for(int v=0; v<N; ++v) {
			if(Dist[v] > Dist[u]+Graph[u][v]) {
				Dist[v] = Dist[u]+Graph[u][v];
				pq.push(make_pair(Dist[v], v));
			}
		}
	}
	
}

int main() {
	
	freopen("./src/DijkstraTest_1.txt", "r", stdin);
	cin >> N >> E;
	cout << N << E << endl;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i==j)
				Graph[i][j]=0;
			else
				Graph[i][j]=INF;			
		}
	}
	
	for(int i=0; i<E; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;		
		Graph[u][v] = Graph[v][u] = cost;
	}
	
	dijkstra(0);
	
	for(int i=0; i<N; ++i)
		cout << Dist[i] << ' ';
		cout << endl;
		return 0;
}
