//Map
//https://wyatti.tistory.com/87#google_vignette

#include <iostream>
#include <map>
#include <string>

using namespace std;


int main() {
	map<int, string> myMap;

	//map�� key-value �� �߰�
	myMap.insert(make_pair(1, "apple"));
	myMap.insert(make_pair(2, "banana"));
	myMap.insert(make_pair(3, "cherry"));

	//map ũ�� ���
	cout << "Map size: " << myMap.size() << "\n";

	//key������ map�˻��ϱ�
	auto iter = myMap.find(2);

	if (iter != myMap.end()) {
		cout << "Key Matched: " << iter->first << " Value: " << iter->second << " \n";
	}
	else {
		cout << "Key not found " << "\n";
	}
	
	//map ��ȸ�ϱ�
	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
		cout << "Key Matched: " << iter->first << " Value: " << iter->second << " \n";
	}
	
	
	return 0;
}

