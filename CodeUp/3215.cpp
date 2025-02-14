//CodeUp 3215 - 최단경로 1
//https://codeup.kr/problem.php?id=3215
//Algo: 다익스트라(dijkstra)
//풀이: https://crane206265.tistory.com/21
#define _CRT_SECURE_NO_WARINGS
#define MAX_N 27
#define INF 987654321

#include <stdio.h>

char st_nodec, fn_nodec;
int N, M, st_node, fn_node, d, start, end, i, j;
int weight[MAX_N][MAX_N];
int dist[MAX_N];
int visit[MAX_N];

void init_weight() {

    for(i=1; i<=N; i++) {
        for(i=1; i<=N; i++)
            if(i!=j)
                weight[i][j] = INF;
    }

}

void dist_init() {
    for(i=1; i<=N; i++)
        dist[i] = weight[st_node][i];
}

int all_visit() {
    int ret=0;
    for(i=1; i<=N; i++) {
        if(visit[i]==0) {
            ret=0;
        } else {
            ret=1;
        }
    }
    return ret;
}

int min_dist_index() {
    int index = 0;
    int min_dist = INF;
    for(i=1; i<=N; i++) {
        if(visit[i]==0) {
            if(min_dist > dist[i]) {
                min_dist = dist[i];
                index = i;
            }
        }
    }
    visit[index]=1;
    return index;
}

void dijkstra() {

    while(!all_visit()) {
        if(visit[fn_node]==1) {
            break;
        }

        int via_n = min_dist_index();
        for(i=1; i<=N; i++) {
            if(visit[i]==0) {
                int dist_d = dist[i];
                int dist_v = dist[via_n]+weight[via_n][i];
                dist[i] = dist_d<dist_v?dist_d:dist_v;
            }   
        }

    }//while
}


int main() {

    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    
    scanf("%d %d", &N, &M);
    init_weight();

    for(i=1; i<=M; i++) {
        char nd1, nd2;
        scanf("%c %c %d", &nd1, &nd2, &d);

        weight[(int)nd1-65][(int)nd2-65]=d;
        weight[(int)nd2-65][(int)nd1-65]=d;
    }
    scanf("%c %c", &st_nodec, &fn_nodec);
    st_node = (int)st_nodec-65;
    fn_node = (int)fn_nodec-65;

    dist_init();
    visit[st_node]=1;

    dijkstra();

    if(dist[fn_node]==INF) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[fn_node]);
    }

    return 0;
}