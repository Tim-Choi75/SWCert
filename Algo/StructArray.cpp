//구조체 배열
//https://inging9731.tistory.com/40
#include <iostream>
#include <cstring>

using namespace std;

struct  point {
	int x;
	int y;
};

struct person {
	char name[30];
	char phonenum[30];
	int age;
};

int main() {
	
	struct person p[3];
	int i;
	
	for(i=0; i<3; i++) {
		cout <<"이름: ";
		cin >> p[i].name;

		cout <<"핸드폰 번호: ";
		cin >> p[i].phonenum;

		cout <<"나이: ";
		cin >> p[i].age;				
	}
	
	p[0].age=10;
	strcpy(p[0].name, "이선우");
	strcpy(p[0].phonenum, "010-1234-1234");
	
	p[1].age=20;
	strcpy(p[1].name, "김승우");
	strcpy(p[0].phonenum, "010-1234-5678");	
	
	for(i=0; i<3; i++) {
		cout <<"이름: " << p[i].name << " 전번: " << p[i].phonenum << " 나이: " << p[i].age << "\n"; 
			
	}
	return 0;
}
