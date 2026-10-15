#include "fonctions.h"



// Fonction multiplication 64x2
void mult64_64_128(uint64_t * a, uint64_t * b, uint64_t * res)
{
        __asm__ volatile("mov %2,%%rax\n\t"// rax <- a
							"mov %3,%%rdx\n\t"// rdx <- b
							"mul %%rdx"// rdx,rax <- a * b
							: "=a" (res[0]),//output
							  "=d" (res[1])
							: "m" (a[0]), "m" (b[0]));//input


}

// Fonction addition avec renvoi de la retenue 64x2
void addc64_64_128(uint64_t * a, uint64_t * b, uint64_t * res)
{
		//printf("res[0] = %lx, res[1] = %lx\n",res[0],res[1]);
        __asm__ volatile("mov %2,%0\n\t"
        					"xor %1,%1\n\t"
        					"add %3, %0\n\t"// res0 <- a + b
							"adc $0, %1\n\t"// res1 <- carry
							: "=q" (res[0]),//output
							  "=q" (res[1])
							: "m" (a[0]), "m" (b[0]));//input


}



int mult1n(uint64_t * a, uint64_t * b, uint64_t * res, int size)
{

	/************************************
		A compléter, algo 3 page 4
	*/

	return 0;
}


int multMP(uint64_t * a, uint64_t * b, uint64_t * res, int size)
{

	/************************************
		A compléter, algo 4 page 5
	*/



	return 0;
}


int squaringMP(uint64_t * a, uint64_t * res, int size)
{
	multMP(a,a,res,size);
	/************************************
		Ou a compléter, algo 5 page 6
	*/
	
	return 0;
}


