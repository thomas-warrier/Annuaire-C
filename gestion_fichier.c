#include "gestion_fichier.h"


int nombre_ligne(FILE *fp)
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




void print_tableau(client *clients, int nombre_client)
{
    int y = 0;
    while (y < nombre_client)
    {
        printf("ligne %d :", y);
        printf("%s, ", clients[y].prenom);
        printf("%s, ", clients[y].nom);
        printf("%s, ", clients[y].ville);
        printf("%s, ", clients[y].code_postal);
        printf("%s, ", clients[y].num_de_tel);
        printf("%s, ", clients[y].adresse_mail);
        printf("%s\n", clients[y].profession);
        y++;
    }
}



char *strsep(char **stringp, const char *delim)
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