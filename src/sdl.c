#include "lemipc.h"
#include "../include/lemipc.h"

void    pausee(void)
{
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
}

int     process(t_data *data)
{
    SDL_Surface     playeurs;
    SDL_Rect        position;
    unsigned char map[64];
    int     x;
    int     y;

    map = data->map->tab;
    while (x < SIZE)
    {
        if(map[i] == 1)
            SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 50, 50, 50);
    }

}

int     show(t_data *data)
{
    SDL_Surface     *ecran = NULL;
    SDL_Surface     *rectangle[];

    char            tab[64];

    int i, j = 0;
    int x = data->pos % MAP_WIDTH;
    int y = data->pos / MAP_WIDTH;

    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    ecran = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("LemIPC de ouf !", NULL);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 25, 25, 25));


    SDL_Flip(ecran);
    pause();
    for (i = 0 ; i <= data->map->nb_gamer ; i++)
        SDL_FreeSurface(rectangle[i]);
    SDL_Quit();
    return EXIT_SUCCESS;
};
