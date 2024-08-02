// gcc chal.c -o chal_64 -no-pie -m64
// gcc chal.c -o chal_32 -no-pie -m32
#include <stdio.h>
#include <string.h>

int main(void)
{
    char password[6];
    int authorised = 0;

    printf("Password: \n");
    gets(password);

    if(strcmp(password, "SuperSecretPassword") == 0)
    {
        printf("Correct Password!\n");
        authorised = 1;
    }
    else
    {
        printf("Incorrect Password!\n");
    }

    if(authorised)
    {
        printf("Successfully logged in! \n", authorised);
    }else{
		printf("Failed to log in\n", authorised);
	}

    return 0;
}