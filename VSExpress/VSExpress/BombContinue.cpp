//������ź 
//https://pro.mincoding.co.kr/enterprise/contest/sds/445/problem/DAY2_02
//https://studyfield.tistory.com/139

#include<iostream>
using namespace std;

int N = 0;
int arr[1001][1001];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

struct Node {
	int value;
	int x;
	int y;
};

int main() {

	cin >> N;
	struct Node DAT[1001*1001 + 1];

	//��ź ���� �Է� 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> DAT[i].value;
			DAT[i].x = i;
			DAT[i].y = j;
		}
	}

	//��ź ���� ���-����� 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << i <<"th DAT value: " << DAT[i].value << " x: " << DAT[i].x  << " y: "<< DAT[i].y << "\n";
		}
	}

	//�ð��� �帣�°��� for������ ǥ��
	int cnt = 0;
	for (int time = 1; time <= N * N; time++) {
		//Node now 
	}

	return 0;
}