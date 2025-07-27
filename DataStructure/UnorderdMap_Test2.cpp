//https://tinyurl.com/2dd7tb3r

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> umap;    //create unordered_map of string, pair

    //add key pair value
    umap{"apple"} = 5;
    umap{"banana"} =3;
    umap{"cherry"} =8;

    //search with key
    cout << "Number of aoples: " << umap["apple"] << endl;

    //check if key exists
    if(umap.find("banana"))





}