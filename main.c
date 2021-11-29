#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGHT 429
/*
on initialise le struct client,et on définis un type afin de ne pas tout recopier a chaque fois 
*/
typedef struct{
    char prenom[64];
    char nom[64];
    char ville[128];
    char code_postal[6];
    char num_de_tel[32];
    char adresse_mail[64];
    char profession[64];
} client;

int nombre_ligne(FILE* fp);
char* jusqua_virgule(FILE* fp, char* information, int a);


int main(){
/*
ouverture du fichier,on l'ouvre en lecture seulement.
si le fichier ne peut pas être ouvert (fp=NULL) on affiche un erreur dans le terminal.
*/ 
    FILE * fp;
    fp = fopen("annuaire5000.csv","r");
    if (fp==NULL)
    {
        printf("erreur lors de l'ouverture du fichier/n");
        return 1;
    }
    char str[MAX_LENGHT]; // on initialise un tableau qui peut contenir toute la taille de notre struct
    int n=0;

    fseek(fp,0,SEEK_SET);
    int nombre_client = nombre_ligne(fp);
    client* clients = malloc(nombre_client * sizeof(client));//attribuer la taille nécessaire
    /*char sans_virgules[128];*/

    // while (n<nombre_client){ // somme de la taille de chaque attribue d'un client + 6 * ',' + '\n'
    //     strcpy(clients[n].prenom, jusqua_virgule(fp, sans_virgule));
    //     // jusqua_virgule(fp, clients[n].prenom, 64);
    //     strcpy(clients[n].nom, jusqua_virgule(fp));
    //     strcpy(clients[n].adresse, jusqua_virgule(fp));
    //     strcpy(clients[n].num_de_tel, jusqua_virgule(fp));
    //     strcpy(clients[n].code_postal, jusqua_virgule(fp));
    //     strcpy(clients[n].adresse_mail, jusqua_virgule(fp));
    //     strcpy(clients[n].profession, jusqua_virgule(fp));
    //     n++;
    // }
    fseek(fp,0,SEEK_SET);
    while (n<nombre_client){ // somme de la taille de chaque attribue d'un client + 6 * ',' + '\n'
        jusqua_virgule(fp,clients[n].prenom, 64);
        jusqua_virgule(fp,clients[n].nom, 64);
        jusqua_virgule(fp,clients[n].ville, 64);
        jusqua_virgule(fp,clients[n].code_postal, 6);
        jusqua_virgule(fp,clients[n].num_de_tel, 32);
        jusqua_virgule(fp,clients[n].adresse_mail, 64);
        jusqua_virgule(fp,clients[n].profession, 64);
        n++;
    }



    /*printf("-----------------------------\n");
    for (int i = 0; i < 64; i++)
    {
        printf("%d = ", i);
        if(clients[1].prenom[i] == '\n'){printf("\\n");}
        else if(clients[1].prenom[i] == '\0'){printf("\\0");}
        else{printf("%c",clients[1].prenom[i]);}

        printf("\n");
    }*/

    

    fclose(fp);
    free(clients);
    return 0;
}

int nombre_ligne(FILE* fp){
    int nb_ligne = 0;
    fseek(fp, 0, SEEK_SET);
    char str[429];
    while(fgets(str,MAX_LENGHT,fp)!=NULL){
        nb_ligne++;
    }
    return nb_ligne;
}


/*
on retourne la chaine de caractére jusqua a la virgules,on return le resultat sans la chaine de caractére sans la virgule
*/
char* jusqua_virgule(FILE* fp, char* information, int a){
    char c;
    int i=0;
    while ((c=fgetc(fp))!= EOF &&  i<a && c!=',' && c!='\n'){
       information[i]=c;
       i++;
    }
    information[i]='\0';
    
}



afficher_tab(clients,nombre_client){
        int n = 0;
        while (n<nombre_client){ // somme de la taille de chaque attribue d'un client + 6 * ',' + '\n'
        printf("%s, %s, %s, %s, %s, %s, %s\n", clients[n].prenom, clients[n].nom,clients[n].ville, clients[n].code_postal,clients[n].num_de_tel, clients[n].adresse_mail, clients[n].profession);
        n++;
    }