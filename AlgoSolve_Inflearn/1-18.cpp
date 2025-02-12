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

	int N, M, time, max_cnt=-999, cnt=0;
	freopen("D:/Git/SWCert/input/AlgoSolve_Inflearn-18.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	//printf("N: %d M: %d\n", N, M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &time);
		
		if (time > M) {			
			cnt++;
			printf("compare: time: %d M: %d cnt: %d\n", time, M, cnt);
		} else {
			cnt = 0;
		}

		if(cnt > max_cnt) {
			max_cnt = cnt;
		}
	}

	if(max_cnt == 0)
		printf("-1\n");
	else
		printf("%d\n", max_cnt);

	return 0;
}