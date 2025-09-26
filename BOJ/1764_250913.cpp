//백준(BOJ) 1764 - 듣보잡
//https://www.acmicpc.net/problem/1764
//Algo: Dijkstra
//Solve: https://nanyoungkim.tistory.com/168


#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

//ChatGPT Guide
//chatgpt.com/s/t_68b387ca26e481919e8aac503577524f

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1854.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1764.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_1764_1.txt", "r", stdin);

	int N, M;
	scanf("%d %d", &N, &M);
	unordered_map<string, bool> umap;
	vector<string> ansVec;
	char buf[25];

	for (int i = 0; i < N; i++) {
		scanf("%s", buf);
		umap[string(buf)] = true;	//듣도 보지 못한사람 저장
	}

	for (int i = 0; i < M; i++) {
		scanf("%s", buf);
		string name(buf);
		if (umap.find(name) != umap.end()) {
			ansVec.push_back(name);	//겹치면 저장
		}
	}

	sort(ansVec.begin(), ansVec.end());	//사전순 정렬
	printf("%d\n", (int)ansVec.size());

	for (auto &s : ansVec)
		printf("%s\n", s.c_str());

	return 0;
}