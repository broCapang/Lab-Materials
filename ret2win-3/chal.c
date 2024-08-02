// gcc chal.c -o chal_64 -fno-stack-protector -m64
// gcc chal.c -o chal_32 -fno-stack-protector -m32


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void win()
{
    system("/bin/sh");
}

void vuln() {
    char buffer[64];

    puts("This time there is a address protection");
    puts("Input: ");
    gets(buffer);
    printf(buffer);

    puts("\n2nd Input: ");
    gets(buffer);
}

int main() {
    vuln();
}