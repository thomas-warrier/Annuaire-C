#pragma once

#include "gestion_client.h"
#include "gestion_fichier.h"
#include "tri.h"

int chercher_par_filtre();
/** 
entrée: aucune
précond: aucune
post-cond: lit un entier au clavier et retourne cet entier
sortie: entier 
*/

int chercher_par_recherche();
/** 
entrée: aucune
précond: aucune
post-cond: lit au clavier un entier et le retourne
sortie: entier
*/

char* par_quoi_chercher_recherche(client *clients, int choix_information);
/* 
entrée: aucune
précond: aucune
post-cond: retourne un pointeur sur l'élément de la structure correspondant à l'entier passé en paramètre
sortie: pointeur sur une chaine de caractères
*/ 

char* par_quoi_chercher_filtre(client *clients,int choix_information);
/**
entrée: un pointeur sur une structure client et un entier
précond: aucune
post-cond: retourne un pointeur sur un élément de la structure si l'entier passé en paramètre est compris entre 1 et 4
sortie: pointeur sur une chaine de charactères
*/

void recherche_sequentielle(client clients[], char* recherche,int choix_information,int nombre_client);
/**
entree : tableau de structure, entier qui correspond au nombre de client actuel, entier qui correspond a un choix
pre_cond : tableau de structure qui contient les données
sortie : 
post_cond : affiche un client seulement si le critère sur le choix correspond entre la recherche et le client
*/

void filtre(client clients[],char* mot_filtre,int choix_information,int nombre_client);
/**
entree : tableau de structure, entier qui correspond au nombre de client actuel, char* qui correspond au filtre, entier qui correspond au choix de la colonne a trié
pre_cond : tableau de structure qui contient les données,
sortie : 
post_cond : affiche les clients si l'information dans la colonne choisis correspond
*/

int strcmp_minuscule (const char *p1, const char *p2);
//correspond au code source de la fonction strcmp et qui a été modifié de sorte qu'au moment de la comparaison il compare les caractères en minuscule.
/**
entree : deux chaines de caractère
pre_cond : 
sortie : int
post_cond : 0 si chaines de caractère égales, >0 si le premier caractère différent est plus grand dans le premier mot, <0 si c'est l'inverse
*/

void info_manquante(client clients[],int nombre_client);
/** 
entrée: tableau de structures client et nombre d'éléments du tableau
précond: aucune
post-cond: affiche toutes les structures qui contiennent des champs manquants
sortie: aucune
*/