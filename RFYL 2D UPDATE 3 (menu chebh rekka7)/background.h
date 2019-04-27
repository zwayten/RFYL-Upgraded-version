#ifndef TACHE_BG_H
#define TACHE_BG_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL_ttf.h"



typedef struct window
{
	SDL_Surface *screen;
}window;


typedef struct background 
{
	SDL_Surface *B_grnd;
	SDL_Surface *B_grndMask;
	SDL_Rect posB_grnd;
	float vx,vy;
}Background;


typedef struct personnage
{
	SDL_Surface *Sprite;
	SDL_Rect pos_Sprite;
	int done;
}personnage;

void prepare_window(window *win);
void LoadRessources_backround(Background *BGnd);
int event_handling(personnage *perso , SDL_Event test_event , int r , int d);
void Launch_Music(Mix_Music *Music);


#endif