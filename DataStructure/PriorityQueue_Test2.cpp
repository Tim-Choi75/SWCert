//https://www.youtube.com/watch?v=dUjd2BYU6zg&t=21s

#include <iostream>
#include <queue>

using namespace std;

int main() {

    int n, i;
    priority_queue<int, vector<int>, less<int>> pq;
    cin >> n;
    for(i=0; i<n; i++) {
        int x;
        cin >> x;
        pq.push(x);

    }

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}