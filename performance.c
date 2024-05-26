#include "performance.h"
#include <string.h>
#include <stdio.h>

// Ajoute une nouvelle performance au tableau des performances
void add_performance(Performance *performances, int *count, const char *athlete_name, const char *athlete_surname, const char *event, const char *date, float time) {
    // Copie le prénom de l'athlète dans la structure `performance`
    strncpy(performances[*count].athlete_name, athlete_name, MAX_NAME_LENGTH - 1);
    performances[*count].athlete_name[MAX_NAME_LENGTH - 1] = '\0';

    // Copie le nom de famille de l'athlète dans la structure `performance`
    strncpy(performances[*count].athlete_surname, athlete_surname, MAX_NAME_LENGTH - 1);
    performances[*count].athlete_surname[MAX_NAME_LENGTH - 1] = '\0';

    // Copie l'événement de la performance dans la structure `performance`
    strncpy(performances[*count].event, event, MAX_EVENT_LENGTH - 1);
    performances[*count].event[MAX_EVENT_LENGTH - 1] = '\0';

    // Copie la date de la performance dans la structure `performance`
    strncpy(performances[*count].date, date, 19);
    performances[*count].date[19] = '\0';

    // Affecte le temps de la performance
    performances[*count].time = time;

    // Incrémente le compteur de performances
    (*count)++;
}

// Affiche les informations d'une performance
void print_performance(const Performance *performance) {
    printf("Athlete: %s %s\n", performance->athlete_name, performance->athlete_surname);
    printf("Event: %s\n", performance->event);
    printf("Date: %s\n", performance->date);
    printf("Time: %.2f minutes\n", performance->time);
}

// Génère le nom de fichier pour une performance basée sur le prénom et le nom de famille de l'athlète
void generate_filename(const char *athlete_name, const char *athlete_surname, char *filename) {
    snprintf(filename, 100, "%s_%s.txt", athlete_name, athlete_surname);
}

// Sauvegarde une performance dans un fichier
void save_performance(const Performance *performance) {
    char filename[100];
    generate_filename(performance->athlete_name, performance->athlete_surname, filename);
    FILE *file = fopen(filename, "a");
    if (file) {
        // Écrit les informations de la performance dans le fichier
        fprintf(file, "%s %s %s %s %.2f\n", performance->athlete_name, performance->athlete_surname, performance->event, performance->date, performance->time);
        fclose(file);
    }
}

// Charge les performances à partir d'un fichier
void load_performance(Performance *performances, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        char athlete_name[MAX_NAME_LENGTH];
        char athlete_surname[MAX_NAME_LENGTH];
        char event[MAX_EVENT_LENGTH];
        char date[20];
        float time;

        // Lit les informations de chaque performance dans le fichier
        while (fscanf(file, "%49s %49s %49s %19s %f", athlete_name, athlete_surname, event, date, &time) == 5) {
            strncpy(performances[*count].athlete_name, athlete_name, MAX_NAME_LENGTH - 1);
            performances[*count].athlete_name[MAX_NAME_LENGTH - 1] = '\0';
            strncpy(performances[*count].athlete_surname, athlete_surname, MAX_NAME_LENGTH - 1);
            performances[*count].athlete_surname[MAX_NAME_LENGTH - 1] = '\0';
            strncpy(performances[*count].event, event, MAX_EVENT_LENGTH - 1);
            performances[*count].event[MAX_EVENT_LENGTH - 1] = '\0';
            strncpy(performances[*count].date, date, 19);
            performances[*count].date[19] = '\0';
            performances[*count].time = time;
            (*count)++;
        }
        fclose(file);
    }
}

// Sauvegarde une performance dans un fichier (fonction supplémentaire pour compatibilité)
void save_performance_to_file(const Performance *performance) {
    char filename[100];
    generate_filename(performance->athlete_name, performance->athlete_surname, filename);
    FILE *file = fopen(filename, "a");
    if (file) {
        // Écrit les informations de la performance dans le fichier
        fprintf(file, "%s %s %s %s %.2f\n", performance->athlete_name, performance->athlete_surname, performance->event, performance->date, performance->time);
        fclose(file);
    }
}

// Charge les performances à partir d'un fichier (fonction supplémentaire pour compatibilité)
void load_performances_from_file(Performance *performances, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        char athlete_name[MAX_NAME_LENGTH];
        char athlete_surname[MAX_NAME_LENGTH];
        char event[MAX_EVENT_LENGTH];
        char date[20];
        float time;

        // Lit les informations de chaque performance dans le fichier
        while (fscanf(file, "%49s %49s %49s %19s %f", athlete_name, athlete_surname, event, date, &time) == 5) {
            strncpy(performances[*count].athlete_name, athlete_name, MAX_NAME_LENGTH - 1);
            performances[*count].athlete_name[MAX_NAME_LENGTH - 1] = '\0';
            strncpy(performances[*count].athlete_surname, athlete_surname, MAX_NAME_LENGTH - 1);
            performances[*count].athlete_surname[MAX_NAME_LENGTH - 1] = '\0';
            strncpy(performances[*count].event, event, MAX_EVENT_LENGTH - 1);
            performances[*count].event[MAX_EVENT_LENGTH - 1] = '\0';
            strncpy(performances[*count].date, date, 19);
            performances[*count].date[19] = '\0';
            performances[*count].time = time;
            (*count)++;
        }
        fclose(file);
    }
}

// Affiche toutes les performances pour une discipline spécifique
void display_performances_by_discipline(const Performance *performances, int performance_count, const char *discipline) {
    int found = 0;
    for (int i = 0; i < performance_count; i++) {
        if (strcmp(performances[i].event, discipline) == 0) {
            print_performance(&performances[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No performances found for the discipline: %s\n", discipline);
    }
}
