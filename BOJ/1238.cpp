//BOJ 1238 - 파티
//https://www.acmicpc.net/problem/1238
//Algo: 다익스트라(dijkstra)
//풀이:https://howudong.tistory.com/284

#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 1001
#define INF 987654321

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int N, M, X, i, j, ans=0;
int map[MAX_N][MAX_N];
int dist[MAX_N];
int visit[MAX_N];
typedef pair<int, int> pii;

void init_array() {
    for(i=1; i<=N; i++) {
        for(i=1; i<=N; i++) {
            if(i!=j)
                map[i][j]=INF;
        }
    }

    for(i=1; i<=N; i++) 
        dist[i] = INF;

}

void dijkstra(int num) {

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, num});
    

    while(!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        for(i=1; i<=N; i++) {
            if(dist[i]> dist[here]+map[here][i]) {
                dist[i]=dist[here]+map[here][i];
                pq.push(make_pair(dist[i], i));
            }
        }
    }

}



int main() {

    int A, B, T;
	
    freopen("/Users/timchoi/Git/SWCert/input/BOJ_1238.txt", "r", stdin);
    //freopen("D:/Git/SWCert/input/BOJ_1238.txt", "r", stdin);
    scanf("%d %d %d", &N, &M, &X);
    //printf("N: %d M: %d x: %d\n", N, M, X);

    init_array();

    for(i=1; i<=M; i++) {
        scanf("%d %d %d", &A, &B, &T);
        //printf("A: %d B: %d T: %d\n", A, B, T);
        map[A][B]=T;
        
    }

    for(i=1; i<=N; i++) 
        dijkstra(i);

    printf("%d\n", ans);

    return 0;
}