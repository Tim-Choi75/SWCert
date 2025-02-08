/*  IT취업을 위한 알고리즘_인프런
	AlgoSolve_Inflearn
	17. 선생님 퀴즈 */

#include <stdio.h>
#include <iostream>

using namespace std;

int num[11], sum[11];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, i, j;

	//freopen("input.txt", "rt", stdin);
	freopen("D:/Git/SWCert/input/AlgoSolve_Inflearn-17.txt", "r", stdin);
	scanf("%d", &N);

	printf("N: %d\n", N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &num[i]);

		printf("i: %d, \n", N);
		for (j = 1; j < num[i]; j++) {
			sum[j] = sum[j] + j;
		}

		if (num[i] == num[j])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}