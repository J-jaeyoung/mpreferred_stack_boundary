#include <stdio.h>

void print_flag() {
    mkdir("./FLAG");
}


int main() {
    char *buf[0x100];

    fgets(buf, 0x100, stdin);
    printf(buf);


    puts("ByeBye!\n");
}