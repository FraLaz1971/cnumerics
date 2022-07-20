#include <stdio.h>
int main()
{
    char c, e; int ret, d;
    printf("Enter the character code for self-destruct (and then ENTER)? ");
    ret = scanf("%c", &c);
    /* use fpurge(stdin) in unix */
    printf("Input number code to confirm self-destruct (and then ENTER)?");
    ret = scanf("%d", &d);
    if(c=='G' && d==0)
    {
        printf("AUTO DESTRUCT ENABLED!\n");
        printf("Bye!\n");
    }
    else
    {
        printf("Okay. Whew!\n");
    }
        printf("press a key and then enter\n");
        ret = scanf("%s", &e);
        printf("Bye!\n");
    return(0);
}
