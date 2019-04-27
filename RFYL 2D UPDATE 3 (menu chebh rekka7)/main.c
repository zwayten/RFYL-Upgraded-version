#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL_ttf.h"
#include"background.h"
#include"perfect_collide.h"
#include"menu.h"
#include"animation.h"
#include"time.h"
#include"jump.h"





int main(void)
{

SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
SDL_Init(SDL_INIT_AUDIO);

int num_image=1;
int position_save=0;
Uint32 t1=0;
Uint32 t2=0;
int k=1;
int s=0;
int test2=0,test3=0;
int test=0;
int colli=0;
int vies;
int etoiles;
int j=0;
int i=0; // : compteur pour parcourir les case des tableauw perso1.tsawer et perso1.tsawerL
int test_collision=0; // : test de collision : (retour de la fonction perfect_collision)
//variables pour lobtention d'un fps stable :
int now = 0;
int periodeFps = 33;
int ex = 0;
int dt = 0;

int deplacement_horizentale_enemy;
		int indirect=1;
		int direct=0;


		 int numkeys;
    
    Uint8 * keys;

//Définition des structures :
window win;
Background BGnd;
menu menu;
animation perso1;
Enemy_anim enemy;
object obj;
HUD ATH;		


//Declaration des couleurs en RGB :
SDL_Color noir = {18,18,255};
SDL_Color rouge = {0,255,0};

SDL_Surface *texte=NULL;

//Déclaration des positions :
SDL_Rect destlive;
SDL_Rect destnejma;
SDL_Rect positionennemi;
SDL_Rect positionharba;
SDL_Rect poscam;


//Declaraton de l'event de la boucle principale :
SDL_Event event;

//Déclaration des chaines :
char chrono[16];
char text[200];  //On crée une varuiable qui contiendra notre texte


//Déclaration des Font :
TTF_Font *font = NULL;
TTF_Font *police = NULL;


//Déclaration de la partie AUDIO:
Mix_Music *musique = NULL;

//On initialise les variables du jeu :

menu.done_menu=1; // : Init de la boucle du menu à 1
perso1.done=1;// : Init de la boucle du jeux à 1

vies = 5;
etoiles = 0;

destnejma.x = 200;
destnejma.y = 20;

destlive.x = 1100;
destlive.y = 20;

positionharba.x=900;
positionharba.y=520;


//On entre dans le menu "k est est un entier qui retourne 1 si on clique sur PLAY / 2 pour les settings / 3 pour les credits "
k=menu_jeux(&menu);

//Si on clique sur PLAY :
if(k==1)
{

	

	t1 = SDL_GetTicks();

//Création de la fenêtre (le win.screen) :
	prepare_window(&win);
	Load_Resources(&perso1);
	

	font = loadFont("DFTEH.ttf", 32);
	police = TTF_OpenFont("DFTEH.ttf", 50);


	//Intialisation des positions :
	//perso1.pos_Sprite.x = 20;
	//perso1.pos_Sprite.y = 537;

	BGnd.posB_grnd.x = 0;
	BGnd.posB_grnd.y = 0;

	positionennemi.x=500;
	positionennemi.y=450;

	
deplacement_horizentale_enemy=500;

//Loading ressources :
LoadRessources_backround(&BGnd);
LoadRessources_enemy(&enemy);
Load_HudRessources(&ATH);
LoadRessources_Object(&obj);


//Blit initiale des images :
	SDL_BlitSurface(BGnd.B_grndMask,NULL, win.screen , &BGnd.posB_grnd);
	SDL_BlitSurface(BGnd.B_grnd,NULL, win.screen , &BGnd.posB_grnd);
	
	SDL_BlitSurface(texte, NULL, win.screen, 0);
	SDL_BlitSurface(perso1.tsawer[1],NULL, win.screen , &perso1.pos_Sprite);
	SDL_Flip(win.screen);


//Lancer la musique en boucle :
	Launch_Music(musique);
	InitSprite(&perso1);

//Auto-Key :
	//SDL_EnableKeyRepeat(10,10);
	SDL_ShowCursor(SDL_ENABLE);
	while(perso1.done)
	{
       	j++;
		if(j==3)
		{
		   j=0;
		}
		now=SDL_GetTicks();
		dt = now - ex;
		if(dt > periodeFps)
		{
		//SDL_PollEvent(&event);
		SDL_PumpEvents();
		keys = SDL_GetKeyState(&numkeys);
		test_collision = collision_Parfaite(BGnd.B_grndMask ,perso1.tsawer[i] , perso1.pos_Sprite , perso1.direct , &BGnd);

	//La variable perso.direct est reourner pour recupérer la condition pour la position du pixel à comparer avec le masque du background dans la fonction collision_Parfaite :
		
		Evolue(&perso1,keys ,&i ,&perso1.direct ,&BGnd , test_collision);
		
		//test_collision=0; // :Rafraichir la variable de test de collision à chaque tour de boucle :

		if(i==3)
		{
		  i=0;
		}

		if(perso1.direct==0 || perso1.direct==3  )
		{
			SDL_BlitSurface(BGnd.B_grndMask,&BGnd.posB_grnd, win.screen , NULL);
			SDL_BlitSurface(BGnd.B_grnd,&BGnd.posB_grnd, win.screen , NULL);
			if (test==0)
           	{
				if(deplacement_horizentale_enemy<position_save)
				{			  
				 afficher_objetx(  deplacement_horizentale_enemy - BGnd.posB_grnd.x, positionennemi.y, enemy.enemy_Right[j] ,win.screen); 
				}
				if(deplacement_horizentale_enemy>position_save)
				{		  
					 afficher_objetx(deplacement_horizentale_enemy - BGnd.posB_grnd.x, positionennemi.y, enemy.enemy_Left[j] ,win.screen);
				}
    		}
      		if(test2==0)
      		{
			 afficher_objetx(positionharba.x - BGnd.posB_grnd.x , positionharba.y ,obj.obj_pto ,win.screen);
			}

			ATH.HUD_vie=afficher_objetpng( destlive.x, destlive.y ,ATH.HUD_vie , win.screen);
      		ATH.HUD_etoiles=afficher_objetpng( destnejma.x, destnejma.y ,ATH.HUD_etoiles ,win.screen);
			SDL_BlitSurface(texte, NULL, win.screen, 0);
		  //Pour afficher le nombre de vies, on formate notre string pour qu'il prenne la valeur de la variable
    		sprintf(text, "%d", vies);
    	  //Puis on utilise notre fonction créée précédemment
    		drawString(text, 1000, 20, font,win.screen);
     		sprintf(text, "%d", etoiles);
    		drawString(text, 260, 20, font,win.screen);
			SDL_BlitSurface(perso1.tsawer[i],NULL, win.screen , &perso1.pos_Sprite);
			SDL_Flip(win.screen);
			}

		else if(perso1.direct==1 || perso1.direct==3)
		{
			SDL_BlitSurface(BGnd.B_grndMask,&BGnd.posB_grnd, win.screen , NULL);
			SDL_BlitSurface(BGnd.B_grnd,&BGnd.posB_grnd, win.screen , NULL);

			if (test==0)
            {
							if(deplacement_horizentale_enemy<position_save)
							{
							afficher_objetx(  deplacement_horizentale_enemy - BGnd.posB_grnd.x, positionennemi.y, enemy.enemy_Right[j] ,win.screen);
							}
							if(deplacement_horizentale_enemy>position_save)
							{
								afficher_objetx(deplacement_horizentale_enemy - BGnd.posB_grnd.x, positionennemi.y, enemy.enemy_Left[j] ,win.screen);
							}
      		}
      		if(test2==0)
      		{
				 afficher_objetx(  positionharba.x - BGnd.posB_grnd.x , positionharba.y ,obj.obj_pto ,win.screen);
			}
      		ATH.HUD_etoiles=afficher_objetpng( destnejma.x, destnejma.y ,ATH.HUD_etoiles ,win.screen);
      		SDL_BlitSurface(texte, NULL, win.screen, 0);
      		ATH.HUD_vie=afficher_objetpng( destlive.x, destlive.y ,ATH.HUD_vie , win.screen);
			SDL_BlitSurface(perso1.tsawerL[i],NULL, win.screen , &perso1.pos_Sprite);
		  //Pour afficher le nombre de vies, on formate notre string pour qu'il prenne la valeur de la variable
    		sprintf(text, "%d", vies);
    	  //Puis on utilise notre fonction créée précédemment
   		 	drawString(text, 1000, 20, font,win.screen);
     		sprintf(text, "%d", etoiles);
    		drawString(text, 260, 20, font,win.screen);
			SDL_Flip(win.screen);
		}

		else 
		{
			SDL_BlitSurface(BGnd.B_grndMask,&BGnd.posB_grnd, win.screen , NULL);
			SDL_BlitSurface(BGnd.B_grnd,&BGnd.posB_grnd, win.screen , NULL);

			if (test==0)
           	{
				if(deplacement_horizentale_enemy<position_save)
				{

				afficher_objetx(deplacement_horizentale_enemy - BGnd.posB_grnd.x, positionennemi.y, enemy.enemy_Right[j] ,win.screen);
				}
				
			    else if(deplacement_horizentale_enemy>position_save)
				{
				afficher_objetx(deplacement_horizentale_enemy - BGnd.posB_grnd.x, positionennemi.y, enemy.enemy_Left[j] ,win.screen);
				}
      		}

      		else if(test2==0)
      		{
				afficher_objetx(  positionharba.x - BGnd.posB_grnd.x , positionharba.y ,enemy.enemy_Left[j] ,win.screen);
			}

      		ATH.HUD_etoiles=afficher_objetpng( destnejma.x, destnejma.y ,ATH.HUD_etoiles ,win.screen);
      		SDL_BlitSurface(texte, NULL, win.screen, 0);
      	  //Pour afficher le nombre de vies, on formate notre string pour qu'il prenne la valeur de la variable
    		sprintf(text, "%d", vies);
    	  //Puis on utilise notre fonction créée précédemment
    		drawString(text, 1000, 20, font,win.screen);
     		sprintf(text, "%d", etoiles);
    	    drawString(text, 260, 20, font,win.screen);
    		ATH.HUD_vie=afficher_objetpng( destlive.x, destlive.y ,ATH.HUD_vie , win.screen);
			SDL_BlitSurface(perso1.tsawer[1],NULL, win.screen , &perso1.pos_Sprite);
			SDL_Flip(win.screen);
		}
		//save position
		position_save=deplacement_horizentale_enemy;

		//mouvement aleatoire
      if(direct==0)
      {
    deplacement_horizentale_enemy++;
if(deplacement_horizentale_enemy==700)
{
  direct=1;
  indirect=0;
}
    }
  if(indirect==0){
deplacement_horizentale_enemy--;
if(deplacement_horizentale_enemy==500){
  direct=0;
  indirect=1;
}
  }
SDL_Rect pos;
pos.x=900;
pos.y=537;
pos.x-=BGnd.posB_grnd.x;
	if(colli==0)
	{
		colli=collize (perso1.pos_Sprite, pos );
		if(colli==1)
		{
			test2=1;
			etoiles+=5;
		}
	}
	
if(s==0)
	{
positionennemi.x=deplacement_horizentale_enemy;
positionennemi.x-=BGnd.posB_grnd.x;
		s=collize (perso1.pos_Sprite ,positionennemi);

		if(s==1)
 		{
			test=1;
			vies-=1;
		}
	}
    	t2 = SDL_GetTicks() - t1;         //Minute       //Seconde   //Dixieme
    	sprintf(chrono, "%02u:%02u.%u  ", t2/1000/60%60, t2/1000%60, t2%1000/100);
    	texte = TTF_RenderText_Shaded(police, chrono, rouge,noir);

		ex = now;
		}
			else if(dt <= periodeFps)
			{
			SDL_Delay(periodeFps - dt);
			}
        } // : Fermeture de la boucle While(perso.done)
SDL_Flip(win.screen);
}

SDL_FreeSurface(menu.background_menu);
SDL_FreeSurface(menu.boutton1_menu);
SDL_FreeSurface(menu.boutton2_menu);
SDL_FreeSurface(menu.boutton3_menu);
SDL_FreeSurface(menu.boutton_exit_menu);
SDL_FreeSurface(menu.boutton1_Active_menu);
SDL_FreeSurface(menu.boutton2_Active_menu);
SDL_FreeSurface(menu.boutton3_Active_menu);
SDL_FreeSurface(menu.boutton_exit_Active_menu);
SDL_FreeSurface(menu.cursor);
SDL_FreeSurface(texte);
SDL_FreeSurface(ATH.HUD_vie);
SDL_FreeSurface(ATH.HUD_etoiles);
SDL_FreeSurface(obj.obj_pto);
Mix_FreeMusic(menu.music_background_menu);
Mix_FreeChunk(menu.sound_effect);
 //Liberation des espaces alloués :
SDL_FreeSurface(BGnd.B_grnd);
SDL_FreeSurface(BGnd.B_grndMask);
for(i=0 ; i>3 ; i++)
{
	SDL_FreeSurface(perso1.tsawer[i]);
	SDL_FreeSurface(perso1.tsawerL[i]);
}
for(j=0 ; j<3 ; j++)
{
	SDL_FreeSurface(enemy.enemy_Right[j]);
	SDL_FreeSurface(enemy.enemy_Left[j]);
}
TTF_CloseFont (police);
TTF_CloseFont(font);
Mix_CloseAudio();
SDL_FreeSurface(win.screen);
//Quitter le jeux :
TTF_Quit;
SDL_Quit;
return 0;
}
