#include "courbe.h"

/*
Fonction qui trace les 3 courbes de cycles CPU pour la matrice représenté en un tableau 1D.
*/
void tracer_courbe_tab()
{
    const char* gnuname = "plotingFile.txt";
    const char* gnupath = "/mnt/c/gnuplot/bin/wgnuplot.exe";
    char command[512];

    FILE* f_plot = fopen(gnuname, "w");
    if (f_plot == NULL)
    {
        fprintf(stderr, "Impossible de creer le fichier %s.\n", gnuname);
        return;
    }

    fprintf(f_plot, "set title 'Comparaison des cycles CPU (Tableau 1D, int64_t)'\n");
    fprintf(f_plot, "set xlabel 'Taille N'\n");
    fprintf(f_plot, "set ylabel 'Cycles CPU (echelle log)'\n");
    fprintf(f_plot, "set grid\n");
    fprintf(f_plot, "set autoscale x\n");
    fprintf(f_plot, "set logscale y\n"); // Indispensable pour voir O(N^2) et O(N^3) ensemble
    fprintf(f_plot, "set key left top box\n");

    // Tracé des 3 courbes sur le même repère (séparées par des virgules)
    fprintf(f_plot,
            "plot 'data.txt' using 1:2 title 'Vecteur * Matrice' with linespoints lc rgb 'red' lw 2 pt 7, "
            "'data.txt' using 1:3 title 'Matrice * Vecteur' with linespoints lc rgb 'blue' lw 2 pt 5, "
            "'data.txt' using 1:4 title 'Matrice * Matrice' with linespoints lc rgb 'green' lw 2 pt 9\n");

    fclose(f_plot);

    // Lancement affichage
    snprintf(command, sizeof(command), "gnuplot -persist \"%s\" &", gnuname);
    system(command);
}