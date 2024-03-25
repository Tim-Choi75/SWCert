//BlackList
//https://pro.mincoding.co.kr/enterprise/contest/sds/445/problem/DAY1_02

#include <iostream>
#include <algorithm>

using namespace std;

int apt[100001]={0,};
int check[100001]={0,};
	
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int h, w, num;
	cin >> h;
	cin >> w;
	

	
	for(int i=0; i<h; i++)	 {
		for(int j=0; j<w; j++) {
			cin >> num;
			apt[num]++;
		}
	}

	int bh, bw, blackCnt;
	cin >> bh;
	cin >> bw;	
	for(int i=0; i<bh; i++)	 {
		for(int j=0; j<bw; j++) {			
			cin >> num;
			blackCnt+=apt[num]++;
			apt[num]=0;			
		}
	}
	
	cout << blackCnt <<'\n';
	cout << h*w-blackCnt <<'\n';
	
	return 0;
}
