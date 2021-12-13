
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_fichier.h"
#include "gestion_client.h"
#define NOM_FICHIER "annuaire5000.csv"

void menu_principal(int nombre_client, client clients[])
{
    int choix;
    
    do
    {
        printf("==========================[ menu principal ]==========================\n1)ajouter un client\n2)afficher tout les clients\n3)supprimer un client de l'annuaire\n4)modifier les informations d'un client de l'annuaire\n5)trier le tableau\n6)quitter\n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            ajouter_client(&clients, nombre_client);
            nombre_client++; //on incrémente nombre client comme on rajoute un client.            
            break;
        case 2: 
            print_tableau(clients,nombre_client);
            break;
        case 3:;
            supprimer_client(clients,nombre_client);
            modifier_tableau(&clients, -1, nombre_client);
            nombre_client--;
            break;
            
        case 4:
            modif_client(choix_client(),clients);
            break;

        case 5:
            // triRapid(clients,0,nombre_client-1,trier_sur());
            tri_rapide(clients, 0, nombre_client-1, trier_sur());
            break;

        default:
            break;
        }
    }while(choix!=6);
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

    client clients[3];

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
    menu_principal(nombre_client, clients);
    // free(clients);
    return 0;
}