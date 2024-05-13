//백준 2023 - 신기한 소수
//https://www.acmicpc.net/problem/1000
//https://www.youtube.com/watch?v=Q98DqTkhzFs&t=1s

#include <iostream>
using namespace std;
static int N;

void DFS(int number, int jarisu);
bool isPrime(int number);

bool isPrime(int number) {
	for(int i=2; i<=number/2; i++) {
		if(number%i == 0)
			return false;
	}
	return true;
}

void DFS(int number, int jarisu) {
	
	if(jarisu==N) {
		//소수이면 출력
		if(isPrime(number)) {
			cout << number << "\n";
		}
		return;
	}
	
	for(int i=1; i<10; i++) {
		if(i%2 == 0)	//짝수는 skip 
			continue;
			
		if(isPrime(number*10+i)) {
			DFS(number*10+i, jarisu+1);
		}
	}
	
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);	
	

	cin >> N;
	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
	
}
