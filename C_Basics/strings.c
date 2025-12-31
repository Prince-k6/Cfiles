//  #include<stdio.h>
//  int main (){
//     char name[]={'p','r','i','n','c','e','\0'};
//     printf("%s\n",name);
//     char name1[]="abcedf";
//     printf("%s\n",name1);
//     return 0;
// }


//wap to enter name and print it
// #include<stdio.h>
// void print_arr(char arr[]);
// void print_arr(char arr[]){
//     for (int i=0;arr[i] != '\0' ;i++){
//         printf("%c",arr[i]);
//     }
//     printf("\n");
// }

// int main(){
//     char name[50];
//     printf("enter name:");
//     scanf("%s",name);
//     printf("your name is %s\n",name);
//     return 0;
// }



// fgets() and puts() functions
// #include<stdio.h>
// int main(){
//     char str[100];
//     printf("enter name:");
//     fgets(str,100,stdin);
//     puts(str);
//     return 0;
// }


// #include<stdio.h>
// int main(){
//     char *trial="hola";       // modifiable
//     char trial[]="hola";     //not modifiable
//     puts(trial);
//     trial="hello";
//     puts(trial);
//     return 0;
// }



// //waf to count no of charaters in strings
// #include<stdio.h>
// int count(char arr[]);
// int count(char arr[]){
//     int cnt=0;
//     for (int i=0;arr[i]!='\0';i++){
//         cnt+=1;
//     }
//     return cnt-1;
// }  
// int main(){
//     char name[100];
//     printf("enter:");
//     fgets(name,100,stdin);
//     int val=count(name);
//     printf("no.of characters=%d\n",val);
//     return 0;
// }


                 //standard library functions
#include<stdio.h>
#include<string.h>
// 1.length of str
int main(){
    char abc[]="abcdef";
    int length=strlen(abc);
    printf("length of %s=%d\n",abc,length);
    return 0;
}

//2.copy old str data to new str
// int main(){
//     char old_str[]="old str";
//     char new_str[]="new str";
//     strcpy(new_str,old_str);
//     puts(new_str);
//     return 0;
// }

//3.concating one string to another string
// note: there shold be ample space left for concatination
// int main(){
//     char firststr[100]="helo";
//     char secondstr[]=" world";
//     strcat(firststr,secondstr);
//     puts(firststr);
//     puts(secondstr);
// }

//4.comparing 2 strings
// int main(){
//     char firststr[]="Gandu";
//     char secondstr[]="CHUTIYA";
//     printf("%d\n",strcmp(firststr,secondstr));
//     // printf("%d",strcmp("APPLE","CANANA"));   //thia will return -1
//     return 0;
// }

//find the salted form of a password entered by the user if the salt is "123" & added at the end
// #include<stdio.h>
// #include<string.h>
// void salting(char password[]);
// void salting(char password[]){
//     char salt[]="123";
//     char unsalted_pass[20];
//     strcpy(unsalted_pass,password);
//     strcat(unsalted_pass,salt);
//     printf("salted password=");
//     puts(unsalted_pass);
// }
// int main(){
//     char password[10];
//     printf("enter password:");
//     // fgets(password,100,stdin);
//     scanf("%s",password);
//     salting(password);
//     return 0;
// }
 

// wAF which takes up string and returns a sliced string from index n to m
// #include<stdio.h>
// #include<string.h>
// void slice(char str[],int n,int m);
// void slice(char str[],int n,int m){
//     int l=strlen(str)-1;
//     printf("length of string=%d\n",l);
//     char new_str[100];
//     int j=0;

//     for ( int i=n;i<=m;i++){
//         new_str[j]=str[i];
//         j++;
//     }
//     puts(new_str);
// }

// int main(){
//     char str[100];
//     printf("enter string:");
//     fgets(str,100,stdin);

//     int n,m;
//     printf("enter from where(n):");
//     scanf("%d",&n);
//     printf("enter till where(m):");
//     scanf("%d",&m);

//     slice(str,n,m);
// }

//WAF to count the occurence of vowels in a string
// #include<stdio.h>
// #include<string.h>
// int count_vowel(char str[]);
// int count_vowel(char str[]){
//     int l=strlen(str)-1;
//     int count=0;
//     // for (int i=0;i<=l;i++){     // or for (int i=0;str[i]!='\0';i++){
//     for (int i=0;str[i]!='\0';i++){
//         if (str[i]=='A'||str[i]=='a'||str[i]=='E'||str[i]=='e'||str[i]=='I'||
//         str[i]=='i'||str[i]=='O'||str[i]=='o'||str[i]=='U'||str[i]=='u'){
//             count+=1;
//         }
//     }
//     return count;
// }

// int main(){
//     char str[100];
//     printf("Enter string:");
//     fgets(str,100,stdin);
//     int val=count_vowel(str);
//     printf("no.of vowels =%d\n",val);

//     return 0;
// }


 
//WAP to check if a given chracter is present in a string
#include<stdio.h>
int main(){
    char str[]="hello unknown person";
    char x;
    printf("enter character you wanna search:");
    scanf("%c",&x);
    for (int i=0;str[i]!='\0';i++){   //'\0'--> null character
        if(str[i]==x){
            printf("character is prsent\n");
            break;
        }
    }  
    return 0; 
}