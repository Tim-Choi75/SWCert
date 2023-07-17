//https://codeup.kr/problem.php?id=1512
//https://banguli.tistory.com/411
//Result: Understand Fail

#include <stdio.h>

int arr[101][101];

int main(void) {
	int N, X, Y, K, L, i, j;
	scanf("%d %d %d", &N, &Y, &X);
	
	arr[0][0] = X+Y-1;
	for(K=1; K<N; K++) {
		if(K<X)
			arr[0][K]=arr[0][K-1]-1;
		if(K>=X)
			arr[0][K]=arr[0][K-1]+1;
	}//for K
	
	for(L=1; L<N; L++) {
		for(i=0; i<N; i++) {
			if(L<Y)
				arr[L][i]=arr[L-1][i]-1;
			if(L>=Y)
				arr[L][i]=arr[L-1][i]+1;
			
		}
	}//for L

	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			printf("%d ", arr[i][j]);	
		}
		printf("\n");
	}
	
}