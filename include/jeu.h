
#ifndef JEU_H
#define JEU_H



typedef struct {
    int dim;        // Nombre maximum d'elements dans la pile
    int n;          // Nombre d'elements dans la pile
    char** mots;      // Les elements
} PileMots;


PileMots* initPileMots(int dim);
void freePileMots(PileMots *pm);
void pushMots(PileMots *pm, char* e);
char* popMots(PileMots *pm);
void printPileMots(PileMots *pm);
char* MotsRand(PileMots* pm);
char* motsATrouver(char* mot);
int ExisteC(char* mot,char c);
void penduAscii(int nbessaies);
int TrouverMots(char* mot,char* motmasque);
int countmot(PileMots* pm);


#endif