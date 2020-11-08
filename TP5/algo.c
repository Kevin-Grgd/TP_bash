#include <stdlib.h>
#include <stdio.h>
#include "algo.h"

void affiche(int* acces, int nb_case) {
	int i;
	printf("{");
	for (i=0;i<nb_case-1;i++) {
		if(acces[i]) {
			printf("%d",acces[i]);
		}
	}

	if(acces[i]){
		printf("%d}\n",acces[i]);
	} else {
		printf("}\n");
	}
}

void afficher_bit_valide(page* pages, int* acces, int nb_case){
	int i;
	printf("{");
	for(i=0;i<nb_case-1;i++) {
		if(acces[i]) {
			printf("%d",pages[acces[i]].b_valide);
		}
	}

	if(acces[i]) {
		printf("%d}\n",pages[acces[i]].b_valide);
	} else {
		printf("}\n");
	}
}

int est_pleine(int* acces, int nb_case) {
	int i;
	for (i=0;i<nb_case;i++) {
		if(!acces[i]) {
			return 0;
		}
	}
	return 1;
}


int appartient(int* acces, int elem, int nb_case) {
	int i=0;
	for(i=0;i<nb_case;i++) {
		if(acces[i] == elem) {
			return 1;
		}
	}
	return 0;
}

void enfiler(int* acces, int elem, int nb_case) {
	int i=0;
	while(acces[i] != 0) {
		i++;
	}
	acces[i] = elem;
}

int utiliser_longtemps(page *pages, int* acces, int nb_acces) {
	int i,tmp,min=acces[0];

	for(i=1;i<nb_acces;i++) {
		tmp=acces[i];
		if(pages[tmp].dernier_acces < pages[min].dernier_acces) {
			min = tmp;
		}
	}
	return min;
}

void supprimer(int* acces, int elem, int nb_case) {
	int i;
	for(i=0;i<nb_case;i++) {
		if(acces[i] == elem) {
			acces[i]=0;
		}
	}
}

void fifo(FILE* f, page* page, int* acces, int nb_page, int nb_case, int debug) {
	int tmp,i,defaut=0;

	while(fscanf(f,"%d",&tmp) == 1) {
		if(debug) {
			printf("Enfiler %d:\n", tmp);
		}

		if(!appartient(acces,tmp,nb_case)) {
			if (!est_pleine(acces,nb_case)) {
				enfiler(acces,tmp,nb_case);
			} else {
				defaut++;
				for(i=0;i<nb_case-1;i++) {
					acces[i] = acces[i+1];
				}
				acces[i]=tmp;
				if(debug) {
					printf("Defaut de page : %d remplace %d\n",tmp,i);
				}
			}
		}
		if(debug) {
			affiche(acces,nb_case);
		}
	}
	printf("%d defauts de pages\n",defaut);
}


void nru(FILE* f, page* pages, int* acces, int nb_page, int nb_case, int debug) {
	int i,tmp,temps=0,min,defaut=0;

	while(fscanf(f,"%d",&tmp) == 1) {
		if(debug) {
			printf("Enfiler : %d",tmp);
		}

		if(!appartient(acces,tmp,nb_case)) {
			if(!est_pleine(acces,nb_case)) {
				enfiler(acces,tmp,nb_case);
			} else {
				defaut++;
				min = utiliser_longtemps(pages,acces,nb_case);
				if(debug) {
					printf("Defaut de page : %d poids = %d remplace %d poids = %d\n",tmp,pages[tmp].dernier_acces,min,pages[min].dernier_acces);
				}
				i=0;
				while(acces[i]!=min) {
					i++;
				}
				acces[i]=tmp;
			}
		}
		temps++;
		pages[tmp].dernier_acces=temps;
		if(debug){
			printf("RAM :");
			affiche(acces,nb_case);
		}
	}
	printf("%d défaut(s) de pages\n",defaut);
}


void lru(FILE* f, page* pages, int* acces, int nb_page, int nb_case, int debug) {
	int i=0,tmp,min,defaut=0;

	while(fscanf(f,"%d",&tmp)==1) {
		if(debug) {
			printf("Traiter %d :\n",tmp);
		}
		if(!appartient(acces,tmp,nb_case)) {
			if(!est_pleine(acces,nb_case)) {
				enfiler(acces,tmp,nb_case);
			} else {
				defaut++;
				min = utiliser_longtemps(pages,acces,nb_case);
				if(debug) {
					printf("Defaut de page : %d poids = %d remplace %d poids = %d\n",tmp,pages[tmp].dernier_acces,min,pages[min].dernier_acces);
				}
				i=0;
				while(acces[i] != min) {
					i++;
				}
				acces[i]=tmp;
			}
		}
		acces[i] = tmp;
		if(debug) {
			printf("RAM :");
			affiche(acces,nb_case);
		}
	}
	printf("%d defauts de pages\n",defaut);
}

void principe_horloge(page* pages, int* acces, int nb_case) {
	int tmp=acces[0],i;
	for(i=0;i<nb_case-1;i++) {
		acces[i]=acces[i+1];
	}
	acces[i]=tmp;
}

void horloge(FILE* f, page* pages, int* acces, int nb_page, int nb_case,int debug) {
	int tmp,remplace,defaut=0;

	while(fscanf(f,"%d",&tmp)==1) {
		if(debug) {
			printf("Traiter %d :\n",tmp);
		}

		if(!appartient(acces,tmp,nb_case)) {
			if(!est_pleine(acces,nb_case)) {
				enfiler(acces,tmp,nb_case);
				pages[tmp].b_valide=1;
			} else {
				defaut++;
				remplace = acces[0];
				while(pages[remplace].b_valide) {
					pages[remplace].b_valide = 0;
					principe_horloge(pages,acces,nb_case);
					remplace = acces[0];
				}
				if(debug) {
					printf("Defaut de page : %d remplace %d\n",tmp,remplace);
				}
				acces[0]=tmp;
				pages[tmp].b_valide=1;
				pages[remplace].b_valide=0;
				principe_horloge(pages,acces,nb_case);
			}
		} else {
			pages[tmp].b_valide=1;
		}
		if(debug) {
			printf("RAM :");
			affiche(acces,nb_case);
			printf("Bit :");
			afficher_bit_valide(pages,acces,nb_case);
		}
	}
	printf("%d defauts de page\n",defaut);
}

/*
void optimal(FILE* f, page* page, int* acces, int nb_page, int nb_case, int debug) {
}
*/