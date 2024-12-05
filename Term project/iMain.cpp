# include "iGraphics.h"
#include <math.h>
#include <time.h>
#include <string.h>
#include <windows.h>

int x = 0, y = 600, r = 15,i=0,j,axis=1,Height=1000,Width=1000;
int count=0,show=0,highscore,show_highscore=0,game_time=1;
int speed1=15,speed2=30;
bool gotoleft=false;
bool gotoright=false;
int positionx;
int positiony=600;
char name1[15],str3[10];
int gamestate=0;
int minute=1,sec=30;
int flag=0,len=0;
char str1[5],str2[10];
int highscore1[100],check_help=0,sound=1,exit_button=0,resume=0,gameover=0,back_button=0;
FILE *file;


struct eggfall
{
   char imagelocation[100];
//   int positionx=0;

   void setposition ()
   {
       if (positionx>780 || positionx<0)
       {
           positionx=0;
       }
//       else
//       {
//           positionx+=speed;
//       }
       if (positiony<=0 )
       {
           positiony=600;

           positionx=rand()%1000;
       }

       else
        positiony-=speed2;

   }
   void setloaction()
   {
       strcpy(imagelocation,"dim1.bmp");
   }
}v1,v2,v3;


typedef struct
{
    char name[30];
    char score[10];
} Highscore;
Highscore h[11];

void getHighscore()
{
    file=fopen("highscore.txt","r");
    for(i=0; i<10; i++)
    {
        fgets(h[i].name,30,file);
    }
    for(i=0; i<10; i++)
    {
        fgets(h[i].score,10,file);
    }
    fclose(file);
}

void putHighscore()
{
    file=fopen("highscore.txt","w");
    for(i=0; i<10; i++)
    {
        fputs(h[i].name,file);
    }
    for(i=0; i<10; i++)
    {
        fputs(h[i].score,file);
    }
    fclose(file);
}

void Sort_Highscore()
{
    char t1[10],t2[30];
    for(i=0; i<11; i++)
    {
        for(j=i+1; j<11; j++)
        {
            if(atoi(h[i].score)<atoi(h[j].score))
            {
                strcpy(t1,h[i].score);
                strcpy(t2,h[i].name);
                strcpy(h[i].score,h[j].score);
                strcpy(h[i].name,h[j].name);
                strcpy(h[j].score,t1);
                strcpy(h[j].name,t2);
            }
        }
    }
}

int collision()
   {
    if ((x>=positionx && x<=positionx+150)&&(positiony<125)&&(positionx<100 || positionx>700))
    {
        positiony=600;
        positionx=rand()%1000;
        count++;


    }

    else if ((positionx>=100 && positionx<200) && (x>=positionx && x<=positionx+150)&&(positiony<125))
        {
          positiony=600;
          positionx=rand()%1000;
          count+=5;

        }

    else if ((positionx>=350 && positionx<=450) && (x>=positionx && x<=positionx+150)&&(positiony<125))
        {
          positiony=600;
          positionx=rand()%1000;
          count-=10;

        }
        else if ((positionx>=200 && positionx<=350) && (x>=positionx && x<=positionx+150)&&(positiony<125))
        {
           positiony=600;
           positionx=rand()%1000;
           count+=10;

        }
           else if ((positionx>450 && positionx<=500) && (x>=positionx && x<=positionx+150)&&(positiony<125))
        {
           positiony=600;
           positionx=rand()%1000;
           count+=20;

        }
        if ((positionx>500 && positionx<=600) && (x>=positionx && x<=positionx+150)&&(positiony<125))
        {
           positiony=600;
           positionx=rand()%1000;
           minute=0,sec=0;

        }
         if ((positionx>600 && positionx<=700) && (x>=positionx && x<=positionx+150)&&(positiony<125))
        {
           positiony=600;
           positionx=rand()%1000;
           sec+=5;
        }

          return count;
    }

