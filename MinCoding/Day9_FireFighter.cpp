//FireFighter
//https://pro.mincoding.co.kr/enterprise/contest/sds/446/problem/DAY4_03
//https://blog.naver.com/not_layer/223032814137 <- �̰Ŷ� ���?
//https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include <iostream>

using namespace std;

#define MAX_N 20


struct Node {
    int x,y;
    int distance;
};

/*
# ��
A ��ȭ��
$ �� 
_ �����
*/
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

int arr[MAX_N+1][MAX_N+1]={0};
int used[MAX_N+1][MAX_N+1]={0};


int main() {
	cin >> N;	//N*Nũ���� �Է� 
	
}
