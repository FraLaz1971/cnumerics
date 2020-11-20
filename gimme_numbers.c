/* gimme_numbers.c : this program prints numbers 5,6,7,8 and shows how to use
function parameters  */
#include <stdio.h>
int gimme_five();
int gimme_six(void);
int gimme_seven(int p1);
int gimme_eight(int p1, int p2);

int main(){
	printf("%i\n", gimme_five() );
	printf("%i\n", gimme_six() );
	printf("%i\n", gimme_seven(4) );
	printf("%i\n", gimme_eight(10, -330) );
}


int gimme_five(){
    return 5;
}

int gimme_six(void){
    return 6;
}

int gimme_seven(int p1){
    return 5;
}

int gimme_eight(int p1, int p2){
    return 5;
}

