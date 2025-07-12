//https://www.acmicpc.net/problem/1197
//https://minwook6457.tistory.com/6

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100001
#pragma warning(disable:4996)

typedef struct edge {
    int start, end, weight;
} edge;

int compare(const void* a, const void* b) {

    struct edge* x = (struct edge*)a;
    struct edge* y = (struct edge*)b;
    return x->weight-y->weight;
}


int parent[MAX_N];
edge E[MAX_N];

int find(int x) {
    if(x == parent[x]) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

void union_find(int a, int b) {
    a = parent[a];
    b = parent[b];
    parent[a] = b;
}

int main() {

   int v, e;
   scanf("%d %d", &v, &e);

   for(int i=0; i<e; i++) {
    int temp1, temp2, temp3;
    scanf("%d %d %d", &temp1, &temp2, &temp3);

    E[i].start = temp1;
    E[i].end = temp2;
    E[i].weight = temp3;
   }

   for(int i=1; i<=v; i++) {
        parent[i]=i;
   }

   //가중치 기준으로 정렬
   qsort(E, e, sizeof(struct edge), compare);

   int j = 0;
   int accepted = 0;

   int a, b, result = 0;

   while(accepted != v-1) {//크루스칼 알고리즘 적용
     a = E[j].start;
     b = E[j].end;

    if(find(a) != find(b)) {
        union_find(a, b);
        accepted++;
        result += E[j].weight;
    }
    j++;

   }//while
   printf("%d", result);
   return 0;

}