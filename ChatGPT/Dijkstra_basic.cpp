#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // 무한대를 의미

// 간선 정보 구조체 (비용, 목적지)
typedef pair<int, int> pii;

void dijkstra(int start, vector<vector<pii>>& graph, vector<int>& distance) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // 비용이 작은 순으로 정렬

    distance[start] = 0;
    pq.push({0, start}); // 시작 노드 (비용, 노드)

    while (!pq.empty()) {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        // 이미 처리된 노드면 무시
        if (distance[current] < cost) continue;

        for (const auto& edge : graph[current]) {
            int next = edge.second;
            int next_cost = cost + edge.first;

            if (next_cost < distance[next]) {
                distance[next] = next_cost;
                pq.push({next_cost, next});
            }
        }
    }
}

int main() {
    int V, E; // 정점 수, 간선 수
    cin >> V >> E;

    vector<vector<pii>> graph(V + 1); // 1-indexed
    vector<int> distance(V + 1, INF);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // u에서 v로 가는 가중치 w인 간선
        graph[u].emplace_back(w, v);
    }

    int start = 1; // 시작 노드 (필요하면 입력으로 받아도 됨)
    dijkstra(start, graph, distance);

    // 결과 출력
    for (int i = 1; i <= V; ++i) {
        if (distance[i] == INF)
            cout << "INF\n";
        else
            cout << distance[i] << '\n';
    }

    return 0;
}