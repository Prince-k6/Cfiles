//WAP to store bank details using structures
#include<stdio.h>
struct bank_account{
    char bank_name[20];
    int acc_no;
    char holder_name[20];
};

void acc_info(struct bank_account x){
    printf("bank name=%s,acc_no=%d,holder_name=%s\n",x.bank_name,x.acc_no,x.holder_name);
}

int main(){
    struct bank_account a1={"sbi",12345,"abcd"};
    struct bank_account a2={"hdfc",45213,"xyzz"};
    acc_info(a1);
    acc_info(a2);
    return 0;
}

