//https://www.acmicpc.net/problem/1753
//https://tinyurl.com/28lmv72p
//https://dev-check.tistory.com/11

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 20005

using namespace std;

vector<pair<int, int>> node[20005];
priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > pq;
int value[20005];

int main() {

    int V, E, K;
    int u, v, w, i, j;

    cin >> V >> E >> K;

    for(i=0; i<E; i++) {
        cin >> u >> v >> w;
        node[u].push_back(make_pair(v, w));
    }

    for(i=1; i<=V; i++) 
        value[i]=INF;

    value[K]=0;

    pq.push(make_pair(0, K));

    while(!pq.empty()) {
        int x = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        for(i=0; i<node[u].size(); i++) {
            int v = node[u][i].first;
            int w = node[u][i].second;
        }

        if(x+w < value[v]) {
            value[v] = x+w;
            pq.push(make_pair(x+w, v));
        }

    }//while

    for(i=1; i<=V; i++) {
        if(value[i]==INF)
            cout << "INF" << endl;
        else
            cout << value[i] << endl;
    }

}