void display()
{
     v1.setposition();
     collision();
     char str[100];
      if (positionx>=100 && positionx<200)
    {
          iShowBMP2(positionx+140,positiony,"blue egg final.bmp",0);

    }

       else if (positionx>=200 && positionx<=350)
    {
        iShowBMP2(positionx+140,positiony,"golden-egg.bmp",0);

    }
    else if (positionx>=350 && positionx<=450)
    {
        iShowBMP2(positionx+140,positiony,"shit2.bmp",255);
    }
    else if (positionx>450 && positionx<=500)
    {
        iShowBMP2(positionx+140,positiony,"gift box.bmp",0);
    }
     else if (positionx<100 || positionx>700)
    {
        iShowBMP2(positionx+140,positiony,v1.imagelocation,0);

    }
    else if (positionx>600 && positiony<=700)
    {
        iShowBMP2(positionx+140,positiony,"timebonus.bmp",0);
    }

      sprintf(str,"%d",count);
      iSetColor(255,0,0);
      iText(250,950,"YOUR SCORE : ",(void*)5);
      iSetColor(255,0,0);
      iText(430,950,str,(void*)5);
      iShowBMP2(positionx,y,"Chicken2.bmp",0);

      iShowBMP2(x,0,"basket.bmp",0);
      iShowBMP2(800,950,"pause.bmp",0);
      iShowBMP2(00,920,"quit.bmp",0);


}
void display1()
{
    iSetColor(255,0,0);
    iShowBMP2(300,700,"start game.bmp",0);
    iShowBMP2(300,600,"high score.bmp",0);
    iShowBMP2(300,530,"HELP1.bmp",0);
    iShowBMP2(300,450,"time.bmp",0);
    iShowBMP2(300,385,"RESUME1.bmp",0);
}
void display2()
{
    if ( show==1)
    {
        iShowBMP2(300,200,"RESUME1.bmp",0);
        iShowBMP2(00,920,"quit.bmp",0);
    }

}

void back_option()
{
    iShowBMP2(50,100,"BACK.bmp",0);
}
void danger()
{
    if (positionx>500 && positionx<=600)
    {
        iShowBMP2(positionx+140,positiony,"danger.bmp",0);
    }
//    if (b<=0)
//    {
//        b=1000;
//
//    }
//    else
//        b-=speed2;
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
     if ((mx>=x || mx<=x) && (my<=355))
     x=mx;


}
void instructions()
{
     iShowBMP2(00,200,"instructions.bmp",0);
}

