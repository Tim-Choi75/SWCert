//#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	
	freopen("input.txt", "r", stdin);

	char a[101];
	scanf("%s", &a);
	int i, cnt1=0, cnt2=0;
	
	if(i=0; a[i]!='\0'; i++) {
		if(a[i]=='(')
			cnt1++;
		
		if(a[i]==')')
			cnt2++;			
	}
	
	if(cnt1==cnt2)
		printf("YES");
	else
		printf("NO");	
		
	return 0;
}