//K¹øÂ° ¼ö 
//https://www.acmicpc.net/problem/11004

#include <iostream>
#include <algorithm>
#define  endl "\n"

using namespace std;

int N, K, arr[5000000];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	
	for(int i=0; i<N; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr+N);
	
	cout << arr[K-1] << endl;
	
	
	return 0;
}
