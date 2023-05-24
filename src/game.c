#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int compare(int number1, int number2) {
    if (number1 < number2) {
        printf("Plus grand !\n");
        return -1;
    } else if (number1 > number2) {
        printf("Plus petit !\n");
        return 1;
    } else {
        printf("Vous avez trouvé le nombre !\n");
        return 0;
    }
}

typedef struct {
    int secretNumber;
    int guessCount;
} Game;

//Initialiser une nouvelle partie
void initGame(Game* game) {
    int choice;
    int difficulte;
    printf("1:Facile(0-10) 2:Normal(0-100) 3:Difficile(0-1000)\nChoisir un niveau de difficulté:");
    while (scanf("%d", &choice) != 1 || (choice < 1 || choice > 3)) {
        printf("Erreur : niveau de difficulté invalide. Réessayez : ");

        // Effacer le contenu du flux d'entrée
        while (getchar() != '\n')
            continue;
    }
        switch (choice){
            case 1:
                difficulte=10;
                printf("Mode Facile choisi");
                break;
            case 2:
                difficulte=100;
                printf("Mode Normal choisi");
                break;
            case 3:
                difficulte=1000;
                printf("Mode Difficile choisi");
                break;

        }
    srand(time(NULL));
    game->secretNumber = rand() % difficulte + 1; //Initialise le code a trouver
    game->guessCount = 0;
}

// Fonction pour jouer une partie
void playGame(Game* game) {
    int guess;
    int result;
    int scanfResult;
     do {
        printf("\nDevinez le nombre : ");
        scanfResult = scanf("%d", &guess);

        // Vérif si l'entier à été lu
        if (scanfResult == 1) {
            result = compare(guess, game->secretNumber);
            game->guessCount++;
        } else { //Si l'entré ne correspond pas a un nombre...
            printf("Erreur : Veuillez saisir un nombre entier valide.\n");
            // Effacer le contenu du flux d'entrée
            while (getchar() != '\n')
                continue;
            result = -1;  // Pour continuer la boucle et redemander la saisie
        }
    } while (result != 0);
    printf("Vous avez trouvé en %d coups !\n", game->guessCount);
}
