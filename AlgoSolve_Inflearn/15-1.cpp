/*  IT취업을 위한 알고리즘_인프런
    15. 소수의 개수 */
    
#include <stdio.h>

bool isPrime(int x) {
	int i;
	bool flag=true;
	
	if(x==1)
		return false;
	
	for(i=2; i<x; i++) {
		if(x%i ==0) {
			flag = false;
			break;
		}
	}
	return flag;
}
	
int main() {
	
	//freopen("input.txt", "rt", stdin);
	
	int N, i, num, answer=0;
	scanf("%d", &N);
		
	for(i=2; i<=N; i++) {
				
		if(isPrime(i))
			answer++;
				
	}		
	
	printf("%d\n", answer);
	return 0;
}