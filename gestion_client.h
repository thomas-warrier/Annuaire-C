
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGHT 429

typedef struct
{
	char prenom[64];
	char nom[64];
	char ville[128];
	char code_postal[6];
	char num_de_tel[32];
	char adresse_mail[64];
	char profession[64];
} client;



void modifier_tableau(client* clients[], int taille_augmenter, int nombre_client);
/**
entree : tableau de structure, entier pour la taille a augmenter, entier qui correspond au nombre de clients acteul
pre_cond : tableau de structure qui contient les données
sortie : Aucune
post_cond : modifie la taille du tableau
*/

void ajouter_client(client* clients[],int nombre_client);
/**
entree : tableau de structure, entier qui correspond au nombre de clients actuel
pre_cond : tableau de structure qui contient les données
sortie : Aucune
post_cond : demande a  l'utilisateur les données d'une personne a ajouter puis les met dans le tableau de structure
*/

int demande_client_modif();
/**
entree : 
pre_cond : 
sortie : entier
post_cond : demande a  l'utilisateur de choisir un numero qui correspond a un chois de modification puis le renvoie
*/

int choix_client();
/**
entree : 
pre_cond : 
sortie : entier
post_cond : demande a  l'utilisateur de choisir un numero de client puis le renvoie
*/

void modif_client(int choix_client, client clients[]);
/**
entree : entier, tableau de structure
pre_cond : tableau de structure qui contient les données
sortie : 
post_cond : permet de modifier les infos d'un client
*/

int supprimer_client(client clients[],int nombre_client);
/**
entree : tableau de structure, entier qui correspond au nombre de client actuel
pre_cond : tableau de structure qui contient les données
sortie : 0 si code bien executé
post_cond : appelle une fonction pour décaler le tableau et print si l'appel est correct
*/

void decaler_tableau(client clients[], int position, int nombre_client);
/**
entree : tableau de structure, entier qui correspond au nombre de client actuel, entier qui correspond a la position du client a supprimer
pre_cond : tableau de structure qui contient les données
sortie : 
post_cond :décale toute les lignes du tableau de structure pour enlever le client a la bonne position
*/

void sauvegarde();