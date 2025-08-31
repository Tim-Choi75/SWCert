//백준(BOJ) 17396 - 백도어
//https://www.acmicpc.net/problem/17396
//Algo: Dijkstra
//Solve: https://junseok.tistory.com/286

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define F first
#define S second
#define INF 1234987654321
#define LL long long int 
#define P pair<LL, int>
#define isPrint 1

using namespace std;

int N, M;
int View[100001];
vector<P> connect[100001];
LL Distance[100001];
priority_queue<P> q;

void reset_distance(){
    for(int i = 1; i <= N; i++){
        Distance[i] = INF;
    }
}

void Dijstra(){
    Distance[1] = 0;
    q.push({-0, 1});
    while(!q.empty()){
        int x = q.top().S;
        LL cost = -q.top().F;
        if (isPrint) printf("cost: %lld, x: %d\n", cost, x);

        q.pop();
        if(Distance[x] < cost) continue;
        for(int i = 0; i < connect[x].size(); i++){
            int xx = connect[x][i].F;
            int n_cost = connect[x][i].S;
            if (isPrint) printf("n_cost: %lld, xx: %d\n", n_cost, xx);
            
            if(Distance[xx] > Distance[x] + n_cost){
                Distance[xx] = Distance[x] + n_cost;
                if (isPrint) printf("x: %d->xx: %d, Distance[xx]: %lld\n", x, xx, Distance[xx]);
                q.push({-Distance[xx], xx});
            }
        }
    }
}

void solve(){
    reset_distance();
    Dijstra();
    if(Distance[N] == INF) cout << "-1";
    else cout << Distance[N];
}

int main() {

	freopen("D:/Git/SWCert/input/BOJ_17396.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_17396_1.txt", "r", stdin);

    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> View[i];
    }
    View[N] = 0;
    for(int i = 1; i <= M; i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        printf("x: %d, y: %d, cost: %d\n", x, y, cost);

        if(View[x+1] == 1 || View[y+1] == 1) continue;
        connect[x+1].push_back({y+1, cost});
        connect[y+1].push_back({x+1, cost});
    }
    solve();
    return 0;
}
