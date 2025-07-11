//https://minwook6457.tistory.com/6

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100001
#pragma warning(disable:4996)

typedef struct edge {
    int start, end, weight;
}

int parent[MAX_N];
edge E[MAX_N];


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

   //가중치 기준으로 정렬ㄴ 
   qsort(E, e, sizeof(struct edge), compare);

   int j = 0;
   int accepted = 0;





}