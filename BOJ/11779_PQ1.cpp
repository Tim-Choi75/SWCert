//백준(BOJ) 11779 - 최소비용 구하기 2
//https://www.acmicpc.net/problem/11779
//Algo: Dijkstra
//DataStructure: Priority Queue
//Solu: https://www.youtube.com/watch?v=w2hQaGzWYc8&t=1125s
//      https://bbeomgeun.tistory.com/112


#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

#define MAX_N 1001
#define INF 987654321

int n, m, i, j;
typedef pair<int, int> pii;
vector <pii> v[MAX_N];
int dist[MAX_N], route[MAX_N];
stack<int> st;

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_11779.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_11779.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	int a, b, c;

	for (i = 1; i <= m: i++) {
		scanf("%d %d %d", &a, &b, &c);
	}

}