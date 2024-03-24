//DebugTest
//https://zapiro.tistory.com/entry/Visual-Studio-%EB%94%94%EB%B2%84%EA%B1%B0-%EC%82%AC%EC%9A%A9%EB%B2%95


#include <stdio.h>

int main() {
	
	int iCnt;
	int iSum;
	
	for (iCnt=0, iSum=0; iCnt<5; iCnt++) {
		iSum = iSum + iCnt;
		printf("iCnt: %d\t iSum: %d\n", iCnt, iSum);
	}
	
	return 0;
}
