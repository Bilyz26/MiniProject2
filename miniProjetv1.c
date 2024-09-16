#include <stdio.h>
#include <string.h>

#define MAX_LIVRES 100

typedef struct {
    char titre[100];
    char auteur[100];
    float prix;
    int quantite;
} Livre;

Livre stock[MAX_LIVRES];
int totalLivres = 0;

void ajouterLivre() {
    if (totalLivres < MAX_LIVRES) {
        printf("Entrez le titre du livre : ");
        scanf(" %[^\n]", stock[totalLivres].titre);
        printf("Entrez l'auteur du livre : ");
        scanf(" %[^\n]", stock[totalLivres].auteur);
        printf("Entrez le prix du livre : ");
        scanf("%f", &stock[totalLivres].prix);
        printf("Entrez la quantité en stock : ");
        scanf("%d", &stock[totalLivres].quantite);
        totalLivres++;
        printf("Livre ajouté avec succès.\n");
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
            printf("Titre : %s\n", stock[i].titre);
            printf("Auteur : %s\n", stock[i].auteur);
            printf("Prix : %.2f\n", stock[i].prix);
            printf("Quantité : %d\n\n", stock[i].quantite);
        }
    }
}

void rechercherLivre() {
    char titreRecherche[100];
    printf("Entrez le titre du livre à rechercher : ");
    scanf("%s", titreRecherche);

    for (int i = 0; i < totalLivres; i++) {
        if (strcmp(stock[i].titre, titreRecherche) == 0) {
            printf("Livre trouvé :\n");
            printf("Titre : %s\n", stock[i].titre);
            printf("Auteur : %s\n", stock[i].auteur);
            printf("Prix : %.2f\n", stock[i].prix);
            printf("Quantité : %d\n", stock[i].quantite);
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

void mettreAJourQuantite() {
    char titreRecherche[100];
    printf("Entrez le titre du livre à mettre à jour : ");
    scanf(" %[^\n]", titreRecherche);

    for (int i = 0; i < totalLivres; i++) {
        if (strcmp(stock[i].titre, titreRecherche) == 0) {
            printf("Entrez la nouvelle quantité : ");
            scanf("%d", &stock[i].quantite);
            printf("Quantité mise à jour avec succès.\n");
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

void supprimerLivre() {
    char titreRecherche[100];
    printf("Entrez le titre du livre à supprimer : ");
    scanf(" %[^\n]", titreRecherche);

    for (int i = 0; i < totalLivres; i++) {
        if (strcmp(stock[i].titre, titreRecherche) == 0) {
            for (int j = i; j < totalLivres - 1; j++) {
                stock[j] = stock[j + 1];
            }
            totalLivres--;
            printf("Livre supprimé avec succès.\n");
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

void afficherNombreTotal() {
    int totalQuantites = 0;
    for (int i = 0; i < totalLivres; i++) {
        totalQuantites += stock[i].quantite;
    }
    printf("Nombre total de livres en stock : %d\n", totalQuantites);
}

int main() {
    int choix;

    do {
        printf("\n----- Système de Gestion de Stock de Librairie -----\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres disponibles\n");
        printf("3. Rechercher un livre par son titre\n");
        printf("4. Mettre à jour la quantité d'un livre\n");
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
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix != 7);

    return 0;
}
