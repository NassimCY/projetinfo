#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "athlete.h"
#include "performance.h"

void save_athletes(Athlete *athletes, int count, const char *filename);
void load_athletes(Athlete *athletes, int *count, const char *filename);
void save_performances(Performance *performances, int count, const char *filename);
void load_all_performances(Performance *performances, int *count, const char *filename);
void ouvrir_et_gerer_fichier();


#endif // DATA_MANAGER_H
