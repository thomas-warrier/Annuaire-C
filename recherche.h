#pragma once

#include "gestion_client.h"
#include "gestion_fichier.h"
#include "tri.h"

int chercher_par();
char* par_quoi_chercher(client *clients,int choix_information);

void recherche_par_interpolation(client* clients[], int taille, char* recherche,int choix_information);