//√Ú∑ŒΩ∫(churros)
//https://pro.mincoding.co.kr/enterprise/contest/sds/446/problem/DAY1_02
//Parametric Search
//Solution: https://blog.naver.com/cyh197/222242677586 
//https://www.crocus.co.kr/1000

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K, result;
vector<int> v;

bool test(int mid) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt += v[i] / mid;
		if (cnt >= K)
			return true;
	}
	return false;
}

int main() {

	cin >> N >> K;

	while (N--) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int start = 0;
	int end = v[v.size() - 1];
	result = -1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (test(mid)) {
			result = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}//

	cout << result << "\n";
	return 0;
}