
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gestion_client.h"
#include "tri.h"



int nombre_ligne_fichier(FILE* fp);

//int nombre_clients_struct(client clients[]);

void print_tableau(client clients[], int nombre_client);

char* strsep(char** stringp, const char* delim);