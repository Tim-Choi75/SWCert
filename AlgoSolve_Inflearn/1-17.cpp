/*  IT취업을 위한 알고리즘_인프런
    17. 선생님 퀴즈 */

#include <stdio.h> 

int num[11], sum[11];

int main() {
	
	freopen("input.txt", "rt", stdin);
	int N=0, i, j;
	
	for(i=1; i<=N; i++) {
		scanf("%d", &num[i]);
		
		for(j=1; j<num[i]; j++) {
			sum[j]=sum[j]+j;
		}
		
		if(num[i] == num[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}