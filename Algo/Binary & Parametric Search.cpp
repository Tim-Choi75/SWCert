//Binary & Parametric Search.cpp 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int Arr[MAXN], t, T, N, M, key;

int binarySearch(int *arr, int size, int key) {
	int lb = -1, ub=size-1, m;
	while(lb+1 < ub) {
		m = lb+(ub-lb)/2;
		if(arr[m] >= key)
			ub=m;
		else lb=m;
	}
	return ub
	
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(t=1; t<=T; t++) {
		printf("#%d", t);
		scanf("%d %d". &N, &M);
		
		for(int i=0; i<N; i++)
			scanf("%d", &Arr[i]);
		
		for(int i=0; i<M; i++) {
			scanf("%d", &key);
			printf(" %d", binarySearch(Arr, N, key));
		}
		printf("\n");
	}
	return 0;
	
}
