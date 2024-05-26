#include "utils.h"
#include "performance.h"
#include <stdio.h>
#include <string.h>

// Fonction pour comparer deux dates au format "YYYY-MM-DD"
int compare_dates(const char *date1, const char *date2) {
    return strcmp(date1, date2);
}

// Fonction pour trier les performances par date
void sort_performances_by_date(Performance *performances, int count) {
    Performance temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compare_dates(performances[j].date, performances[j + 1].date) > 0) {
                temp = performances[j];
                performances[j] = performances[j + 1];
                performances[j + 1] = temp;
            }
        }
    }
}

