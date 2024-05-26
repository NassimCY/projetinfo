# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Iinclude -Wall -Wextra -Werror

# Dossiers des fichiers sources et des fichiers objets
SRC_DIR = src
OBJ_DIR = obj

# Fichiers sources
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/athlete.c $(SRC_DIR)/performance.c $(SRC_DIR)/data_manager.c $(SRC_DIR)/utils.c

# Fichiers objets
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Nom de l'exécutable
TARGET = projet

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

# Règle pour créer les fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer le projet
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Règle pour forcer la recréation de l'exécutable
rebuild: clean all

# Indiquer que ces règles ne sont pas des fichiers
.PHONY: all clean rebuild
