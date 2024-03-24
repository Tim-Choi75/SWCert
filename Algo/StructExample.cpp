//구조체 예제
//https://lypicfa.tistory.com/133
//https://tcpschool.com/cpp/cpp_struct_intro

#include <iostream>
using namespace std;

struct point {
	int x,y;
};

int main() {
	point z;
	z.x=1;
	z.y=2;
	cout << "x: " << z.x <<  " y: " << z.y <<"\n"; 
}
