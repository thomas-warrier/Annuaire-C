#include "gestion_client.h"
#include "gestion_fichier.h"

void modifier_tableau(client *clients[], int taille_augmenter, int nombre_client)
{

    client *temporaire = *clients;
    *clients = malloc((nombre_client + taille_augmenter) * sizeof(client));
    if (taille_augmenter >= 0)
    {
        memcpy(*clients, temporaire, nombre_client * sizeof(client));
    }
    else
    {
        memcpy(*clients, temporaire, (nombre_client + taille_augmenter) * sizeof(client));
    }
    free(temporaire);
}



void ajouter_client(client *clients[], int nombre_client)
{
    modifier_tableau(clients, 1, nombre_client); //on agrandit le tableau afin d'ajouter un nouveau client.

    printf("saisisser le prénom du client que vous souhaitez ajouter :  ");
    scanf("%s", (*clients)[nombre_client].prenom);
    printf("saisisser son nom :  ");
    scanf("%s", (*clients)[nombre_client].nom);
    printf("saisisser sa ville :  ");
    scanf("%s", (*clients)[nombre_client].ville);
    printf("saisisser son code postal :  ");
    scanf("%s", (*clients)[nombre_client].code_postal);
    printf("saisisser son numéro de téléphone :  ");
    scanf("%s", (*clients)[nombre_client].num_de_tel);
    printf("saisisser son adresse mail :  ");
    scanf("%s", (*clients)[nombre_client].adresse_mail);
    printf("saisisser sa profession :  ");
    scanf("%s", (*clients)[nombre_client].profession);

    printf("votre client a bien été ajouté !\n");
}
int choix_client()
{
    int choix_client;
    printf("saisisser le numéros de votre client :  ");
    scanf("%d", &choix_client);
    return choix_client;
}

int demande_client_modif()
{
    int choix_information;
    printf("================[qu'elle information souhaitez vous modifier ?]=======================\n1)prenom\n2)nom\n3)ville\n4)code postal\n5)numero de telephone\n6)adresse email\n7)profession\n8)Quitter l'interface de modification\n");
    scanf("%d", &choix_information);
    return choix_information;
}

int modif_client(int choix_client, client clients[])
{
    int choix_info=demande_client_modif();
    do
    {
        choix_info=demande_client_modif();
        switch (choix_info)
        {
        case 1:
            printf("rentrer le nouveau nom de votre client.\n");
            scanf("%s", clients[choix_client].prenom);
            break;
        case 2:
            printf("rentrer le nouveau nom de votre client.\n");
            scanf("%s", clients[choix_client].nom);
            break;
        case 3:
            printf("rentrer la nouvelle ville de votre client.\n");
            scanf("%s", clients[choix_client].ville);
            break;
        case 4:
            printf("rentrer le nouveau code postal de votre client.\n");
            scanf("%s", clients[choix_client].code_postal);
            break;
        case 5:
            printf("rentrer le nouveau nouveau numéros de téléphone de votre client.\n");
            scanf("%s", clients[choix_client].num_de_tel);
            break;
        case 6:
            printf("rentrer la nouvelle adresse email de votre client.\n");
            scanf("%s", clients[choix_client].adresse_mail);
            break;
        case 7:
            printf("rentrer la nouvelle profession de votre client.\n");
            scanf("%s", clients[choix_client].profession);
            break;
        default:
            printf("le choix entrer n'est pas valide.\n");
            break;
        }
    } while (choix_info != 8);
    printf("vos changements on bien été effectués.\n");
}

int supprimer_client(client clients[], int nombre_client)
{
    decaler_tableau(clients, choix_client(), nombre_client);
    printf("votre suppression a bien ete enregistrer.\n");

    return 0;
}

int decaler_tableau(client clients[], int position, int nombre_client)
{
    int i = position;
    while (i < nombre_client - 1)
    {
        strcpy(clients[i].prenom, clients[i + 1].prenom);

        strcpy(clients[i].nom, clients[i + 1].nom);

        strcpy(clients[i].ville, clients[i + 1].ville);

        strcpy(clients[i].code_postal, clients[i + 1].code_postal);

        strcpy(clients[i].num_de_tel, clients[i + 1].num_de_tel);

        strcpy(clients[i].adresse_mail, clients[i + 1].adresse_mail);

        strcpy(clients[i].profession, clients[i + 1].profession);
        i++;
    }
    strcpy(clients[i].prenom, "");

    strcpy(clients[i].nom, "");

    strcpy(clients[i].ville, "");

    strcpy(clients[i].code_postal, "");

    strcpy(clients[i].num_de_tel, "");

    strcpy(clients[i].adresse_mail, "");

    strcpy(clients[i].profession, "");
}