void gametime()
{
    iShowBMP2(300,300,"thirty sec.bmp",0);
    iShowBMP2(300,500,"one minute.bmp",0);
    iShowBMP2(300,700,"two minutes.bmp",0);

}
//void soundoff()
//{
//    if (sound==0)
//    {
//       PlaySound(0,0,0);
//    }
//    else
//    {
//    PlaySound("ChillingMusic.wav",NULL,SND_LOOP|SND_ASYNC);
//    }
//}
void resume_game()
{
    file=fopen("load.txt","w");
    fprintf(file,"%d %d ",positionx,positiony);
    fprintf(file,"%d %d %d ",count,minute,sec);
    fprintf(file,"%d %d ",x,y);
    fprintf(file,"%d %d",speed1,speed2);
    fclose(file);

}
void resume_button()
{
    file=fopen("load.txt","r");
    fscanf(file,"%d%d",&positionx,&positiony);
    fscanf(file,"%d%d%d",&count,&minute,&sec);
    fscanf(file,"%d%d",&x,&y);
    fscanf(file,"%d%d",&speed1,&speed2);
    fclose(file);
    gamestate=1;

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
      if((show==0) && (mx>=300 && mx<=543) && (my>=773 && my<=846))
      {
          gamestate=1;
          game_time=0;
          resume=0;
      }
      if ((show%2 !=0 && exit_button==1) && (mx>=300 && mx<=490) &&(my>=330 && my <=380))
      {
          gamestate=1;
          show=0;
      }
      if ((gamestate==1) && (mx>=790 && mx<1000) && (my>=980 && my<=1000))
      {
          show=(show+1)%2;
          gamestate=0;
          exit_button=1;
      }
      if ((gamestate==0 ) && (mx>=300 && mx<500) && (my>=670 && my<=750))
      {
         show_highscore=1;
         getHighscore();

      }
    if ((gamestate==0 ) && (mx>=300 && mx<=510) && (my>=470 && my<=510))
     {
        resume=1;
//      gamestate=1;
//      show=1;
         gameover=0;
     }
      if ((gamestate==0) && (mx>=300 && mx<540) && (my>=420 && my<=540))
      {
         sound=0;

      }

      if ((gamestate==0 && show==0) && (mx>=300 && mx<400) && (my>=610 && my<=650))
      {
          show=4;
          check_help=1;
      }
      if ((gamestate==0) && (mx>=300 && mx<741) && (my>=550 && my<=590))
      {
          show=6;
      }
     if ((show==4)&& (mx>=50 && mx<=185) && (my>=250 && my<=270))
     {
        gamestate=0;
        show=0;
        check_help=0;
     }
     if ((show==6 && game_time==1)&& (mx>=300 && mx<=620) && (my>=740 && my<=783))
     {
         minute=1,sec=60;
         gamestate=0;
         show=0;

     }
     if ((show==6 &&  game_time==1)&& (mx>=300 && mx<=592) && (my>=590 && my<=620))
     {
         minute=1,sec=0;
         gamestate=0;
         show=0;
         check_help=0;
     }
     if ((show==6 &&  game_time==1)&& (mx>=300 && mx<=592) && (my>=420 && my<=470))
     {
         minute=0,sec=30;
         gamestate=0;
         show=0;
     }
     if ((show==6 )&& (mx>=50 && mx<=185) && (my>=250 && my<=270))
     {
        gamestate=0;
        show=0;
        check_help=0;
     }
      if ((show==8)&& (mx>=50 && mx<=185) && (my>=250 && my<=270))
     {
        gamestate=0;
        show=0;
        show_highscore=0;
     }
       if ((show==3 && back_button==1)&& (mx>=50 && mx<=185) && (my>=250 && my<=270))
     {
        gamestate=0;
        show=0;
        show_highscore=0;
        count=0;
        minute=1,sec=30;
        back_button=0;
        speed1=25;
        speed2=30;
        gameover=0;


     }

      if ((gamestate==1 || exit_button ==1||resume==1)&&(mx>=00 && mx<=200) && (my>=930 && my<=980))
      {
        show=3;
        gamestate=0;
//          exit(0);
        flag=1;
        resume_game();
        gameover=1;
//        resume=1;

      }


//      if (( show==3) && (mx>= 500 && mx<=700) && (my>=500 && my<=550))
//      {
//          flag=1;
//      }

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
//      if (key=='h')
//      {
//          show_highscore=1;
//          getHighscore();
//
//      }
      if (gameover==1)
      {
          name1[len++]=key;
        if(key=='\r')
        {
          getHighscore();
          strcat(name1,"\n\0");
          strcpy(h[10].name,name1);
          itoa(count,str3,10);
          strcat(str3,"\n\0");
          strcpy(h[10].score,str3);
          Sort_Highscore();
          putHighscore();
          back_option();
          back_button=1;
          gameover=0;
          flag=0;
          game_time=1;
          for (int i=0;i<14;i++)
          {
              name1[i]='\0';
          }
        }
      }




    //place your codes for other keys here
}
void show_score()
{
     if (flag==1)
     {
        iSetColor(0,0,0);
        sprintf(str2,"%d",count);
        iSetColor(255,0,0);
        iText(350,405,"YOUR SCORE:",GLUT_BITMAP_HELVETICA_18);
        iText(520,405,str2,GLUT_BITMAP_HELVETICA_18);
     }

}


