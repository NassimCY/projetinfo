
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "<structures.h>"

#define MAX_NAME_LENGTH 50
#define MAX_EVENT_LENGTH 50
#define MAX_FILENAME_LENGTH 200
typedef struct {
    
    int disipline;//la discpline 100m,400m ..
     char date[20]; //date de la course
    int IdRun; //si on fait cette discipline dans la meme date
   
	float time; // le temps en seconde de la course
	
} Performance;
typedef struct {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    int age;
    char country[MAX_NAME_LENGTH];
    int preferd_discipline;
    
	int rank_100m;
	int rank_400m;
	int rank_5000m;
	int rank_Marathon;
	int rank_relais;
    float avrtime_100m;
    float avrtime_400m;
    float avrtime_5000m;
    float avrtime_Marathon;
    float avrtime_relais;
 Performance *performances;
    int numPerformances;
} Athlete;



typedef struct {
    Athlete* athletes;
    int numAthletes;
} AthleteDatabase;

const char* performanceTypes[5] = {"100m", "400m", "5000m", "marathon", "relais"};
const char* directoryAthlete="C:/Temp/athlete";

// teste
// permet de generer une performace, avec une discipline au hasard
Performance generateRandomPerformance(int j) {
    Performance newperformance ;

     newperformance.disipline=rand() % 5;
    newperformance.IdRun=j;
    sprintf(newperformance.date, "2022-10-15");  // Date aléatoire
    newperformance.time = (float)(rand() % 20 + 10);  // Temps aléatoire entre 10 et 30 secondes

    return newperformance;
}
// teste
// Générer un athlète avec des données aléatoires
// en lui associant 10 performances
Athlete generateRandomAthlete(const char* name, const char* surname) {
    Athlete athlete ;
    strcpy(athlete.name, name);
    strcpy(athlete.surname, surname);
    athlete.age = rand() % 10 + 20;  // Âge aléatoire entre 20 et 30 ans
    strcpy(athlete.country, "Country"); // Pays aléatoire
    athlete.preferd_discipline=rand() % 5;
    

    // Générer des performances aléatoires pour chaque athlète
    int numPerformances = 10;  // Nombre aléatoire de performances entre 1 et 5
    athlete.numPerformances = numPerformances;
    athlete.performances = (Performance*)malloc(numPerformances * sizeof(Performance));

    for (int j = 0; j < 10; j++) {
        athlete.performances[j] = generateRandomPerformance(j);
    }

    return athlete;
}
// teste
// Fonction pour sauvegarder les performances d'un athlète dans un fichier dans le repertoire directoryathlete et le fichier aura le nom de l athlete
void savePerformances(const Athlete athlete) {
    char filename[MAX_FILENAME_LENGTH];
    
    snprintf(filename, sizeof(filename), "%s/%s.txt", directoryAthlete,athlete.surname);
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        //int i=0;
       for (int i = 0; i < athlete.numPerformances; i++) {
          fprintf(file, "%d;%d;%s;%.2f\n", athlete.performances[i].IdRun, athlete.performances[i].disipline, 
                    athlete.performances[i].date, athlete.performances[i].time);
                    //fprintf(file,"ccccc");
        }
        fclose(file);
    } else {
        // Gérer l'échec d'ouverture du fichier
    }
}
// teste
// Fonction pour sauvegarder la liste des athlètes dans un fichier athlete_list.txt dans le repertoire directoryAthlete, et provoquer la sauveagrde des parformance de chaque athlete
void saveAthleteList(const AthleteDatabase* db) {
    char filename[MAX_FILENAME_LENGTH];
    snprintf(filename, sizeof(filename), "%s/athlete_list.txt", directoryAthlete);
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        for (int i = 0; i < db->numAthletes; i++) {
            fprintf(file, "%s;%s;%d;%s;%d\n", db->athletes[i].name, db->athletes[i].surname, 
                    db->athletes[i].age, db->athletes[i].country, db->athletes[i].preferd_discipline);
                     savePerformances(db->athletes[i]);
        }
        fclose(file);
       
    } else {
        // Gérer l'échec d'ouverture du fichier
    }
}
// non teste
// calcul des moyenne des teams par discipline pour chaque athlete
void calcAvrGlobal(const AthleteDatabase* db) {
 
  
    
        for (int i = 0; i < db->numAthletes; i++) {
           db->athletes[i].rank_100m=0;
           db->athletes[i].rank_400m=0;
           db->athletes[i].rank_5000m=0;
           db->athletes[i].rank_Marathon=0;
           db->athletes[i].rank_relais=0;
           db->athletes[i].avrtime_100m=0;
           db->athletes[i].avrtime_400m=0;
           db->athletes[i].avrtime_5000m=0;
           db->athletes[i].avrtime_Marathon=0;
           db->athletes[i].avrtime_relais=0;
             float avrtime_100m=0;
    float avrtime_400m=0;
    float avrtime_5000m=0;
    float avrtime_Marathon=0;
    float avrtime_relais=0;
    int nbtime_100m=0;
    int nbtime_400m=0;
    int nbtime_5000m=0;
    int nbtime_Marathon=0;
    int nbtime_relais=0;
        for (int j = 0; j < db->athletes[i].numPerformances; j++) {
           //db->athletes[i].performances[j].IdRun, 
           if (db->athletes[i].performances[j].disipline==0){
                    //db->athletes[i].performances[j].date, 
                    avrtime_100m=avrtime_100m+db->athletes[i].performances[j].time;
                    nbtime_100m=nbtime_100m+1;
           }
             if (db->athletes[i].performances[j].disipline==1){
                    //db->athletes[i].performances[j].date, 
                    avrtime_400m=avrtime_400m+db->athletes[i].performances[j].time;
                    nbtime_400m=nbtime_400m+1;
           }
             if (db->athletes[i].performances[j].disipline==2){
                    //db->athletes[i].performances[j].date, 
                    avrtime_5000m=avrtime_5000m+db->athletes[i].performances[j].time;
                    nbtime_5000m=nbtime_5000m+1;
           }
             if (db->athletes[i].performances[j].disipline==3){
                    //db->athletes[i].performances[j].date, 
                    avrtime_Marathon=avrtime_Marathon+db->athletes[i].performances[j].time;
                    nbtime_Marathon=nbtime_Marathon+1;
           }
             if (db->athletes[i].performances[j].disipline==4){
                    //db->athletes[i].performances[j].date, 
                    avrtime_relais=avrtime_relais+db->athletes[i].performances[j].time;
                    nbtime_relais=nbtime_relais+1;
           }
        }
        if (nbtime_100m>0){
            db->athletes[i].avrtime_100m = avrtime_100m/nbtime_100m;
        }
        if (nbtime_400m>0){
            db->athletes[i].avrtime_400m = avrtime_400m/nbtime_400m;
        }
             if (nbtime_5000m>0){
            db->athletes[i].avrtime_5000m = avrtime_5000m/nbtime_5000m;
        }
             if (nbtime_Marathon>0){
            db->athletes[i].avrtime_Marathon = avrtime_Marathon/nbtime_Marathon;
        }
             if (nbtime_relais>0){
            db->athletes[i].avrtime_relais = avrtime_relais/nbtime_relais;
        }
             
   
}
}
// non teste
// calcule le clasement de chaque athlete par rapport au discipline ou il a participe, sinon son rank est 0
void calcRankGlobal(const AthleteDatabase* db) {
 
  
    
        for (int i = 0; i < db->numAthletes; i++) {
           db->athletes[i].rank_100m=0;
           db->athletes[i].rank_400m=0;
           db->athletes[i].rank_5000m=0;
           db->athletes[i].rank_Marathon=0;
           db->athletes[i].rank_relais=0;
           
           db->athletes[i].avrtime_100m=0;
           db->athletes[i].avrtime_400m=0;
           db->athletes[i].avrtime_5000m=0;
           db->athletes[i].avrtime_Marathon=0;
           db->athletes[i].avrtime_relais=0;
            
     
        int nbtime_100m=0;
        int nbtime_400m=0;
        int nbtime_5000m=0;
        int nbtime_Marathon=0;
        int nbtime_relais=0;
        if (db->athletes[i].avrtime_100m!=0)
           db->athletes[i].rank_100m=1;
        if (db->athletes[i].avrtime_400m!=0)
            db->athletes[i].rank_400m=1;
        if (db->athletes[i].avrtime_5000m!=0)
            db->athletes[i].rank_5000m=1;  
        if (db->athletes[i].avrtime_Marathon!=0)
            db->athletes[i].rank_Marathon=1;  
             if (db->athletes[i].avrtime_relais!=0)
            db->athletes[i].rank_relais=1;         
        for (int j = 0; j < db->numAthletes; j++) {
           //db->athletes[i].performances[j].IdRun, 
           if (i!=j) // pas le meme athlete
           {   if (db->athletes[i].avrtime_100m!=0)
          
                if ( db->athletes[j].avrtime_100m< db->athletes[i].avrtime_100m){
                    db->athletes[i].rank_100m=db->athletes[i].rank_100m+1;
                }
                 if (db->athletes[i].avrtime_400m!=0)
          
                if ( db->athletes[j].avrtime_400m< db->athletes[i].avrtime_400m){
                    db->athletes[i].rank_400m=db->athletes[i].rank_400m+1;
                }
                 if (db->athletes[i].avrtime_5000m!=0)
          
                if ( db->athletes[j].avrtime_5000m< db->athletes[i].avrtime_5000m){
                    db->athletes[i].rank_5000m=db->athletes[i].rank_5000m+1;
                }
                 if (db->athletes[i].avrtime_Marathon!=0)
          
                if ( db->athletes[j].avrtime_Marathon< db->athletes[i].avrtime_Marathon){
                    db->athletes[i].rank_Marathon=db->athletes[i].rank_Marathon+1;
                }
                 if (db->athletes[i].avrtime_relais!=0)
          
                if ( db->athletes[j].avrtime_relais< db->athletes[i].avrtime_relais){
                    db->athletes[i].rank_relais=db->athletes[i].rank_relais+1;
                }
            }
        }
        }
             
   
}
//teste
// ajouter un athlete dans la base, cette athlete doit etre cree avant
void addAthlete(AthleteDatabase* db, const Athlete* newAthlete) {
    db->numAthletes++;
    db->athletes = (Athlete*)realloc(db->athletes, db->numAthletes * sizeof(Athlete));
    if (db->athletes == NULL) {
        // Gérer l'échec de l'allocation de mémoire
    }
    db->athletes[db->numAthletes - 1] = *newAthlete;
}
//teste
// Fonction pour ajouter une performance à un athlète, la performance doit etre lue du fichier ou saisie 
void addPerformanceToAthlete(Athlete* athlete, const Performance* newPerformance) {
    athlete->numPerformances++;
    athlete->performances = (Performance*)realloc(athlete->performances, athlete->numPerformances * sizeof(Performance));
    if (athlete->performances == NULL) {
        // Gérer l'échec de l'allocation de mémoire
    }
    athlete->performances[athlete->numPerformances - 1] = *newPerformance;
}

