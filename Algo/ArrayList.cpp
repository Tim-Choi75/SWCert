//ArrayList
//https://velog.io/@sangh00n/%EB%A6%AC%EC%8A%A4%ED%8A%B8List%EC%9D%98-%EC%9D%B4%ED%95%B4

#include <iostream>
#include <string>

using namespace std;

class List {

	private:
		string shoppingList[100];
		int length=0;
	
	public:
		void add(string str)	{
			shoppingList[length]=str;
			length++;
		}
		
		void del(string str) {
			if(isEmpty()) {
				cout << "리스트가 비어있습니다!";
				return; 
			}
			
			for(int i=0; i<length; i++) {
				if(shoppingList[i] == str) {
					for(int j=i; j<length; j++) {
						shoppingList[j] = shoppingList[j+1];
					}
				}	
			}
		};
		
		bool isEmpty() {
			if(length == 0) 
				return true;
			else
				return false;
		};
		
		void displayALL() {
			cout << "쇼핑 리스트 목록입니다.\n";
			for(int i=0; shoppingList[i].size()!=0; i++) {
				cout << i+1 << ". " << shoppingList[i] << endl;
			}  
		}
		
};
int main() {
	
	List list1;
	
	cout <<"쇼핑 리스트에 넣을 항목 입력하시오. 다음단계 q\n";
	cout <<"입력할 항목: ";
	
	for(int i=0; i<100; i++) {
		string t;
		cin >> t;
		if (t == "q")
			break;
		
		list1.add(t);
	}

	cout <<"집에 있는 물건을 보고 삭제할 물건들은 삭제합니다. 다음단계 q\n";
	cout <<"삭제할 항목: ";	
	for(int i=0; i<100; i++) {
		string t;
		cin >> t;
		if (t == "q")
			break;
		
		list1.del(t);
	}
	
	cout <<"쇼핑 리스트에 넣을 항목 입력하시오. 다음단계 q\n";
	list1.displayALL()	;
}
