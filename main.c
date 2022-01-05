
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_fichier.h"
#include "gestion_client.h"
#include "recherche.h"

#define NOM_FICHIER "annuaire5000.csv"

void clear()
{
    system("clear||cls");
}

void menu_principal(int nombre_client, client clients[])
{
    int choix;

    do
    {
        printf("\n==========================[ menu principal ]==========================\n1)ajouter un client\n2)afficher tout les clients\n3)supprimer un client de l'annuaire\n4)modifier les informations d'un client de l'annuaire\n5)trier le tableau\n6)rechercher un client par une information\n7)filtre\n8)afficher la liste des donnes manquante\n9)Sauvegarder dans le fichier\n10)Quitter\n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            ajouter_client(&clients, nombre_client);
            nombre_client++; //on incrémente nombre client comme on rajoute un client.
            break;
        case 2:
            print_tableau(clients, nombre_client);
            break;
        case 3:
            supprimer_client(clients, nombre_client);
            modifier_tableau(&clients, -1, nombre_client);
            nombre_client--;
            break;

        case 4:
            modif_client(choix_client(), clients);
            break;

        case 5:
            // triRapid(clients,0,nombre_client-1,trier_sur());
            tri_rapide(clients, 0, nombre_client - 1, trier_sur());
            break;
        case 6:;
            int choix_information = chercher_par_recherche();
            if (choix_information <= 4)
            {
                char *recherche;
                printf("\nrentrer le nom de votre recherche : ");
                scanf("%s", recherche);
                recherche_sequentielle(clients, recherche, choix_information, nombre_client);
            }
            else
            {
                clear();
            }
            break;
            
        case 7:;
            int choix_information_filtre = chercher_par_filtre();
            if (choix_information_filtre <= 4)
            {
                char filtre_mot[128];
                printf("\nrentrer le nom du filtre : ");
                scanf("%s", filtre_mot);
                filtre(clients, filtre_mot, choix_information_filtre, nombre_client);
            }
            else
            {
                clear();
            }
            break;
        case 8:
            info_manquante(clients,nombre_client);
            break;
        
        case 9:
            sauvegarde(clients,NOM_FICHIER,nombre_client);

        default:
            break;
        }
    } while (choix != 10);
}

int main()
{

    /**
     * @brief on lit simplement le fichier,
     * pour mettre les infos dans le struct,on écrira le fichier a la fin
     * quand on sauvegardera dans le fichier
     * 
     */
    FILE *fp = fopen(NOM_FICHIER, "r");
    int nombre_client = nombre_ligne_fichier(fp);

    client *clients;
    clients = malloc(nombre_client * sizeof(client));
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
            if (*token != '\n' && token != NULL && *token != '\0')
            {
                strcpy(clients[index].code_postal, token);
            }
            token = strsep(&copie_ligne, ",");
            if (*token != '\n' && token != NULL)
            {
                strcpy(clients[index].num_de_tel, token);
            }
            token = strsep(&copie_ligne, ",");
            if (*token != '\n' && token != NULL && *token != '\0')
            {
                strcpy(clients[index].adresse_mail, token);
            }
            token = strsep(&copie_ligne, "\n");
            if (*token != '\n' && token != NULL)
            {
                strcpy(clients[index].profession, token);
            }

            index++;
        }
        fclose(fp);
    }
    else
    {
        printf("erreur d'ouverture\n");
    }
    menu_principal(nombre_client, clients);
    return 0;
}