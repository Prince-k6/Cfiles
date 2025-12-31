// char is digit or not??
#include<stdio.h>
#include<ctype.h>            //type module
int main(){
    char x;
    printf("enter your character: ");
    scanf("%c",&x);
    if (isdigit(x))                //isdigit() function
        printf("%c is numeric\n",x);
    else if (isalpha(x))           //isalpha() function
        printf("%c is an alphabet\n",x);
    else
        printf("%c is neither digit nor alphabet\n",x);
    return 0;
}