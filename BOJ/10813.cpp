//https://www.acmicpc.net/problem/10813
//https://www.acmicpc.net/step/6

#include <iostream>
#define MAX_N 101

using namespace std;

int N, M;	//N:¹Ù±¸´Ï, M 
int arr[MAX_N];

int main() {
	
	cin >> N >> M;
	
	int i, temp, first, second;
	for(i=1; i<=N; i++) {
		arr[i]=i;
	}

	for(i=1; i<=N; i++) {
		//cout << arr[i] << " ";
	}	
	//cout << endl;
		
	for(int i=1; i<=M; i++) {		
		cin >> first >> second;
		//cout << first  << second << endl;
		//cout << first  << "," << arr[first] << endl;
		//cout << second  << "," << arr[second] << endl;
		
		temp=arr[first];
		arr[first]=arr[second];
		arr[second]=temp;

	}

	for(i=1; i<=N; i++) {
		cout << arr[i] << " ";
	}	
	return 0;
}
