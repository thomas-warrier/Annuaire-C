#pragma once

#include "gestion_client.h"
#include "gestion_fichier.h"
#include "tri.h"

int chercher_par();
char* par_quoi_chercher(client *clients,int choix_information);

void recherche_sequentielle(client clients[], char* recherche,int choix_information,int nombre_client);

void filtre(client clients[],char* mot_filtre,int choix_information,int nombre_client);

int strcmp_minuscule (const char *p1, const char *p2);