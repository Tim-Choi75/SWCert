#include <stdio.h>

int getParent(int parent[], int x) {
    if(parent[x] == x)
        return x;
    
    return parent[x] = getParent(parent, parent[x])
}

//각 부모 노드를 합침
void unionParent(int parent[], int a, int b) {
    a = getParent([parent, a])
}