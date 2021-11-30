#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "studente.h"

t_studente* studente_leggi(t_studente* pt_studente, FILE* f) {
	char stringa_formato[] = "%[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; ";

	/*
	Osservate la stringa di formato che ho assegnato ad una variabile per metteral in evidenza :
    char stringa_formato[] = "%[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; ";
 
	Come potete vedere si ripete 9 volte l'atomo %[^;] ;  (notate lo spazio bianco prima e dopo il ;
	quindi ogni atomo serve a leggere una stringa (compresi gli eventuali caratteri bianchi):
	
	il carattere % significa che questa è la descrizione di un tipo da leggere (come in tutti i casi)
	[ ] significa una stringa che contiene SOLO i caratteri indicati all'interno, ad esempio [abcdef] leggere la stringa  
	fincheè contiene i caratteri abcdef. Se quindi scrivo scanf("%[abcdef]", buffer) e provo a leggere aabcccXXedef leggerò "aabbccc" perchè, 
	essendo X non appartenente mi fermo durante la lettura
	
	^; significa tutti i caratteri eccetto quello preceduto dal simbolo ^ (cappelleto punto e virgola significa tutti i caratteri eccetto ; 
	cioè fernati quando trovi il punto e virgola che non viene letto. 
	Nella stringa MLGMHL60C19C351K ;MALGERI;MICHELE GIUSEPPE; leggo tutto fino al ;, cioè quello in rosso.
	
	;  significa nella stringa di ingresso DEVO trovare zero o più spazi (o ritorni a capo, tabulatori, ecc), 
	il ; e zero o più spazi che vanno saltati senza essere caricati!!

	Quindi se scrivo scanf( "%[^;] ; %[^;] ;", s1, s2) significa che leggo qualsiasi stringa e la termino con ; 
	(nell'esempio MLGMHL60C19C351K, poi cerco zero o più caratteri bianchi un ; e zero o più caratteri bianchi 
	(in vola) che salto poi leggo un'altra stringa terminata dal ; (MALGERI). 
 
	Un poco complesso, quindi ribadisco che NON è necessario per fare gli esercizi ma volevo evidenziare la potenza di questa istruzione 
	nel gestire dati in ingresso. Tra l'latro se provate ad importare come CVS il file elenco.txt con excel vedrete che vi carica una tabella! 
	E si può anche fare il viceversa, cioè salvare i dati di una tabella nel formato separato da ;*/


	if (f == NULL)
		return NULL;
	if (pt_studente == NULL)
		return NULL;
	int risultato = fscanf(f, stringa_formato,
		pt_studente->codice_fiscale,
		pt_studente->cognome,
		pt_studente->nome,
		pt_studente->matricola,
		pt_studente->comune_nascita,
		pt_studente->provincia,
		pt_studente->data_nascita,
		pt_studente->numero_telefono,
		pt_studente->indirizzo_mail);

	return (risultato == 9) ? pt_studente : NULL;
}
t_studente* studente_scrivi(const t_studente* pt_studente, FILE* f) {
	char stringa_formato[] = "%s;%s;%s;%s;%s;%s;%s;%s;%s;\n";
	if (f == NULL)
		return NULL;
	if (pt_studente == NULL)
		return NULL;

	int risultato = fprintf(f, stringa_formato,
		pt_studente->codice_fiscale,
		pt_studente->cognome,
		pt_studente->nome,
		pt_studente->matricola,
		pt_studente->comune_nascita,
		pt_studente->provincia,
		pt_studente->data_nascita,
		pt_studente->numero_telefono,
		pt_studente->indirizzo_mail);
	return (risultato == 9) ? pt_studente : NULL;
}
int studente_confronta_codice_fiscale(const t_studente* pt_a, const t_studente* pt_b) {
	return strncmp(pt_a->codice_fiscale, pt_b->codice_fiscale, STUDENTE_LUNGHEZZA_CODICE);
}
int studente_confronta_matricola(const t_studente* pt_a, const t_studente* pt_b) {
	return strncmp(pt_a->matricola, pt_b->matricola, STUDENTE_LUNGHEZZA_CODICE);
}


