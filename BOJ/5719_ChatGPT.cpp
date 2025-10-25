#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

// Edge 구조체: 목적지 정점(to)와 가중치(weight)를 가진다.
struct Edge {
    int to;
    int weight;
};

int N, M;           // N: 정점 수, M: 간선 수
int S, D;           // S: 출발점, D: 도착점
vector<vector<Edge>> graph;             // 인접 리스트 방식의 그래프: graph[u] -> u에서 나가는 간선 목록
unordered_map<int, vector<int>> parents; // 각 정점별로 '최단 경로 상의 바로 이전 노드들'을 저장 (역추적용)
vector<vector<bool>> removed;           // 제거된 간선 여부: removed[u][v]가 true면 u->v 간선을 사용하지 않음

// 다익스트라: start에서 모든 정점까지의 최단 거리를 dist에 채운다.
// 이 함수에서 parents 맵을 갱신하여 '최단 경로의 부모들'을 기록한다.
void dijkstra(int start, vector<int>& dist) {
    // dist를 무한(INF)으로 초기화
    dist.assign(N, INT_MAX);

    // 우선순위 큐(거리, 정점) - 최소 힙
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // 시작점 초기화
    dist[start] = 0;
    pq.push({0, start});

    // 큐가 빌 때까지 반복
    while (!pq.empty()) {
        auto [cost, now] = pq.top();
        pq.pop();

        // 현재 꺼낸 비용이 이미 알고 있는 최단거리보다 크면 무시
        if (cost > dist[now]) continue;

        // 현재 정점에서 나가는 모든 간선 탐색
        for (auto& edge : graph[now]) {
            int next = edge.to;
            int w = edge.weight;

            // 만약 이 간선이 '제거된 간선'이면 건너뛴다
            if (removed[now][next]) continue;

            int nextDist = cost + w;

            // 더 짧은 경로를 찾았을 때
            if (nextDist < dist[next]) {
                dist[next] = nextDist;       // 거리 갱신
                pq.push({nextDist, next});   // 큐에 추가
                parents[next].clear();       // 이전 부모 목록 초기화
                parents[next].push_back(now);// 새 부모로 now 추가
            }
            // 같은 최단거리를 찾았을 때 (동일 거리 경로가 여러 개일 수 있음)
            else if (nextDist == dist[next]) {
                parents[next].push_back(now);// 추가 부모로 now 추가 (역추적 시 모든 경로 제거 위해)
            }
        }
    }
}

// BFS(또는 큐)를 이용해 도착점 dest에서 시작하여 parents를 따라 올라가며
// 모든 '최단 경로에 포함된 간선'을 removed에 표시하여 제거한다.
void removeShortestPaths(int dest, const vector<int>& dist) {
    queue<int> q;
    q.push(dest);

    // 방문 체크(선택적). 부모 그래프에서 중복으로 같은 정점을 여러 번 큐에 넣지 않도록 한다.
    vector<bool> visited(N, false);
    visited[dest] = true;

    while (!q.empty()) {
        int now = q.front(); q.pop();

        // now로 올 수 있었던 모든 이전 정점(prev)을 순회
        for (int prev : parents[now]) {
            // prev -> now 간선들을 찾아서 실제로 최단 경로 상의 간선이면 제거 표시
            for (auto& e : graph[prev]) {
                if (e.to == now) {
                    // 안전 검사: dist[prev] + e.weight == dist[now] 인 경우에만 최단 경로 간선이다
                    if (dist[prev] != INT_MAX && dist[prev] + e.weight == dist[now]) {
                        removed[prev][now] = true;
                    }
                }
            }

            // prev가 아직 큐에 넣은 적 없다면 넣어서 그 부모들도 처리하게 함
            if (!visited[prev]) {
                visited[prev] = true;
                q.push(prev);
            }
        }
    }
}
//https://chatgpt.com/share/68fc476e-67f4-8000-b5e7-f9f73ff5d603
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        // 입력: N, M (둘 다 0이면 종료)
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        // 그래프 초기화: 정점 0..N-1
        graph.assign(N, {});

        // removed 행렬 초기화: N x N, false로 초기화
        // (N 최대 1000이므로 N*N bool은 메모리 허용 범위 내)
        removed.assign(N, vector<bool>(N, false));

        // 출발점 S, 도착점 D 입력
        cin >> S >> D;

        // 간선 입력 M개: u v p (u->v 가중치 p)
        for (int i = 0; i < M; ++i) {
            int u, v, p;
            cin >> u >> v >> p;
            graph[u].push_back({v, p});
        }

        // 1) 첫 번째 다익스트라로 최단거리 계산
        vector<int> dist;
        parents.clear();        // parents 맵 초기화
        dijkstra(S, dist);

        // 2) 최단 경로 간선들을 제거
        removeShortestPaths(D, dist);

        // 3) 제거된 간선을 반영한 상태에서 두 번째 다익스트라 수행
        //    (parents를 다시 갱신해도 되지만, 두번째 결과의 parents는 필요 없다)
        vector<int> dist2;
        // 부모 정보 재사용을 막기 위해 clear 해도 되고, 여기선 재사용하지 않음
        parents.clear();
        dijkstra(S, dist2);

        // 도착점까지의 거리가 존재하면 출력, 없으면 -1 출력
        if (dist2[D] == INT_MAX) cout << -1 << '\n';
        else cout << dist2[D] << '\n';
    }

    return 0;
}
