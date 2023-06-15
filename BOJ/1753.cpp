//최단경로 
//https://www.acmicpc.net/problem/1753
//Algo: Dijkstra
//Solu:https://yabmoons.tistory.com/376
//Result:

#include <iostream>
#include <vector>

#define endl "\n"
#define MAX 20010
#define INF 987654321

int V, E, start;	//V:정점, E:간선 
int MAP[MAX][MAX];
int dist[MAX];
bool Select[MAX];

using namespace std;

void input()
{
	cin >> V >> E >> start;
	
	for(int i=1; i<=V; i++) {
		dist[i] = INF;
		for(int j=1; j<=V; i++) {
            if (i == j) 
				MAP[i][j] = 0;
            else
				MAP[i][j] = INF;			
		}		
	}
	
	for(int i=0; i<E; i++) {
		int a, b, c; 
		cin >> a >> b >> c;
		MAP[a][b] = c;
	}
	
	
}

void dijkstra() {
	
}

void solution() {
	
	dijkstra();
	
	for(int i=1; i<=V; i++) {
		if(dist[i]==INF) 
			cout<<"INF"<<endl;
		else cout
			cout<<dist[i]<<endl;		
	}
}
void solve() 
{
	input();
	solution();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    
    //freopen("./BOJ_1753.txt", "r", stdin);
	solve();
	
    return 0;
}
