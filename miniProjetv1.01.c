#include <stdio.h>
#include <string.h>

#define MAX_LIVRES 100
#define MAX_CHAINE 100

char titres[MAX_LIVRES][MAX_CHAINE];
char auteurs[MAX_LIVRES][MAX_CHAINE];
float prix[MAX_LIVRES];
int quantites[MAX_LIVRES];
int totalLivres = 0;

void ajouterLivre() {
    if (totalLivres < MAX_LIVRES) {
        printf("Entrez le titre du livre : ");
        scanf(" %[^\n]", titres[totalLivres]);
        printf("Entrez l'auteur du livre : ");
        scanf(" %[^\n]", auteurs[totalLivres]);
        printf("Entrez le prix du livre : ");
        scanf("%f", &prix[totalLivres]);
        printf("Entrez la quantit� en stock : ");
        scanf("%d", &quantites[totalLivres]);
        totalLivres++;
        printf("Livre ajout� avec succ�s.\n");
    } else {
        printf("Stock plein. Impossible d'ajouter un autre livre.\n");
    }
}

void afficherLivres() {
    if (totalLivres == 0) {
        printf("Aucun livre en stock.\n");
    } else {
        printf("Liste des livres disponibles :\n");
        for (int i = 0; i < totalLivres; i++) {
            printf("Livre %d :\n", i + 1);
            printf("Titre : %s\n", titres[i]);
            printf("Auteur : %s\n", auteurs[i]);
            printf("Prix : %.2f\n", prix[i]);
            printf("Quantit� : %d\n\n", quantites[i]);
        }
    }
}

void rechercherLivre() {
    char titreRecherche[MAX_CHAINE];
    printf("Entrez le titre du livre � rechercher : ");
    scanf(" %[^\n]", titreRecherche);

    for (int i = 0; i < totalLivres; i++) {
        if (strcmp(titres[i], titreRecherche) == 0) {
            printf("Livre trouv� :\n");
            printf("Titre : %s\n", titres[i]);
            printf("Auteur : %s\n", auteurs[i]);
            printf("Prix : %.2f\n", prix[i]);
            printf("Quantit� : %d\n", quantites[i]);
            return;
        }
    }
    printf("Livre non trouv�.\n");
}

void mettreAJourQuantite() {
    char titreRecherche[MAX_CHAINE];
    printf("Entrez le titre du livre � mettre � jour : ");
    scanf(" %[^\n]", titreRecherche);

    for (int i = 0; i < totalLivres; i++) {
        if (strcmp(titres[i], titreRecherche) == 0) {
            printf("Entrez la nouvelle quantit� : ");
            scanf("%d", &quantites[i]);
            printf("Quantit� mise � jour avec succ�s.\n");
            return;
        }
    }
    printf("Livre non trouv�.\n");
}

void supprimerLivre() {
    char titreRecherche[MAX_CHAINE];
    printf("Entrez le titre du livre � supprimer : ");
    scanf(" %[^\n]", titreRecherche);

    for (int i = 0; i < totalLivres; i++) {
        if (strcmp(titres[i], titreRecherche) == 0) {
            for (int j = i; j < totalLivres - 1; j++) {
                strcpy(titres[j], titres[j + 1]);
                strcpy(auteurs[j], auteurs[j + 1]);
                prix[j] = prix[j + 1];
                quantites[j] = quantites[j + 1];
            }
            totalLivres--;
            printf("Livre supprim� avec succ�s.\n");
            return;
        }
    }
    printf("Livre non trouv�.\n");
}

void afficherNombreTotal() {
    int totalQuantites = 0;
    for (int i = 0; i < totalLivres; i++) {
        totalQuantites += quantites[i];
    }
    printf("Nombre total de livres en stock : %d\n", totalQuantites);
}

int main() {
    int choix;

    do {
        printf("\n----- Syst�me de Gestion de Stock de Librairie -----\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres disponibles\n");
        printf("3. Rechercher un livre par son titre\n");
        printf("4. Mettre � jour la quantit� d'un livre\n");
        printf("5. Supprimer un livre\n");
        printf("6. Afficher le nombre total de livres en stock\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterLivre();
                break;
            case 2:
                afficherLivres();
                break;
            case 3:
                rechercherLivre();
                break;
            case 4:
                mettreAJourQuantite();
                break;
            case 5:
                supprimerLivre();
                break;
            case 6:
                afficherNombreTotal();
                break;
            case 7:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide, veuillez r�essayer.\n");
        }
    } while (choix != 7);

    return 0;
}
