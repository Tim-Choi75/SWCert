#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// ����� ������ ��� ���� (v[�������� �޴� ��] = (�ð�,������ ��))
vector<pair<int,int>> v[100001]; 
int dp[100001]; // �� ����� �ּ� �ð��� ��� dp �迭
int n,d,c;

// ���ͽ�Ʈ�� �˰���
void dijkstra(int x){
    // �켱���� ť (�������� ����) ���� ��, �ð��� �������� ���� �ͺ��� ������
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    dp[x] = 0; // �ڱ� �ڽ��� �ð��� 0���� ����
    q.push(make_pair(0,x)); // ť�� ����


    while(!q.empty()){
        int cnt = q.top().second; // ���� ���
        int t = q.top().first; // ���� �ð�
        q.pop();
        // �ִܰŸ��� �ƴ� ��쿣 ���� ���ص� ��
        if(dp[cnt] < t) continue;
        for(int i = 0; i < v[cnt].size(); i++){
            int next = v[cnt][i].second; // ���� ���
            int nextTime = v[cnt][i].first + t; // ���� �ð� + ���� �ð�
            // ����Ǿ��ִ� �ð����� �۾ƾ߸� ����
            if(nextTime < dp[next]){
                dp[next] = nextTime;
                q.push(make_pair(nextTime,next)); // ť�� ����
            }
        }
    }

    // ���� 
    int com = 0, t = 0;
    for(int i = 1; i <= n; i++){
        if(dp[i] == INT32_MAX) continue;
        com++;
        t = max(t,dp[i]);
    }
    cout << com << " " << t << "\n";
    
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        cin >> n >> d >> c;
        fill(dp,dp+100001,INT32_MAX);
        for(int i = 0; i <= 100000; i++) v[i].clear();
        for(int i = 0; i < d; i++){
            int v1,v2,v3;
            cin >> v1 >> v2 >> v3;
            v[v2].push_back(make_pair(v3,v1)); // (�ð�,��ǻ��)
        }
        dijkstra(c);
    }
}