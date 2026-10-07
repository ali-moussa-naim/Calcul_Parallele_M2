#include <stdio.h>
#include <stdlib.h>

/*
Fonction pour afficher matrice de taille l * c
*/
void display(int* m, int l, int c)
{
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", m[i * c + j]);
        }
        printf("\n");
    }
}

/*
Fonction qui fait produit matricielle pour 2 matrices carrés n * n
Résultat dans la matrice c qui est carré n * n 
*/
void mul(int* a, int* b, int* c, int n)
{
    int i, j, k, cpt = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            for(k = 0; k < n; k++)
            {
                c[i * n + j] += a[i * n + k] * b[k * n + j];
            }
        }
    }
}

int main()
{
    int n = 2, cpt=1;
    int* a = (int*)malloc(n * n * sizeof(int));
    int* b = (int*)malloc(n * n * sizeof(int));
    int* c = (int*)malloc(n * n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i * n + j] = cpt;
            b[i * n + j] = 5 + cpt;
            cpt++;
        }
    }

    printf("Affichage de la matrice A:\n");
    display(a, n, n);

    printf("Affichage de la matrice B:\n");
    display(b, n, n);

    mul(a, b, c, n);

    printf("Affichage de la matrice finale C:\n");
    display(c, n, n);

    return 0;
}
