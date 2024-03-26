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

  // 각 원소는 자기 자신을 대표하는 집합으로 초기화
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	int a, b;
	// 간선의 정보를 받아서 각 노드를 이어줌
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		Union(a, b);
	}

	int cnt = 0;

	// 집합의 개수 = 대표원소의 개수 이므로,
	// 본인이 대표원소라면, cnt에 추가
	for (int i = 0; i < N; i++) {
		if (Find(i) == i) cnt++;
	}

	cout << cnt; // 2
}
