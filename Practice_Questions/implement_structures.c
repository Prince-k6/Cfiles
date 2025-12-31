                            //  my code
#include<stdio.h>
#include<string.h>

struct student{
    char USN[10];
    char Name[20];
    float Marks[3];
    float avg;
};

int main(){
    int n,i;
    printf("enter the number of students in class:");
    scanf("%d",&n);
    struct student s[n];
    for(i=0;i<n;i++){                     //reading details
        printf("\nEnter details of student%d\n",i+1);
        printf("USN:");
        scanf("%s",s[i].USN);
        printf("Name:");
        scanf("%s",s[i].Name);
        printf("Enter marks of 3 subjects:");
        scanf("%f%f%f",&s[i].Marks[0],&s[i].Marks[1],&s[i].Marks[2]);
    }
    printf("\nDetails of class\n");
    printf("SNo.\tUSN\tNAME\tMARKS IN 3 SUBJECTS\t\tAVERAGE\n");
    for(i=0;i<n;i++){
        s[i].avg=(s[i].Marks[0]+s[i].Marks[1]+s[i].Marks[2])/3;
        printf("%d\t%s\t%s\t%f,%f,%f\t%f\n",i+1,s[i].USN,s[i].Name,s[i].Marks[0],s[i].Marks[1],s[i].Marks[2],s[i].avg);
    }
    //calculating class average
    int class_sum=0;
    for(i=0;i<n;i++){
        class_sum+=s[i].avg;
    }
    float class_average=class_sum/n;
    printf("class average=%f\n",class_average);
    for(i=0;i<n;i++){
        if(s[i].avg>class_average){
            printf("\n%s has scored above avg",s[i].Name);
        }
        else{
            printf("\n%s has scored below avg\n",s[i].Name);
        }
    }
}