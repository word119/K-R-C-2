#include<stdio.h>

int main(int argc, char *argv[])
{
    int i;

    // for (i = 1; i<argc; i++) {
    //     printf("%s%s", argv[i], i<argc-1 ? " " : "");
    // }

    /* argv: pointer for the pointer of char */
    while (--argc) {
        // printf("%s%s", *++argv, argc>1? " ": "");
        printf(argc > 1 ? "%s " : "%s", *++argv);
    }
    printf("\n");
    return 0;
}