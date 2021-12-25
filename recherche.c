#include "recherche.h"

int chercher_par()
{
    int choix_information;
    printf("================[quelle information souhaitez vous rechercher ?]=======================\n1)prenom\n2)nom\n3)code postal\n4)profession\n");
    scanf("%d", &choix_information);
    return choix_information;
}

char *par_quoi_chercher(client *clients, int choix_information)
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

int strcmp_minuscule(const char *p1, const char *p2) //j'ai repris le code source de la fonction strcmp et je l'ai modifié en ajoutant en faisant en sorte qu'au moment de la comparaison il compare les caractére en minuscule.
{
    const unsigned char *s1 = (const unsigned char *)p1;
    const unsigned char *s2 = (const unsigned char *)p2;
    unsigned char c1, c2;
    do
    {
        c1 = tolower((unsigned char)*s1++);
        c2 = tolower((unsigned char)*s2++);
        if (c1 == '\0')
            return c1 - c2;
    } while (c1 == c2);
    return c1 - c2;
}

void recherche_sequentielle(client clients[], char *recherche, int choix_information, int nombre_client)
{
    int i = 0;
    while (i < nombre_client)
    {
        if (strcmp_minuscule((par_quoi_chercher(&clients[i], choix_information)), recherche) == 0)
        {
            printf("\n%s,%s,%s,%s,%s,%s,%s", clients[i].prenom, clients[i].nom, clients[i].ville, clients[i].code_postal, clients[i].num_de_tel, clients[i].adresse_mail, clients[i].profession);
        }
        i++;
    }
}

void filtre(client clients[], char *mot_filtre, int choix_information, int nombre_client)
{
    /*
    nous voulons que notre fonction ne prenne pas en compte les majuscules,minuscule.
    par exemple si je rentre "ber" en filtre et qu'il existe Bertrand je dois le trouver.
    seulement le probléme est que la fonction strstr() fait une comparaison dans l'état actuelle
    de la chaine de caractére en étant sensible aux majuscules et minuscules.
    mon idée de base était de trouver le code source de la fonction strstr() afin de le modifier et qu'il effectue la 
    comparaison en lowercase,j'ai trouver certains code source sur internet mais je n'ais pas vraiment réussis a les comprendres car ils faisaient appelent
    a des connaissance que je n'ai pas. j'ai donc trouver l'alternative suivante
    */
    int i = 0;
    char *p;

    size_t len = strlen(mot_filtre);
    char *mot_filtre_minuscule = calloc(len + 1, sizeof(char));
    for (size_t i = 0; i < len; ++i)
    {
        mot_filtre_minuscule[i] = tolower((unsigned char)mot_filtre[i]);
    }

    while (i < nombre_client)
    {
        char *info = par_quoi_chercher(&clients[i], choix_information);

        size_t len = strlen(info);
        char *info_minuscule = calloc(len + 1, sizeof(char));

        for (size_t i = 0; i < len; ++i)
        {
            info_minuscule[i] = tolower((unsigned char)info[i]);
        }

        p = strstr(info_minuscule, mot_filtre_minuscule);
        if (p)
        {
            printf("a la ligne %d : %s \n",i,par_quoi_chercher(&clients[i], choix_information));
        }
        i++;
        free(info_minuscule);
    }
    free(mot_filtre_minuscule);
}
