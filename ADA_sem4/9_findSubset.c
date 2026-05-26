//Design and implement C/C++ Program to find a subset of a given set S = {sl, s2,..,sn} of
//n positive integers whose sum is equal to a given positive integer d.

#include<stdio.h>

void findSubsets(int S[],int n,int idx,int d,int subset[],int size){
    if(d==0){
        printf("{ ");
        for(int i=0;i<size-1;i++){
            printf("%d,",subset[i]);
        }
        printf("%d }\n",subset[size-1]);
        return;
    }
    if(d<0 || idx>=n){
        return;
    }
    subset[size] = S[idx];
    findSubsets(S,n,idx+1,d-S[idx],subset,size+1);
    findSubsets(S,n,idx+1,d,subset,size);
}
int main(){
    // int S[] = {1,2,5,6,8};
    // int S[] = {3,10,11,20};
    // int S[] = {1,2,3,4};
    int S[] = {2,7,10};

    int n = sizeof(S)/sizeof(S[0]);
    // int d = 9;
    // int d = 24;
    // int d =10;
    int d =7;

    int subset[n];
    int size = 0;

    findSubsets(S,n,0,d,subset,size);

    if(size==0){
        printf("No other subset found\n");
    }
    return 0;
}

