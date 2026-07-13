#include<stdio.h>

int max(int a, int b){return a>b? a : b ;}

// int knapsack(int n, int m, int wt[], int val[]){
//     int dp[n+1][m+1];
//     for(int i=0;i<=n;i++){
//         dp[i][0] = 0;
//     }
//     for(int j=0;j<=m; j++){
//         dp[0][j] = 0;
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m ;j++){
//             int take = 0;
//             int skip = 0;
//             if(wt[i-1] <= j){
//                 take = val[i-1] + dp[i-1][j-wt[i-1]];
//             }
//             skip = dp[i-1][j];
//             dp[i][j] = max(take,skip);
//         }
//     }
//     return dp[n][m];
// }


int knapsack(int n, int m, int wt[], int val[]){
    int dp[n+1][m+1];
    for(int i=0; i<=n ;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int take =0;
            int skip = 0;
            if(wt[i-1] <= j){
                take = val[i-1] + dp[i-1][j - wt[i-1]];
            }
            skip = dp[i-1][j];
            dp[i][j] = max(take,skip);
        }
    }
    return dp[n][m];
}

int main(){
    // int n;       // no of items
    // printf("enter no of items : ");
    // scanf("%d",&n);
    // int m;       //bag capacity
    // printf("enter the capacity of bag:");
    // scanf("%d",&m);

    // int wt[n];       //weight of each. item
    // int val[n];       //value of each item
    // printf("enter the weight and value of each item:\n");
    // for(int i=0; i<n; i++){
    //     scanf("%d%d", &wt[i], &val[i]);
    // }

    int n = 4;
    int m = 5;
    int wt[] = {5,4,2,3};
    int val[] = {10,40,30,50};
    printf("%d\n",knapsack(n,m,wt,val));
    return 0;
}