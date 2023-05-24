#include "game.h"
#include "game.c"

int main() {
    Game game;
    initGame(&game);
    playGame(&game);
    return 0;
}
