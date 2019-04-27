#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

typedef struct Enemy_anim
{
	SDL_Surface *enemy_Right[4];
	SDL_Surface *enemy_Left[4];
	SDL_Rect pos_enemy;
}Enemy_anim;

typedef struct object
{
	SDL_Surface *obj_pto;
	SDL_Rect pos_obj;
}object;

typedef struct HUD
{
	SDL_Surface *HUD_vie;
	SDL_Surface *HUD_etoiles;
	//SDL_Surface *texte;
}HUD;




void LoadRessources_enemy(Enemy_anim *enemy);
void Load_HudRessources(HUD *ATH);
void LoadRessources_Object(object *obj);

void afficher_objetx( int x,int y, SDL_Surface *en_anim ,SDL_Surface *ecran);

SDL_Surface* afficher_objetpng( int x,int y, SDL_Surface *image ,SDL_Surface *ecran );



TTF_Font *loadFont(char *name, int size);
void closeFont(TTF_Font *font);
void drawString(char *text, int x, int y, TTF_Font *font, SDL_Surface *ecran);
int collize (SDL_Rect detective, SDL_Rect ennemi);

#endif /* FONCTIONS_H_ */
