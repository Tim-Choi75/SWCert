/* CodeUp 2605 - ÄµµðÆÎ
https://codeup.kr/problem.php?id=2605
Algo: DFS
git test
https://studyingandcoding.tistory.com/4
*/

#include <iostream>
using namespace std;

int check[8][8] = {0};
int data[8][8];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int num = 0;

int dfs(int nowx, int nowy) {

  int nx, ny;
  int count = 1;
  check[nowx][nowy] = 1;

  for (int i = 0; i < 4; i++) {
    nx = nowx + dx[i];
    ny = nowy + dy[i];

    if (nx <= 7 && nx >= 1 && ny <= 7 && ny >= 1) {
      if (check[nx][ny] == 0 && data[nowx][nowy] == data[nx][ny]) {
        count += dfs(nx, ny);
      }
    }
  }
  return count;
}

int main() {
  for (int i = 1; i <= 7; i++) {
    for (int j = 1; j <= 7; j++)
      cin >> data[i][j];
  }

  for (int i = 1; i <= 7; i++) {
    for (int j = 1; j <= 7; j++)
      if (dfs(i, j) >= 3)
        num++;
  }

  cout << num;
  return 0;
}
