#include "gestion_client.h"

void agrandir_tableau(client* clients[], int taille_augmenter, int nombre_client)
{
    client *temporaire = *clients;
    *clients = malloc((nombre_client + taille_augmenter) * sizeof(client));
    memcpy(*clients, temporaire, nombre_client * sizeof(client));
    free(temporaire);
}

void ajouter_client(client* clients[], int nombre_client)
{
    agrandir_tableau(clients, 1, nombre_client); //on agrandit le tableau afin d'ajouter un nouveau client.

    printf("saisisser le prénom du client que vous souhaitez ajouter :  ");
    scanf("%64s", (*clients)[nombre_client].prenom);
    printf("saisisser son nom :  ");
    scanf("%64s", (*clients)[nombre_client].nom);
    printf("saisisser sa ville :  ");
    scanf("%128s", (*clients)[nombre_client].ville);
    printf("saisisser son code postal :  ");
    scanf("%6s", (*clients)[nombre_client].code_postal);
    printf("saisisser son numéro de téléphone :  ");
    scanf("%32s", (*clients)[nombre_client].num_de_tel);
    printf("saisisser son adresse mail :  ");
    scanf("%64s", (*clients)[nombre_client].adresse_mail);
    printf("saisisser sa profession :  ");
    scanf("%64s", (*clients)[nombre_client].profession);

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
    printf("================[qu'elle information souhaitez vous modifier ?]=======================\n1)prenom\n2)nom\n3)ville\n4)code postal\n5)numero de telephone\n6)adresse email\n7)profession\n");
    scanf("%d", &choix_information);
    return choix_information;
}

int modif_client(int choix_information, int choix_client, client clients[])
{
    switch (choix_information)
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
    printf("vos changement on bien été effectués.\n");
}

int supprimer_client(client clients[], int nombre_client)
{
    decaler_tableau(clients, choix_client(), nombre_client);
    printf("votre suppression a bien été enregistrer.\n");

    return 0;
}

int decaler_tableau(client clients[], int position, int nombre_client)
{
    for (int i = position; i < nombre_client-1; i++)
    {
        strcpy(clients[i].prenom, clients[i + 1].prenom);

        strcpy(clients[i].nom, clients[i + 1].nom);

        strcpy(clients[i].ville, clients[i + 1].ville);

        strcpy(clients[i].code_postal, clients[i + 1].code_postal);

        strcpy(clients[i].num_de_tel, clients[i + 1].num_de_tel);
        
        strcpy(clients[i].adresse_mail, clients[i + 1].adresse_mail);
        
        strcpy(clients[i].profession, clients[i + 1].profession);
    }
}