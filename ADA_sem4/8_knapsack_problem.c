#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsackDP(int n, int W, int wt[], int val[]) {
    int dp[n + 1][W + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main() {
  int n, W, i;
  printf("Enter the number of items: ");
  scanf("%d", &n);

  int val[n], wt[n];
  printf("Enter the weight and value of each item:\n");
  for (i = 0; i < n; i++)
    scanf("%d%d", &wt[i], &val[i]);

  printf("Enter the maximum weight capacity of the knapsack: ");
  scanf("%d", &W);

  printf("The maximum value that can be obtained is: %d",
         knapsackDP(n, W, wt, val));
  return 0;
}