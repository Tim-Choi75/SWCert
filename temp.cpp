#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;
    
    for(int i=3; i<n; i++) {
        if(n%i==0)
            break;
        else 
            answer++;
    }
        
    cout << answer+1;;
    return 0;
}
