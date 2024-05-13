//น้มุ 2588 - ฐ๖ผภ 
//https://www.acmicpc.net/problem/2588
//https://st-lab.tistory.com/215


#include <bits/stdc++.h>
using namespace std;

int A;
string B;


int main() {
	
	cin >> A;
	cin >> B;
	cout << A*B[2] << "\n";
	cout << A*B[1] << "\n";
	cout << A*B[0] << "\n";
	cout << A*stoi(B);
	
	return 0;
		
}
