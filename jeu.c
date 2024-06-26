#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "jeu.h"



PileMots* initPileMots(int dim){
    PileMots* pile=malloc(sizeof(PileMots));
    pile->dim=dim;
    pile->n=0;
    pile->mots=(char**)malloc(sizeof(char*)*dim);
    return pile;
}

void freePileMots(PileMots *pm) {
    int i;
    for(i=0;i<pm->n;i++){
        free(pm->mots[i]);
    }
    free(pm->mots);
    pm->mots=NULL;
    pm->n=0;
    pm->dim=0;
}



void pushMots(PileMots *pm, char* e) {
     if(pm->n < pm->dim) {
        pm->mots[pm->n] = strdup(e);
        pm->n++;        
    } else
        fprintf(stderr, "Erreur: pile pleine!\n");
}



char* popMots(PileMots *pm) { 
    char* e=NULL;  
    if(pm->n > 0) {
        e =strdup(pm->mots[pm->n-1]);    
        pm->n--;               
    } else{
        fprintf(stderr, "Erreur: pile vide!\n");}
    return e;
}


void printPileMots(PileMots *pm) {
    printf("Pile de %d mots (max = %d)\n", pm->n, pm->dim);
    int i;
    for(i = 0; i < pm->n; i++)
        printf("%s\n", pm->mots[i]); 
}



char* MotsRand(PileMots* pm){
    int r = rand() % (pm->n);
    char* mot=pm->mots[r];
    int i=0;
    for(i=0;i<pm->n;i++){
        if(strcmp(pm->mots[i], pm->mots[r])) break;
    }
    for(int j=i;j<pm->n-1;j++){
        pm->mots[j] = pm->mots[j+1];
    }
    popMots(pm);
    return mot;
}



char* motsATrouver(char* mot){
    int s=strlen(mot);
    char* emot=(char*)malloc(sizeof(char)*s);
    for(int i=0;i<s;i++){
        emot[i]='*';
    }
    return emot;
}

int ExisteC(char* mot,char c){
    for (int i=0;i<(int)strlen(mot);i++){
        if (mot[i]==c){
            return 1;
        }
    }
    return 0;
}



int TrouverMots(char* mot,char* motmasque){
    char lettre;
    int nbessaies=7;
    printf("Mot à trouver : %s\n",motmasque);
    printf("Il vous rest %d coups.\n",nbessaies);
    printf("\n\nVotre lettre : ");
    do{

        
        scanf("%c",&lettre);
        while(getchar()!='\n');
        
        if (ExisteC(mot,tolower(lettre))==0){
            nbessaies--;
            printf("\n\n\nNon, cette lettre n'est pas dans le mot :(\n");
            printf("Mot à trouver: %s\n", motmasque);
            printf("Il vous reste %d coups.\n",nbessaies);

            if(nbessaies== 0){
                printf("\n\n\nLe mot était : %s\n",mot);
                printf("Vous n'avez plus de coups, vous êtes mort X_X\n\n\n");
                return 0;
            }
            else{
                printf("\n\nVotre lettre : ");
            }
        }
        else{
            for (int i=0; i<(int)strlen(mot);i++){
                if (lettre==mot[i]){
                    motmasque[i]=mot[i];
                }
            }
            printf("\n\n\nMot a trouver: %s\n", motmasque);
            printf("Il vous reste %d coups.\n",nbessaies);
            if (strcmp(motmasque,mot)!=0){
                printf("\n\nVotre lettre : ");
            }
        }
    }while(strcmp(motmasque,mot)!=0);
    printf("\n\n\nBravo!! Vous avez trouver le mot secret, c'était bien %s !\n\n\n", mot);
    return 0;
}


int countmot(PileMots* pm){
    int res=0;
    for (int i=0;i<pm->n;i++){
        if(pm->mots[i]) res++;
    }
    return res;
}