#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 노드의 정보를 담는 벡터 (v[의존성을 받는 컴] = (시간,의존성 컴))
vector<pair<int,int>> v[100001]; 
int dp[100001]; // 각 노드의 최소 시간을 담는 dp 배열
int n,d,c;

// 다익스트라 알고리즘
void dijkstra(int x){
    // 우선순위 큐 (내림차순 정렬) 꺼낼 때, 시간을 기준으로 작은 것부터 꺼내짐
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    dp[x] = 0; // 자기 자신의 시간을 0으로 설정
    q.push(make_pair(0,x)); // 큐에 넣음


    while(!q.empty()){
        int cnt = q.top().second; // 현재 노드
        int t = q.top().first; // 현재 시간
        q.pop();
        // 최단거리가 아닐 경우엔 굳이 안해도 됨
        if(dp[cnt] < t) continue;
        for(int i = 0; i < v[cnt].size(); i++){
            int next = v[cnt][i].second; // 다음 노드
            int nextTime = v[cnt][i].first + t; // 현재 시간 + 가는 시간
            // 저장되어있는 시간보다 작아야만 갱신
            if(nextTime < dp[next]){
                dp[next] = nextTime;
                q.push(make_pair(nextTime,next)); // 큐에 담음
            }
        }
    }

    // 개수 
    int com = 0, t = 0;
    for(int i = 1; i <= n; i++){
        if(dp[i] == INT32_MAX) continue;
        com++;
        t = max(t,dp[i]);
    }
    cout << com << " " << t << "\n";
    
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        cin >> n >> d >> c;
        fill(dp,dp+100001,INT32_MAX);
        for(int i = 0; i <= 100000; i++) v[i].clear();
        for(int i = 0; i < d; i++){
            int v1,v2,v3;
            cin >> v1 >> v2 >> v3;
            v[v2].push_back(make_pair(v3,v1)); // (시간,컴퓨터)
        }
        dijkstra(c);
    }
}