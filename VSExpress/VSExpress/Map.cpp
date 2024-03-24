//Map
//https://wyatti.tistory.com/87#google_vignette

#include <iostream>
#include <map>
#include <string>

using namespace std;


int main() {
	map<int, string> myMap;

	//map에 key-value 쌍 추가
	myMap.insert(make_pair(1, "apple"));
	myMap.insert(make_pair(2, "banana"));
	myMap.insert(make_pair(3, "cherry"));

	//map 크기 출력
	cout << "Map size: " << myMap.size() << "\n";

	//key값으로 map검색하기
	auto iter = myMap.find(2);

	if (iter != myMap.end()) {
		cout << "Key Matched: " << iter->first << " Value: " << iter->second << " \n";
	}
	else {
		cout << "Key not found " << "\n";
	}
	
	//map 순회하기
	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
		cout << "Key Matched: " << iter->first << " Value: " << iter->second << " \n";
	}
	
	
	return 0;
}

