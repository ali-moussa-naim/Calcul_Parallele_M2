#ifndef CALCUL_H
#define CALCUL_H

#include "global.h"

float* comp_vec_mat(int64_t* vecteur, int64_t* matrice);
double* comp_mat_vec(int64_t* matrice, int64_t* vecteur);
uint64_t* comp_mat_mat(int64_t* mat1, int64_t* mat2);
float* comp_vec_mat_2(int64_t* vecteur, int64_t** matrice);

#endif 