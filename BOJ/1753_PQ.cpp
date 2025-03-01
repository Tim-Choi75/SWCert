#include <iostream>
#include <queue>
#include <vector>

#define endl "\n"
#define MAX 20010
#define INF 987654321

using namespace std;

int V, E, Start, i, j;
int Dist[MAX];
vector<pair<int, int>> Vertex[MAX];

void input() {

    cin >> V >> E >> Start;
    for(i=0; i<E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Vertex[a].push_back(make_pair(b, c));

    }

    for(i=1; i<=V; i++) {
        Dist[i]=INF;
    }


}

void dijkstra() {

    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, Start));
    Dist[Start]=0;


    while(!PQ.empty()) {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;

        PQ.pop();

        for(i=0; i<Vertex[Cur].size(); i++) {
            int next = Vertex[Cur][i].first;
            int nCost = Vertex[Cur][i].second;

            if(Dist[next] > Cost + nCost) {
                Dist[next] = Cost + nCost;
                PQ.push(make_pair(-Dist[next], next));
            }
        }
    }

    for(i=1; i<=V; i++) {
        if(Dist[i] == INF)
            cout << "INF" << endl;
        else 
            cout << Dist[i] << endl;
    }

}

void solve() {
    input();
    dijkstra();

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("D:/Git/SWCert/input/BOJ_1753.txt", "r", stdin);
    solve();
}