/* https://www.youtube.com/watch?v=w2hQaGzWYc8 */
#define _CRT_SECURE_NO_WARINGS

#include <iostream>
#include <queue>

using namespace std;

#define INF 987654321
#define MAX_N 10

typedef pair<int, int> pii;

int N, E;
int map[MAX_N][MAX_N];
int dist[MAX_N];

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
	
	freopen("D:/Git/SWCert/input/DijkstraTest.txt", "r", stdin); 
	scanf("%d %d", &N, &E);	//N:노드수, E:간선수
	
	for(int i=1; i<=N; i++) {
		for(int j=0; j<N; j++) {
			if(i==j)
				Graph[i][j]=0;
			else
				Graph[i][j]=INF;			
		}
	}
	
	for (i = 1; i <= E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = c;
	}
	
	dijkstra(1);
	
	for(int i=1; i<=N; ++i)
		printf("%d ", dist[i]);
	
	return 0;
}
