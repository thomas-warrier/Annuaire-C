#include "gestion_fichier.h"

/**
 * @brief prend en compte le nombre de ligne du fichier,mais pas celui du tableau struct.
 * 
 * @param fp 
 * @return int 
 */
int nombre_ligne_fichier(FILE *fp)
{
    int nb_ligne = 0;
    fseek(fp, 0, SEEK_SET);
    char str[MAX_LENGHT];
    while (fgets(str, MAX_LENGHT, fp) != NULL)
    {
        nb_ligne++;
    }
    return nb_ligne;
}
/**
 * @brief compte le nombre d'octets avec la fonction sizeof () du premier 
 * élément de tableau strs [0] (dans ce cas, 20 octets) diviser la taille entière avec la 
 * taille d'un élément ce qui vous donnera le nombre d'éléments.
 * 
 * @param clients 
 * @return int 
 */

//int nombre_clients_struct(client clients[])
//{
//    int nombre_ligne = (sizeof((client)* clients))/sizeof(client); //on divise la taille du tableau de tableau par la taille d'un élément afin d'avoir le nombre de clients.
//    return nombre_ligne;
//}




void print_tableau(client clients[], int nombre_client)
{
    int y = 0;
    while (y < nombre_client)
    {
        printf("\nligne %d :", y);
        printf("%s,", clients[y].ID);
        printf("%s,", clients[y].prenom);
        printf("%s,", clients[y].nom);
        printf("%s,", clients[y].ville);
        printf("%s,", clients[y].code_postal);
        printf("%s,", clients[y].num_de_tel);
        printf("%s,", clients[y].adresse_mail);
        printf("%s\n", clients[y].profession);
        
        y++;
    }
}



char *strsep(char **stringp, const char *delim) //pris sur https://code.woboq.org/userspace/glibc/string/strsep.c.html
{
    char *begin, *end;
    begin = *stringp;
    if (begin == NULL)
        return NULL;
    /* Find the end of the token.  */
    end = begin + strcspn(begin, delim);
    if (*end)
    {
        /* Terminate the token and set *STRINGP past NUL character.  */
        *end++ = '\0';
        *stringp = end;
    }
    else
        /* No more delimiters; this is the last token.  */
        *stringp = NULL;
    return begin;
}