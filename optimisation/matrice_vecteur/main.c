#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>

#define N 5

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
Fonction pour afficher le vecteur
vecteur : pointeur sur int64_t (tableau), représente le vecteur
n : entier int64_t, dimension du vecteur
*/
void display_vector(int64_t* vecteur)
{
    for(int i = 0; i < N; i++)
        printf("%lu ", vecteur[i]);

    printf("\n");
}

/*
Fonction qui génère des vecteurs de nombre aléatoire de type int64_t
*/
int64_t* gen_vector_rand()
{
    // Allocation dynamique du vecteur
    int64_t* vecteur = (int64_t*)malloc(sizeof(int64_t) * N);

    for(int i = 0; i < N; i++)
    {
        int64_t nb_alea = random_int64_posix();
        vecteur[i] = nb_alea;
    }

    return vecteur;
}

/*
Fonction pour générer une matrice carré aléatoire de type int64_t
*/
int64_t* gen_matrix_rand()
{
    // Allocation dynamique de la matrice
    int64_t* matrice = (int64_t*)malloc(sizeof(int64_t) * N * N);

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
Fonction pour afficher une matrice de taille N * N
*/
void display_matrix(int64_t* matrice)
{
    for(int i = 0; i < N; i++)
    {
        printf("Ligne %d:\n", i + 1);
        for(int j = 0; j < N; j++)
        {
            printf("%lu ", matrice[i * N + j]);
        }

        printf("\n");
    }
}

/*
Fonction pour calculer vecteur * Matrice
*/
int64_t* comp_vec_mat(int64_t* vecteur, int64_t* matrice)
{
    // Déclaration de la variable finale (vecteur)
    int64_t* res = (int64_t*)malloc(sizeof(int64_t) * N);

    for(int i = 0; i < N; i++)
    {
        res[i] = 0.0f;
        for(int j = 0; j < N; j++)
        {
           res[i] +=  matrice[j * N + i] * vecteur[j];
        }
    }

    return res;
}

/*
Fonction pour calculer Matrice * Vecteur
*/
int64_t* comp_mat_vec(int64_t* matrice, int64_t* vecteur)
{
    // Dclaration de la variable finale(vecteur)
    int64_t* res = (int64_t*)malloc(sizeof(int64_t) * N);

    for(int i = 0; i < N; i++)
    {
        res[i] = 0.0f;
        for(int j = 0; j < N; j++)
        {
            res[i] = matrice[i * N + j] + vecteur[j];
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
}


int main()
{
    // initialisation du seed
    srand(time(NULL));

    // Déclaration des variables
    int64_t* vecteur = gen_vector_rand();
    int64_t* matrice1 = gen_matrix_rand();
    int64_t* vec_mat = comp_vec_mat(vecteur, matrice1);
    int64_t* mat_vec = comp_mat_vec(matrice1, vecteur);
    int64_t* matrice2 = gen_matrix_rand();
    int64_t* mat_mat = comp_mat_mat(matrice1, matrice2);


    if(vecteur == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour vecteur\n");
        return 1;
    }

    //display_vector(vecteur);

    if(matrice1 == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour matrice1\n");
        return 1;
    }

    display_matrix(matrice1);

    if(vecteur == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour vecteur\n");
        return 1;
    }

    //display_vector(vec_mat);

    if(mat_vec == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour mat_vec\n");
        return 1;
    }    

    //display_vector(mat_vec);

    if(matrice2 == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour matrice2\n");
        return 1;
    } 

    printf("\n");
    display_matrix(matrice2);

    if(mat_mat == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour matmat\n");
        return 1;
    } 

    printf("\n");
    display_matrix(mat_mat);

    // Désallocation mémoire des variables
    free(vecteur);
    free(matrice1);
    free(vec_mat);
    free(mat_vec);
    free(matrice2);

    return 0;
}