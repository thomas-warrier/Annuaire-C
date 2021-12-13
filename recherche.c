#include "recherche.h"

int chercher_par()
{
    int choix_information;
    printf("================[quelle information souhaitez vous rechercher ?]=======================\n1)prenom\n2)nom\n3)code postal\n4)profession\n");
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

int strcmp_minuscule (const char *p1, const char *p2)   //j'ai repris le code source de la fonction strcmp et je l'ai modifié en ajoutant en faisant en sorte qu'au moment de la comparaison il compare les caractére en minuscule.
{
  const unsigned char *s1 = (const unsigned char *) p1;
  const unsigned char *s2 = (const unsigned char *) p2;
  unsigned char c1, c2;
  do
    {
      c1 = tolower((unsigned char) *s1++);
      c2 = tolower((unsigned char) *s2++);
      if (c1 == '\0')
        return c1 - c2;
    }
  while (c1 == c2);
  return c1 - c2;
}

void recherche_sequentielle(client clients[], char* recherche,int choix_information,int nombre_client)
{
    int i=0;
    while (i< nombre_client){
        if (strcmp_minuscule((par_quoi_chercher(&clients[i],choix_information)),recherche) == 0 ){
            printf("\n%s,%s,%s,%s,%s,%s,%s",clients[i].prenom,clients[i].nom,clients[i].ville,clients[i].code_postal,clients[i].num_de_tel,clients[i].adresse_mail,clients[i].profession);
        }
        i++;        
    }
}

void filtre(client clients[],char* mot_filtre,int choix_information,int nombre_client)
{
    int i=0;
    char* p;
    while (i< nombre_client){
        p=strstr((par_quoi_chercher(&clients[i],choix_information)),mot_filtre);
        if (p){
            printf("\n%s",p);
        }
        i++;        
    }
}
