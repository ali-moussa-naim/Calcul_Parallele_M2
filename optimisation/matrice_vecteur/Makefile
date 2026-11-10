# Variables
CC = gcc
CFLAGS = -Wall 
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
HEADERS = $(wildcard *.h)
TARGET = main

all: $(TARGET)

# Lien de l'exécutable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ 

# Compilation des fichiers objets
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Test pour lancer plusieurs fois à la suite le programme
test:
	@for i in 1 2 3 4 5 6 7 8 9 10; do \
		echo "-- Test avec la constante N=$$i --"; \
		$(CC) $(CFLAGS) -DN=$$i -c $(SOURCES); \
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS); \
		./$(TARGET); \
		echo ""; \
	done

# Nettoyage
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean