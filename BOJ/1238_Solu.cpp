//BOJ 1238 - ��Ƽ
//https://www.acmicpc.net/problem/1238
//Algo: ���ͽ�Ʈ��(dijkstra)
//Ǯ��:https://howudong.tistory.com/284

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999999
int N,M,X;
vector<pair<int,int>> v[1001]; // ������ ���� ����
int d[1001][1001] = {0,}; // �� �������� �ٸ� ���������� �ּ� ��� ����

// ���ͽ�Ʈ�� �˰���(�Ű����� : ���� ����)
void dijkstra(int num){
    // �Ÿ��� ���� �������� ����(�Ÿ��� ª���ͺ��� ����)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

    d[num][num] = 0;
    q.push({0,num});

    while(!q.empty()){
        int x = q.top().second;
        int distance = q.top().first;
        q.pop();

        // ����� ����
        for(int i = 0; i < v[x].size(); i++){
            int nx = v[x][i].first; // ����� ����
            // ���� �ð� + �� ���θ� �ǳʴµ� ��� ���
            int nDistance =distance + v[x][i].second;
            
            // ������ �ͺ��� �Ÿ��� ª���� ����
            if(d[num][nx] > nDistance){
                d[num][nx] = nDistance;
                q.push({nDistance,nx});
            }
        }
    }

}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    freopen("D:/Git/SWCert/input/BOJ_1238.txt", "r", stdin);
    
    cin >> N >> M >> X;

    for(int i = 0; i < M; i++){
        int v1,v2,v3;
        cin >> v1 >> v2 >> v3;
        v[v1].push_back({v2,v3});
    }
    fill(&d[0][0],&d[1000][1001],INF);
    for(int i = 1; i <= N; i++) dijkstra(i);


    int ans = 0;
    for(int i = 1; i<= N; i++){
        ans = max(ans,d[i][X]+d[X][i]);
    }
    cout << ans;

}