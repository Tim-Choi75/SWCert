//https://blog.naver.com/1hyungjin1/223209877939

#include <iostream>
#include <string>
using namespace std;

struct Data{
	int data1;
	int data2;
	int data3;
};

int main() {
	Data d;

	d.data1 = 10;
	d.data2 = 20;

	cout << "print: " << d.data1 << " , "<<d.data2 << endl;
	cout << "d size: " << sizeof(d) << endl;

	return 0;
}

