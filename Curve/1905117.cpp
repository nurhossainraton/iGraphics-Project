# include "iGraphics.h"
# include "gl.h"
#include <math.h>

//int ball_x, ball_y;
int dx=5,axis=1,ballspeed=3;
double theta,x=0,y;
double width=1024,height=684,middlepoint=height/2;
int showcurve=0;
int ampx=7;
  int amplitude[]={10,10,15};
int freq=2,freqx=1;
int curve[]={1,0,1};
int ball_x = 0;
int green[]={0,255,0};
int red[]={255,0,0};
int blue[]={0,0,255};
double mx=0,my=0;
int totalcurves= 3;
int ballshow[]={1,1,1};
int resultant=1;
int dis=1;
int ballremain=0;
/*
	function iDraw() is called again and again by the system.
*/


void ball()
{
  double bally,result;
  int i,j;
  //for (i=0;i<=width;i++){
            result=0;
        theta=ball_x*3.1416/180;
        for (j=0;j<3;j++){
             iSetColor(red[j%4],green[j%4],blue[j%4]);
            if (curve[j]==1){

            bally=ampx*amplitude[j]*sin((theta*freq*freqx)+x);
            }
            else {
                bally=ampx*amplitude[j]*cos((theta*freq*freqx)+x);
            }

            result+=bally;
           if (ballshow[j]) iFilledCircle(ball_x,bally+middlepoint,5);


        }
     iSetColor(255,255,255);

  if (resultant)
    iFilledCircle(ball_x,result+middlepoint,5);

  }


void ballChange(){

        ball_x+=axis*ballspeed;

	if(ball_x > width ||ball_x < 0 )
       axis*=-1;

	//if(ball_y > height || ball_y < 0)dy = -dy;
}
void graph()
{
     double i,graphsum;
      int j;
  for (i=0;i<=width;i++){

            graphsum=0;
        theta=i*3.1416/180;
        for (j=0;j<totalcurves;j++){
            if (curve[j]==1){

        y=ampx*amplitude[j]*sin((theta*freq*freqx)+x);
            }
            else {
                y=ampx*amplitude[j]*cos((theta*freq*freqx)+x);
            }
       graphsum +=y;
     iPoint(i,y+middlepoint);
     }
     iPoint(i,graphsum+middlepoint);
     }

     iLine(0,middlepoint,width,middlepoint);
}





/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{


      	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p' || key=='P')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r' || key == 'R')
	{
		iResumeTimer(0);
	}
	if (key== '+')
	{
	    ballspeed++;
	}
	if (key== '-')
	{
	    ballspeed--;
	}

	if (ballspeed<0)
        ballspeed=0;
    if (key == 'a' )
     {
         ampx+= 1.5;
     }
       if (key == 'A' )
     {
         ampx -= 1.5;
         if (ampx<0)
            ampx=0;
     }
     if (key== 'f')
     {
         freqx += 1.5;
     }
     if (key == 'F')
     {
         freqx --;
         if (freqx<0)
            freqx=0;
     }
     if (key== 's')
     {
         showcurve=(showcurve+1)%2;
     }
     if(key>='1' && key<='9'){
        int i = key-'0'-1;
        if(i<=totalcurves) ballshow[i] = (ballshow[i]+1) % 2;
       else if(i==totalcurves+1) resultant = (resultant + 1) % 2;
    }
    if (key=='x'){
        x -=(3.1416/2);
    }
    if (key=='X'){
        x +=(3.1416/2);
    }



	//place your codes for other keys here
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

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key==GLUT_KEY_F1)
     {
         showcurve=(showcurve+1)%2;
         dis=(dis+1)%2;
         ballremain=(ballremain+1)%2;

     }
	//place your codes for other keys here
}
void display()
{
    iSetColor(255,0,0);
     iShowBMP(0,0,"help.bmp");
    iText(400,600,"MAIN MENU/START       : F1",GLUT_BITMAP_HELVETICA_18);
       iText(400,580,"PAUSE              : P/p",GLUT_BITMAP_HELVETICA_18);
       iText(400,560,"RESUME             : R/r",GLUT_BITMAP_HELVETICA_18);
       iText(400,540,"INCREASE SPEED     : +",GLUT_BITMAP_HELVETICA_18);
       iText(400,520,"DECREASE SPEED     : -",GLUT_BITMAP_HELVETICA_18);
       iText(400,500,"INCREASE FREQUENCY : f",GLUT_BITMAP_HELVETICA_18);
       iText(400,480,"DECREASE FREQUENCY : F",GLUT_BITMAP_HELVETICA_18);
       iText(400,460,"INCREASE AMPLITUDE : a",GLUT_BITMAP_HELVETICA_18);
       iText(400,440,"DECREASE AMPLITUDE : A",GLUT_BITMAP_HELVETICA_18);
       iText(400,420,"TRACE CURVE        : CURVE NO",GLUT_BITMAP_HELVETICA_18);
        iText(400,400,"INCREASE PHASE       : X",GLUT_BITMAP_HELVETICA_18);
        iText(400,380,"DECREASE PHASE       : x",GLUT_BITMAP_HELVETICA_18);
       iText(400,360,"EXIT : End",GLUT_BITMAP_HELVETICA_18);

}
void iDraw()
{

	iClear();




       if (dis)
        display();

      if (showcurve && ballremain)
      {

        graph();

	iText(10, 10, "Press p for pause, r for resume, END for exit.");}

	if (ballremain)ball();


}



int main()
{

	iSetTimer(10, ballChange);

	iInitialize(width, height, "My Project");

	return 0;
}

