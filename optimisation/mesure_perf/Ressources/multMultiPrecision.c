/**********************************************
*
*		Projet pour M1 DID
*
*/


// compilation gcc multMultiPrecision.c -o multMultiPrecision -O3 -std=c99 -g -lm -lgmp

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gmp.h>
#include <math.h>
#include <inttypes.h>
#include "fonctions.h"




int affichage(uint64_t * res, int size, char *txt)
{
	printf("%s = ",txt);
	for (int i=0;i<size;i++) printf("%16.16lX ",res[size-1-i]);
	printf(" ;\n\n");
	
	return 0;
}


/********************************************************************************
*
*	MAIN !!!!!!!!!!
*
*/


int main()
{


	int i,size=SIZE;
	size_t count;
	uint64_t a[SIZE],b[SIZE], res[SIZE<<1], test[SIZE<<1] , indicateur = 0;
	uint64_t x=0xffffffffffffffff,y=0xffffffffffffffff,c=1;
	



	srand(time(NULL));
	indicateur = 0 ;
	for (i=0;i<size;i++)
	{
		// pour avoir A[i] et B[i] entre 0x00000000 et 0xffffffff
		a[i] = (((uint64_t)(rand()+rand())<<32)^(rand()+rand()));
		b[i] = (((uint64_t)(rand()+rand())<<32)^(rand()+rand()));
	}


	printf("--------------------------------------------------------------------------\n");
	printf("                             SIZE = %d 64 bit words\n",size);
	printf("--------------------------------------------------------------------------\n");

	
	affichage(a,size,"a");	
	
	affichage(b,size,"b");
		
	addc64_64_128(&x,&y,res);
	printf("a+b : (64_64_128)\n");
	affichage(res,2,"res");
			
	
	mult64_64_128(a,b,res);
	printf("a*b : (64_64_128)\n");
	affichage(res,2,"res");
	
	mult1n(a,b,res,size);
	printf("a*b : (mult1n)\n");
	affichage(res,size+1,"res");


	multMP(a,b,res,size);
	printf("a*b : (multMP)\n");
	affichage(res,size<<1,"res");

	squaringMP(a,res,size);
	printf("a*a : (squaringMP)\n");
	affichage(res,size<<1,"res");
	
	
	/************************************
		A compléter, algo 4 page 5
	*/
	


	printf("Au revoir et merci !\n");

	return 0;


}
