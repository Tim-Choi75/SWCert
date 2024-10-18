//https://codeup.kr/problem.php?id=2840

#include <iostream>
#include <queue>
using namespace std;

#define INF 999
#define MAX_N 1000
int n, m, i, j;
int weight[MAX_N][MAX_N], dist[MAX_N];
bool visit[MAX_N];

void print_weight() {
    cout << endl;
    cout << "----- print_weight -----" << endl;
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            cout << weight[i][j] << " ";
        }
        cout << endl;
    }            
}

void print_dist() {
    cout << "----- print_dist -----" << endl;
    for(i=1; i<=n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

void init_weight() {
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            if(i==j)
                weight[i][j]=0;
            else
                weight[i][j]=INF;
        }
    }
}

void dijkstra(int start) {
    for(i=1; i<=n; i++) {
        dist[i] = weight[start][i];
    }

    print_dist();

}
  

int main() {

    cin >> n >> m;
    int s, e, w;

    init_weight();

    for(i=1; i<m; i++) {
        cin >> s >> e >> w;

        weight[s][e]=w;
        weight[e][s]=w;
    }
    
    print_weight();

    dijkstra(1);
  
    return 0;
}