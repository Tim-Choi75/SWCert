#include <iostream>

using namespace std;

int type, N, input, num1, num2, num3, num4, num5, num6, num7, num8, num9;
int arr[1001]={0,};
		
int main() {

	
	cin >> type;
	
	if(type == 1) {
	
		cin >> N;
		
		for(int i=0; i<N; i++) {
			cin >> input;
		
			if(input==1) {
				num1++;
			} else if(input==2) {
				num2++;
			} else if(input==3) {
				num3++;				
			} else if(input==4) {
				num4++;
			} else if(input==5) {			
				num5++;
			} else if(input==6) {
				num6++;
			} else if(input==7) {
				num7++;			
			} else if(input==8) {
				num8++;
			} else if(input==9) {										
				num9++;
			}
		
		}//for i
	
		cout << 1 <<":"<<num1 << "개\n";
		cout << 2 <<":"<<num2 << "개\n";
		cout << 3 <<":"<<num3 << "개\n";
		cout << 4 <<":"<<num4 << "개\n";
		cout << 5 <<":"<<num5 << "개\n";
		cout << 6 <<":"<<num6 << "개\n";
		cout << 7 <<":"<<num7 << "개\n";
		cout << 8 <<":"<<num8 << "개\n";
		cout << 9 <<":"<<num9 << "개\n";
		
	
	} else if(type == 2) { //type 2
		cin >> N;
		int flag=0;
		for(int i=0; i<N; i++) {
			cin >> arr[i];
		}
		
		for(int i=0; i<N; i++) {
			for(int j=1; j<i; j++) {
				if(arr[i] == arr[j]) {
					//cout <<"i: " << i <<  " j: " << j <<"\n";
					//cout <<"arr[i]: " << arr[i] <<  " arr[j]: " << arr[j]<<"\n";
					flag=1;
					break;					
				}

			}
		}
		
		if(flag == 1) {
			cout <<"중복발견\n";
		} else {
			cout <<"중복없음\n";			
		}
	}
	return 0;
}
