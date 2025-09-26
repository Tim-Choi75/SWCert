//Kruskal Algorithm-동빈나
//https://www.youtube.com/watch?v=LQ3JHknGy8c

#include <iostream>
#include <vector>

using namespace std;

int getParent(int parent[], int x) {
    if(parent[x] == x)
        return x;
    return parent[x] = getParent(parent, parent[x]);
}

int unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if( a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if( a == b)
        return 1
    else
        return 0;
}

//간선 클래스
class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0]=a;
        this->node[a]=b;
        this->distance = distance;
    }

    bool operator < (Edge &edge) {
        return this->distance < edge.distance;
    }
};


int main(void) {
    int n = 7;
    int m = 11;

    vector<Edge> v;
    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(1, 7, 28));
    v.push_back(Edge(1, 2, 67));
    v.push_back(Edge(1, 5, 17));
    v.push_back(Edge(2, 4, 24));
    v.push_back(Edge(2, 5, 62));
    v.push_back(Edge(3, 5, 20));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(4, 7, 13));
    v.push_back(Edge(5, 6, 45));
    v.push_back(Edge(5, 7, 73));

    //간선의 비용을 기준으로 오름차순 정렬
    sort(v.begin(), v.end());
    
    //각정점이 포함된 그래프가 어디인지 저장
    int parent[n];
    for(int i=0; i<n; i++) 
        parent[i] = 1;

    int sum = 0;

}