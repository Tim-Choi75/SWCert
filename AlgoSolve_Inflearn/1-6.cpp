//#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	
	freopen("input.txt", "r", stdin);
	char a[100];
	int res=0, cnt=0, i;
	
	scanf("%s", &a);
	
	for(i=0; a[i]!='\0'; i++) {
		if(a[i]>=48 &&a[i]<=57) {
			res= res*10+(a[i]-48);
		}
	}
	printf("%d\n", res);
	for(i=1; i<=res; i++) {
		if(res%i==0)
			cnt++;
	}
	printf("%d\n", cnt);
				
	return 0;
}