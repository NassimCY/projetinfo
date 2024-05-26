#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#define MAX_NAME_LENGTH 50
#define MAX_EVENT_LENGTH 50

typedef struct {
    char athlete_name[MAX_NAME_LENGTH];
    char athlete_surname[MAX_NAME_LENGTH];
    char event[MAX_EVENT_LENGTH];
    char date[20];
    float time;
} Performance;

void add_performance(Performance *performances, int *count, const char *athlete_name, const char *athlete_surname, const char *event, const char *date, float time);
void print_performance(const Performance *performance);
void generate_filename(const char *athlete_name, const char *athlete_surname, char *filename);
void save_performance(const Performance *performance);
void load_performance(Performance *performances, int *count, const char *filename);
void save_performance_to_file(const Performance *performance);
void load_performances_from_file(Performance *performances, int *count, const char *filename);
void display_performances_by_discipline(const Performance *performances, int performance_count, const char *discipline); // Nouvelle fonction

#endif // PERFORMANCE_H
