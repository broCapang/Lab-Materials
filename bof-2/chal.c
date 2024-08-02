// gcc chal.c -o chal_64 -no-pie -m64
// gcc chal.c -o chal_32 -no-pie -m32
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void do_input(){
    int key = 0x12341234;
    char input[32];
    printf("Input:");
    fflush(stdout);
    gets(input);
    if(key == 0xdeadbeef){
        printf("Correct!!\n");
        printf("%04x\n", key);
        fflush(stdout);
    }
    else{
        printf("%04x\n", key);
        printf("...\n");
        fflush(stdout);
    }
}

int main(int argc, char* argv[]){
    do_input();
    return 0;
}