
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "jump.h"
#include "background.h"

void InitSprite(animation* Sp)
{
    Sp->pos_Sprite.y = 537.0f;
    Sp->status = STAT_SOL;
    Sp->vx = Sp->vy = 0.0f;
}


void Saute(animation* Sp,float impulsion)
{
    Sp->vy = -impulsion;
    Sp->status = STAT_AIR;
}

void ControleSol(animation* Sp , Background *BGnd)
{

    if (Sp->pos_Sprite.y>530.0f) //sol
    {
        Sp->pos_Sprite.y = 530.0f; //sol 
        if (Sp->vy>0)
            Sp->vy = 0.0f;
        Sp->status = STAT_SOL;
    }

    if (Sp->pos_Sprite.x>825.0f - BGnd->posB_grnd.x  && Sp->pos_Sprite.x<850 - BGnd->posB_grnd.x  && Sp->pos_Sprite.y==530.0f) //sol
    {
        Sp->pos_Sprite.y = 800.0f; //sol 
        if (Sp->vy>0)
           Sp->vy = 0.0f;
        Sp->status = STAT_SOL;
        
    }
}

// controler la laongueur du saut :
void Gravite(animation* Sp,float factgravite,float factsautmaintenu,Uint8* keys)
{
    if (Sp->status == STAT_AIR && keys[SDLK_SPACE])
        factgravite/=factsautmaintenu;
    Sp->vy += factgravite;
}

void Evolue(animation* Sp,Uint8* keys , int *i , int *d , Background *BGnd ,int test_collision)
{
    float lateralspeed = 0.5f;
    float airlateralspeedfacteur = 10.5f;
    //vitesse du personnage
    float maxhspeed = 4.0f;
    // adherance bech yetza7le9 :
    float adherance = 1.15f;
    float impulsion = 10.0f;
    //factgravite bech yraka7 el gravité :
    float factgravite = 0.8f;
    float factsautmaintenu = 3.0f;
// controle lateral
    if((*i)==3)
    {
        (*i)=0;
    }

    if (keys[SDLK_ESCAPE])
    {
        Sp->done=0;
    }
    if (Sp->status == STAT_AIR) // (*2)
        lateralspeed*= airlateralspeedfacteur;
    if (keys[SDLK_LEFT] && !keys[SDLK_SPACE] ) // (*1)
        {
            (*d)=1;
            (*i)++;
        Sp->vx-=lateralspeed;
        if(test_collision==1 || test_collision==2)
        {
        	Sp->vx+=Sp->pos_Sprite.x;
        }
       // BGnd->posB_grnd.x = Sp->pos_Sprite.x;
        }
    if (keys[SDLK_RIGHT] && !keys[SDLK_SPACE])
    {
        (*d)=0;
        Sp->vx+=lateralspeed;
        if(test_collision==1 || test_collision==2)
        {
        Sp->vx-=Sp->pos_Sprite.x;
        }
        (*i)++;

        //BGnd->posB_grnd.x = Sp->pos_Sprite.x;
    }
    if (Sp->status == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
        Sp->vx/=adherance;
// limite vitesse
    if (Sp->vx>maxhspeed) // (*4)
        Sp->vx = maxhspeed;
    if (Sp->vx<-maxhspeed)
        Sp->vx = -maxhspeed;


    if (BGnd->posB_grnd.x>maxhspeed) // (*4)
        BGnd->posB_grnd.x = maxhspeed;
    if (BGnd->posB_grnd.x<-maxhspeed)
        BGnd->posB_grnd.x = -maxhspeed;
// saut
    if (keys[SDLK_SPACE] && Sp->status == STAT_SOL)
    {
        (*d)=3;
        Saute(Sp,impulsion);
        if(test_collision==1 || test_collision==2)
        {
        	Sp->vy-=Sp->vy;
        }
    }

   

   
// application du vecteur à la position.
    Sp->pos_Sprite.x +=Sp->vx;
    Sp->pos_Sprite.y +=Sp->vy;
    BGnd->posB_grnd.x += Sp->pos_Sprite.x;
    
    Gravite(Sp,factgravite,factsautmaintenu,keys);
    ControleSol(Sp,BGnd);

}
