
#include "fssimplewindow.h"

void DrawPlayer(int x, int y)
{
  glColor3ub(0,255,0);
  glBegin(GL_QUADS);
  glVertex2i(x-5,y-19); 
  glVertex2i(x+4,y-19); 
  glVertex2i(x+4,y ); 
  glVertex2i(x-5,y );  glVertex2i(x-15,y-9); 
  glVertex2i(x+14,y-9); 
  glVertex2i(x+14,y ); 
  glVertex2i(x-15,y ); 
  glEnd();
}
	

int main(void)
{
  FsOpenWindow(16,16,800,600,1);

  int terminate=0,playerX=400,playerY=580;
  int missile=0, missileX=0,missileY=0;

  
  while(0==terminate)
  {
	FsPollDevice();
	int key=FsInkey();

	switch(key)
	{
		case FSKEY_ESC:
		  terminate=1;
		  break;
		
		case FSKEY_LEFT:
		  playerX-=10;
		  break;		
		
		case FSKEY_RIGHT:
		  playerX+=10;
		  break;

		case FSKEY_SPACE:
		  if (0==missile)
		  { 
		    missile=1;
		    missileX=playerX;
		    missileY=playerY;
		  }
		  break;
		
	}

	glClear(GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawPlayer(playerX,playerY);

	if (missile!=0)
	  missileY-=15;
	  if (missileY<0)
	    missile=0;
	  
	  glColor3ub(255,0,0);
	  
	FsSwapBuffers();
	FsSleep(20);

	}

return 0;

}
