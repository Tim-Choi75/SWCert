//https://pro.mincoding.co.kr/enterprise/contest/sds/445/problem/DAY1_01
//https://codechacha.com/ko/cpp-min-max-in-array/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int type, n;
	cin >> type;
	if(type ==1) {
		int arr[30], sum;
		long gop;	
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> arr[i];
			sum += arr[i];
			gop *= arr[i];
		}
		
		cout << sum << "\n";
		cout << gop;	
	} else if(type == 2) {
		cin >> n;
		string str[100], mini_str="", maxi_str;
		
		int mini = INT_MAX;
		int maxi = 0;
		
		for(int i=0; i<n; i++) { 
			cin >> str[i];
			
			if(str[i].length() < mini) {
				mini = str[i].length();
				mini_str=str[i];
			}
			
			if(str[i].length() < maxi) {
				maxi = str[i].length();
				mini_str=str[i];
			}
			
			cout << mini << "\n";
			cout << maxi << "\n";
		}
		
	} else if(type == 3) {
		int x, y, min, cnt;
		int *twoarr = new int[100][100];
		
		cin >> x;
		cin >> y;
				
		for(int i=0; i<x; i++) { 
			for(int j=0; j<y; j++) {
				cin >> twoarr[x][j];				
			}		
		}
		
		
		min = *min_element(twoarr, twoarr + 30);
		cnt=0;
		
		for(int i=0; i<x; i++) { 
			for(int j=0; j<y; j++) {
				if(min == twoarr[x][j])
					cnt++;
			}		
		}
		cout << cnt << "\n";
				
	}

	
	return 0;
}
