#include "tabella_hash.h"

int _inserimento_lista_trabocco(_t_lista_trabocco* pt_lista, t_studente studente) {
	_t_nodo_lista_collisione* pt_aux;
	pt_aux = (_t_nodo_lista_collisione*)malloc(sizeof(_t_nodo_lista_collisione));
	if (pt_aux == 0)
		return -1;
	pt_aux->dato = studente;
	pt_aux->successivo = *pt_lista;
	*pt_lista = pt_aux;
	return 1;
}
t_studente* _ricerca_lista_trabocco(_t_lista_trabocco lista, tabella_hash_chiave chiave) {
	// classica ricerca sequenziale in una lista
	while (lista != NULL) {
		if (strcmp(chiave, lista->dato.matricola) == 0)
			return &(lista->dato); // ATTENZIONE alla &, chiedetevi perchè!!!!!
	}
	return NULL; // Non ho trovato niente!
}
void tabella_hash_inizializza(t_tabella_hash* pt_tabella, int dimensione) {
	pt_tabella->tabella = (_t_lista_trabocco *)malloc(sizeof(_t_lista_trabocco) * dimensione);
	if (pt_tabella->tabella == 0) {
		pt_tabella->dimensione;
		return;
	}
	pt_tabella->dimensione = dimensione;
	for (int i = 0; i < pt_tabella->dimensione; ++i)
		pt_tabella->tabella[i] = NULL;
}

int tabella_hash_aggiungi(t_tabella_hash* pt_tabella, t_studente elemento) {
	int k = _tabella_hash_funzione(*pt_tabella, elemento.matricola);
	return _inserimento_lista_trabocco(&(pt_tabella->tabella[k]), elemento);
}

void tabella_hash_rimuovi(t_tabella_hash* pt_tabella, tabella_hash_chiave chiave) {
	printf("da fare");
}
t_studente* tabella_hash_trova(t_tabella_hash tabella, tabella_hash_chiave chiave) {
	int k = _tabella_hash_funzione(tabella, chiave);
	// identifico la lista e poi cerco l'elemnto al suo interno. Ogni elemento non
	// e' altro che la radice di una lista
	return _ricerca_lista_trabocco(tabella.tabella[k], chiave);
}
int tabella_hash_elemento_vuoto(const t_studente* pt_a) {
	return strcmp(pt_a->cognome, TABELLA_HASH_VUOTO) == 0;
}

int _tabella_hash_funzione(t_tabella_hash tabella, tabella_hash_chiave chiave) {
	int k = 0;
	const int a = 0.2 * tabella.dimensione;
	const int b = 0.7 * tabella.dimensione;

	for (int i = 0; i < strlen(chiave); ++i)
		k += chiave[i];

	return (a * k + b) % tabella.dimensione;
}

int _tabella_hash_ispezione(t_tabella_hash tabella, int indice_iniziale) {
	// questa funzione non serve nel caso delle tabelle hash con trabocco
}
