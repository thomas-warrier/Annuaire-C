#include "tri.h"


// fonction pour permuter les elements
void permuter(client *c1, client *c2) 
{
    /* 
    entrée: deux pointeurs sur des structures client
    précond: aucune
    post-cond: permute les deux structures passées en paramètre
    sortie: aucune 
    */
    client c3 = *c1;
    *c1=*c2;
    *c2=c3;
}


int trier_sur()
{
    /* 
    entrée: aucune
    précond: aucune
    post-cond: lit un entier au clavier et retourne cet entier
    sortie: entier 
    */
    int choix_information;
    printf("================[par quelle information souhaitez vous trier ?]=======================\n1)prenom\n2)nom\n3)code postal\n4)profession\n");
    scanf("%d", &choix_information);
    return choix_information;
}

char* par_quoi_trier(client *clients,int choix_information)
{  
    /* 
    entrée: un pointeur sur une structure client et un entier
    précond: l'entier doit être compris entre 1 et 4 
    post-cond: retourne selon l'entier passé en paramètre un pointeur sur un élément de la structure client
    sortie: pointeur sur une chaîne de caractère 
    */
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

// function qui permet de retrouver la position de la partition
int partition(client *clients, int debut, int fin, int choix_information){

    int resultat_comparaison = 0;
  
    // sélectionner l'élément le plus à droite comme pivot
    client pivot = clients[fin];
    
    // pointeur pour un élément plus grand
    int i = (debut - 1);

    // parcourir chaque élément du tableau et les comparer avec le pivot
    for (int j = debut; j < fin; j++){

        resultat_comparaison = strcmp(
                par_quoi_trier(&clients[j],choix_information),
                par_quoi_trier(&pivot,choix_information)
            );

        if( resultat_comparaison <= 0 ){
            // si un élément plus petit que le pivot est trouvé, il est échangé avec l'élément plus grand pointé par i
            i++;
            // échanger l'élément en i avec l'élément en j
            permuter(&clients[i], &clients[j]);
        }
    }

    // échanger l'élément pivot avec l'élément le plus grand à i
    permuter(&clients[i + 1], &clients[fin]);
    
    // retourne la postion du point de partition
    return (i + 1);
}

void tri_rapide(client *clients, int debut, int fin, int choix_information){
    if( debut < fin ){
        
        // trouver l'élément pivot tel que
        // les éléments plus petits que le pivot sont à gauche du pivot
        // les éléments supérieurs au pivot sont à droite du pivot.
        int pivot = partition(clients, debut, fin, choix_information);
        
        // appel récursif à gauche du pivot
        tri_rapide(clients, debut, pivot - 1, choix_information);
        
        // appel récursif à droite du pivot
        tri_rapide(clients, pivot + 1, fin, choix_information);
    }
}