//https://www.acmicpc.net/problem/10811
//https://www.acmicpc.net/step/6
//https://codechacha.com/ko/cpp-reverse-array-order/

#include <iostream>
#include <algorithm>

#define MAX_N 101

using namespace std;

int N, M, i, s, e;	//N:¹Ù±¸´Ï, M 
int arr[MAX_N];

void print_arr() {
	cout << "Inside print: ";
	for(i=0; i<N; i++) {
		cout << arr[i] << " ";
	}	
}

int main() {
	
	cin >> N >> M;

	for(i=0; i<N; i++) {
		arr[i]=i+1;
	}

//	for(i=0; i<N; i++) {
//		cout << arr[i] << " ";
//	}	
//	cout << endl;
	
	//cout <<"M: "<< M << endl;
	for(i=1; i<=M; i++) {
		//cout <<"i: "<< i << endl;
		cin >> s >> e;
		cout <<"i: "<< i << " s: "<< s << "," << e << endl;
		//reverse(arr+s-1, arr+e-1);
		reverse(arr+s, arr+e);
		print_arr();
		cout << endl;	
	}


	for(i=0; i<N; i++) {
		cout << arr[i] << " ";
	}	
	return 0;
}
