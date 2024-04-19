//πÈ¡ÿ2309-¿œ∞ˆ≥≠¿Ô¿Ã
//https://www.inflearn.com/course/lecture?courseSlug=10%EC%A3%BC%EC%99%84%EC%84%B1-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-%ED%81%B0%EB%8F%8C&unitId=151225
//https://www.acmicpc.net/source/share/6b0acb8d4af043f88800c74b72d77610

#include <bits/stdc++.h>
using namespace std;
int sum, arr[9];
pair<int, int> ret;
vector<int> v;

void solve() {
	for(int i=0; i<9; i++) {
		for(int j=0; j<i; j++) {
			if(sum-arr[i]-arr[j] == 100) {
				ret = {i, j};
				return;
			}
		}
	}
}

int main() {
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);	
	
	for(int i=0; i<9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	
	solve();
	
	for(int i=0; i<9; i++) {
		if(ret.first == i || ret.second == i)
			continue;
		v.push_back(arr[i]);
	}
	
	sort(v.begin(), v.end());
	for(int i : v)
		cout << i << " ";
	return 0;
}
