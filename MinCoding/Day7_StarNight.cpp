//StarNight 
//https://pro.mincoding.co.kr/enterprise/contest/sds/446/problem/DAY2_01
//https://lg960214.tistory.com/26

#include <iostream>

using namespace std;

int N, M;
int parent[100];

int Find(int now) {
	if (now == parent[now])
		return now;

	return parent[now] = Find(parent[now]);
}

void Union(int A, int B) {

	int root_A = Find(A);
	int root_B = Find(B);

	if (root_A != root_B) {
		parent[root_B] = root_A;
	}

	return;
}

int main() {
	cin >> N >> M;

  // �� ���Ҵ� �ڱ� �ڽ��� ��ǥ�ϴ� �������� �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	int a, b;
	// ������ ������ �޾Ƽ� �� ��带 �̾���
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		Union(a, b);
	}

	int cnt = 0;

	// ������ ���� = ��ǥ������ ���� �̹Ƿ�,
	// ������ ��ǥ���Ҷ��, cnt�� �߰�
	for (int i = 0; i < N; i++) {
		if (Find(i) == i) cnt++;
	}

	cout << cnt; // 2
}
