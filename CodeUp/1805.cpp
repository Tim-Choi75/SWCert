//https://codeup.kr/problem.php?id=1805

#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct factory {	//기동 장치 
	int a;	//식별번호(id, 중복X) 
	int b; 	//가스보유량
};

bool compare(const factory& f1, const factory& f2) {
	if(p1.a >= p2.a) 
		return p1.a;
	else 
		return p2.a;		
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	struct factory f[100];
	for(i=0; i<n; i++) {
		cin >> f[i].a;	//식별번호 
		cin >> f[i].b;	//가스보유량
	}

	sort(f, f+n, compare);
	

	return 0;	
}
