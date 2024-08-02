// gcc chal.c -o chal_64 -fstack-protector -no-pie -m64
// gcc chal.c -o chal_32 -fstack-protector -no-pie -m32
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void win()
{
    system("/bin/sh");
}

void vuln() {
    char buffer[64];

    puts("This time there is a stack protection");
    puts("Input: ");
    gets(buffer);
    printf(buffer);

    puts("\n2nd Input: ");
    gets(buffer);
}

int main() {
    vuln();
}