#ifndef MENU_H
#define MENU_H
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"

typedef struct menu
{
	//Déclaration des variables :
SDL_Surface *screen_menu;
SDL_Surface *background_menu;
SDL_Surface *boutton1_menu;
SDL_Surface *boutton1_Active_menu;
SDL_Surface *boutton2_menu;
SDL_Surface *boutton2_Active_menu;
SDL_Surface *boutton3_menu;
SDL_Surface *boutton3_Active_menu;
SDL_Surface *boutton_exit_menu;
SDL_Surface *boutton_exit_Active_menu;
SDL_Surface *cursor;
SDL_Surface *tmp;

//Déclaration des positions :
SDL_Rect position_background_menu;
SDL_Rect position_Boutton1;
SDL_Rect position_Boutton2;
SDL_Rect position_Boutton3;
SDL_Rect position_Boutton_exit;
SDL_Rect position_Click;
SDL_Rect position_click1;

//Déclaration des variables de son : 
Mix_Music *music_background_menu;
Mix_Chunk *sound_effect;

SDL_Event event_menu;
int bt_menu;

int done_menu;


}menu;

int menu_jeux(menu *menu);

#endif