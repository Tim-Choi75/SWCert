//https://codeup.kr/problem.php?id=1420

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	string arr[50][2] = {"0"};
	int scoreArr[50];
	
	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> arr[i][0] >> arr[i][1];
		scoreArr[i] = stoi(arr[i][1]);
	}
	
	sort(scoreArr, scoreArr+n);
	
	for(int i=0; i<n; i++) {
		if(scoreArr[n-3] == stoi(arr[i][1]);
		cout << 
	}
	
}
