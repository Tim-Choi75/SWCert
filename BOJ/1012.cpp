//백준 1012 - 유기농 배추
//https://www.acmicpc.net/problem/1012
//

#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int T, M, N, K, cnt;
int arr[MAX][MAX];
bool check[MAX][MAX];

int dx[]={0, 0, -1, 1};
int dy[]={-1, 1, 0, 0};

void dfs(int x, int y) {
    
    cout << "[" << x << "," << y << "]->";
    check[x][y]=1;
    for(int i=0; i<4; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0 && nx<N && ny>=0 && ny<M) {
            if(arr[nx][ny]==1 && check[nx][ny]==0) {
                cout << "[" << nx << "," << ny << "]";
                dfs(nx, ny);        
            }
        }
    }//for i

}//DFS

int main() {

    cin >> T;
    int x=0, y=0;
    for(int i=0; i<T; i++) {
        cin >> M >> N >> K;
        for(int i=0; i<K; i++) {
            cin >> x >> y;
            arr[x][y]=1;
        }


        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(arr[i][j]==1) {
                    if(!check[i][j]) {
                        cnt++;
                        dfs(i, j);
                    }
                }
            }
        }

        cout << cnt << "\n";

    }//for T

}