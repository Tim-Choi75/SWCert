//Binary Search
//https://velog.io/@junsj119/%EC%9D%B4%EC%A7%84%ED%83%90%EC%83%89Binary-Search

#include <iostream>
#include <algorithm>

using namespace std;

int N, T, target[1000], arr[1000];

int binarySearch(int n, int x) {
	int s=0;
	int e=n-1;
	int mid;
	
	while(e-s>= 0) {
		mid=(s+e)/2;
		
		if(target[mid]==x)  {
			return 1;			
		}
		else if(target[mid]>x) {
			e=mid-1;			
		} else
			s=mid+1;
	}

	return 0;
} 


int main() {
	
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> target[i];
	}
	
	sort(target, target+N);
	
	cin >> T;
	for(int i=0; i<T; i++) {
		cin >> arr[i];
		
		if(binarySearch(N, arr[i]) == 1) {
			cout<<"O";
		} else
			cout<<"X";
	}

	
	return 0;
	
}

