//Priority queue
//https://kbj96.tistory.com/15


#include <iostream>
#include <queue>
#include <functional> //greater, less

#define endl "\n"

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	priority_queue<int> pq;
	
	pq.push(4);
	pq.push(7);
	pq.push(3);
	pq.push(1);
	pq.push(10);

	cout << "우선순위 큐 사이즈: " << pq.size() << endl;
	
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	
	return 0;
}
