//1-10.cpp

#include <iostream>
using namespace std;

int cnt[50001];

int main() {
	
	
	
	//printf("Hello world\n");
	
	int n, i, j;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	
	for(i=1; i<=n; i++) {
		for(j=i; j<=n; j=j+i) {
			
			printf("i: %d, j: %d\n", i, j);
			cnt[j]++;
		}
	}
	
	for(i=1; i<=n; i++) {
		printf("%d ", cnt[i]);
	}
	
	return 0;
}
