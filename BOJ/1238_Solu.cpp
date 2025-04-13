//BOJ 1238 - 파티
//https://www.acmicpc.net/problem/1238
//Algo: 다익스트라(dijkstra)
//풀이:https://howudong.tistory.com/284

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999999
int N,M,X;
vector<pair<int,int>> v[1001]; // 마을과 간선 정보
int d[1001][1001] = {0,}; // 각 정점에서 다른 정점으로의 최소 비용 정보

// 다익스트라 알고리즘(매개변수 : 기준 정점)
void dijkstra(int num){
    // 거리에 대해 내림차순 정렬(거리가 짧은것부터 뽑힘)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

    d[num][num] = 0;
    q.push({0,num});

    while(!q.empty()){
        int x = q.top().second;
        int distance = q.top().first;
        q.pop();

        // 연결된 간선
        for(int i = 0; i < v[x].size(); i++){
            int nx = v[x][i].first; // 연결된 마을
            // 기존 시간 + 그 도로를 건너는데 드는 비용
            int nDistance =distance + v[x][i].second;
            
            // 기존에 것보다 거리가 짧으면 갱신
            if(d[num][nx] > nDistance){
                d[num][nx] = nDistance;
                q.push({nDistance,nx});
            }
        }
    }

}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    freopen("D:/Git/SWCert/input/BOJ_1238.txt", "r", stdin);
    
    cin >> N >> M >> X;

    for(int i = 0; i < M; i++){
        int v1,v2,v3;
        cin >> v1 >> v2 >> v3;
        v[v1].push_back({v2,v3});
    }
    fill(&d[0][0],&d[1000][1001],INF);
    for(int i = 1; i <= N; i++) dijkstra(i);


    int ans = 0;
    for(int i = 1; i<= N; i++){
        ans = max(ans,d[i][X]+d[X][i]);
    }
    cout << ans;

}