//teste
// Fonction pour charger les performances d'un athlète à partir de son fichier dédié, le fichier est le nom du repertoire directoryathlete et le nom du fichier est le surnom de l'athlete
void loadPerformancesFromFile(Athlete* athlete) {
    char filename[MAX_FILENAME_LENGTH];
    
    snprintf(filename, sizeof(filename), "%s/%s.txt", directoryAthlete,athlete->surname);
    athlete->numPerformances=0;
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        char line[200];
        while (fgets(line, sizeof(line), file)) {
            Performance newPerformance;
            sscanf(line, "%d;%d;%[^;];%f\n",&newPerformance.IdRun, &newPerformance.disipline, 
                    newPerformance.date, &newPerformance.time );

                  
            addPerformanceToAthlete(athlete, &newPerformance);
        }
        fclose(file);
    } else {
        // Gérer l'échec d'ouverture du fichier
    }
}

//teste
// Fonction pour charger les données des athlètes à partir du fichier principal se trouvant dans directoryAthlete ayant comme nom athlete_list.txt,
// cette fonction va appeler le chargement des performace de l athlete
void loadAthletesFromFile(AthleteDatabase* db) {
    char filename[MAX_FILENAME_LENGTH];
    snprintf(filename, sizeof(filename), "%s/athlete_list.txt", directoryAthlete);
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        char line[2000];
        while (fgets(line, sizeof(line), file)) {
            Athlete newAthlete;
             newAthlete.numPerformances=0;
             newAthlete.performances=NULL;

            sscanf(line, "%[^;];%[^;];%d;%[^;];%d\n", newAthlete.name, newAthlete.surname, 
                   &newAthlete.age, newAthlete.country, &newAthlete.preferd_discipline);

                  
            addAthlete(db, &newAthlete);
            loadPerformancesFromFile(&db->athletes[db->numAthletes-1]);
        }
        fclose(file);
    } else {
        // Gérer l'échec d'ouverture du fichier
    }
}

