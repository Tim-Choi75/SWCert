//제로
//https://www.acmicpc.net/problem/10773
//Algo: Vector
//풀이:  https://velog.io/@minjgziii/BOJ%EB%B0%B1%EC%A4%80-C-10773%EB%B2%88-%EC%A0%9C%EB%A1%9C-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B4-%EB%B2%A1%ED%84%B0-%EC%82%AC%EC%9A%A9

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int K,num;
vector<int> v;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;
	
	for(int i=0; i<K; i++) {
		cin >> num;
		v.push_back(num);
	}
	
	for(int j=0; j<v.size(); j++) {
		if(v[j]==0) {
			v.erase(v.begin()+j);
			v.erase(v.begin()+j-1);
			j -= 2;
		}	
	
	}
	
	cout << accumulate(v.begin(), v.end(), 0);
	
	return 0;
}
