//============================================================================
// Name        : RobienEngine.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>


int main() {
	std::cout << "Hello World !!!" << std::endl;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);

    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }


    SDL_Quit();

    return EXIT_SUCCESS;


}
