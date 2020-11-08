#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algo.h"

void usage(char* s) {
	printf("Usage : %s <algo> <nb page> <mode d'affichage> <fichier>\n\n",s);
	printf("Algo :\n");
	printf("	1 - FIFO; 2 - NRU; 3 - LRU; 4 - HORLOGE; 5 - OPTIMAL\n\n");
	printf("Nb page :\n");
	printf("	le nombre de page en RAM\n\n");
	printf("mode d'affichage :\n");
	printf("	1 - Avec debug; 0 - Sans debug\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
	if (argc<5) {
		usage(argv[0]);
	}

	int i,nb_page,case_max=atoi(argv[2]),page_max,debug=atoi(argv[3]);

	if (strcmp(argv[2],"-h") || strcmp(argv[2],"-help")) {
		usage(argv[0]);
	}

	if(debug) {
		printf("Debug : ON\n");
	}

	FILE* f = fopen(argv[4],"r");

	if (f==NULL) {
		printf("Erreur d'ouverture du fichier\n");
		usage(argv[0]);
	}

	fscanf(f,"%d",&nb_page);
	fscanf(f,"%d",&page_max);
	page* pages;
	int* acces;

	pages=malloc((page_max+1) * sizeof(page));
	printf("%d accès différents\n",nb_page);
	acces=malloc(case_max * sizeof(int));
	printf("%d cases\n",case_max);

	int algo_choisi=atoi(argv[1]);

	for (i=0;i<case_max;i++) {
		acces[i]=0;
	}
	for (i=0;i<page_max;i++) {
		pages[i].b_valide=0;
		pages[i].b_acces=0;
		pages[i].b_modif=0;
		pages[i].dernier_acces=0;
	}

	switch(algo_choisi) {
		case 1:
			printf("FIFO :\n");
			fifo(f,pages,acces,nb_page,case_max,debug);
			break;
		case 2:
			printf("NRU :\n");
			nru(f,pages,acces,nb_page,case_max,debug);
			break;
		case 3:
			printf("LRU :\n");
			lru(f,pages,acces,nb_page,case_max,debug);
			break;
		case 4:
			printf("HORLOGE :\n");
			horloge(f,pages,acces,nb_page,case_max,debug);
			break;
		case 5:
		printf("OPTIMAL :\n");
		/*optimal(f,pages,acces,nb_page,case_max,debug);*/
		printf("Cet algomrithme n'est pas codé\n");
		break;
	default:
	usage(argv[0]);
	printf("Erreur\n");
	}

	free(pages);
	free(acces);
	fclose(f);
	exit(EXIT_SUCCESS);
}