
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gestion_fichier.h"
#include "gestion_client.h"
#include "recherche.h"

char nom_du_fichier[64];

void clear()
{
    system("clear||cls");
}

/* 
entrée: le nombre de clients, et un tableau de structures client
précond: aucune
post-cond: affiche le menu
sortie: aucune 
*/
void menu_principal(int nombre_client, client clients[])
{
    int choix;

    do
    {
        printf("\n==========================[ menu principal ]==========================\n1)ajouter un client\n2)afficher tout les clients\n3)supprimer un client de l'annuaire\n4)modifier les informations d'un client de l'annuaire\n5)trier le tableau\n6)rechercher un client par une information\n7)filtre\n8)afficher la liste des donnes manquante\n9)Sauvegarder dans le fichier\n10)Quitter\n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:;
            ajouter_client(&clients, nombre_client);
            nombre_client++; //on incrémente nombre client comme on rajoute un client.
            
            break;
        case 2:;
            clock_t begin1 = clock();
            print_tableau(clients, nombre_client);
            clock_t end1 = clock();
            double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
            printf("\n\ntemps d'executions %f secondes\n",time_spent1);
            break;
        case 3:;
            clock_t begin2 = clock();
            supprimer_client(clients, nombre_client);
            modifier_tableau(&clients, -1, nombre_client);
            nombre_client--;
            clock_t end2 = clock();
            double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
            printf("\n\ntemps d'executions %f secondes\n",time_spent2);

            break;

        case 4:;
            clock_t begin3 = clock();
            modif_client(choix_client(), clients);
            clock_t end3 = clock();
            double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
            printf("\n\ntemps d'executions %f secondes\n",time_spent3);
            break;

        case 5:;
            // triRapid(clients,0,nombre_client-1,trier_sur());
            int rep = trier_sur();
            clock_t begin4 = clock();
            tri_rapide(clients, 0, nombre_client - 1, rep);
            clock_t end4 = clock();
            double time_spent4 = (double)(end4 - begin4) / CLOCKS_PER_SEC;
            printf("\n\ntemps d'executions %f secondes\n",time_spent4);
            break;
        case 6:;
            int choix_information = chercher_par_recherche();
            if (choix_information <= 4)
            {
                char recherche[64];
                printf("\nrentrer le nom de votre recherche : ");
                scanf("%s", recherche);
                clock_t begin5 = clock();
                recherche_sequentielle(clients, recherche, choix_information, nombre_client);
                clock_t end5 = clock();
                double time_spent5 = (double)(end5 - begin5) / CLOCKS_PER_SEC;
                printf("\n\ntemps d'executions %f secondes\n",time_spent5);

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
                clock_t begin6 = clock();
                filtre(clients, filtre_mot, choix_information_filtre, nombre_client);
                clock_t end6 = clock();
                double time_spent6 = (double)(end6 - begin6) / CLOCKS_PER_SEC;
                printf("\n\ntemps d'executions %f secondes\n",time_spent6);
            }
            else
            {
                clear();
            }

            break;
        case 8:;
            clock_t begin7 = clock();
            info_manquante(clients,nombre_client);
            clock_t end7 = clock();
            double time_spent7 = (double)(end7 - begin7) / CLOCKS_PER_SEC;
            printf("\n\ntemps d'executions %f secondes\n",time_spent7);
            break;
        
        case 9:;
            clock_t begin8 = clock();
            sauvegarde(clients,nom_du_fichier,nombre_client);
            clock_t end8 = clock();
            double time_spent8 = (double)(end8 - begin8) / CLOCKS_PER_SEC;
            printf("\n\ntemps d'executions %f secondes\n",time_spent8);

        default:
            break;
        }
    } while (choix != 10);
}

int main()
{
    printf("inserer le nom du fichier a charger avec l'extension utiliser : ");
    scanf("%s",nom_du_fichier);

    FILE *fp = fopen(nom_du_fichier, "r");
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
        menu_principal(nombre_client, clients);
    }
    else
    {
        printf("erreur d'ouverture\n");
    }
    return 0;
}