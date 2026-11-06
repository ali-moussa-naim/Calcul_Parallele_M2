#include "aleatoire.h"

/*
Fonction pour générer un nombre aléatoirre de type int64_t
*/
int64_t random_int64_posix(void) {
    uint64_t high = (uint64_t)random(); // Récupère 31 bits
    uint64_t low = (uint64_t)random();  // Récupère 31 bits
    uint64_t rest = (uint64_t)random(); // Récupère le reste
    
    uint64_t result = (high << 33) | (low << 2) | (rest & 0x03);
    return (int64_t)result;
}

/*
Fonction qui génère des vecteurs de nombre aléatoire de type int64_t
*/
int64_t* gen_vector_rand()
{
    // Allocation dynamique du vecteur
    int64_t* vecteur = (int64_t*)malloc(sizeof(int64_t) * N);

    // vérification de la variable vecteur
    if(vecteur == NULL)
        return NULL;

    // Génération aléatoire des valeurs du vecteur
    for(int i = 0; i < N; i++)
    {
        int64_t nb_alea = random_int64_posix();
        vecteur[i] = nb_alea;
    }

    return vecteur;
}

/*
Fonction pour générer une matrice carré aléatoire de type int64_t, tableau
*/
int64_t* gen_matrix_rand()
{
    // Allocation dynamique de la matrice
    int64_t* matrice = (int64_t*)malloc(sizeof(int64_t) * N * N);

    // Vérification de la variable matrice
    if(matrice == NULL)
        return NULL;

    // Génération aléatoire des valeurs de la matrice
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int64_t nb_alea = random_int64_posix();
            matrice[i * N + j] = nb_alea;
        }
    }

    return matrice;
}

/*
Fonction pour générer une matrice carré aléatoire de type int64_t, tableau de tableau
*/
int64_t** gen_matrix_rand_2()
{
    // Allocation dynamique de la matrice
    int64_t** matrice = (int64_t**)malloc(sizeof(int64_t*) * N);

    // Vérification de la variable matrice
    if(matrice == NULL)
        return NULL;

    // Génération aléatoire des valeurs de la matrice
    for(int i = 0; i < N; i++)
    {
        matrice[i] = (int64_t*)malloc(sizeof(int64_t) * N);
        for(int j = 0; j < N; j++)
        {
            int64_t nb_alea = random_int64_posix();
            matrice[i][j] = nb_alea;
        }
    }

    return matrice;
}