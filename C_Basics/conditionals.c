#include<stdio.h>

//  int main(){
//     int age;
//     printf("enter age: ");
//     scanf("%d",&age);
//     if (age>=18){
//         printf("adult\n");
//     }
//     else if(age<18 && age>13){
//         printf("teenager\n");
//     }
//     else{
//         printf("i don't know");
//     }
//     return 0;
//  }

                                  /*using ternary conditional operator*/
// int main(){
//     int age;
//     printf("enter age");
//     scanf("%d",&age);
//     (age>18)?printf("adult\n"):printf("not adult\n");
//     return 0;
// }


                                    /*using switch case*/
// int main(){
//     char day;
//     printf("enter day (1-7):");
//     scanf("%s",&day);
//     switch (day){
//         case 'm': printf("monday\n");
//             break;
//         case 't': printf("tuesday\n");
//             break;
//         case 'w': printf("wednesday\n");
//             break;
//         case 'T': printf("thrusday\n");
//             break;
//         case 'f' : printf("FRIDAY\n");
//             break;
//         case 'S' :printf("saturday\n");
//             break;
//         case 's' : printf("sunday\n");
//             break;
//         default: printf("entered invaild number\n");
//     }
//     return 0;
// }

int main(){
    int num;
    printf("enter number:");
    scanf("%d",&num);

    switch (num){
        case 1: printf("A\n");
            break;
        case 2: printf("B\n");
            break;
        case 3: printf("C\n");
            break;
        default: printf("error");
    } return 0;
    
}

                                          /* marks Grading */
// int main(){
//     float marks;
//     printf("enter student marks(0-100):");
//     scanf("%f",&marks);
//     if (marks<30){
//         printf("grade C\n");
//     } else if (marks>30 && marks<70){
//         printf("grade B\n");
//     } else if (marks>=70 && marks<90){
//         printf("grade A\n");
//     } else if (marks>90 && marks<=100){
//         printf("grade A+\n");
//     }
// }

                                   /*to find upper or lower case*/
// int main(){
//     char ch;
//     printf("enter character:");
//     scanf("%c",&ch);
//     if (ch>='A' && ch<='Z'){
//         printf("upper case\n");
//     } else if (ch>='a' && ch <='z'){
//         printf("lower case\n");
//     } else {
//         printf("not an alphabet\n");
//     }
// }