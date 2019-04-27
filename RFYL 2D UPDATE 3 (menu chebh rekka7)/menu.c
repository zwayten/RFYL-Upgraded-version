#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"menu.h"


int menu_jeux(menu *menu)
{
	int k=0;
	menu->bt_menu = -1;
//initialisation des variables :
menu->screen_menu=NULL;
menu->background_menu=NULL;
menu->boutton1_menu=NULL;
menu->boutton1_Active_menu=NULL;
menu->boutton2_menu=NULL;
menu->boutton2_Active_menu=NULL;
menu->boutton3_menu=NULL;
menu->boutton3_Active_menu=NULL;
menu->boutton_exit_menu=NULL;
menu->boutton_exit_Active_menu=NULL;
menu->cursor=NULL;

menu->music_background_menu = NULL;
menu->sound_effect = NULL;


SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);


 SDL_WM_SetCaption("MENU R.F.Y.L !", NULL);
 SDL_WM_SetIcon(IMG_Load("DARE.png"), NULL);
//Ouverture de la fenetre ""screen_menu"" :
menu->screen_menu= SDL_SetVideoMode(1315,742,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

//Centrer la fenêtre :
putenv("SDL_VIDEO_CENTERED=1");

//Ressources Load :
menu->background_menu=SDL_DisplayFormat(IMG_Load("Graphics/RessourcesMenu/background_menu.png"));
menu->boutton1_menu=SDL_DisplayFormatAlpha(IMG_Load("Graphics/RessourcesMenu/play.png"));
menu->boutton2_menu=SDL_DisplayFormatAlpha(IMG_Load("Graphics/RessourcesMenu/settings.png"));
menu->boutton3_menu=SDL_DisplayFormatAlpha(IMG_Load("Graphics/RessourcesMenu/CREDITS.png"));
menu->boutton_exit_menu=SDL_DisplayFormatAlpha(IMG_Load("Graphics/RessourcesMenu/boutton_exit_menu.png"));
menu->boutton1_Active_menu=SDL_DisplayFormatAlpha(IMG_Load("Graphics/RessourcesMenu/play2.png"));
menu->boutton2_Active_menu=SDL_DisplayFormatAlpha(IMG_Load("Graphics/RessourcesMenu/settings2.png"));
menu->boutton3_Active_menu=SDL_DisplayFormatAlpha(IMG_Load("Graphics/RessourcesMenu/CREDITS2.png"));
menu->boutton_exit_Active_menu=SDL_DisplayFormatAlpha(IMG_Load("Graphics/RessourcesMenu/boutton_exit_Active_menu.png"));
menu->cursor=SDL_DisplayFormatAlpha(IMG_Load("Graphics/RessourcesMenu/mf_cursor.png"));





//Test du lancement du son : 
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
	printf("%s",Mix_GetError());
	//return 1;
	}


//initialisation des coordonnées :

   //Background_menu : 
    menu->position_background_menu.x=0;
    menu->position_background_menu.y=0;
   //Boutton_1 :
    menu->position_Boutton1.x=360;
    menu->position_Boutton1.y=300;
   //Boutton_2 :
    menu->position_Boutton2.x=360;
    menu->position_Boutton2.y=395;
   //Boutton_3 :
    menu->position_Boutton3.x=360;
    menu->position_Boutton3.y=505;
   //Boutton_exit_menu : 
    menu->position_Boutton_exit.x=1169;
    menu->position_Boutton_exit.y=576;


//Blitting surfaces :
SDL_BlitSurface(menu->background_menu, NULL ,menu->screen_menu , &(menu->position_background_menu));
SDL_BlitSurface(menu->boutton1_menu , NULL , menu->screen_menu , &(menu->position_Boutton1));
SDL_BlitSurface(menu->boutton2_menu , NULL , menu->screen_menu , &(menu->position_Boutton2));
SDL_BlitSurface(menu->boutton3_menu , NULL , menu->screen_menu , &(menu->position_Boutton3));
SDL_BlitSurface(menu->boutton_exit_menu , NULL , menu->screen_menu , &(menu->position_Boutton_exit));
SDL_Flip(menu->screen_menu);


