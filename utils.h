#ifndef UTILS_H
#define UTILS_H

#define MAX_DATE_LENGTH 20
#include "performance.h"
// Fonction pour comparer deux dates au format "YYYY-MM-DD"
// Retourne 0 si les dates sont égales, un nombre négatif si date1 < date2, un nombre positif sinon
int compare_dates(const char *date1, const char *date2);

// Fonction pour trier les performances par date
void sort_performances_by_date(Performance *performances, int count);

#endif // UTILS_H

