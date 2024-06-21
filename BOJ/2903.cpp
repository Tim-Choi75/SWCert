//https://www.acmicpc.net/problem/2903
//https://www.acmicpc.net/step/8
//https://www.acmicpc.net/problem/5622

#include <iostream>
using namespace std;

int answer;

int main() {
	
	string a;
	cin >> a;
	
	for(int i=0; a[i]!=NULL; i++) {

		if(a[i]=='A' || a[i]=='B' || a[i]=='C') {
			answer+=3;
		} else if(a[i]=='D' || a[i]=='E' || a[i]=='F') {
			answer+=4;
		} else if(a[i]=='G' || a[i]=='H' || a[i]=='I') {
			answer+=5;
		} else if(a[i]=='J' || a[i]=='K' || a[i]=='L') {
			answer+=6;
		} else if(a[i]=='M' || a[i]=='N' || a[i]=='O') {
			answer+=7;
		} else if(a[i]=='P' || a[i]=='Q' || a[i]=='R' || a[i]=='S') {
			answer+=8;
		} else if(a[i]=='T' || a[i]=='U' || a[i]=='V') {
			answer+=9;
		} else if(a[i]=='W' || a[i]=='X' || a[i]=='Y' || a[i]=='Z') {
			answer+=10;
		}
	}
	cout << answer;
	return 0;
}
