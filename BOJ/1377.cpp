//https://www.acmicpc.net/problem/1377
//https://www.inflearn.com/course/lecture?courseSlug=%EB%91%90%EC%9E%87-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-%EC%94%A8%EC%81%A0%EC%81%A0&unitId=148478&tab=curriculum

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N;
    cin >> N;
    vector<pair<int, int> > A(N);

    for(int i=0; i<N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    int Max = 0;
    for(int i=0;  i<N; i++) {
        if(Max < A[i].second-i) {
            Max < A[i].second-i;
        }
    }
    cout << Max+1;
}    