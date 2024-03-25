//BOJ 1202-보석도둑
//https://www.acmicpc.net/problem/1202
//https://guccin.tistory.com/105
//https://www.youtube.com/watch?v=QgHV5h8kZuk

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;

int main () {
	priority_queue<pair<int,int> > pq;
	cin >> N >> K;	//N: 보석, K	
	
	vector<pair<int,int> > nv;
	vector <long> kv;
	
	int a, b;
	
	for(int i=0; i<N; i++) {
		cin >> a >> b;
		nv.push_back(pair<int, int>(a, b));
	}
	sort(nv.begin(), nv.end());
	
	for(int i=0; i<K; i++) {
		cin >> a;
		kv.push_back(a);
	}
	sort(kv.begin(), kv.end());
	
	int bag;
	int ni=0;
	
	long long sum=0;
	for(int i=0; i<K; i++) {
		bag=kv[i];
		while(ni<N && bag >= nv[ni].first) {
			pq.push(pair<int, int>(nv[ni].second, nv[ni].first));
			ni++;
		}
		if(!pq.empty()) {
			pair<int, int> tmp = pq.top();
			pq.pop();
			sum += tmp.first;
		}
	}
	
	cout << sum << "\n";
	return 0;
}
