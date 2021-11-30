#include "gestion_client.h"

void agrandir_tableau(client **clients, int taille_augmenter, int nombre_client)
{
    client *temporaire = *clients;
    *clients = malloc((nombre_client + taille_augmenter) * sizeof(client));
    memcpy(*clients, temporaire, nombre_client * sizeof(client));
    free(temporaire);
}

void ajouter_client(client *clients,int taille_augmenter,int nombre_client)
{
    agrandir_tableau(clients, 1, nombre_client); //on agrandit le tableau afin d'ajouter un nouveau client.

    printf("saisisser le prénom du client que vous souhaitez ajouter :");
    scanf("%s", clients[nombre_client].prenom);
    printf("saisisser son nom : ");
    scanf("%s", clients[nombre_client].nom);
    printf("saisisser sa ville : ");
    scanf("%s", clients[nombre_client].ville);
    printf("saisisser son code postal : ");
    scanf("%s", clients[nombre_client].code_postal);
    printf("saisisser son numéro de téléphone : ");
    scanf("%s", clients[nombre_client].num_de_tel);
    printf("saisisser son adresse mail : ");
    scanf("%s", clients[nombre_client].adresse_mail);
    printf("saisisser sa profession : ");
    scanf("%s", clients[nombre_client].profession);

    printf("votre client a bien été ajouté !");
}

int demande_client()
{
    int choix_information;
    printf("================[qu'elle information souhaitez vous rechercher ?]=======================\n1)prenom\n2)nom\n3)ville\n4)code postal\n5)numero de telephone\n6)adresse email\n7)profession\n");
    scanf("%d", &choix_information);
    return choix_information;
}

int modif_client(int choix_information, int choix_client, client *clients)
{
    switch (choix_information)
    {
    case 1:
        printf("rentrer le nouveau nom de votre client");
        scanf("%s", clients[choix_client].prenom);
        break;
    case 2:
        printf("rentrer le nouveau nom de votre client");
        scanf("%s", clients[choix_client].nom);
        break;
    case 3:
        printf("rentrer la nouvelle ville de votre client");
        scanf("%s", clients[choix_client].ville);
        break;
    case 4:
        printf("rentrer le nouveau code postal de votre client");
        scanf("%s", clients[choix_client].code_postal);
        break;
    case 5:
        printf("rentrer le nouveau nouveau numéros de téléphone de votre client");
        scanf("%s", clients[choix_client].num_de_tel);
        break;
    case 6:
        printf("rentrer la nouvelle adresse email de votre client");
        scanf("%s", clients[choix_client].adresse_mail);
        break;
    case 7:
        printf("rentrer la nouvelle profession de votre client");
        scanf("%s", clients[choix_client].profession);
        break;
    default:
        printf("le choix entrer n'est pas valide");
        break;
    }
    printf("vos changement on bien été effectuer");
}


int supprimer_client(client *clients)
{
    int y;
    printf("rentrer l'identifiant de l'utilisateur que vous souhaitez supprimés");
    scanf("%d", y);
    clients[y].prenom = '\0';
    clients[y].nom = '\0';
    clients[y].ville = '\0';
    clients[y].code_postal = '\0';
    clients[y].num_de_tel = '\0';
    clients[y].adresse_mail = '\0';
    clients[y].profession = '\0';
}