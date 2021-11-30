#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "studente.h"
#include "tabella_hash.h"

void apri_file(t_tabella_hash* pt, FILE* fp) {
	t_studente studente;
	if ((fp == NULL) || pt->dimensione == 0)
		return;
	while (studente_leggi(&studente, fp) != NULL) {
		if (tabella_hash_aggiungi(pt, studente) == -1) {
			printf("Tabella piena, alcuni record non saranno caricati\n");
			break;
		}
	}
}
int main(void) {
	tabella_hash_chiave chiave;
	t_tabella_hash dizionario;
	t_studente studente;
	t_studente* pt_studente = NULL;
	int k;
	int scelta;
	FILE* fp;
	char buffer[128];
	do {
		printf("1. inserisci studente\n");
		printf("2. apri file\n");
		printf("3, stampa il contenuto\n");
		printf("4. Inizializza tabella\n");
		printf("5. Cerca\n");
		printf("6. rimuovi \n");
		scanf("%d", &scelta);
		switch (scelta) {
		case 0:
			printf("chiusura programma ...");
			break;
		case 2: // carica da file
			printf("Inserisci il nome del file: ");
			scanf("%s", buffer);
			if ((fp = fopen(buffer, "r")) == NULL) {
				printf("Impossibile aprire %s\n", buffer);
				break;
			}
			apri_file(&dizionario, fp);
			fclose(fp);
			break;
		case 3:
			// esercizio da fare come attivita'
			break;
		case 4: // inizializzazione della tabelle
			printf("Inserisci le dimensioni della tabella: ");
			scanf("%d", &dizionario.dimensione);
			tabella_hash_inizializza(&dizionario, dizionario.dimensione);
			break;
		case 5:

			printf("Inserisci la chiave di ricerca: ");
			scanf("%s", buffer);
			pt_studente = tabella_hash_trova(dizionario, buffer);
			if (pt_studente != NULL)
				studente_scrivi(pt_studente, stdout);
			else
				printf("elemento non trovato\n");
			break;
		case 6:
			// esercizio da fare come attivita'
			break;
		}
	} while (scelta != 0);
}