/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
     if(key == GLUT_KEY_RIGHT)
    {
//      gotoright=true;
//      gotoleft=false;

        x=x+speed1;
    }
    if (key== GLUT_KEY_UP){

    }
    if (key== GLUT_KEY_LEFT)
    {
//        gotoleft=true;
//        gotoright=false;
        x-=speed1;

    }
     if (key== GLUT_KEY_DOWN )
     {

     }
    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    //place your codes for other keys here
}
void timer ()
{

    char str[100],str1[100];
    sprintf(str,"TIME REMAINING %d:",minute);
    sprintf(str1,"%d",sec);
    iSetColor(255,0,0);
//  iText(500,400,"YOUr",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(500,950,str,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(730,950,str1,GLUT_BITMAP_TIMES_ROMAN_24);

}
void adjust_time ()
{
    if (gamestate==1 || resume==1)
    {

     if (sec==0 && minute==1)
    {
        minute=0;
        sec=59;
    }
    if (minute==0 && sec==0)
    {
        show=3;
        gamestate=0;
        flag=1;
        gameover=1;
        resume=1;
    }
     sec--;
     if (minute ==1 && sec<20)
        speed2=35;
     else if (minute ==1 && sec<10)
        speed2=37;
     else if (minute ==0 && (sec<60 && sec>50))
        speed2=40;
     else if (minute ==0 && (sec<50 && sec>40))
        speed2=45;
     else if (minute ==0 && (sec <40 && sec>20))
        speed2=46;
     else if (minute ==0 && (sec <20 && sec>0))
        speed2=50;
//        if ((sec>45 && sec<50)||(sec>25 && sec<30)||(sec>13 && sec<17))
//            positionx+=5;
    }

}

void iDraw()
{

      iClear();
      iShowBMP(0,0,"project1.bmp");
      if (gamestate==0 && show==4 && check_help==1)
      {
        instructions();
        back_option();
      }
//      if (gamestate==0 && show==3 && check_help==0)
//      {
//
//        back_option();
//
//      }
      if (show==6 &&  game_time==1)
      {
          gametime();
          back_option();
      }
      if (show==8 &&  highscore==1)
      {

          back_option();
      }

      if (gamestate==0 && show==0  && check_help==0)
      {
          display1();
      }

      if ((gamestate==1) && show==0)
      {
          iLine(0,650,1000,650);
          display();
          timer();
      }

      else if (resume==1)
      {
        resume_button();

        exit_button=1;
        gamestate=1;

//      if (gamestate==0 && show==0  && check_help==0)
//      {
//          display1();
//      }

//       v2.setloaction();

       if (gamestate==1)
      {
//          positionx=rand()%1000;

          iLine(0,650,1000,650);
          display();
          timer();
          show=0;
      }

      if (show==1)
      {
          display2();
      }

      if (x>900)
      {
        x=900;
      }
       if (x<0)
       x=0;

      if (show==1)
      {
          display2();
      }

     if (x>900)
     {
        x=900;
     }
     if (x<0)
        x=0;
     if (show==3)
    {
    if (flag==1)
      {
          iSetColor(0,0,0);
          iRectangle(500,400,200,50);
          show_score();
          gameover=1;


      }


    }
      resume=0;
      }

      if (show==1)
      {
          display2();
      }

     if (x>900)
     {
        x=900;
     }
     if (x<0)
        x=0;
     if (show==3)
    {
    if (flag==1)
      {
          iSetColor(0,0,0);
          iRectangle(500,400,200,50);
          show_score();
      }

    }
    if (show_highscore==1)
    {
        show=8;
        highscore=1;
       for (int i=0;i<10;i++)
       {
           iText(50,900-i*50,h[i].name,GLUT_BITMAP_TIMES_ROMAN_24);
           iText(800,900-i*50,h[i].score,GLUT_BITMAP_TIMES_ROMAN_24);
       }
    }
    if (gameover==1)
    {
        iText(350,300,"ENTER YOUR NAME:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(350,280,"(press enter to finish)");
        iSetColor(255,0,0);
        iText(600,300,name1,GLUT_BITMAP_TIMES_ROMAN_24);
        show=3;
        gamestate=0;
    }
    if (back_button==1)
    {
        back_option();
    }
    danger();
    if (count>100)
    {
        positionx+=5;
    }
        if (count>120)
    {
        positionx+=10;
    }



}


int main()
{
            iSetTimer(1000,adjust_time);

//            soundoff();
          PlaySound("ChillingMusic.wav",NULL,SND_LOOP|SND_ASYNC);
            v1.setloaction();

            iInitialize(Height,Width,"Catch The Egg");
            return 0;
}
