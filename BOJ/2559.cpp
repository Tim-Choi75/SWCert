//백준2559-수열
//https://www.acmicpc.net/problem/2559

 #include <bits/stdc++.h>
 using namespace std;
 
 #define MAX_N 100000
 #define endl "\n";
 
 int N, K, arr[MAX_N], sum, maxSum;	//N:날짜수, K:연속날짜수
 
 int main() {
 	
 	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
 	
 	cin >> N >> K;
 	cout << N << K << endl;
 	
 	for(int i=0; i<N; i++) {
 		cin >> arr[i];
 	}
 	
  	for(int i=0; i<N; i++) {
 		cout <<  "i: " << i << " arr[i] " << arr[i] << endl;
 	}
	 	
 	for(int i=0; i<N; i++) {
 		for(int j=1; i<N-1; j++) {
 			sum=arr[i]+arr[j];
 			
 			//cout << "i: " << i << " arr[i]: " << arr[i] << "j: " << j << " arr[j] : " << arr[j] << "sum: "<< sum << endl;
 		}//for j
		
	 }//for i
 	
 	
 	
 	return 0;
 }
 
