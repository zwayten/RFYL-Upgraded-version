#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL_ttf.h"
#include"animation.h"

void Load_Resources(animation *perso1)
{
  perso1->tsawer[0]=NULL;
  perso1->tsawer[1]=NULL;
  perso1->tsawer[2]=NULL;
  perso1->tsawer[3]=NULL;
  
  perso1->tsawerL[0]=NULL;
  perso1->tsawerL[1]=NULL;
  perso1->tsawerL[2]=NULL;
  perso1->tsawerL[3]=NULL;


  perso1->tsawer[0]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/AnimationPerso/imin1.png"));
  perso1->tsawer[1]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/AnimationPerso/imin2.png"));
  perso1->tsawer[2]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/AnimationPerso/imin3.png"));
  perso1->tsawer[3]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/AnimationPerso/imin4.png"));

  

  perso1->tsawerL[0]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/AnimationPerso/isar1.png"));
  perso1->tsawerL[1]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/AnimationPerso/isar2.png"));
  perso1->tsawerL[2]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/AnimationPerso/isar3.png"));
  perso1->tsawerL[3]=SDL_DisplayFormatAlpha(IMG_Load("Graphics/AnimationPerso/isar4.png"));

}



int animation_pers(animation *perso, SDL_Event event_anim , int test_collision , int *i ,int d , Background *BGnd)
{

	switch(event_anim.type)
    {
    case SDL_QUIT:
    perso->done = 0;
    break;
		case SDL_MOUSEMOTION:
			{
				/*while (test_collision==0)
				{
					printf("%d \n",current.x);//=perso->pos_Sprite.x;
					printf("%d \n",current.y);//=perso->pos_Sprite.y;
				}*/
				perso->pos_Sprite.x= event_anim.motion.x;
				perso->pos_Sprite.y= event_anim.motion.y;
				if((test_collision==1) || (test_collision==2))
				{
					SDL_WarpMouse(20,537);
				}
			}
    case SDL_KEYDOWN:

      switch(event_anim.key.keysym.sym)
      {
      case SDLK_ESCAPE:
      perso->done=0;
      break;

      case SDLK_UP:
      {
      perso->pos_Sprite.y-=5;

      if(test_collision==1)
      {
        perso->pos_Sprite.y+=5;
      }
      }
       break;

      case SDLK_DOWN: // Flèche bas
      {
       perso->pos_Sprite.y+=5;
       d=3;
      if(test_collision==1)
      {
        perso->pos_Sprite.y-=5;
      }
      }
      break;

      case SDLK_RIGHT: // Flèche droite
      {
      perso->pos_Sprite.x+=1;
      BGnd->posB_grnd.x+=5;
      d=0;
      (*i)++;
      if(test_collision==1)
      {
        perso->pos_Sprite.x-=1;
        BGnd->posB_grnd.x-=5;
      }


    }
       break;

      case SDLK_LEFT: // Flèche gauche
      {
      perso->pos_Sprite.x-=1;
      BGnd->posB_grnd.x-=5;
      d=1;
      (*i)++;
      if(test_collision==1)
      {
        perso->pos_Sprite.x+=1;
        BGnd->posB_grnd.x+=5;
      }

      }
        break;
      }
    }
    return d;
}