//non teste
// Fonction pour rechercher un athlète dans la base de données
Athlete* findAthlete(const AthleteDatabase* db, const char* name) {
    for (int i = 0; i < db->numAthletes; i++) {
        if (strcasecmp(db->athletes[i].name, name) == 0 )
            {
            return &db->athletes[i];
        }
    }
    return NULL;  // Aucun athlète correspondant trouvé
}



//non teste
// Fonction pour saisir les informations d'un athlète
Athlete* addNewAthlete(AthleteDatabase* db) {
                 char name[MAX_NAME_LENGTH];
                 Athlete athlete;
                printf("Nom de l'athlète : ");
                scanf("%s", athlete.name);
				
				Athlete* athleteEx = findAthlete(db, athlete.name);
				if (athleteEx == NULL) {
					
                printf("Prénom de l'athlète : ");
                scanf("%s", athlete.surname);
                printf("Âge de l'athlète : ");
                scanf("%d", &athlete.age);
                printf("Pays de l'athlète : ");
                scanf("%s", athlete.country);
                athlete.numPerformances=0;
				athlete.performances=NULL;
				addAthlete(db, &athlete);
				return &db->athletes[db->numAthletes - 1] ;
                } 
                else {
                    printf("L'athlète exist dans la base de données.\n");
					return NULL;
                }
				
}

