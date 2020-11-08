#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int b_valide;
	int b_acces;
	int b_modif;
	int dernier_acces;
}page;

/*affiche les acces et le nombre de case en paramèter*/
void affiche(int* acces, int nb_case);

/*affiche le bit de validite de l'acces[i] de chaque page en paramètre*/
void afficher_bit_valide(page* pages, int* acces, int nb_case);

/*retourne 1 si acces[i] est vide sinon 0*/
int est_pleine(int* acces, int nb_case);

/*retourne 1 si l'élement elem appartient à acces[i]*/
int appartient(int* acces, int elem, int nb_case);

void enfiler(int* acces, int elem, int nb_case);

/*retourne l'acces utilisé le moins récemment*/
int utiliser_longtemps(page *pages, int* acces, int nb_acces);

/*supprime l'élément elem de acces[i]*/
void supprimer(int* acces, int elem, int nb_case);

/*FIFO*/
void fifo(FILE* f, page* page, int* acces, int nb_page, int nb_case, int debug);

/*NRU*/
void nru(FILE* f, page* pages, int* acces, int nb_page, int nb_case, int debug);

/*LRU*/
void lru(FILE* f, page* pages, int* acces, int nb_page, int nb_case, int debug);

/*HORLOGE*/
void principe_horloge(page* pages, int* acces, int nb_case);
void horloge(FILE* f, page* pages, int* acces, int nb_page, int nb_case,int debug);

/*OPTIMAL
void optimal(FILE* f, page* page, int* acces, int nb_page, int nb_case, int debug);
*/