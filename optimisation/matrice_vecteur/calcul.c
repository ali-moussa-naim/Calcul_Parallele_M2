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
Fonction pour calculer vecteur * Matrice, avec une matrice tableau tableau
*/
float* comp_vec_mat_2(int64_t* vecteur, int64_t** matrice)
{
    // Déclaration de la variable final, un vecteur
    float* res = (float*)malloc(sizeof(float) * N);

    // Vérification de la variable res
    if(res == NULL)
        return NULL;

    // Calcul du produit vecteur * Matrice
    for(int i = 0; i < N; i++)
    {
        res[i] = 0.0f;
        for(int j = 0; j < N; j++)
        {
            res[i] += (float)matrice[i][j] * (float)vecteur[j];
        }
    }

    return res;
}

/*
Fonction pour calculer Matrice * Vecteur
*/
float* comp_mat_vec(int64_t* matrice, int64_t* vecteur)
{
    // Dclaration de la variable finale(vecteur)
    float* res = (float*)malloc(sizeof(float) * N);

    // Vérification de la variable res
    if(res == NULL)
        return NULL;

    // Calcul du produit matrice * vecteur
    for(int i = 0; i < N; i++)
    {
        res[i] = 0.0f;
        for(int j = 0; j < N; j++)
        {
            res[i] += (float)matrice[i * N + j] * (float)vecteur[j];
        }
    }

    return res;
}

/*
Fonction pour calculer Matrice * Vecteur, avec matrice tableau * tableau
*/
float* comp_mat_vec_2(int64_t** matrice, int64_t* vecteur)
{
    // Dclaration de la variable finale(vecteur)
    float* res = (float*)malloc(sizeof(float) * N);

    // Vérification de la variable res
    if(res == NULL)
        return NULL;

    // Calcul du produit matrice * vecteur
    for(int i = 0; i < N; i++)
    {
        res[i] = 0.0f;
        for(int j = 0; j < N; j++)
        {
            res[i] += (float)matrice[i][j] * (float)vecteur[j];
        }
    }

    return res;
}

/*
Fonction pour calculer Matrice * Matrice
*/
int64_t* comp_mat_mat(int64_t* mat1, int64_t* mat2)
{
    // Déclaration de la variable finale(matrice)
    int64_t* res = (int64_t*)malloc(sizeof(int64_t) * N * N);

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
                res[i * N + j] += mat1[i * N + k] * mat2[k * N + j];
            }
        }
    }

    return res;
}

/*
Fonction pour calculer Matrice * Matrice, matrice tableau * tableau
*/
int64_t** comp_mat_mat_2(int64_t** mat1, int64_t** mat2)
{
    // Déclaration de la variable finale(matrice)
    int64_t** res = (int64_t**)malloc(sizeof(int64_t*) * N);

    // Vérification de la variable res
    if(res == NULL)
        return NULL;

    // Calcul du produit matrice * matrice
    for(int i = 0; i < N; i++)
    {
        res[i] = (int64_t*)malloc(sizeof(int64_t) * N);
        for(int j = 0; j < N; j++)
        {
            res[i][j] = 0UL;
            for(int k = 0; k < N; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return res;
}

