#include<stdio.h>
#include<stdlib.h>

int main(){
    int *marks;
    int n;
    //malloc
    printf("Enter iniial number of students:");
    scanf("%d",&n);
    marks=(int*)malloc(n*sizeof(int));
    if(marks==NULL){
        printf("memory allocation failed\n");
        exit(0);
    }

    printf("enter students marks\n");   
    for(int i=0;i<n;i++){
        scanf("%d",&marks[i]);
    }

    //realloc
    int new_n;
    printf("enter new class size:");
    scanf("%d",&new_n);
    marks=(int *)realloc(marks, new_n*sizeof(int));
    if(marks==NULL){
        printf("memory allocation failed\n");
        exit(0);
    }
    //enter marks for new students
    printf("enter students marks\n");   
    for(int i=0;i<new_n;i++){
        scanf("%d",&marks[i]);
    }
    //display(printf("enter students marks\n");   
    for(int i=0;i<new_n;i++){
        printf("%d\t",marks[i]);
    }
    prinitf("\n");
    free(marks);        //free memory
    return 0;
}