//ī�� �߱ޱ�
//https://pro.mincoding.co.kr/enterprise/contest/sds/445/problem/DAY1_03

#include <iostream>

using namespace std;
 
 int main() {
 	
 	int T, N;
 	
 	cin >> T; //TestCase
 	int height[1000000]={0,};
 	
 	for(int i=0; i<T; i++) {
		//Ű ���� �Է�
	 	//202 195 191 195 232
	 	cin >> N; //�л��� 
	 	for(int i=0; i<N; i++) {
	 		cin >> height[i];
	 		
		}
		
		//ī������ �Է�
		//2 3 5 1 4
		int cardNum, DAT[1000000]={0,};
	 	for(int i=0; i<N; i++) {
	 		cin >> cardNum;
	 		DAT[cardNum]=height[i];
		}	 
		
		int flag=0;
		
		for(int i=2; i<N+1; i++) {
			if(DAT[i-1] < DAT[i]) {
				flag=1;
			}
		}
		
		if(flag == 0) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		} 		
 		
	}//for T
 	
 	
 	return 0;
 }
