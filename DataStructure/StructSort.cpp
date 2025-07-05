//https://tinyurl.com/ysxxtsz9

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Data {
    int when, money;
    Data(int a, int b) {
        when =a;
        money = b;
    }

    bool operator<(const Data &d) const {
        return when < d.when;
    }
};

int n;
vector<Data> V;

int main() {

    freopen("StructSort.txt", "rt", stdin);
    cin >> n;

    for(int i=1; i<=n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        V.push_back(Data(temp1, temp2));
    }

    //before sort
    for(int i=1; i<V.size(); i++) {
        cout <<"when: " << V[i].when;
        cout <<", money: " << V[i].money;
        cout << "\n";    
    }

    cout << "sorting by when..............\n";
    cout << "\n";

    sort(V.begin(), V.end());

    for(int i=0; i<V.size(); i++) {
        cout <<"when: " << V[i].when;
        cout <<", money: " << V[i].money;
        cout << "\n";         
    }

}