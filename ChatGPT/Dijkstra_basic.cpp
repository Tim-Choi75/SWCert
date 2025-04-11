#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // ���Ѵ븦 �ǹ�

// ���� ���� ����ü (���, ������)
typedef pair<int, int> pii;

void dijkstra(int start, vector<vector<pii>>& graph, vector<int>& distance) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // ����� ���� ������ ����

    distance[start] = 0;
    pq.push({0, start}); // ���� ��� (���, ���)

    while (!pq.empty()) {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        // �̹� ó���� ���� ����
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
    int V, E; // ���� ��, ���� ��
    cin >> V >> E;

    vector<vector<pii>> graph(V + 1); // 1-indexed
    vector<int> distance(V + 1, INF);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // u���� v�� ���� ����ġ w�� ����
        graph[u].emplace_back(w, v);
    }

    int start = 1; // ���� ��� (�ʿ��ϸ� �Է����� �޾Ƶ� ��)
    dijkstra(start, graph, distance);

    // ��� ���
    for (int i = 1; i <= V; ++i) {
        if (distance[i] == INF)
            cout << "INF\n";
        else
            cout << distance[i] << '\n';
    }

    return 0;
}