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
				cout << "����Ʈ�� ����ֽ��ϴ�!";
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
			cout << "���� ����Ʈ ����Դϴ�.\n";
			for(int i=0; shoppingList[i].size()!=0; i++) {
				cout << i+1 << ". " << shoppingList[i] << endl;
			}  
		}
		
};
int main() {
	
	List list1;
	
	cout <<"���� ����Ʈ�� ���� �׸� �Է��Ͻÿ�. �����ܰ� q\n";
	cout <<"�Է��� �׸�: ";
	
	for(int i=0; i<100; i++) {
		string t;
		cin >> t;
		if (t == "q")
			break;
		
		list1.add(t);
	}

	cout <<"���� �ִ� ������ ���� ������ ���ǵ��� �����մϴ�. �����ܰ� q\n";
	cout <<"������ �׸�: ";	
	for(int i=0; i<100; i++) {
		string t;
		cin >> t;
		if (t == "q")
			break;
		
		list1.del(t);
	}
	
	cout <<"���� ����Ʈ�� ���� �׸� �Է��Ͻÿ�. �����ܰ� q\n";
	list1.displayALL()	;
}
