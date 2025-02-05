/*  IT취업을 위한 알고리즘_인프런
	14. 뒤집은 소수 */
	
#include <stdio.h>

int reverse(int x) {
	
	int tmp, res=0;
	while(x > 0) {
		tmp = x%10;
		res = res*10+tmp;
		x = x/10;
	}

	return res;

}


bool isPrime(int x) {
	
	int i;
	bool flag=true;
	
	if(x==1)
		return false;
		
	for(i=2; i<x; i++) {
		if(x%i == 0) {
			flag=false;
			break;
		}		
	}
	return flag;
}
	
int main() {
	
	freopen("input.txt", "rt", stdin);
	
	int n, num, i, tmp;
	scanf("%d", &n);
	printf("n: %d\n", n);
	
	for(i=1; i<=n; i++) {
		scanf("%d", &num);
		tmp = reverse(num);
		if(isPrime(tmp)) 
			printf("%d\n", tmp);
		
	}		
	
	return 0;
}