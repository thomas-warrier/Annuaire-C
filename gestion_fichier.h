
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gestion_client.h"
#include "tri.h"



int nombre_ligne_fichier(FILE* fp);
/** 
entrée: un pointeur sur un fichier
précond: aucune
post-cond: retourne le nombre de lignes que contient le fichier qui correspond au pointeur passé en paramètre
sortie: entier 
*/

//int nombre_clients_struct(client clients[]);

void print_tableau(client clients[], int nombre_client);
/**
entrée : tableau de structure, entier qui correspond au nombre de client actuel
précond : tableau de structure qui contient nos donneés
post-cond : affiche toute les lignes du tableau
sortie :
*/


char* strsep(char** stringp, const char* delim);
//pris sur https://code.woboq.org/userspace/glibc/string/strsep.c.html
/**
entrée : chaine de caratère qui contient une ligne, chaine de caractère qui correspond au délimitateur
précond :
post-cond : renvoie un pointeur vers l'élément extrait
sortie :pointeur vers l'élément extrait
*/


void sauvegarde(client clients[],char* Nom_fichier,int nombre_client);
/**
entree : tableau de structure, chaine de caractère qui contient le nom du fichier, entier qui corespond au nombre de client actuel
pre_cond : tableau de structure qui contient nos donneés
sortie : 
post_cond : écris dans le fichier toute les données du tableau de structure
*/