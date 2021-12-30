
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

void ajouter_client(client* clients[],int nombre_client);

int demande_client_modif();

int choix_client();

int modif_client(int choix_client, client clients[]);

int supprimer_client(client clients[],int nombre_client);

int decaler_tableau(client clients[], int position, int nombre_client);
