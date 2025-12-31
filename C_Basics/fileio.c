#include<stdio.h>
// int main(){
//     FILE *fptr;
//     fptr=fopen("test.txt","r");
//     if(fptr==NULL){
//         printf("file does not exit\n");
//     } else{
//         printf("file exist\n");
//     }
//     fclose(fptr);
//     return 0;
// }

int main(){
    FILE *fptr;
    fptr=fopen("test.txt","r");
    char ch;
    fscanf(fptr,"%c",&ch);
    printf("%c\n",ch);

    fscanf(fptr,"%c",&ch);
    printf("%c\n",ch);

    fscanf(fptr,"%c",&ch);
    printf("%c\n",ch);

    fscanf(fptr,"%c",&ch);
    printf("%c\n",ch);

    fscanf(fptr,"%c",&ch);
    printf("%c\n",ch);

    return 0;

}