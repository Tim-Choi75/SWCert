//�ּڰ� ã��
//https://www.acmicpc.net/problem/11003
//Algo: Priority Queue, Sliding Window, Vector, Deque
//Ǯ��: https://non-stop.tistory.com/31
//����: https://velog.io/@hyez_dev/%EB%B0%B1%EC%A4%80-11003-%EC%B5%9C%EC%86%9F%EA%B0%92-%EC%B0%BE%EA%B8%B0-C
//����: https://imksh.com/13
 
#include <iostream>
#include <queue>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

vector<int> v;
deque<pair<int, int> > dq;
int N, L;
 
int main(int argc, char* argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> N >> L;
	
	for(int i=0; i<N; i++) {
		cin >> num;
		v.push_back(num);
		
	}
	
	for(int i=0; i<N; i++) {
		if(!dq.empty()) {
			if(dq.front().second<i-L+1)	//dq�� �� ù���Ұ� �ε��������� ������ ����
				dq.pop_front();
		}
		
		while(!dq.empty() && dq.back().first > v[i-1])//�ڿ������� ���� ���� ���Һ��� ū������
			dq.pop_back();
		dq.push_back(make_pair(v[i-1],i));
		cout << dq.front().first << "";
	}	
	
	return 0;
}
