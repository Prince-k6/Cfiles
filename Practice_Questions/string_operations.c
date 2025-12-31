//wihout inbuilt function

//WRITE FUNCTIONS TO IMPLEMENT STRING OPERATIONS SUCH AS COMPARE, CONCATENATE, STRING LENGTH.
//USE THE PARAMETER PASSING TECHNIQUES.


#include<stdio.h>
#include<string.h>

int strlength(char str[]){
    int i=0;
    while (str[i]!='\0'){
        i++;
    }
    return i-1;
}
void compare(char s1[],char s2[]){
    int i=0;
    int flag=1;
    while(s1[i]!='\0'){
        if(s1[i]!=s2[i]){
            flag=0;
            break;
        }
        i++;
    }
    if (flag==1){
        printf("\nBoth the strings are same\n");      
    }
    else{
        printf("\nBoth the strings are different\n");
    }
}
void concatenate(char s1[],char s2[]){
    int l1 = strlength(s1);
    int l2 = strlength(s2);
    int j;
    for(j=0;s2[j]!='\0';j++){
        s1[l1+j]=s2[j];
    }
    puts(s1);
}

int main(){
    char str1[100],str2[100];

    printf("enter first string:");
    fgets(str1,100,stdin);
    printf("enter second string:");
    fgets(str2,100,stdin);
    printf("\nlength of string1 = %d\n",strlength(str1));   
    printf("length of string2 = %d\n",strlength(str2)); 
    
    compare(str1,str2);

    printf("\nConcatenation of string1 and string2: ");
    concatenate(str1,str2);

    return 0;  
}