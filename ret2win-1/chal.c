// gcc chal.c -o chal_64 -no-pie -m64
// gcc chal.c -o chal_32 -no-pie -m32
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void win()
{
    system("/bin/sh");
}

void vuln() {
    char buffer[64];

    puts("Input: ");
    gets(buffer);
    printf(buffer);

}

int main() {
    vuln();
}