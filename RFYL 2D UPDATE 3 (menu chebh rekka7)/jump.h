#ifndef JUMP_H
#define JUMP_H



#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animation.h"

#define STAT_SOL 0
#define STAT_AIR 1

typedef struct
{
    int status;/*!<entier*/
    float x,y;/*!<reel*/
    float vx,vy;/*!<reel*/

    SDL_Rect pos;

    SDL_Surface *tsawer[4];
    SDL_Surface *tsawerL[4];
   
} Sprite;

void InitSprite(animation* Sp);
void Saute(animation* Sp,float impulsion);
void ControleSol(animation* Sp , Background *BGnd);
void Gravite(animation* Sp,float factgravite,float factsautmaintenu,Uint8* keys);
void Evolue(animation* Sp,Uint8* keys , int *i , int *d , Background *BGnd , int test_collision);

#endif