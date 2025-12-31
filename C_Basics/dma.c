#include <stdio.h>
#include<string.h>


// struct student {             //stucture defination
//     int roll;
//     float cgpa;
//     char name[100];
// };
// void printInfo(struct student s);
// void printInfo(struct student s){
//     printf("Student[s] information\n");
//     printf("----------------------\n");
//     printf("s.rollno:%d\n",s.roll);
//     printf("s.name=%s\n",s.name);
//     printf("s.cgpa:%f\n",s.cgpa);
//     printf("----------------------\n");
// }


// int main(){
//     struct student s1;
//     s1.roll=17;
//     s1.cgpa=9.0;
//     // s1.name="Prince";
//     strcpy(s1.name,"Prince");
//     // printf("%d\t%s\t%f\n",s1.roll,s1.name,s1.cgpa);
//     printInfo(s1);
//     //initializing structures
//     struct student s2={29,10.0,"Rishika"};
//     // printf("%d\t%s\t%f\n",s2.roll,s2.name,s2.cgpa);
//     printInfo(s2);

//     // struct student s3={0};
//     // printf("%d\t%s\t%f\n",s3.roll,s3.name,s3.cgpa);

//     // //pointer to structures
//     // struct student s4={1164,5.00,"abc"};
//     // struct student *ptr;
//     // ptr=&s4;
//     // printf("s4 roll no:%d\n",s4.roll);
//     // printf("s4 roll no:%d\n",(*ptr).roll);
//     return 0;
// }


                                        //dyanmic memory allocation
//malloc():allocates memory variable;

int main(){
    float*ptr;
    ptr=(float*)malloc(5*sizeof(float));     //allocates 5*4=20bytes memory for the ptr variable
    ptr[0]=19;
    ptr[1]=30;
    ptr[2]=43;
    ptr[3]=83;
    ptr[4]=98;
    for (int i=0;i<5;i++){
        printf("%f\t",ptr[i]);
    }
    return 0;
}


            //calloc():continous allocaation

// int main(){
//     int n;
//     printf("enter n:");
//     scanf("%d",&n);
//     int *ptr;
//     ptr=(int*)calloc(n,sizeof(int));
//     for (int i=0;i<n;i++){
//         printf("%d\n",ptr[i]);
//     }
//     printf("-------------\n");
//     free(ptr);
//     ptr=(int*)calloc(2,sizeof(int));
//     for (int i=0;i<2;i++){
//         printf("%d\n",ptr[i]);
//     }
//     return 0;
// }