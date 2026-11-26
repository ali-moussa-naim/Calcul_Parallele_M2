# Variables
CC = gcc
CFLAGS = -Wall -O2
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
HEADERS = $(wildcard *.h)
TARGET = main
SIZES = 128

all: $(TARGET)

# Lien de l'exécutable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ 

# Compilation des fichiers objets
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Test pour lancer plusieurs fois à la suite le programme
bench:
	@> data_1D.txt
	@> data_2D.txt
	@for n in $(SIZES); do \
		gcc -O0 -DN=$$n main.c calcul.c mesure.c aleatoire.c affichage.c courbe.c -o prog && \
		./prog; \
	done

# Nettoyage
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean