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
    fflush(stdin); //clear le tampon pour pouvoir mettre des champs vide. 
    printf("saisisser le prenom du client que vous souhaitez ajouter :  ");
    scanf("%[^\n]", (*clients)[nombre_client].prenom);
    fflush(stdin);
    printf("saisisser son nom :  ");
    scanf("%[^\n]", (*clients)[nombre_client].nom);
    fflush(stdin);
    printf("saisisser sa ville :  ");
    scanf("%[^\n]", (*clients)[nombre_client].ville);
    fflush(stdin);
    printf("saisisser son code postal :  ");
    scanf("%[^\n]", (*clients)[nombre_client].code_postal);
    fflush(stdin);
    printf("saisisser son numero de telephone :  ");
    scanf("%[^\n]", (*clients)[nombre_client].num_de_tel);
    fflush(stdin);
    printf("saisisser son adresse mail :  ");
    scanf("%[^\n]", (*clients)[nombre_client].adresse_mail);
    fflush(stdin);
    printf("saisisser sa profession :  ");
    scanf("%[^\n]", (*clients)[nombre_client].profession);

    printf("votre client a bien ete ajoute !\n");
}
int choix_client()
{
    int choix_client;
    printf("saisisser le numeros de votre client :  ");
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

void modif_client(int choix_client, client clients[])
{
    
    int choix_info;
    do
    {
        choix_info=demande_client_modif();
        switch (choix_info)
        {
        case 1:
            fflush(stdin);
            printf("rentrer le nouveau prenom de votre client.\n");
            scanf("%[^\n]", clients[choix_client].prenom);
            break;
        case 2:
            fflush(stdin);
            printf("rentrer le nouveau nom de votre client.\n");
            scanf("%[^\n]", clients[choix_client].nom);
            break;
        case 3:
            fflush(stdin);
            printf("rentrer la nouvelle ville de votre client.\n");
            scanf("%[^\n]", clients[choix_client].ville);
            break;
        case 4:
            fflush(stdin);
            printf("rentrer le nouveau code postal de votre client.\n");
            scanf("%[^\n]", clients[choix_client].code_postal);
            break;
        case 5:
            fflush(stdin);
            printf("rentrer le nouveau nouveau numéros de téléphone de votre client.\n");
            scanf("%[^\n]", clients[choix_client].num_de_tel);
            break;
        case 6:
            fflush(stdin);
            printf("rentrer la nouvelle adresse email de votre client.\n");
            scanf("%[^\n]", clients[choix_client].adresse_mail);
            break;
        case 7:
            fflush(stdin);
            printf("rentrer la nouvelle profession de votre client.\n");
            scanf("%[^\n]", clients[choix_client].profession);
            break;
        default:
            printf("le choix entrer n'est pas valide.\n");
            break;
        }
    } while (choix_info != 8);
    printf("vos changements on bien ete effectuer.\n");
}

int supprimer_client(client clients[], int nombre_client)
{
    decaler_tableau(clients, choix_client(), nombre_client);
    printf("votre suppression a bien ete enregistrer.\n");

    return 0;
}

void decaler_tableau(client clients[], int position, int nombre_client)
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