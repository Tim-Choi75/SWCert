#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>


using namespace std;

int N, M;

int main() {
 
    freopen("D:/Git/SWCert/input/BOJ_1764.txt", "r", stdin);
	//freopen("D:/Git/SWCert/input/BOJ_1764_1.txt", "r", stdin);

    scanf("%d %d", &N, &M);
    unordered_map<string, int> umap;
    vector<string> ansVec;

    string str1;
    for (int i = 0; i < N; i++) {
        cin >> str1;
        umap[str1] = 1;
    }

    string str2;
    for (int i = 0; i < M; i++) {
        cin >> str2;
        if (umap.find(str2) != umap.end()) {
            ansVec.push_back(str2);
        }
    }

    sort(ansVec.begin(), ansVec.end());
    cout << ansVec.size() << "\n";
    for (auto &s : ansVec)
        cout << s << "\n";

    return 0;
}
