//����ü �迭
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
		cout <<"�̸�: ";
		cin >> p[i].name;

		cout <<"�ڵ��� ��ȣ: ";
		cin >> p[i].phonenum;

		cout <<"����: ";
		cin >> p[i].age;				
	}
	
	p[0].age=10;
	strcpy(p[0].name, "�̼���");
	strcpy(p[0].phonenum, "010-1234-1234");
	
	p[1].age=20;
	strcpy(p[1].name, "��¿�");
	strcpy(p[0].phonenum, "010-1234-5678");	
	
	for(i=0; i<3; i++) {
		cout <<"�̸�: " << p[i].name << " ����: " << p[i].phonenum << " ����: " << p[i].age << "\n"; 
			
	}
	return 0;
}
