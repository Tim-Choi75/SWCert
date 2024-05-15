//백준 1012 - 유기농 배추
//https://www.acmicpc.net/problem/1012
//

#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int T, M, N, K;
int arr[MAX][MAX];
bool check[MAX][MAX];

int dx[]={}

int main() {

    cin >> T;
    int x, y;
    for(int i=0; i<T; i++) {
        cin >> M >> N >> K;
        for(int i=0; i<K; i++) {
            cin >> x >> y;
            arr[x][y]=1;
            arr[y][x]=1;
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