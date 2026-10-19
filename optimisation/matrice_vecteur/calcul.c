#include "calcul.h"

/*
Fonction pour calculer vecteur * Matrice
*/
float* comp_vec_mat(int64_t* vecteur, int64_t* matrice)
{
    // Déclaration de la variable finale (vecteur)
    float* res = (float*)malloc(sizeof(float) * N);

    // Vérification de la variable res
    if(res == NULL)
        return NULL;

    // Calcul du produit vecteur * matrice
    for(int i = 0; i < N; i++)
    {
        res[i] = 0.0f;
        for(int j = 0; j < N; j++)
        {
           res[i] +=  (float)matrice[j * N + i] * (float)vecteur[j];
        }
    }

    return res;
}

/*
Fonction pour calculer Matrice * Vecteur
*/
double* comp_mat_vec(int64_t* matrice, int64_t* vecteur)
{
    // Dclaration de la variable finale(vecteur)
    double* res = (double*)malloc(sizeof(double) * N);

    // Vérification de la variable res
    if(res == NULL)
        return NULL;

    // Calcul du produit matrice * vecteur
    for(int i = 0; i < N; i++)
    {
        res[i] = 0.0f;
        for(int j = 0; j < N; j++)
        {
            res[i] += (double)matrice[i * N + j] * (double)vecteur[j];
        }
    }

    return res;
}

/*
Fonction pour calculer Matrice * Matrice
*/
uint64_t* comp_mat_mat(int64_t* mat1, int64_t* mat2)
{
    // Déclaration de la variable finale(matrice)
    uint64_t* res = (uint64_t*)malloc(sizeof(uint64_t) * N * N);

    // Vérification de la variable res
    if(res == NULL)
        return NULL;

    // Calcul du produit matrice * matrice
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            res[i * N + j] = 0UL;
            for(int k = 0; k < N; k++)
            {
                res[i * N + j] += (uint64_t)mat1[i * N + k] * (uint64_t)mat2[k * N + j];
            }
        }
    }

    return res;
}
