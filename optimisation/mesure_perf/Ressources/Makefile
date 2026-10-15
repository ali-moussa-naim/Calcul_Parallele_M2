OPTIONS= -O3 -std=c99 -g -lm -lgmp
WARNINGS= -Wall -pedantic -Wextra
OPTIONS+= $(WARNINGS)
OPTIONS+= $(MACROS)
multMultiPrecision : multMultiPrecision.o fonctions.o
	gcc -o multMultiPrecision multMultiPrecision.o fonctions.o $(OPTIONS)

fonctions.o : fonctions.c fonctions.h
	gcc -c fonctions.c $(OPTIONS)

multMultiprecision.o : fonctions.o
	gcc -c multMultiPrecision.c $(OPTIONS)

all : multMultiPrecision


clean :
	rm *.o -fv *~

cleanall : clean
	rm multMultiPrecision -f

