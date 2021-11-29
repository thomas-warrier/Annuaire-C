#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

char *strsep(char **stringp, const char *delim);
void print_tableau(client *clients, int nombre_client);
int nombre_ligne(FILE *fp);

int main()
{
	FILE *fp = fopen("annuaire5000.csv", "r");
	int nombre_client = nombre_ligne(fp);
	client *clients = malloc(nombre_client * sizeof(client));

	if (fp)
	{
		char ligne[MAX_LENGHT];
		char *token;
		char *separateur = ",";
		int index = 0;

		fseek(fp, 0, SEEK_SET);
		while (fgets(ligne, MAX_LENGHT, fp) != NULL)
		{

			char *copie_ligne = strdup(ligne); //dupliquer la chaîne ligne avec strdupa car le strsep modifie
											   //le pointeur passé, et nous ne voulons pas perdre la valeur d’origine

			token = strsep(&copie_ligne, ",");
			if (*token != '\n' && token != NULL)
			{
				strcpy(clients[index].prenom, token);
			}
			token = strsep(&copie_ligne, ",");
			if (*token != '\n' && token != NULL)
			{
				strcpy(clients[index].nom, token);
			}
			token = strsep(&copie_ligne, ",");
			if (*token != '\n' && token != NULL)
			{
				strcpy(clients[index].ville, token);
			}
			token = strsep(&copie_ligne, ",");
			if (*token != '\n' && token != NULL)
			{
				strcpy(clients[index].code_postal, token);
			}
			token = strsep(&copie_ligne, ",");
			if (*token != '\n' && token != NULL)
			{
				strcpy(clients[index].num_de_tel, token);
			}
			token = strsep(&copie_ligne, ",");
			if (*token != '\n' && token != NULL)
			{
				strcpy(clients[index].adresse_mail, token);
			}
			token = strsep(&copie_ligne, ",");
			if (*token != '\n' && token != NULL)
			{
				strcpy(clients[index].profession, token);
			}

			index++;
		}
		fclose(fp);
	}
	print_tableau(clients, nombre_client);
}

int nombre_ligne(FILE *fp)
{
	int nb_ligne = 0;
	fseek(fp, 0, SEEK_SET);
	char str[MAX_LENGHT];
	while (fgets(str, MAX_LENGHT, fp) != NULL)
	{
		nb_ligne++;
	}
	return nb_ligne;
}

void print_tableau(client *clients, int nombre_client)
{
	int y = 0;
	while (y < nombre_client)
	{
		printf("ligne %d :", y);
		printf("%s, ", clients[y].prenom);
		printf("%s, ", clients[y].nom);
		printf("%s, ", clients[y].ville);
		printf("%s, ", clients[y].code_postal);
		printf("%s, ", clients[y].num_de_tel);
		printf("%s, ", clients[y].adresse_mail);
		printf("%s\n", clients[y].profession);
		y++;
	}
}

char *strsep(char **stringp, const char *delim)
{
	char *begin, *end;
	begin = *stringp;
	if (begin == NULL)
		return NULL;
	/* Find the end of the token.  */
	end = begin + strcspn(begin, delim);
	if (*end)
	{
		/* Terminate the token and set *STRINGP past NUL character.  */
		*end++ = '\0';
		*stringp = end;
	}
	else
		/* No more delimiters; this is the last token.  */
		*stringp = NULL;
	return begin;
}