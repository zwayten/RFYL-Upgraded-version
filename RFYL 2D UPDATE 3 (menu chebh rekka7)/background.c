#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL_ttf.h"
#include"background.h"
#include"menu.h"




void LoadRessources_backround(Background *BGnd)
{
  //Background du jeux :
  BGnd->B_grnd=NULL;  
  BGnd->B_grnd = SDL_DisplayFormat(IMG_Load("Graphics/Background/bg6-small.png"));

  //Background masque (les obstacles sont recouverts avec la couleur Perfect_Blue'0.0.255') :
  BGnd->B_grndMask=NULL; 
  BGnd->B_grndMask = SDL_DisplayFormat(IMG_Load("Graphics/Background/bg7-small.png"));
}




void prepare_window(window *win)
{
  const SDL_VideoInfo *pinfo;
  pinfo = SDL_GetVideoInfo();
  int Bpp ;   
  Bpp = pinfo->vfmt->BitsPerPixel;
  win->screen = NULL;
  win->screen= SDL_SetVideoMode(1800,800, Bpp ,  SDL_HWSURFACE | SDL_DOUBLEBUF );
    SDL_WM_SetCaption(" GAME !", NULL);
}


int event_handling(personnage *perso ,  SDL_Event test_event , int r , int d)
{
  
  
  switch(test_event.type) 
    {
    case SDL_QUIT: 
    perso->done = 0; 
    break;
    case SDL_KEYDOWN: 
      
      switch(test_event.key.keysym.sym)
      {
      case SDLK_ESCAPE: 
      perso->done=0;
      break;

      case SDLK_UP: 
      {
      perso->pos_Sprite.y-=2;
      d=2;
      
      if (r==1)
      {
          perso->pos_Sprite.y+=2;
              
      }
  
      }
       break;

      case SDLK_DOWN: // Flèche bas
      {
       perso->pos_Sprite.y+=2;
      d=3;
      
      if (r==1)
      {
       perso->pos_Sprite.y-=2;       
      }
      } 
      break;

      case SDLK_RIGHT: // Flèche droite
      { 
      perso->pos_Sprite.x+=2;
      d=0;
      
      if (r==1)
      {
      perso->pos_Sprite.x-=2;
              
      }
      } 
       break;

      case SDLK_LEFT: // Flèche gauche
      {
      perso->pos_Sprite.x-=2;
      d=1;
      
      if (r==1)
      {
      perso->pos_Sprite.x+=2;
              
      }
      
      }
                    
      }

    break;

    }
    return d;
}



void Launch_Music(Mix_Music *Music)
{
  Music=Mix_LoadMUS("Audio/music.mp3");
  Mix_PlayMusic(Music, -1);
}




