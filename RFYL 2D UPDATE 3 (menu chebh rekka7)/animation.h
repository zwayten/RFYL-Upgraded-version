#ifndef ANIMATION_H
#define ANIMATION_H


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL_ttf.h"
#include "background.h"


typedef struct animation
{
	SDL_Surface *tsawer[4];
	SDL_Surface *tsawerL[4];
	SDL_Rect pos_Sprite;
	int done;
	int direct;
	 int status;/*!<entier*/
    float x,y;/*!<reel*/
    float vx,vy;/*!<reel*/
}animation;

void Load_Resources(animation *perso1);


int animation_pers(animation *perso, SDL_Event event , int test_collision , int *i , int d , Background *BGnd);


#endif