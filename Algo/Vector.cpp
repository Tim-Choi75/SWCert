//Vector
//https://blog.naver.com/yangyubinstory/223240321066

#include <iostream>
#include <vector>

#define endl "\n";

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//vector 선언 
	vector<int> myVector;
	
	//데이터 추가 
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);
	
	//벡터 크기 
	cout << "벡터 크기" <<myVector.size() << endl;
	
	//벡터 순회 
	for(int i=0; i<myVector.size(); i++) {
		cout <<"요소: "<<i<<": "<<myVector[i]<<endl;
	}
	
	//데이터 제거 
	myVector.pop_back();

	//제거후 벡터크기
	cout<< "제거후 벡터크기: " << myVector.size() << endl;
	
	return 0;
	
}
