#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "jeu.h"
#define S_MAX 50




int main(){
    int nbVictoires=0;
    int nbDefaites=0;
    char choix;
    srand(time(NULL));
    char* str4=(char*)malloc(S_MAX*sizeof(char));
    FILE* f=fopen("mots.txt","r");

    int nbmots=0;
    if(f!=NULL){
        while(fscanf(f,"%s",str4)==1){
            nbmots++;
        }
        fclose(f);
    }
    

    PileMots* pm=initPileMots(nbmots);
    FILE* fi=fopen("mots.txt","r");


    if(fi!=NULL){
        while(fscanf(f,"%s",str4)==1){
            pushMots(pm,str4);
        }
        fclose(fi);
    }
    //printPileMots(pm);

    printf("\t\t\t\tJEU DU PENDU\n\n\n");

    do{
        char* rand=MotsRand(pm);
        //printf("%s\n",rand);
        char* emot=motsATrouver(rand);
        int res=TrouverMots(rand,emot);
        if(res==1){
            nbVictoires++;
        }else{
            nbDefaites++;
        }
        printf("Voulez-vous continuer? (o/n)\n");
        scanf(" %c",&choix);
    }while(choix=='o');

    printf("Score final : %d victoires, %d défaites.\n", nbVictoires, nbDefaites);

    return 0;

}