//non teste
// Fonction pour ajouter une épreuve et une performance à un athlète
void addNewPerformanceToAthlete(Athlete* athlete) {
    Performance newPerformance;
    do {
	printf("Discipline : 100m:0, 400m:1, 5000m:2, marathon:3, relais:4 ");
    scanf("%d", newPerformance.disipline);
	if (newPerformance.disipline<0 || newPerformance.disipline>4) {printf("erreur de saisie, resaisissez");}
	} 
    
    while (newPerformance.disipline<0 || newPerformance.disipline>4);
do {	
	printf("idDiscipline entre 1 et 5: ");
    scanf("%d", newPerformance.IdRun);
 	if (newPerformance.IdRun<0 || newPerformance.IdRun>4) {printf("erreur de saisie, resaisissez");}
	} while (newPerformance.IdRun<1 || newPerformance.IdRun>5);   
	printf("Date de la performance : ");
    scanf("%s", newPerformance.date);
    printf("Temps de la performance : ");
    scanf("%f", &newPerformance.time);
    addPerformanceToAthlete(athlete, &newPerformance);
}
//non teste
// Fonction pour afficher les performances d'un athlète
void displayAthletePerformances(const Athlete* athlete) {
    printf("Performances de l'athlète %s %s :\n", athlete->name, athlete->surname);
    for (int i = 0; i < athlete->numPerformances; i++) {
     
			    printf("Performance %d - id discipline pour cette date  %d - dicipline: %s, Date: %s, Time: %.2f\n",
                   i+1,  athlete->performances[i].IdRun, athlete->performances[i].disipline,
                    athlete->performances[i].date,  athlete->performances[i].time);
    }
}


