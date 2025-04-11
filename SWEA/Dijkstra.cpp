//https://swexpertacademy.com/main/learn/referenceCode/referenceCodeDetail.do?referenceId=DIJKSTRA&category=undefined

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_N 101
#define INF 1e9

typedef pair<int, int> pii;




int main() {

	freopen("/Users/timchoi/Git/SWCert/input/SWEA_Dijkstra.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/SWEA_Dijkstra.txt", "r", stdin);

    int tc, i, j, node, start, end, edge, a, b, c;
    int dist[MAX_N];
    vector<pii> graph[MAX_N];
    priority_queue<pii, vector<pii>, greater<pii>> pq;


    scanf("%d", &tc);
    printf("tc: %d\n", tc);

    for(i=1; i<=tc; i++) {

        scanf("%d %d %d", &node, &start, &end);
        printf("node: %d, start: %d, end: %d\n", node, start, end);

        scanf("%d", &edge);
        //printf("edge: %d\n", edge);

        for(j=1; j<=edge; j++) {
            scanf("%d %d %d", &a, &b, &c);
            //printf("a: %d, b: %d, c: %d\n", a, b, c);
            graph[a].push_back(make_pair(b,c));
        }

        for(j=1; j<=node; j++)
            dist[j] = INF;
        
        dist[start]=0;
        pq.push(make_pair(start, 0));

        while(!pq.empty()) {
            int now = pq.top().first;
            int nowCost = pq.top().second;
            printf("now: %d,  nowCost: %d\n", now, nowCost);

            pq.pop();

            if(nowCost > dist[now])
                continue;

            for(i=1; i<=graph[now].size(); i++) {

                int next = graph[now][i].first;
                int nextCost = nowCost + graph[now][i].second;
                
                printf("next: %d,  nextCost: %d\n", next, nextCost);

                if(dist[next] > nextCost) {
                    printf("IN: next: %d,  dist[next]: %d, nextCost: %d\n", next, dist[next], nextCost);
                    dist[next] = nextCost;
                    pq.push(make_pair(next, nextCost));
                }//if
            }//for

        }//while-pq

        printf("%d\n", dist[end]);

    }//while-tc


    return 0;
}