#include <iostream>
#include <queue>

using namespace std;
#define MAX_N 8

int i, j, cnt=0, answer=0;
int arr[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
queue <pair<int, int> > q;

bool print_YN = true;

int isOut(int row, int col) {
 	if(row <=0 || row >=8 || col <=0  ||  col>=8)
		return true;
	else 
        return false;	   
}

void print_arr() {
    for(i=1; i<=7; i++) {
        for(j=1; j<=7; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int bfs(int row, int col) {
    q.push(make_pair(x, y));
    visited[row][col] = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = x+dx[dir];
            int ny = y+dy[dir];

            if(arr[x][y]==arr[nx][ny]) {
                cnt++;
                if(cnt >= 3) 
                  answer++;         
            }
        }


    }
}



int main() {
    
    for(i=1; i<=7; i++) {
        for(j=1; j<=7; j++) {
            cin >> arr[i][j];
        }
    }

    if(print_YN) print_arr();

    for(i=1; i<=7; i++) {
        for(j=1; j<=7; j++) {
            cnt=1;
            bfs(i, j);
        }
    }

    return 0;
}