//Ajout du son en fond au lancement du menu :
menu->music_background_menu=Mix_LoadMUS("Audio/music_background_menu.mp3");
Mix_PlayMusic(menu->music_background_menu, -1);
menu->sound_effect = Mix_LoadWAV("Audio/clock-tick1.wav");

int x ;
int p=0;
int v;
int t;

//Boucle du menu :
while(menu->done_menu)
{
	Mix_VolumeChunk (menu->sound_effect, v);
	Mix_VolumeMusic(x); 
		
		if(menu->bt_menu==4)
		{
			menu->bt_menu =-1;
		}

       //Utilisation de 100% du CPU et sans mise en pause :
        SDL_PollEvent(&(menu->event_menu));
 
       //Test du type de l'événement :
	switch(menu->event_menu.type) 
		{


       //Si l'event est de Quitter le menu :
		case SDL_QUIT: 
		menu->done_menu = 0; 
		break;

		case SDL_KEYUP:
		{
			case SDLK_RETURN :
			p=0;
			break;

			
		}

		case SDL_KEYDOWN :
		{

			switch(menu->event_menu.key.keysym.sym)
			{
			  case SDLK_ESCAPE: 
     		  menu->done_menu =0;
      		break;

      		case SDLK_DOWN :
      		menu->bt_menu ++;
      		break;

      		case SDLK_RETURN :
      		p=1;
      		break;

      
		 	}


if(menu->bt_menu == 0)
		{
			Mix_PlayChannel(1 ,menu->sound_effect, 0);
			SDL_BlitSurface(menu->background_menu, NULL ,menu->screen_menu , &(menu->position_background_menu));
			SDL_BlitSurface(menu->boutton1_Active_menu , NULL , menu->screen_menu , &(menu->position_Boutton1));
			SDL_BlitSurface(menu->boutton2_menu , NULL , menu->screen_menu , &(menu->position_Boutton2));
			SDL_BlitSurface(menu->boutton_exit_menu , NULL , menu->screen_menu , &(menu->position_Boutton_exit));
			SDL_BlitSurface(menu->boutton3_menu , NULL , menu->screen_menu , &(menu->position_Boutton3));
			SDL_Flip(menu->screen_menu);
			SDL_Delay(200);
			if(p==1)
			{
			k=1;
			return k;
		}
			
		}
		else if(menu->bt_menu == 1)
		{
			Mix_PlayChannel(1 ,menu->sound_effect, 0);
			SDL_BlitSurface(menu->background_menu, NULL ,menu->screen_menu , &(menu->position_background_menu));
			SDL_BlitSurface(menu->boutton1_menu , NULL , menu->screen_menu , &(menu->position_Boutton1));
			SDL_BlitSurface(menu->boutton2_Active_menu , NULL , menu->screen_menu , &(menu->position_Boutton2));
			SDL_BlitSurface(menu->boutton_exit_menu , NULL , menu->screen_menu , &(menu->position_Boutton_exit));
			SDL_BlitSurface(menu->boutton3_menu , NULL , menu->screen_menu , &(menu->position_Boutton3));
			SDL_Flip(menu->screen_menu);	
			SDL_Delay(200);
			if(p==1)
			{
			printf("music Volume:\t");
			scanf("%d",&x);
			printf("SFX Volume :\t");
			scanf("%d",&v);
			printf("taille de la fenetre :\t");
			scanf("%d",&t);
			if(t==0)
			{
				menu->screen_menu= SDL_SetVideoMode(1315,742,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
			}
			if(t==1)
			{
				menu->screen_menu= SDL_SetVideoMode(1315,742,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN | SDL_RESIZABLE);		
			}
			}

		}
		else if(menu->bt_menu == 2)
		{
			Mix_PlayChannel(1 ,menu->sound_effect, 0);
			SDL_BlitSurface(menu->background_menu, NULL ,menu->screen_menu , &(menu->position_background_menu));
			SDL_BlitSurface(menu->boutton1_menu , NULL , menu->screen_menu , &(menu->position_Boutton1));
			SDL_BlitSurface(menu->boutton2_menu , NULL , menu->screen_menu , &(menu->position_Boutton2));
			SDL_BlitSurface(menu->boutton3_Active_menu , NULL , menu->screen_menu , &(menu->position_Boutton3));
			SDL_BlitSurface(menu->boutton_exit_menu , NULL , menu->screen_menu , &(menu->position_Boutton_exit));
			SDL_Flip(menu->screen_menu);
			SDL_Delay(200);

		}
		else if(menu->bt_menu == 3)
		{
			Mix_PlayChannel(1 ,menu->sound_effect, 0);
			SDL_BlitSurface(menu->background_menu, NULL ,menu->screen_menu , &(menu->position_background_menu));
			SDL_BlitSurface(menu->boutton1_menu , NULL , menu->screen_menu , &(menu->position_Boutton1));
			SDL_BlitSurface(menu->boutton2_menu , NULL , menu->screen_menu , &(menu->position_Boutton2));
			SDL_BlitSurface(menu->boutton3_menu , NULL , menu->screen_menu , &(menu->position_Boutton3));
			SDL_BlitSurface(menu->boutton_exit_Active_menu , NULL , menu->screen_menu , &(menu->position_Boutton_exit));
			SDL_Flip(menu->screen_menu);
			SDL_Delay(200);
			if(p==1)
			{
				menu->done_menu=0;
			}

		}
		break;
		

		}
		
		case SDL_MOUSEBUTTONDOWN:
	
	if(menu->event_menu.button.button == SDL_BUTTON_LEFT)
		{
			
	
	//Récupération des coordonnées du curseur de la souris :
		menu->position_Click.x = menu->event_menu.button.x;
		menu->position_Click.y = menu->event_menu.button.y;
		
	//Si on clique sur la porte on quitte le menu :
      		if(menu->event_menu.button.x > 1169 && menu->event_menu.button.x < 1315 && menu->event_menu.button.y > 576 && menu->event_menu.button.y < 742)
		{
		menu->done_menu=0;
		}

		

		if(menu->event_menu.motion.x > 390 && menu->event_menu.motion.x < 547 && menu->event_menu.motion.y > 317 && menu->event_menu.motion.y < 366)
		{
			k=1;
			Mix_PlayChannel(-1 ,menu->sound_effect, 0);
			return k;
		}

		if(menu->event_menu.motion.x > 388 && menu->event_menu.motion.x < 552 && menu->event_menu.motion.y > 409 && menu->event_menu.motion.y < 460)
		{
			
			Mix_PlayChannel(1 ,menu->sound_effect, 0);
			printf("music Volume:\t");
			scanf("%d",&x);
			printf("SFX Volume :\t");
			scanf("%d",&v);
			printf("taille de la fenetre :\t");
			scanf("%d",&t);
			if(t==0)
			{
				menu->screen_menu= SDL_SetVideoMode(1315,742,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
			}
			if(t==1)
			{
				menu->screen_menu= SDL_SetVideoMode(1315,742,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN | SDL_RESIZABLE);		
			}
		}

		if(menu->event_menu.motion.x > 390 && menu->event_menu.motion.x < 550 && menu->event_menu.motion.y > 519 && menu->event_menu.motion.y < 566)
		{
			
			Mix_PlayChannel(-1 ,menu->sound_effect, 0);
		}
		}

		

		
	//Changement de l'apparence des bouttons au passege du curseur au dessus :
		case SDL_MOUSEMOTION:
		
			menu->position_click1.x = menu->event_menu.motion.x;
			menu->position_click1.y = menu->event_menu.motion.y;
		
		if(menu->event_menu.motion.x > 390 && menu->event_menu.motion.x < 547 && menu->event_menu.motion.y > 317 && menu->event_menu.motion.y < 366)
		{

			SDL_ShowCursor(SDL_DISABLE);
			SDL_BlitSurface(menu->background_menu, NULL ,menu->screen_menu , &(menu->position_background_menu));
			SDL_BlitSurface(menu->boutton1_Active_menu , NULL , menu->screen_menu , &(menu->position_Boutton1));
			SDL_BlitSurface(menu->boutton2_menu , NULL , menu->screen_menu , &(menu->position_Boutton2));
			SDL_BlitSurface(menu->boutton_exit_menu , NULL , menu->screen_menu , &(menu->position_Boutton_exit));
			SDL_BlitSurface(menu->boutton3_menu , NULL , menu->screen_menu , &(menu->position_Boutton3));
			SDL_BlitSurface(menu->cursor, NULL , menu->screen_menu , &(menu->position_click1));
			SDL_Flip(menu->screen_menu);
			menu->bt_menu =0;
			
		}


		else if(menu->event_menu.motion.x > 388 && menu->event_menu.motion.x < 552 && menu->event_menu.motion.y > 409 && menu->event_menu.motion.y < 460)
		{
			SDL_ShowCursor(SDL_DISABLE);
			SDL_BlitSurface(menu->background_menu, NULL ,menu->screen_menu , &(menu->position_background_menu));
			SDL_BlitSurface(menu->boutton1_menu , NULL , menu->screen_menu , &(menu->position_Boutton1));
			SDL_BlitSurface(menu->boutton2_Active_menu , NULL , menu->screen_menu , &(menu->position_Boutton2));
			SDL_BlitSurface(menu->boutton_exit_menu , NULL , menu->screen_menu , &(menu->position_Boutton_exit));
			SDL_BlitSurface(menu->boutton3_menu , NULL , menu->screen_menu , &(menu->position_Boutton3));
			SDL_BlitSurface(menu->cursor, NULL , menu->screen_menu , &(menu->position_click1));
			SDL_Flip(menu->screen_menu);
			menu->bt_menu =1;
		}


		else if(menu->event_menu.motion.x > 390 && menu->event_menu.motion.x < 550 && menu->event_menu.motion.y > 519 && menu->event_menu.motion.y < 566)
		{
			SDL_ShowCursor(SDL_DISABLE);
			SDL_BlitSurface(menu->background_menu, NULL ,menu->screen_menu , &(menu->position_background_menu));
			SDL_BlitSurface(menu->boutton1_menu , NULL , menu->screen_menu , &(menu->position_Boutton1));
			SDL_BlitSurface(menu->boutton2_menu , NULL , menu->screen_menu , &(menu->position_Boutton2));
			SDL_BlitSurface(menu->boutton3_Active_menu , NULL , menu->screen_menu , &(menu->position_Boutton3));
			SDL_BlitSurface(menu->boutton_exit_menu , NULL , menu->screen_menu , &(menu->position_Boutton_exit));
			SDL_BlitSurface(menu->cursor, NULL , menu->screen_menu , &(menu->position_click1));	
			SDL_Flip(menu->screen_menu);
			menu->bt_menu =2;
		}


		else  if(menu->event_menu.motion.x > 1169 && menu->event_menu.motion.x < 1315 && menu->event_menu.motion.y > 576 && menu->event_menu.motion.y < 742)
		{
			SDL_ShowCursor(SDL_DISABLE);
			SDL_BlitSurface(menu->background_menu, NULL ,menu->screen_menu , &(menu->position_background_menu));
			SDL_BlitSurface(menu->boutton1_menu , NULL , menu->screen_menu , &(menu->position_Boutton1));
			SDL_BlitSurface(menu->boutton2_menu , NULL , menu->screen_menu , &(menu->position_Boutton2));
			SDL_BlitSurface(menu->boutton3_menu , NULL , menu->screen_menu , &(menu->position_Boutton3));
			SDL_BlitSurface(menu->boutton_exit_Active_menu , NULL , menu->screen_menu , &(menu->position_Boutton_exit));
			SDL_BlitSurface(menu->cursor, NULL , menu->screen_menu , &(menu->position_click1));	
			SDL_Flip(menu->screen_menu);
			menu->bt_menu = 3;
		} 

	
		
		else
		{
			
			SDL_BlitSurface(menu->background_menu, NULL , menu->screen_menu , &(menu->position_background_menu));
			SDL_BlitSurface(menu->boutton1_menu , NULL , menu->screen_menu , &(menu->position_Boutton1));
			SDL_BlitSurface(menu->boutton2_menu , NULL , menu->screen_menu , &(menu->position_Boutton2));
			SDL_BlitSurface(menu->boutton3_menu , NULL , menu->screen_menu , &(menu->position_Boutton3));
			SDL_BlitSurface(menu->boutton_exit_menu , NULL , menu->screen_menu , &(menu->position_Boutton_exit));
			SDL_Flip(menu->screen_menu);
			SDL_ShowCursor(SDL_ENABLE);
			Mix_PlayMusic(menu->music_background_menu, -1);
			menu->bt_menu = -1;
		}
		


} //fermeture switch(event_menu.type) 
} //fermeture while(done_menu)
return k;
}





















