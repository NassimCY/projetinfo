#ifndef ATHLETE_H
#define ATHLETE_H

#include "performance.h" 

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    int age;
    char country[MAX_NAME_LENGTH];
    char preferred_discipline[MAX_NAME_LENGTH]; 
} Athlete;

void add_athlete(Athlete *athletes, int *count, const char *name, const char *surname, int age, const char *country, const char *preferred_discipline); 
void print_athlete(const Athlete *athlete);
void save_athlete_to_file(const Athlete *athlete, const char *filename);
void load_athlete_from_file(Athlete *athletes, int *count, const char *filename);
void create_athlete_file(const Athlete *athlete);
void update_athlete_file(const Athlete *athlete, const Performance *performance);
void search_athlete_by_name(const Athlete *athletes, int athlete_count, const char *name, const char *surname); 
void display_athletes_by_discipline(const Athlete *athletes, int athlete_count, const char *discipline); 

#endif 
