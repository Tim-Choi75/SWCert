//����(BOJ) 1764 - �躸��
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
//chatgpt.com/s/t_68b37effb8e481918f22d60784853f8e

int main() {

	//freopen("/Users/timchoi/Git/SWCert/input/BOJ_1854.txt", "r", stdin);
	freopen("D:/Git/SWCert/input/BOJ_1764.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_1764_1.txt", "r", stdin);

	int N, M;
	scanf("%d %d", &N, &M);

	unordered_map<string, bool> umap;
	vector<string> result;
	char buf[25]; // �̸� ���� �ִ� 20, �����ְ� 25�� ����

	for (int i = 0; i < N; i++) {
		scanf("%s", buf);
		umap[string(buf)] = true; // �赵 ���� ��� ����
	}

	for (int i = 0; i < M; i++) {
		scanf("%s", buf);
		string name(buf);
		if (umap.find(name) != umap.end()) {
			result.push_back(name); // ��ġ�� ����
		}
	}

	sort(result.begin(), result.end()); // ������ ����

	printf("%d\n", (int)result.size());
	for (auto &s : result) {
		printf("%s\n", s.c_str());
	}

	return 0;
}