int main() {
  srand(time(0));  // Initialiser le générateur de nombres aléatoires

    AthleteDatabase database;
    system("cls");
    database.numAthletes=0;
    database.athletes = (Athlete*)malloc(1 * sizeof(Athlete));


 int choice;
    do {
        printf("\nMenu:\n");
        printf("1. cree un jeux de donnee de base\n");
        printf("2. charger depuis la base\n");
     
        printf("10. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                database.numAthletes = 10;
    database.athletes = (Athlete*)malloc(database.numAthletes * sizeof(Athlete));

    const char* names[] = {"John", "Emma", "Michael", "Sophia", "William", "Olivia", "James", "Ava", "Alexander", "Isabella"};
    const char* surnames[] = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};

    for (int i = 0; i < database.numAthletes; i++) {
        database.athletes[i] = generateRandomAthlete(names[i], surnames[i]);
    }
      break;
            }
              case 2: {
                 printf("load from data base ....");

    // Charger les données des athlètes à partir du fichier principal
    loadAthletesFromFile(&database);
                break;
            }

            case 10:
                // Quitter
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choice != 10 && choice !=2 && choice !=1);

   /* */

    if (choice ==2  || choice ==1)
    {
// ecrireici un menu pour ajouter un athlete/performance
// pour une date donnee si trouve afficher le classement
 Athlete* athleteC=NULL;
   
    do {
        if (athleteC!=NULL)
		{ printf("Nom de l'athlète courant %s\n : ",athleteC->name);
               
		}
		printf("\nMenu:\n");
        printf("1. Rechercher un athlete et afficher les performances\n");
        printf("2. Ajouter un athlete\n");
        printf("3. afficher les performances de l'athlete courant\n");
        printf("4. Ajouter une performance a l'athlete courant\n");
        printf("10. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        choice=10;// forcer a 10 pour ne pas execter les parties du code non encore testees

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
  
                
                printf("Nom de l'athlète : ");
                scanf("%s", name);              
                Athlete* athlete = findAthlete(&database, name);
                if (athlete != NULL) {
                    printf("L'athlète a été trouvé avec succes.\n");
					athleteC=athlete;
                } else {
                    printf("Opération annulée.\n");
                }
                break;
            }
            case 2: {
                
				athleteC=addNewAthlete(&database);
                break;
            }
            case 3: {
                
                if (athleteC != NULL) {
                    displayAthletePerformances(athleteC);
                } else {
                    printf("L'athlète n'existe pas dans la base de données.\n");
                }
                break;
            }
			     case 4: {
                
                if (athleteC != NULL) {
                    addNewPerformanceToAthlete(athleteC);
                } else {
                    printf("L'athlète n'existe pas dans la base de données.\n");
                }
                break;
            }
            case 10:
                // Quitter
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choice != 10);

    }


   


    // Afficher les  données chargees
    for (int i = 0; i < database.numAthletes; i++) {
        printf("Athlete %d - Name: %s %s, Age: %d, Country: %s, Discipline: %s\n",
               i+1, database.athletes[i].name, database.athletes[i].surname,
               database.athletes[i].age, database.athletes[i].country,performanceTypes[database.athletes[i].preferd_discipline]);
        for (int j = 0; j < database.athletes[i].numPerformances; j++) {
            printf("Performance %d - id discipline pour cette date  %d - dicipline: %s, Date: %s, Time: %.2f\n",
                   j+1, database.athletes[i].performances[j].IdRun,performanceTypes[database.athletes[i].performances[j].disipline],
                   database.athletes[i].performances[j].date,
                   database.athletes[i].performances[j].time);
        }
        printf("\n");
    }

    saveAthleteList(&database);
    // Libérer la mémoire allouée
    for (int i = 0; i < database.numAthletes; i++) {
        free(database.athletes[i].performances);
    }
    free(database.athletes);
     printf("tapper un char pour sortire : ");
        scanf("%d", &choice);

    return 0;

    

}
