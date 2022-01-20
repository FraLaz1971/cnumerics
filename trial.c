#include<stdio.h>
int main(){
	int var1,var2, add, sub, mult, div,res,i;
	printf("****************************************\n");
	printf("** program trial.c - date: 2022-01-20 **\n");
	printf("** it will read 3 couples of integers **\n");
	printf("** and give simple maths results      **\n");
	printf("** for each of them.		      **\n");
	printf("** authors: Alita & doc. ;-)	      **\n");
	printf("****************************************\n");
        for (i=0; i<3; i++){
	    printf("doing iteration %d\n", i);
	    printf("enter a first int. number ... ");
	    res = scanf("%d", &var1);
	    printf("enter a second int. number ... ");
	    res = scanf("%d", &var2);

	    add = var1 + var2;
	    mult = var1 * var2;
	    div = var1 / var2;
	    sub = var1 - var2;

	    if (sub<0)
	        printf("NOTICE: %d is less than %d \n",var1, var2);
	        printf("the result of %d - %d will be negative \n",var1, var2);

	    printf("WARNING! operator / is integer division (without the fractional part)\n");
	    printf("your results are: %d + %d = %d\n", var1, var2, add  );
	    printf("your results are: %d - %d = %d\n", var1, var2, sub  );
	    printf("your results are: %d * %d = %d\n", var1, var2, mult );
	    printf("your results are: %d / %d = %d\n", var1, var2, div  );
       }
	    printf("You processed 3 couples \n");	
	    printf("*********************** \n");	
	    printf("*** END OF PROGRAM  *** \n");	
	    printf("***      BYE.       *** \n");	
	    printf("*********************** \n");	
            return 0;
}

