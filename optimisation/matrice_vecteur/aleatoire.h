#ifndef ALEATOIRE_H
#define ALEATOIRE_H

#include "global.h"

int64_t random_int64_posix(void);
int64_t* gen_vector_rand();
int64_t* gen_matrix_rand();

#endif 