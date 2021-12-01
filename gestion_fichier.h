
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gestion_client.h"



int nombre_ligne(FILE* fp);

void print_tableau(client clients[], int nombre_client);

char* strsep(char** stringp, const char* delim);