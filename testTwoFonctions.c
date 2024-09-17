#include <stdio.h>
#include <string.h>

// Limite des livres
#define MAX_LIVRES 100

// Variables globales
char titres[MAX_LIVRES][100] = {"Habits", "Hobbit", "Harry Potter", "Lord of the Rings", "Hbm Adventures"};
char auteurs[MAX_LIVRES][100] = {"John Doe", "J.R.R. Tolkien", "J.K. Rowling", "J.R.R. Tolkien", "Jane Smith"};
float prix[MAX_LIVRES] = {9.99, 15.99, 25.00, 30.50, 12.75};
int quantites[MAX_LIVRES] = {10, 5, 8, 3, 7};
int totalLivres = 5;  // Nombre de livres initialisé à 5

// Fonction pour rechercher un livre par une partie du titre (ordre important)
void rechercherLivrePartiel(char *recherche) {
    int tailleRecherche = strlen(recherche);

    printf("Livres correspondant au début \"%s\" :\n", recherche);

    for (int i = 0; i < totalLivres; i++) {
        int correspondance = 1;

        // Comparaison caractère par caractère
        for (int j = 0; j < tailleRecherche; j++) {
            if (titres[i][j] != recherche[j]) {
                correspondance = 0;
                break;
            }
        }

        if (correspondance) {
            printf("Titre : %s\n", titres[i]);
            printf("Auteur : %s\n", auteurs[i]);
            printf("Prix : %.2f\n", prix[i]);
            printf("Quantité : %d\n\n", quantites[i]);
        }
    }
}

// Fonction pour rechercher un livre par une partie du titre sans ordre spécifique
void rechercherLivreSansOrdre(char *recherche) {
    int tailleRecherche = strlen(recherche);

    printf("Livres contenant les lettres \"%s\" (ordre non important) :\n", recherche);

    for (int i = 0; i < totalLivres; i++) {
        int correspondance = 1;
        int lettresTrouvees[tailleRecherche];
        memset(lettresTrouvees, 0, tailleRecherche * sizeof(int));

        for (int j = 0; j < tailleRecherche; j++) {
            int trouve = 0;

            for (int k = 0; titres[i][k] != '\0'; k++) {
                if (recherche[j] == titres[i][k] && lettresTrouvees[j] == 0) {
                    trouve = 1;
                    lettresTrouvees[j] = 1;
                    break;
                }
            }

            if (!trouve) {
                correspondance = 0;
                break;
            }
        }

        if (correspondance) {
            printf("Titre : %s\n", titres[i]);
            printf("Auteur : %s\n", auteurs[i]);
            printf("Prix : %.2f\n", prix[i]);
            printf("Quantité : %d\n\n", quantites[i]);
        }
    }
}

int main() {
    char recherche[100];
    int choix;

    printf("Système de recherche de livres\n");
    printf("1. Rechercher un livre avec l'ordre des lettres important\n");
    printf("2. Rechercher un livre sans ordre des lettres\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);
    getchar();  // Consommer le caractère newline

    printf("Entrez les lettres à rechercher : ");
    fgets(recherche, sizeof(recherche), stdin);
    recherche[strcspn(recherche, "\n")] = '\0';  // Supprimer le saut de ligne

    switch (choix) {
        case 1:
            rechercherLivrePartiel(recherche);
            break;
        case 2:
            rechercherLivreSansOrdre(recherche);
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }

    return 0;
}
