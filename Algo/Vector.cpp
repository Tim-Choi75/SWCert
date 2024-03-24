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

	//vector ���� 
	vector<int> myVector;
	
	//������ �߰� 
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);
	
	//���� ũ�� 
	cout << "���� ũ��" <<myVector.size() << endl;
	
	//���� ��ȸ 
	for(int i=0; i<myVector.size(); i++) {
		cout <<"���: "<<i<<": "<<myVector[i]<<endl;
	}
	
	//������ ���� 
	myVector.pop_back();

	//������ ����ũ��
	cout<< "������ ����ũ��: " << myVector.size() << endl;
	
	return 0;
	
}
