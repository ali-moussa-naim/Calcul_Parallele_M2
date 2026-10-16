#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>

#include "/home/etudiants/nalimous232/M2/calcul_parallele/optimisation/mesure_perf/Ressources/ccount.h"

#define N 30
#define NTEST 1000
#define NSAMPLE 30
#define NWARMUP 300

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
Fonction pour générer une matrice carré aléatoire de type int64_t
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


double mesure_vec_mat(int64_t* vecteur, int64_t* matrice)
{
    unsigned long long START, STOP;
    unsigned long long cycles;
    unsigned long long min_cycles;
    long double somme_min = 0.0L;

    float* res;

    // Chauffage des caches
    for (int i = 0; i < NWARMUP; i++) 
    {
        res = comp_vec_mat(vecteur, matrice);
        if (res == NULL)
            return -1.0;

        free(res);
    }

    // Mesures sur plusieurs échantillons
    for (int s = 0; s < NSAMPLE; s++) 
    {
        min_cycles = ~0ULL;

        for (int i = 0; i < NTEST; i++) 
        {
            STAMP(START);

            res = comp_vec_mat(vecteur, matrice);

            STAMP(STOP);

            if (res == NULL)
                return -1.0;

            cycles = STOP - START;

            free(res);

            if (cycles < min_cycles)
                min_cycles = cycles;
        }

        somme_min += (long double)min_cycles;
    }

    return (double)(somme_min / NSAMPLE);
}

double mesure_mat_vec(int64_t* matrice, int64_t* vecteur)
{
    unsigned long long START, STOP;
    unsigned long long cycles;
    unsigned long long min_cycles;
    long double somme_min = 0.0L;

    double* res;

    // Chauffage des caches
    for (int i = 0; i < NWARMUP; i++) 
    {
        res = comp_mat_vec(matrice, vecteur);
        if (res == NULL)
            return -1.0;

        free(res);
    }

    // Mesures sur plusieurs échantillons
    for (int s = 0; s < NSAMPLE; s++) 
    {
        min_cycles = ~0ULL;

        for (int i = 0; i < NTEST; i++) 
        {
            STAMP(START);

            res = comp_mat_vec(matrice, vecteur);

            STAMP(STOP);

            if (res == NULL)
                return -1.0;

            cycles = STOP - START;

            free(res);

            if (cycles < min_cycles)
                min_cycles = cycles;
        }

        somme_min += (long double)min_cycles;
    }

    return (double)(somme_min / NSAMPLE);
}

double mesure_mat_mat(int64_t* matrice1, int64_t* matrice2)
{
    unsigned long long START, STOP;
    unsigned long long cycles;
    unsigned long long min_cycles;
    long double somme_min = 0.0L;

    uint64_t* res;

    // Chauffage des caches
    for (int i = 0; i < NWARMUP; i++) 
    {
        res = comp_mat_mat(matrice1, matrice1);
        if (res == NULL)
            return -1.0;

        free(res);
    }

    // Mesures sur plusieurs échantillons
    for (int s = 0; s < NSAMPLE; s++) 
    {
        min_cycles = ~0ULL;

        for (int i = 0; i < NTEST; i++) 
        {
            STAMP(START);

            res = comp_mat_mat(matrice1, matrice2);

            STAMP(STOP);

            if (res == NULL)
                return -1.0;

            cycles = STOP - START;

            free(res);

            if (cycles < min_cycles)
                min_cycles = cycles;
        }

        somme_min += (long double)min_cycles;
    }

    return (double)(somme_min / NSAMPLE);
}


int main()
{
    // initialisation du seed
    srandom(time(NULL));

    // Déclaration des variables
    int64_t* vecteur = NULL;
    int64_t* matrice1 = NULL;
    int64_t* matrice2 = NULL;

    // Vérification des allocations
    vecteur = gen_vector_rand();

    if(vecteur == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour vecteur\n");
        return 1;
    }

    matrice1 = gen_matrix_rand();

    if(matrice1 == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour matrice1\n");
        return 1;
    }

    matrice2 = gen_matrix_rand();

    if(matrice2 == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour matrice2\n");
        return 1;
    }

    // Calcul des cycles horloge
    double cycles_vec_mat = mesure_vec_mat(vecteur, matrice1);

    if (cycles_vec_mat < 0.0) {
        fprintf(stderr, "Erreur pendant la mesure\n");
        return 1;
    }

    printf("Vecteur * matrice : %.2f cycles en moyenne\n", cycles_vec_mat);

    double cycles_mat_vec = mesure_mat_vec(vecteur, matrice1);

    if(cycles_mat_vec < 0.0) 
    {
        fprintf(stderr, "Erreur pendant la mesure\n");
        return 1;
    }

    printf("Matrice * vecteur : %.2f cycles en moyenne\n", cycles_mat_vec);

    double cycles_mat_mat = mesure_mat_mat(matrice1, matrice2);

    if(cycles_mat_mat < 0.0) 
    {
        fprintf(stderr, "Erreur pendant la mesure\n");
        return 1;
    }

    printf("Matrice * Matrice : %.2f cycles en moyenne\n", cycles_mat_mat);

    // Désallocation mémoire
    free(vecteur);
    free(matrice1);
    free(matrice2);
}


/*
int main()
{
    // initialisation du seed
    srandom(time(NULL));

    // Déclaration des variables
    int64_t* vecteur = NULL;
    int64_t* matrice1 = NULL;
    int64_t* matrice2 = NULL;

    float* vec_mat = NULL;
    double* mat_vec = NULL;
    uint64_t* mat_mat = NULL;

    // Vérification des allocations
    vecteur = gen_vector_rand();

    if(vecteur == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour vecteur\n");
        return 1;
    }

    matrice1 = gen_matrix_rand();

    if(matrice1 == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour matrice1\n");
        return 1;
    }

    matrice2 = gen_matrix_rand();

    if(matrice2 == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour matrice2\n");
        return 1;
    }

    vec_mat = comp_vec_mat(vecteur, matrice1);

    if(vec_mat == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour vec_mat\n");
        return 1;
    }

    mat_vec = comp_mat_vec(matrice1, vecteur);

    if(mat_vec == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour mat_vec\n");
        return 1;
    }

    mat_mat = comp_mat_mat(matrice1, matrice2);

    if(mat_mat == NULL) 
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour mat_mat\n");
        return 1;
    }

    display_vector_int64(vecteur);
    printf("\n");

    display_matrix(matrice1);
    printf("\n");

    display_vector_float(vec_mat);
    printf("\n");

    //display_vector_double(mat_vec);
    
    //display_matrix(matrice2);

    printf("\n");
    //display_matrix_uint64(mat_mat);

    // Désallocation mémoire des variables
    free(vecteur);
    free(matrice1);
    free(vec_mat);
    free(mat_vec);
    free(matrice2);
    free(mat_mat);

    return 0;
}
*/