#include <stdio.h>
#include <stdlib.h>
#define EX_BADARGS  85          /* Wrong number of arguments */

/* shows all the possible couples 
 * (without repetition) in a set of n elements 
 { s1,s2, ... sn } */
/* global variable section */
int n,i,j;
/* define a 2D array of r rows and c columns 
 each element is a possible couple */
int *ptr, **arr; 
/* r is the number of rows of the 2D array 
   c is the number of columns of the 2D array 
   len is the length of the memory array to allocate */
int r,c,len=0; 
int count = 0,i,j; 

/* functions section */
int show_couples(int);
int allocate_array(int);
int deallocate_array(void);

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

int allocate_array(int n){
    r=n;c=n-1; len=0;
    /* allocate dynamically 2D array arr in RAM */
    len = sizeof(int *) * r + sizeof(int) * c * r; 
    arr = (int **)malloc(len); 
  
    /* ptr is now pointing to the first element of 2D array */
    ptr = (int *)(arr + r); 
  
    /* for loop to point rows pointer to appropriate location in 2D array */
    for(i = 0; i < r; i++) 
        arr[i] = (ptr + c * i); 
    
    /* initialise 2D array to all zeros */
    for (i = 0; i < r; i++) 
        for (j = 0; j < c; j++) 
            arr[i][j] = 0; // OR *(*(arr+i)+j) = ++count 
    return 0;
}

int deallocate_array(void){
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) 
            printf("%d ",arr[i][j]); // OR *(*(arr+i)+j) = ++count 
        puts("");
    }
    free(arr);
    return 0;
}

int show_couples(int n){
    i=1; j=2;
    /* allocate dynamically 2D array arr in RAM */
    allocate_array(n);
    for(i=1; i<=n; i++) 
    {
        for(j=1; j<=n; j++)
        {
            arr[i-1][j-1] = 1;
            if ( (i != j) && ( arr[j-1][i-1] != 1) ){
                printf("{s%d,s%d} ", i, j);
            }
        }
        puts("");
    }
    
    /* deallocate the 2D array arr from RAM */
    deallocate_array();
    
    return 0;
}


