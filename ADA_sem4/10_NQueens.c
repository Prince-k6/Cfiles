//Implement Nqueens using backtracking

#include <stdbool.h>
#include <stdio.h>

int n;
int board[10][10] = {0};

void print_solution() {
  printf("\nSolution:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j]) {
        printf(" Q ");
      } else {
        printf(" . ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

bool is_safe(int row, int col) {
  for (int i = 0; i < n; i++) {
    if (board[row][i] || board[i][col]) {
      return false;
    }
  }
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) {
      return false;
    }
  }
  for (int i = row, j = col; i >= 0 && j <= n - 1; i--, j++) {
    if (board[i][j]) {
      return false;
    }
  }
  return true;
}

void solve_nq(int row) {
  if (row == n) {
    print_solution();
    return;
  }
  for (int col = 0; col < n; col++) {
    if (is_safe(row, col)) {
      board[row][col] = 1;
      solve_nq(row + 1);
      board[row][col] = 0;
    }
  }
}

int main() {
  printf("Enter the number of Queens : ");
  scanf("%d", &n);
  solve_nq(0);
}
