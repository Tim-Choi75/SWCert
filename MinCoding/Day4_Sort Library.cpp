//Sort Library
//https://pro.mincoding.co.kr/enterprise/contest/sds/445/problem/DAY5_01
//https://hipolarbear.tistory.com/11

//String ����
//https://swblossom.tistory.com/46
 
//¦�� �켱���� 
//https://seongjuk.tistory.com/entry/c-sort-%ED%95%A8%EC%88%98-%EC%BB%A4%EC%8A%A4%ED%85%80-%ED%8A%B9%EC%A0%95-%EC%A1%B0%EA%B1%B4-%EC%A0%95%EB%A0%AC-%EC%9A%B0%EC%84%A0%EC%88%9C%EC%9C%84-%ED%81%90-%EC%A0%95%EB%A0%AC

#include <iostream>
#include <algorithm>
#include <string>

#define endl "\n"

using namespace std;
int N, arr[100000]; 
char str_arr[100000]; 

int cmp(int a, int b) {
	if (a%2==0 && b%2==0) { // �Ѵ� ¦��
		return a < b;
	}
	else if (a%2==0) { // a�� ¦�� 
		return 1;
	}
	else if (b%2==0) { // b�� ¦�� 
		return 0;
	}
	return a < b; // �Ѵ� ¦��	
};

bool str_cmp(string s1, string s2) {
	return s1 > s2;
}

int main() {
	
	cin >> N;	
	for(int i=0; i<N; i++) {
		cin >> arr[i];
	}

	for(int i=0; i<N; i++) {
		cin >> str_arr[i];
	}
	
//	for(int i=0; i<N; i++) {
//		cout << arr[i] << " ";
//		cout << str_arr[i] << " ";
//	}
//	
//	cout << endl;
//	for(int i=0; i<N; i++) {
//		cout << str_arr[i] << " ";
//	}		
	
	//���� sort �Լ� ��� 
	sort(arr, arr+N);

	//���ĵ� �Լ� ��� 
	for(int i=0; i<N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	//������ ����
	sort(arr, arr+N, greater<int>());	

	//�����ĵ� �Լ� ��� 
	for(int i=0; i<N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	//¦�� �켱���� ����
	sort(arr, arr+N, cmp);

	//¦�� �켱���ĵ� �Լ� ��� 
	for(int i=0; i<N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	//���ڿ� �Լ� ����
	sort(str_arr, str_arr+N);
	
	//¦�� �켱���ĵ� �Լ� ��� 
	for(int i=0; i<N; i++) {
		cout << str_arr[i] << " ";
	}
			
	return 0;
	
}
