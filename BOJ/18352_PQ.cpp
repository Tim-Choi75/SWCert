//https://www.acmicpc.net/problem/18352

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

typedef pair<int, int> pii;

#define MAX_N   300001
#define 1e9     1e9 

int main() {


	freopen("/Users/timchoi/Git/SWCert/input/BOJ_18352.txt", "r", stdin);

    //������ ���� N, ������ ���� M, �Ÿ� ���� K, ��� ������ ��ȣ X
    int N, M, K, X;
    scanf("%d %d %d %d", &N, &M, &K, &X);

    int A, B;

    vector<int> v[MAX_N];
    int dist[MAX_N];
    for(int i=0; i<M; i++) {
        scanf("%d %d", &A, &B);
        v[A].push_back(B);
    }

    priority_queue<pii> pq;
    pq.push({X, 0})
    for(int i=0; i<N; i++) {
        
    }



    return 0;
}