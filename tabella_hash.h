#pragma once
#include "studente.h"
#define TABELLA_HASH_VUOTO "ELEMENTO_VUOTO"

typedef struct _s_nodo_lista_trabocco {
	t_studente dato;
	struct _s_nodo_lista_collisione* successivo;
} _t_nodo_lista_collisione;
typedef _t_nodo_lista_collisione* _t_lista_trabocco;

typedef struct {
	_t_lista_trabocco* tabella;
	int dimensione;			// numero di elementi presenti
} t_tabella_hash_trabocco;

typedef struct {
	t_studente* tabella;	// allocare dinamicamente il vettore
	int dimensione;			// numero di elementi presenti
}t_tabella_hash;

typedef char tabella_hash_chiave[STUDENTE_LUNGHEZZA_CODICE];

void tabella_hash_inizializza(t_tabella_hash* pt_tabella, int dimensione);
int tabella_hash_aggiungi(t_tabella_hash* pt_tabella, t_studente elemento);
void tabella_hash_rimuovi(t_tabella_hash* pt_tabella, tabella_hash_chiave chiave);
t_studente* tabella_hash_trova(t_tabella_hash tabella, tabella_hash_chiave chiave);

// Funzione che dato un valore della chiave mi restituisce un indice (valore interoo) compreso
// fra 0 e la dimensione della tabella hash

int _tabella_hash_funzione(t_tabella_hash tabella, tabella_hash_chiave chiave);
int tabella_hash_elemento_vuoto(const t_studente* pt_studente);

int _tabella_hash_ispezione(t_tabella_hash tabella, int indice_iniziale);