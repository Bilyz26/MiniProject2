#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    int num;
    char c;

    // 1. Utilisation de fgets() pour lire une ligne enti�re
    printf("Entrez une phrase : ");
    fgets(input, sizeof(input), stdin);
    printf("Lu : %s", input);

    // 2. Utilisation de scanf() pour lire un nombre
    printf("Entrez un nombre : ");
    scanf("%d", &num);
    printf("Nombre entr� : %d\n", num);

    // Nettoyage de l'entr�e apr�s scanf
    while ((c = getchar()) != '\n' && c != EOF);

    // 3. Utilisation de getchar() pour lire un seul caract�re
    printf("Entrez un caract�re : ");
    c = getchar();
    printf("Caract�re entr� : %c\n", c);

    // 4. V�rification de la fin du fichier (utile lors de la redirection)
    printf("Entrez du texte (appuyez sur Ctrl+D pour terminer) :\n");
    while (fgets(input, sizeof(input), stdin) != NULL) {
        printf("Lu : %s", input);
    }
    if (feof(stdin)) {
        printf("Fin des entr�es atteinte.\n");
    }

    return 0;
}
