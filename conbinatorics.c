#include <stdio.h>
#include <stdlib.h>
#include "conbinatorics.h"

int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "usage:%s <n_elements>\n", argv[0]);
        return EX_BADARGS;
    } else {
        n = atoi(argv[1]);
        show_couples(n);
        return EXIT_SUCCESS;
    }
}

