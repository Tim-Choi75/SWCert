//https://codeup.kr/problem.php?id=1172

#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	arr[0]=a;
	arr[1]=b;
	arr[2]=c;

	sort(arr, arr+3);
	
	for(int i=0; i<3; i++) {
		cout<<arr[i]<<' ';
	}
}
