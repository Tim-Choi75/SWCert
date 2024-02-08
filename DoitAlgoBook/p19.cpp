#include <iostream>
using namespace std;

int main() {
	int N = 1000;
	int cnt =1;
	
	for(int i=0; i<N; i++) {
		cout <<"연산횟수: " << cnt++ <<"\n";
	}
}