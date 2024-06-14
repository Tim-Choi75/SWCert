//https://www.acmicpc.net/problem/10810
//https://www.acmicpc.net/step/6

#include <iostream>
#define MAX_N 101

using namespace std;

int N, M;	//N:¹Ù±¸´Ï, M 
int arr[MAX_N];

int main() {
	
	cin >> N >> M;
	int s, e, num;
	for(int i=1; i<=M; i++) {
		cin >> s >> e >> num;
		
		for(int j=s; j<=e; j++) {
			arr[j]=num;
		}
	}
	
	for(int i=1; i<=N; i++) { 
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
