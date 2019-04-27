#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "time.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>



void LoadRessources_enemy(Enemy_anim *enemy)
{
    int j;
	enemy->enemy_Right[0] = NULL;
	enemy->enemy_Right[1] = NULL;
	enemy->enemy_Right[2] = NULL;
	enemy->enemy_Right[3] = NULL;

	enemy->enemy_Left[0] = NULL;
	enemy->enemy_Left[1] = NULL;
	enemy->enemy_Left[2] = NULL;
	enemy->enemy_Left[3] = NULL;

	enemy->enemy_Left[0]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/Enemies/555.png"));
	enemy->enemy_Left[1]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/Enemies/666.png"));
	enemy->enemy_Left[2]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/Enemies/777.png"));
	enemy->enemy_Left[3]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/Enemies/888.png"));
  
	enemy->enemy_Right[0]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/Enemies/111.png"));
	enemy->enemy_Right[1]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/Enemies/222.png"));
	enemy->enemy_Right[2]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/Enemies/333.png"));
	enemy->enemy_Right[3]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/Enemies/444.png"));
   
   
}

void LoadRessources_Object(object *obj)
{
	obj->obj_pto = NULL;
	obj->obj_pto=SDL_LoadBMP("Graphics/objects&&HUD/harbouch.bmp");
    SDL_SetColorKey( obj->obj_pto,SDL_SRCCOLORKEY,SDL_MapRGB(obj->obj_pto->format,255,255,255));
}

void Load_HudRessources(HUD *ATH)
{
	ATH->HUD_vie = NULL;
	ATH->HUD_etoiles = NULL;

	ATH->HUD_vie=IMG_Load("Graphics/objects&&HUD/life.png");
	ATH->HUD_etoiles=IMG_Load("Graphics/objects&&HUD/stars.png");
}

SDL_Surface* afficher_objetpng( int x,int y, SDL_Surface *image ,SDL_Surface *ecran )
{
SDL_Rect pous;
pous.x=x;
pous.y=y;
SDL_BlitSurface(image,NULL,ecran,&pous);
return (image);
}

TTF_Font *loadFont(char *name, int size)
{
    // Utilise SDL_TTF pour charger la police à la taille désirée 

    TTF_Font *font = TTF_OpenFont(name, size);

    if (font == NULL)
    {
        printf("Failed to open Font %s: %s\n", name, TTF_GetError());
        exit(1);
    }

    return font;
}



void drawString(char *text, int x, int y, TTF_Font *font, SDL_Surface *ecran)
{
    SDL_Rect dest;
    SDL_Surface *surface;
    SDL_Color foregroundColor;
    /* On choisit d'écrire le texte en noir */
    foregroundColor.r = 255;
    foregroundColor.g = 25;
    foregroundColor.b = 36;
    /* On utilise SDL_TTF pour générer une SDL_Surface à partir d'une chaîne de caractères (string) */
    surface = TTF_RenderUTF8_Blended(font, text, foregroundColor);

    /* On blitte cette SDL_Surface à l'écran */
    dest.x = x;
    dest.y = y;
    dest.w = surface->w;
    dest.h = surface->h;
    SDL_BlitSurface(surface, NULL, ecran, &dest);
    /* On libère la SDL_Surface temporaire (pour éviter les fuites de mémoire - cf. chapitre dédié) */
    SDL_FreeSurface(surface);
}



 int collize (SDL_Rect detective, SDL_Rect ennemi)
 {
  int s;
    //On teste pour voir s'il y a  collision, si c'est le cas, on renvoie 1
    if ((detective.x >= ennemi.x ) && (detective.x  <= ennemi.x + ennemi.w) && (detective.y >= ennemi.y )&& (detective.y <= ennemi.y + detective.h ))
       s=1;
   else
     s=0 ;
    return s;
}
  



void afficher_objetx( int x,int y,SDL_Surface *en_anim ,SDL_Surface *ecran)
{
SDL_Rect pos;
pos.x=x;
pos.y=y;
 SDL_BlitSurface(en_anim,NULL,ecran,&pos);
}
