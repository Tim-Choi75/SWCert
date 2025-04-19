//프로그래머스(Programmers) Level 2 - 배달
//https://school.programmers.co.kr/learn/courses/30/lessons/12978

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
int i;
vector<pii> v[51];
vector<int> dist;

int min(int a, int b) {
    if(a<b)
        return a;
    else 
        return b;
}


void dijkstra(int N) {
    priority_queue<pii> pq;
    pq.push({0, 1});
    dist[1]=0;
    
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        for(i=0; i<v[curr].size(); i++) {
            int next = v[curr][i].first;
            int ncost = cost + v[curr][i].second;
            
            if(dist[next] > ncost) {
                dist[next] = ncost;
                pq.push({-ncost, next});
            }
        }
        
    }//while
    
}

int solution(int N, vector<vector<int> > road, int K) {
    
    dist.resize(N+1, 1e9);
    
    for(i=0; i<road.size(); i++) {
        int N1 = road[i][0];
        int N2 = road[i][1];
        int dist = road[i][2];
        
        v[N1].push_back({N2, dist});
        v[N2].push_back({N1, dist});        
    }
    
    dijkstra(N);
    int answer = 0;
    
    for(i=1; i<=N; i++) {
        if(dist[i]<=K)
            answer++;
    }
    
    return answer;
}