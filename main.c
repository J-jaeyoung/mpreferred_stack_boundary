#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>

unsigned int secret = 0xdeadbeef;

void handle_failure(char *buf) {
    char msg[100];
    snprintf(msg, sizeof(msg), "Invalid Password: %s\n", buf);
    printf(msg);
}

int main(int argc, char* argv[]) {
    setreuid(getuid(), getuid());
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    int tmp = secret;

    char buf[100];
    printf("SELF Crackme Level 0x00\n");
    printf("Password!\n");

    fgets(buf, sizeof(buf), stdin);

    if(!strcmp(buf, "123123123123\n")) {
        printf("Password OK!\n");
    } else {
        handle_failure(buf);
    }

    if(tmp != secret) {
        puts("The secret is modified!!!\n");
        printf("new secret: 0x%08x\n",secret);
    }

    return 0;
}
