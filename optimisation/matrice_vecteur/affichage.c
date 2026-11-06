#include "affichage.h"

/*
Fonction pour afficher le vecteur
vecteur : pointeur sur int64_t (tableau), représente le vecteur
*/
void display_vector_int64(int64_t* vecteur)
{
    if(N <= 10)
    {
        for(int i = 0; i < N; i++)
        {
            printf("Valeur n%d: %" PRId64 " ", i, vecteur[i]);
            printf("\n");
        }
    }
}

/*
Fonction pour afficher le vecteur
vecteur : pointeur sur double (tableau), représente le vecteur
*/
void display_vector_double(double* vecteur)
{
    if(N <= 10)
    {
        for(int i = 0; i < N; i++)
        {
            printf("Valeur n%d: %f", i, vecteur[i]);
            printf("\n");
        }
    }
}

/*
Fonction pour afficher le vecteur
vecteur : pointeur sur float (tableau), représente le vecteur
*/
void display_vector_float(float* vecteur)
{
    if(N <= 10)
    {
        for(int i = 0; i < N; i++)
        {
            printf("Valeur n%d: %f", i, vecteur[i]);
            printf("\n");
        }
    }
}

/*
Fonction pour afficher une matrice de taille N * N
*/
void display_matrix(int64_t* matrice)
{
    if(N <= 10)
    {
        // Affichage des valeurs
        for(int i = 0; i < N; i++)
        {
            printf("Ligne %d:\n", i + 1);
            for(int j = 0; j < N; j++)
            {
                printf("%" PRId64 " ", matrice[i * N + j]);
            }

            printf("\n");
        }
    }
}

/*
Fonction pour afficher une matrice de taille N * N
*/
void display_matrix_uint64(uint64_t* matrice)
{
    if(N <= 10)
    {
        // Affichage des valeurs
        for(int i = 0; i < N; i++)
        {
            printf("Ligne %d:\n", i + 1);
            for(int j = 0; j < N; j++)
            {
                printf("%" PRIu64 " ", matrice[i * N + j]);
            }

            printf("\n");
        }
    }
}

/*
Fonction pour afficher une matrice de taille N * N, tableau de tableau
*/
void display_matrix_2(int64_t** matrice)
{
    if(N <= 10)
    {
        // Affichage des valeurs
        for(int i = 0; i < N; i++)
        {
            printf("Ligne %d:\n", i + 1);
            for(int j = 0; j < N; j++)
            {
                printf("%" PRIu64 " ", matrice[i][j]);
            }

            printf("\n");
        }
    }
}