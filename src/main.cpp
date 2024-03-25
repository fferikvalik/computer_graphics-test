#include "draw.h"
// TODO: Implement frame rate limiting for animation rendering.
// TODO: Implement dynamic window title update with current coordinates of the cardioid center and current FPS count.
// TODO: Implement rotation of the cardioid around a user-selected point, with a step size of 10 pixels per mouse click.
// TODO: Implement the ability to set the rotation point by clicking on a specific part of the screen.
// TODO: Implement the ability to set the radius within the program itself.

/**
 * @brief The main function of the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return int The exit status of the program.
 */
int main(int argc, char* argv[]) {
    if (!init()) {
        printf("Failed to initialize!\n");
        return 1;
    }

    loadedSurface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,

    0x00FF0000,// R
    0x0000FF00,// G
    0x000000FF,// B
    0x00000000);// alpha

    float a = 74;
    float x_move = 0;
    float y_move = 0;
    double alpha = 0;
    gTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

    if (nullptr == gTexture) {
        printf("Failed to load media!\n");
        close();
        return 1;
    }

    bool quit = false;
    while (!quit) {
        quit = !handleEvents(a, x_move, y_move, alpha);
        if (quit)
            break;
        render(a, x_move, y_move, alpha);
    }

    close();
    return 0;
}
