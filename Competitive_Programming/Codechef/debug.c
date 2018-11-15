#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_VALUE 100000

int min(int a, int b){
    if(a>b) return b;
    else return a;
}

void constructTree(int *input, int *segTree, int low, int high, int pos){
    printf("low: %d high: %d pos:%d\n",low,high,pos);
    if(low == high){
        segTree[pos] = input[low];
        return;
    }
    int mid = (low+high)/2;
    constructTree(input,segTree,low,mid,2*pos+1);
    constructTree(input,segTree,mid+1,high,2*pos+2);
    segTree[pos] = min(segTree[2*pos+1],segTree[2*pos+2]);
}

int rangeMinQuery(int *segTree, int qlow, int qhigh, int low, int high, int pos){
    if(qlow <= low && qhigh >= high) return segTree[pos];
    if(qlow > high || qhigh < low) return MAX_VALUE;
    int mid = (low+high)/2;
    return min(rangeMinQuery(segTree,qlow,qhigh,low,mid,2*pos+1),rangeMinQuery(segTree,qlow,qhigh,mid+1,high,2*pos+2));
}

int main(){
    int n;
    scanf("%d", &n);
    int *input, *segTree;
    input = (int *)malloc(n*sizeof(int));
    segTree = (int *)malloc((2*n - 1)*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", (input+i));
    }
    constructTree(input,segTree,0,n-1,0);
    for(int i = 0; i < 2*n - 1; i++){
        printf("%d ", *(segTree+i));
    }
    printf("\n");
    return 0;
}
