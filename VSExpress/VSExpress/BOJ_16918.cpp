//봄버맨
//https://www.acmicpc.net/problem/16918
//https://yabmoons.tistory.com/198

#include <iostream>
#include <vector>

#define endl "\n"
#define MAX 200

int 	R, C, N;
int 	boom_Time[MAX][MAX];
char	MAP[MAX][MAX];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


using namespace std;

void input() {
	//RxC직사각형 격자판
	//N초가 흐른후의 격자판 상태 
	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'O') {
				boom_Time[i][j] = 3;
			}
		}
	}

}

void install_boom(int t) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] == 'O') {	//폭타이 설치되있으면 
				continue;
				boom_Time[i][j] = t + 3;
			}
		}
	}


void delete_boom(int t) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (boom_Time[i][j] == T) {

					//상하좌우 폭탄을 터뜨린다. 
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx < 0 || ny < 0 || nx >= R || ny >= C)
							contiune;

						if (MAP[nx][ny] == '.')	//이미 터진곳은 skip 
							continue;

						MAP[nx][ny] = '.';	//터진곳으로 처?
					}
					MAP[i][j] = '.';
					boom_Time[i][j] = 0;
				}
			}
		}
}

	void print() {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << MAP[i][j];
			}
		}
		cout << endl;

	}
	void solution() {
		int time = 2;
		while (true) {
			if (time == N + 1)
				break;


			if (time % 2 == 0) { 	//짝수초일때 
				install_boom(time);	//폭탄 설치 
			}
			else {
				delete_boom(time);
			}
			time++;
		}//while

		print();
	}




	void solve() {

		input();
		solution();
	}



	int main() {

		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		solve();

		return 0;

	}