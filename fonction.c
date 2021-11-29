void menu_principal()
{
    int choix;
    printf("==========================[menu principal]======================\n1)charger fichier\n2)afficher tout les clients\n3)ajouter un client dans l'annuaire\n4)supprimer un client de l'annuaire");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        char *nom_fichier;
        printf("rentrer le nom de votre fichier")
        scanf("%s", *nom_fichier);
        charger_fichier(nom_fichier);

        break;
    case 2:
        
    case 3:

    case 4:

    case 5:

    case 6:

    case 7:

    case 8:

    case 9:

    case 10:

    default:
        break;
    }
}

int charger_fichier(char *nom_fichier)
{
    FILE *fp = fopen(nom_fichier, "r");
    int nombre_client = nombre_ligne(fp);
    client *clients = malloc(nombre_client * sizeof(client));

    if (fp)
    {
        char ligne[MAX_LENGHT];
        char *token;
        char *separateur = ",";
        int index = 0;

        fseek(fp, 0, SEEK_SET);
        while (fgets(ligne, MAX_LENGHT, fp) != NULL)
        {

            char *copie_ligne = strdup(ligne); //dupliquer la chaîne ligne avec strdupa car le strsep modifie
                                               //le pointeur passé, et nous ne voulons pas perdre la valeur d’origine

            token = strsep(&copie_ligne, ",");
            if (*token != '\n' && token != NULL)
            {
                strcpy(clients[index].prenom, token);
            }
            token = strsep(&copie_ligne, ",");
            if (*token != '\n' && token != NULL)
            {
                strcpy(clients[index].nom, token);
            }
            token = strsep(&copie_ligne, ",");
            if (*token != '\n' && token != NULL)
            {
                strcpy(clients[index].ville, token);
            }
            token = strsep(&copie_ligne, ",");
            if (*token != '\n' && token != NULL)
            {
                strcpy(clients[index].code_postal, token);
            }
            token = strsep(&copie_ligne, ",");
            if (*token != '\n' && token != NULL)
            {
                strcpy(clients[index].num_de_tel, token);
            }
            token = strsep(&copie_ligne, ",");
            if (*token != '\n' && token != NULL)
            {
                strcpy(clients[index].adresse_mail, token);
            }
            token = strsep(&copie_ligne, ",");
            if (*token != '\n' && token != NULL)
            {
                strcpy(clients[index].profession, token);
            }

            index++;
        }
        fclose(fp);
    }

    int nombre_ligne(FILE * fp)
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

    void print_tableau(client * clients, int nombre_client)
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

    agrandir_tableau(client * *clients, int taille_augmenter, int nombre_client)
    {
        client *temporaire = *clients;
        *clients = malloc((nombre_client + taille_augmenter) * sizeof(client));
        memcpy(*clients, temporaire, nombre_client * sizeof(client));
        free(temporaire);
    }

    void ajouter_client(client * clients, int nombre_client)
    {
        agrandir_tableau(client * clients, 1, nombre_client); //on agrandit le tableau afin d'ajouter un nouveau client.

        printf("saisisser le prénom du client que vous souhaitez ajouter :");
        scanf("%s", client[nombre_client].prenom);
        printf("saisisser son nom : ");
        scanf("%s", client[nombre_client].nom);
        printf("saisisser sa ville : ");
        scanf("%s", client[nombre_client].ville);
        printf("saisisser son code postal : ");
        scanf("%s", client[nombre_client].code_postal);
        printf("saisisser son numéro de téléphone : ");
        scanf("%s", client[nombre_client].num_de_tel);
        printf("saisisser son adresse mail : ");
        scanf("%s", client[nombre_client].adresse_mail);
        printf("saisisser sa profession : ");
        scanf("%s", client[nombre_client].profession);

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
            scanf("%s", clients[choix_client]->prenom);
            break;
        case 2:
            printf("rentrer le nouveau nom de votre client");
            scanf("%s", clients[choix_client]->nom);
            break;
        case 3:
            printf("rentrer la nouvelle ville de votre client");
            scanf("%s", clients[choix_client]->ville);
            break;
        case 4:
            printf("rentrer le nouveau code postal de votre client");
            scanf("%s", clients[choix_client]->code_postal);
            break;
        case 5:
            printf("rentrer le nouveau nouveau numéros de téléphone de votre client");
            scanf("%s", clients[choix_client]->num_de_tel);
            break;
        case 6:
            printf("rentrer la nouvelle adresse email de votre client");
            scanf("%s", clients[choix_client]->adresse_mail);
            break;
        case 7:
            printf("rentrer la nouvelle profession de votre client");
            scanf("%s", clients[choix_client]->profession);
            break;
        default:
            printf("le choix entrer n'est pas valide");
            break;
        }
        printf("vos changement on bien été effectuer");
    }

    int supprimer_client(client * clients)
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
