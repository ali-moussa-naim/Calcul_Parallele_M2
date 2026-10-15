#include <inttypes.h>

#define SIZE 4


// Fonction multiplication 64x2
void mult64_64_128(uint64_t * a, uint64_t * b, uint64_t * res);
// Fonction addition avec renvoi de la retenue 64x2
void addc64_64_128(uint64_t * a, uint64_t * b, uint64_t * res);


// Fonction multiplication 1xn
int mult1n(uint64_t * a, uint64_t * b, uint64_t * res, int size);

// Fonction multiplication nxn
int multMP(uint64_t * a, uint64_t * b, uint64_t * res, int size);

// Fonction carré nxn
int squaringMP(uint64_t * a, uint64_t * res, int size);

