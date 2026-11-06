#include "affichage.h"
#include "aleatoire.h"
#include "calcul.h"
#include "mesure.h"

#include <time.h>

int main()
{
    // initialisation du seed
    srandom(time(NULL));

    // Déclaration des variables
    int64_t* vecteur = NULL;
    int64_t* matrice1 = NULL;
    int64_t* matrice2 = NULL;

    float* vec = NULL;
    int64_t** mat = NULL;

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

    mat = gen_matrix_rand_2();

    if(mat == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour mat\n");
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

    vec = comp_vec_mat_2(vecteur, mat);
    display_vector_float(vec);

    // Désallocation mémoire
    free(vecteur);
    free(matrice1);
    free(matrice2);
    free(vec);
    free(mat);
}
