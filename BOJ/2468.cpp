//백준 2468 - 안전 영역 
//https://www.acmicpc.net/problem/2468
//Algo: 
//

#include <iostream>
using namespace std;

#define MAX_N 101
#define endl "\n" 

int N, maxN=1; 
int arr[MAX_N][MAX_N], visit[MAX_N]

void DFS(int x, int y, int h) {

}



int main() {
	
	cin >> N;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> arr[i][j];
			if(arr[i][j]>=MAX_N)
				MAX_N=arr[i][j];	
		}
	}
	
	for(int h=1; h<=MAX_N-1; h++) {//1부터 최대높이-1까지 
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				DFS(i, j, h);
			}
		}		
	}
	
	return 0;
} 
