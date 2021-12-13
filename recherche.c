#include "recherche.h"

int chercher_par()
{
    int choix_information;
    printf("================[par quelle information souhaitez vous trier ?]=======================\n1)prenom\n2)nom\n3)code postal\n4)profession\n");
    scanf("%d", &choix_information);
    return choix_information;
}

char* par_quoi_chercher(client *clients,int choix_information)
{  
    switch (choix_information)
    {
    case 1:
        return clients->prenom;
    case 2:
        return clients->nom;
    case 3:
        return clients->code_postal;
    case 4:
        return clients->profession;
    }
}


void recherche_par_interpolation(client* clients[], int taille, char* recherche,int choix_information)
{
    int gauche = 0;
    int droite = taille - 1;
    int mid;

    while((par_quoi_chercher(&clients[droite],choix_information)) != clients[gauche]) && (recherche >= clients[gauche]) && (recherche <= clients[droite])){
        mid = gauche + ((recherche - clients[gauche]) * (droite - gauche) / (clients[droite] - clients[gauche]));

        if (clients[mid] < recherche)
            gauche = mid + 1;
        else if (recherche < clients[mid])
            droite = mid - 1;
        else
            printf("%s,%s,%s,%s,%s,%s,%s"),clients[mid]->prenom,clients[mid]->nom,clients[mid]->ville,clients[mid]->code_postal,clients[mid]->num_de_tel,clients[mid]->adresse_mail,clients[mid]->profession;
    }

    if (recherche == clients[gauche])
        return gauche ;
    else
        return -1;
}