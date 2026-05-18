// 1a.Design and implement C program using the Brute Force String Matching algorithm to find all
// occurrences of a given pattern in a text. Display the starting position(s) where the pattern 
// occurs and analyze the time complexity of the algorithm.


#include<stdio.h>
#include<string.h>

void bruteForceMatchAll(char text[] , char pattern[]){
    int n = strlen(text);
    int m = strlen(pattern);
    int count=0;

    for(int i=0;i<n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(text[i+j]!=pattern[j]){
                break;   //mismatch found , break and check for next
            }
        }
        if(j==m){      //found the pattern
            printf("pattern found at index : %d\n",i);  
            count++;
        }
    }
    if(count){
        printf("Total occurances found : %d\n",count);
    }else{
        printf("pattern not found in the text\n");
    }

}