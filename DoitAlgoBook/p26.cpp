#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	
	int answer = 0;
	int A[10001] = {0};
	
	for(int i=1; i<1001; i++) {
		A[i] = rand() * 100;
	}

	for(int t=1; t<testcase+1; t++) {
		int start, end;
		cin >> start >> end;
		for(int i=start; i<=end; i++) {
			answer += A[i];
		}
		
		cout << testcase << "" << answer;
	}
}