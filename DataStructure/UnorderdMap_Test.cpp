//https://math-coding.tistory.com/31

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<string, int> um;

    if(um.empty()) {
        cout <<"unordered_map is empty"<< endl;        
    }

    um.insert(make_pair("Key", 1));
    um["banana"]=2;
    um.insert({"melon", 3});

    cout<<"unordered_map size is " << um.size() << endl;
    
    
    for(pair<string, int> elem:um) {
        cout << "key: " <<elem.first << " value: " << elem.second << endl;
    }

    if(um.find("banana")!=um.end()) {
        um.erase("banana");        
    }
    
    cout<<"unordered_map size is " << um.size() << endl;
    //auto
    for(auto elem:um) {
        cout << "key: " <<elem.first << " value: " << elem.second << endl;
    }

    return 0;
}