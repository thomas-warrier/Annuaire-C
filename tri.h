#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gestion_fichier.h"

void permuter(client *c1, client *c2);

int trier_sur();

char* par_quoi_trier(client *clients,int choix_information);

int partition(client *clients, int debut, int fin, int choix_information);

void tri_rapide(client *clients, int debut, int fin, int choix_information);