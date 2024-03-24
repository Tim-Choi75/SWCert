//https://www.acmicpc.net/problem/10814
//https://www.acmicpc.net/source/share/ee3502617514477380f729ef2f6a891a

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct person {
	int age, idx;	
	string name;
};


bool compare(const person& now, const person& last) {
	if(now.age != last.age)
		return now.age < last.age;
	return 	now.idx < last.idx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	//구조체 선언 및 입력 
	person people[100001];
	for(int i=0; i<N; i++) {
		cin >> people[i].age >> people[i].name;
		people[i].idx = i;
	}
	
	//정렬
	sort(people, people+N, compare);
	
	//답출력
	for(int i=0; i<N; i++)
		cout << i << "th " << people[i].age << people[i].name << "\n";
	
	return 0;
	
}
