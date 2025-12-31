//WAF to concatinate two strings inputed by user using standard library function
#include<stdio.h>
#include<string.h>
void concatinate(char str1[],char str2[]);
void concatinate(char str1[],char str2[]){
    strcat(str1,str2);
    puts(str1);
}
int main(){
    char str1[100];
    char str2[100];
    printf("enter str1:");
    scanf("%s",str1);
    printf("enter str2:");
    scanf("%s",str2);
    concatinate(str1,str2);
    return 0;
}