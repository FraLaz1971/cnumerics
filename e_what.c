#include <stdio.h>
#include <stdlib.h>
#include "errvals.h"

int main(int argc, char **argv){
    int e;
    if (argc != 2){
        fprintf(stderr, "usage: %s <error_code>\n", argv[0]);
        return EX_BADARGS;
    } else {
        e = atoi(argv[1]);
        error_what(e);
        return EXIT_SUCCESS;
    }
}
