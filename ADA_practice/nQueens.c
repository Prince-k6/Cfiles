#include<stdio.h>
#include<stdbool.h>

int n;
int board[10][10];

int count = 0;
void printSolution(){
    count++;
    printf("solution %d\n",count);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]){
                printf("Q ");
            }else{
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}


bool isSafe(int row,int col){
    //horizontal and vetical
    for(int i=0;i<n;i++){
        if(board[row][i] || board[i][col]){
            return false;
        }
    }
    //left diagonal check
    for(int i=row,j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j]){
            return false;
        }
    }
    //right diagonal check
    for(int i=row,j=col; i>=0 && j < n; i--,j++){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}
void nQueens(int row){
    if(row == n){
        printSolution();
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(row,col)){
            board[row][col] = 1;
            nQueens(row+1);
            board[row][col] = 0;
        }
    }
}

int main(){
    printf("enter the value of n:");
    scanf("%d",&n);
    nQueens(0);

    return 0;
}