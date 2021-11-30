#pragma once
#include <stdio.h>
#include <string.h>

#define STUDENTE_LUNGHEZZA_NOME	128
#define STUDENTE_LUNGHEZZA_CODICE	32

typedef struct {
	char codice_fiscale[STUDENTE_LUNGHEZZA_CODICE];
	char matricola[STUDENTE_LUNGHEZZA_CODICE];
	char cognome[STUDENTE_LUNGHEZZA_NOME];
	char nome[STUDENTE_LUNGHEZZA_CODICE];
	char data_nascita[STUDENTE_LUNGHEZZA_CODICE];
	char comune_nascita[STUDENTE_LUNGHEZZA_NOME];
	char provincia[STUDENTE_LUNGHEZZA_NOME];
	char numero_telefono[STUDENTE_LUNGHEZZA_NOME];
	char indirizzo_mail[STUDENTE_LUNGHEZZA_NOME];
} t_studente;

t_studente* studente_leggi(t_studente* pt_studente, FILE* f);
//QUI PASSA IL PUNTATORE PERCHE' LAVORA CON LA LISTA, NEI PROSSIMI NON CI LAVORA -> CONST PUNTATORE

t_studente* studente_scrivi(const t_studente* pt_studente, FILE* f); // <----------- !!!!!!!!!!!!!!!
/*DIGRESSIONE SU CONST T_STUDENTE*
USA UN PUNTATORE PERCHE' NON GLI CONVIENE PASSARE TUTTA LA LISTA IN TERMINI DI PRESTAZIONI 
(UN PUNTATORE E' MOLTO LEGGERO IN CONFRONTO AL CONTENUTO DI UNA LISTA)
MA LA LISTA NON DEVE ESSERE MODIFICATA! QUINDI AGGIUNGO CONST CHE PERMETTE DI NON FARE ASSEGNAZIONI
CON IL PUNTATORE A SINISTRA (CIOE' NON PU0' CAMBIARE VALORE, E' COSTANTE)
*/

//QUI ANCHE PASSA DUE VOLTE DUE CONST PUNTATORI PER RISPARMIARE SPAZIO 
int studente_confronta_codice_fiscale(const t_studente* pt_a, const t_studente* pt_b);
int studente_confronta_matricola(const t_studente* pt_a, const t_studente* pt_b);