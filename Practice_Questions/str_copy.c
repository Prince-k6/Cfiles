// wap to copy data of old str in new str
#include<stdio.h>
#include<string.h>
int main(){
    char old_str[]="oldstr";
    char new_str[]="newstr";
    strcpy(new_str,old_str);   //copies old str to new str
    puts(new_str);
    return 0;
}