#include "mesure.h"

/*
Calcule le nombre de cycles CPU pour Vecteur * Matrice
*/
double mesure_vec_mat(int64_t* vecteur, int64_t* matrice)
{
    unsigned long long int START, STOP;
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

/*
Calcule le nombre de cycles CPU pour Vecteur * Matrice, Matrice tableau * tableau
*/
double mesure_vec_mat_2(int64_t* vecteur, int64_t** matrice)
{
    unsigned long long int START, STOP;
    unsigned long long cycles;
    unsigned long long min_cycles;
    long double somme_min = 0.0L;

    float* res;

    // Chauffage des caches
    for (int i = 0; i < NWARMUP; i++) 
    {
        res = comp_vec_mat_2(vecteur, matrice);
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

            res = comp_vec_mat_2(vecteur, matrice);

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

/*
Calculer le nombre de cycles CPU pour Matrice * Vecteur
*/
double mesure_mat_vec(int64_t* matrice, int64_t* vecteur)
{
    unsigned long long START, STOP;
    unsigned long long cycles;
    unsigned long long min_cycles;
    long double somme_min = 0.0L;

    float* res;

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

/*
Calcule le nombre de cycles CPU pour Matrice * Vecteur, Matrice = tableau * tableau
*/
double mesure_mat_vec_2(int64_t** matrice, int64_t* vecteur)
{
    unsigned long long START, STOP;
    unsigned long long cycles;
    unsigned long long min_cycles;
    long double somme_min = 0.0L;

    float* res;

    // Chauffage des caches
    for (int i = 0; i < NWARMUP; i++) 
    {
        res = comp_mat_vec_2(matrice, vecteur);
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

            res = comp_mat_vec_2(matrice, vecteur);

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

/*
Calcule le nombre de cycles CPU Matrice * Matrice
*/
double mesure_mat_mat(int64_t* matrice1, int64_t* matrice2)
{
    unsigned long long START, STOP;
    unsigned long long cycles;
    unsigned long long min_cycles;
    long double somme_min = 0.0L;

    int64_t* res;

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

/*
Calcule le nombre de cycles CPU pour Matrice * Matrice: Matrice = tableau * tableau
*/
double mesure_mat_mat_2(int64_t** matrice1, int64_t** matrice2)
{
    unsigned long long START, STOP;
    unsigned long long cycles;
    unsigned long long min_cycles;
    long double somme_min = 0.0L;

    int64_t** res;

    // Chauffage des caches
    for (int i = 0; i < NWARMUP; i++) 
    {
        res = comp_mat_mat_2(matrice1, matrice1);
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

            res = comp_mat_mat_2(matrice1, matrice2);

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