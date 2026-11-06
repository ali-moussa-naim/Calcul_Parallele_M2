#ifndef MESURE_H
#define MESURE_H

#include "global.h"
#include "ccount.h"
#include "calcul.h"

double mesure_vec_mat(int64_t* vecteur, int64_t* matrice);
double mesure_mat_vec(int64_t* matrice, int64_t* vecteur);
double mesure_mat_mat(int64_t* matrice1, int64_t* matrice2);

#endif 