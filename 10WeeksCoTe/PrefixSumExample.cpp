//������-Prefix Sum 
//https://blog.naver.com/jhc9639/222283814653?trackingCode=blog_bloghome_searchlist

#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
 
int a[100004], b, c, psum[100004], n ,m;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m; 
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i]; 
	}
	for(int i = 0 ; i < m; i++){
		cin >> b >> c; 
		cout << psum[c] - psum[b - 1] << "\n";
	} 
	return 0;
}
