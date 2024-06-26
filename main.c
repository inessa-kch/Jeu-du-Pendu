#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "jeu.h"
#define S_MAX 50




int main(){
    srand(time(NULL));
    char* str4=(char*)malloc(S_MAX*sizeof(char));
    FILE* f=fopen("ods5.txt","r");

    int nbmots=0;
    if(f!=NULL){
        while(fscanf(f,"%s",str4)==1){
            nbmots++;
        }
        fclose(f);
    }
    

    PileMots* pm=initPileMots(nbmots);
    FILE* fi=fopen("ods5.txt","r");


    if(fi!=NULL){
        while(fscanf(f,"%s",str4)==1){
            pushMots(pm,str4);
        }
        fclose(fi);
    }
    //printPileMots(pm);

    printf("\t\t\t\tJEU DU PENDU\n\n\n");
    char* rand=MotsRand(pm);
    //printf("%s\n",rand);
    char* emot=motsATrouver(rand);
    TrouverMots(rand,emot);

    return 0;

}

