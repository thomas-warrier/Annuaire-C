
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_fichier.h"
#include "gestion_client.h"
#define NOM_FICHIER "annuaire5000.csv"

int charger_fichier()
{
    FILE *fp = fopen(NOM_FICHIER, "r");
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
    return 0;
}

void menu_principal()
    {
        int choix;
        printf("==========================[ menu principal ]======================\n1)charger fichier\n2)afficher tout les clients\n3)ajouter un client dans l'annuaire\n4)supprimer un client de l'annuaire");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1: ;
            char* nom_fichier;
            printf("rentrer le nom de votre fichier");
            scanf("%s", *nom_fichier);
            charger_fichier(nom_fichier);

            break;
        case 2:

        case 3:

        case 4:

        case 5:

        case 6:

        case 7:

        case 8:

        case 9:

        case 10:

        default:
            break;
        }
    }


int main()
{
menu_principal();
return 0;
    
}