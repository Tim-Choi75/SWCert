/*  IT취업을 위한 알고리즘_인프런
	AlgoSolve_Inflearn
	18. 층간 소음 */

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, time, cnt;
	freopen("D:/Git/SWCert/input/AlgoSolve_Inflearn-18.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	
	printf("N: %d M: %d", N, M);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &time);

		if (time > M) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}