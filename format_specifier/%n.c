#include <stdio.h>

int main()
{
    int n,k;
    int x = 123456789;
    printf("!%d!%nhello%n\n",x, &n, &k);
    printf("n: %d\n", n);                       // 11
    printf("k: %d\n", k);                       // 11

    printf("HEllo!!!\n");
    printf("HEllo!!!\n");
    printf("HEllo!!!\n");                       // meaningless!

    printf("\n\r\n\nAAAAA%n",&n);               // only count this string
    printf("n: %d\n", n);                       // 9
    
    printf("%d %d %d %d %d test: %4$d\n", 10,20,30,40,50,60);  // 10 20 30 40 50 40

    int s = 0xaaaaaaaa;
    printf("%256d%hhn", 1, &s);
    printf("\n\n%x\n",s);
}