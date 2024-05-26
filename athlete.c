#include "athlete.h"
#include "performance.h"
#include <string.h>
#include <stdio.h>

// Ajoute un nouvel athlète au tableau des athlètes
void add_athlete(Athlete *athletes, int *count, const char *name, const char *surname, int age, const char *country, const char *preferred_discipline) {
    // Copie le prénom de l'athlète dans la structure `athlete`
    strncpy(athletes[*count].name, name, MAX_NAME_LENGTH - 1);
    athletes[*count].name[MAX_NAME_LENGTH - 1] = '\0';

    // Copie le nom de famille de l'athlète dans la structure `athlete`
    strncpy(athletes[*count].surname, surname, MAX_NAME_LENGTH - 1);
    athletes[*count].surname[MAX_NAME_LENGTH - 1] = '\0';

    // Affecte l'âge de l'athlète
    athletes[*count].age = age;

    // Copie le pays de l'athlète dans la structure `athlete`
    strncpy(athletes[*count].country, country, MAX_NAME_LENGTH - 1);
    athletes[*count].country[MAX_NAME_LENGTH - 1] = '\0';

    // Copie la discipline préférée de l'athlète dans la structure `athlete`
    strncpy(athletes[*count].preferred_discipline, preferred_discipline, MAX_NAME_LENGTH - 1);
    athletes[*count].preferred_discipline[MAX_NAME_LENGTH - 1] = '\0';

    // Incrémente le compteur d'athlètes
    (*count)++;
}


// Affiche les informations d'un athlète
void print_athlete(const Athlete *athlete) {
    printf("Athlete: %s %s\n", athlete->name, athlete->surname);
    printf("Age: %d\n", athlete->age);
    printf("Country: %s\n", athlete->country);
    printf("Preferred Discipline: %s\n", athlete->preferred_discipline); // Ajout de la discipline préférée
}

// Sauvegarde les informations d'un athlète dans un fichier
void save_athlete_to_file(const Athlete *athlete, const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file) {
        // Écrit les informations de l'athlète dans le fichier
        fprintf(file, "%s %s %d %s %s\n", athlete->name, athlete->surname, athlete->age, athlete->country, athlete->preferred_discipline);
        fclose(file);
    }
}

// Charge les informations des athlètes à partir d'un fichier
void load_athlete_from_file(Athlete *athletes, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        char name[MAX_NAME_LENGTH];
        char surname[MAX_NAME_LENGTH];
        int age;
        char country[MAX_NAME_LENGTH];
        char preferred_discipline[MAX_NAME_LENGTH]; // Ajout de la discipline préférée

        // Lit les informations de chaque athlète dans le fichier
        while (fscanf(file, "%49s %49s %d %49s %49s", name, surname, &age, country, preferred_discipline) == 5) {
            strncpy(athletes[*count].name, name, MAX_NAME_LENGTH - 1);
            athletes[*count].name[MAX_NAME_LENGTH - 1] = '\0';
            strncpy(athletes[*count].surname, surname, MAX_NAME_LENGTH - 1);
            athletes[*count].surname[MAX_NAME_LENGTH - 1] = '\0';
            athletes[*count].age = age;
            strncpy(athletes[*count].country, country, MAX_NAME_LENGTH - 1);
            athletes[*count].country[MAX_NAME_LENGTH - 1] = '\0';
            strncpy(athletes[*count].preferred_discipline, preferred_discipline, MAX_NAME_LENGTH - 1);
            athletes[*count].preferred_discipline[MAX_NAME_LENGTH - 1] = '\0';
            (*count)++;
        }
        fclose(file);
    }
}

// Crée un fichier pour un athlète avec ses informations de base et une section pour les performances
void create_athlete_file(const Athlete *athlete) {
    char filename[100];
    snprintf(filename, sizeof(filename), "%s_%s.txt", athlete->name, athlete->surname);
    FILE *file = fopen(filename, "w");
    if (file) {
        // Écrit les informations de base de l'athlète et une section vide pour les performances
        fprintf(file, "Name: %s\nSurname: %s\nAge: %d\nCountry: %s\nPreferred Discipline: %s\n\nPerformances:\n", athlete->name, athlete->surname, athlete->age, athlete->country, athlete->preferred_discipline);
        fclose(file);
    } else {
        perror("Failed to create file");
    }
}

// Met à jour le fichier de l'athlète en ajoutant une nouvelle performance
void update_athlete_file(const Athlete *athlete, const Performance *performance) {
    char filename[100];
    snprintf(filename, sizeof(filename), "%s_%s.txt", athlete->name, athlete->surname);
    FILE *file = fopen(filename, "a");
    if (file) {
        // Ajoute la nouvelle performance à la section des performances dans le fichier de l'athlète
        fprintf(file, "Event: %s, Date: %s, Time: %.2f minutes\n", performance->event, performance->date, performance->time);
        fclose(file);
    } else {
        perror("Failed to update file");
    }
}

// Recherche un athlète par son prénom et nom de famille
void search_athlete_by_name(const Athlete *athletes, int athlete_count, const char *name, const char *surname) {
    for (int i = 0; i < athlete_count; i++) {
        if (strcmp(athletes[i].name, name) == 0 && strcmp(athletes[i].surname, surname) == 0) {
            print_athlete(&athletes[i]);
            return;
        }
    }
    printf("Athlete not found.\n");
}

// Affiche tous les athlètes ayant une discipline préférée spécifique
void display_athletes_by_discipline(const Athlete *athletes, int athlete_count, const char *discipline) {
    int found = 0;
    for (int i = 0; i < athlete_count; i++) {
        if (strcmp(athletes[i].preferred_discipline, discipline) == 0) {
            print_athlete(&athletes[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No athletes found with the preferred discipline: %s\n", discipline);
    }
}
