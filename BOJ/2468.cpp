// BOJ2468-
//https://www.acmicpc.net/problem/2468
//Algo: DFS
//2667

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 101
#define endl "\n"

using namespace std;

int N, maxVal=1, cnt=1;
int arr[MAX_N][MAX_N], visit[MAX_N][MAX_N];
vector<int> v;
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

void DFS(int x, int y, int h) {

    visit[x][y]=1;

    for(int i=0; i<4; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx<0 || nx>=N || ny<0 || ny>=N)
            continue;

        //탐색을 시작한다.
        if(arr[nx][ny]>h && visit[nx][ny]==0) {
            visit[nx][ny]=1;
            DFS(nx, ny, h);
        }
    }

}


int main() {

    cin >> N;

    //input
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> arr[i][j];
            if(arr[i][j]>maxVal)
                maxVal=arr[i][j];
		}
	}
    //cout << maxVal;

    for(int h=1; h<maxVal; h++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(arr[i][j]>h && visit[i][j]==0) {
                    cnt++;
                    DFS(i, j, h);
                    v.push_back(cnt);
                }
            }
        }
    }

    //sort(v.begin(), v.end());
    int max=*max_element(v.begin(), v.end());
    cout << max;
    return 0;
}