#include <stdio.h>

int getParent(int parent[], int x) {
    if(parent[x] == x)
        return x;
    
    return parent[x] = getParent(parent, parent[x])
}

//�� �θ� ��带 ��ħ
void unionParent(int parent[], int a, int b) {
    a = getParent([parent, a])
}