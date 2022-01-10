#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gestion_fichier.h"

void permuter(client *c1, client *c2);
/**
entrée: deux pointeurs sur des structures client
précond: aucune
post-cond: permute les deux structures passées en paramètre
sortie: aucune 
*/

int trier_sur();
/** 
entrée: aucune
précond: aucune
post-cond: lit un entier au clavier et retourne cet entier
sortie: entier 
*/

char* par_quoi_trier(client *clients,int choix_information);
/**
entrée: un pointeur sur une structure client et un entier
précond: l'entier doit être compris entre 1 et 4 
post-cond: retourne selon l'entier passé en paramètre un pointeur sur un élément de la structure client
sortie: pointeur sur une chaîne de caractère 
*/

int partition(client *clients, int debut, int fin, int choix_information);
/** 
entrée: aucune
précond: aucune
post-cond: divise le tableau en deux parties et retourne la position du point de partition
sortie: entier
*/


void tri_rapide(client *clients, int debut, int fin, int choix_information);
/** 
entrée: entrée: pointeur sur une structure et trois entiers
précond: aucune
post-cond: trie le tableau de structures
sortie: aucune
*/
