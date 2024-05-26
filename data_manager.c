#include "data_manager.h"
#include <stdio.h>

void save_athletes(Athlete *athletes, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < count; i++) {
            save_athlete_to_file(&athletes[i], filename);
        }
        fclose(file);
    }
}

void load_athletes(Athlete *athletes, int *count, const char *filename) {
    load_athlete_from_file(athletes, count, filename);
}

void save_performances(Performance *performances, int count, const char *filename) {
    for (int i = 0; i < count; i++) {
        save_performance_to_file(&performances[i]);
    }
}

void load_all_performances(Performance *performances, int *count, const char *filename) {
    load_performances_from_file(performances, count, filename);
}

