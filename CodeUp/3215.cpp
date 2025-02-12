//CodeUp 3215 - 최단경로 1
//https://codeup.kr/problem.php?id=3215
//Algo: 다익스트라(dijkstra)
//풀이:
#define _CRT_SECURE_NO_WARINGS
#define MAX_N 27
#define INF 987654321

#include <stdio.h>

int N, M, A, B, weght, start, end, i, j;
int graph[MAX_N][MAX_N];
int dist[MAX_N];

void init_weight() {

    for(i=1; i<=MAX_N; i++) {
        for(i=1; i<=MAX_N; i++)
    
    }

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    scanf("%d %d", &N, &M);
    
    for(i=1; i<=M; i++) {
        scanf("%c %c %d", &A, &B, &weight);

        scanf("%c %c", &start, &end);

        init_weight()

    }



    return 0;
}