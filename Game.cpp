
//using namespace std;
#include<stdlib.h>
#include <stdio.h>
#include <glut.h>
#include "tga.h"


int jumplimit;
int levelcounter = 0;
int goUp = 0;				// Going up the level 1
int goUp2 = 0;				// Going up the level 2
int goUp3 = 0;				// Going up the level 3
float Dx = 0.0;				// Rate of change of mario in x
float Dy = 0.0;				// Rate of Change of mario in y
float D2x = 0.0;			// Rate of change of mario in x
float D2y = 0.0;
float D1x = 0;				// Rate of Change of enemie
float D4x = 0.01; 
float D3x = 0.01;
float D5x = 0.01;
float D5y;
float D17x = 0.01;
float D117x = 0.01; 
float D16x = 0.01;
float D16y = 0.01;
float D211x = 0.01;
float D211y = 0.01;
float D20x = 0.01;
float D19x = 0.01;
float inc=0.01;
int gravityEnable=1;
float x1 = 0.0;             // Mario
float x2 = 0.1;
float y1 = 0.0;
float y2 = 0.1;				// Mario	
float rx1 = 0.0;			// story # 1
float ry1 = 0.3;
float rx2 = 0.8;
float ry2 = 0.35;			// story # 1
float r1x1 = 0.7;			// green block
float r1y1 = 0.1;
float r1x2 = 0.75;
float r1y2 = 0.2;			// green block
float r2x1 = 0.0;			// story # 2
float r2y1 = 0.6;
float r2x2 = 0.8;
float r2y2 = 0.65;			// story # 2
float r3x1 = 0.2;			// redblock of story 1
float r3y1 = 0.0;
float r3x2 = 0.3;
float r3y2 = 0.05;			// redblock of story 1
float r4x1 = 0.7;			// gate of story 1
float r4y1 = 0.3;
float r4x2 = 1.0;
float r4y2 = 0.35;			// gate of story 1
float r5x1 = 0.7;			// enemie 1
float r5y1 = 0.0;
float r5x2 = 0.75;
float r5y2 = 0.1;			// enemie 1
float r6x1 = 0.7;			// enemie 2
float r6y1 = 0.35;
float r6x2 = 0.75;
float r6y2 = 0.4;			// enemie 2
float r7x1 = 0.7;			// gate of story 2
float r7y1 = 0.6;
float r7x2 = 1.0;
float r7y2 = 0.65;			// gate of story 2
float r8x1 = 0.7;			// gate of story 3
float r8y1 = 0.9;
float r8x2 = 1.0;
float r8y2 = 0.95;			// gate of story 3
float r9x1 = 0.0;			// story # 3
float r9y1 = 0.9;
float r9x2 = 0.8;
float r9y2 = 0.95;			// story # 3
float r10x1 = 0.3;		// enemy 4
float r10x2 = 0.35;
float r10y1 = 1.0;
float r10y2 = 1.0;		// enemy 4
float r11y1 = 0.65;		// enemy 3
float r11y2 = 0.75;
float r11x1 = 0.5;	
float r11x2 = 0.55;		//enemy 3
float r12y1 = 0.65;		// enemy 5
float r12y2 = 0.75;
float r12x1 = 0.0;	
float r12x2 = 0.05;		//enemy 5
float r16x1 = 0.5;			// enemie 22
float r16y1 = 0.35;
float r16x2 = 0.55;
float r16y2 = 0.4;			// enemie 22
float r17x1 = 0.7;			// enemie 1 agn
float r17y1 = 0.0;
float r17x2 = 0.75;
float r17y2 = 0.1;			// enemie 1 agn
float r117x1 = 0.3;			// enemie 1/2 agn
float r117y1 = 0.0;
float r117x2 = 0.35;
float r117y2 = 0.1;		// enemie 1/2 agn
float r19y1 = 0.65;		// enemy 5 agn
float r19y2 = 0.75;
float r19x1 = 0.0;	
float r19x2 = 0.05;		//enemy 5 agn
float r20y1 = 0.65;		// enemy 3 agn
float r20y2 = 0.75;
float r20x1 = 0.5;	
float r20x2 = 0.55;		//enemy 3 
float r211x1 = 0.5;		// enemy 4 agn
float r211x2 = 0.55;
float r211y1 = 1.0;
float r211y2 = 1.0;		// enemy 4 agn


GLuint _textureId;
GLuint _textureId1;
GLuint _textureId2;
GLuint _textureId3;
GLuint _textureId4;
GLuint _textureId5;
GLuint _textureId6;
GLuint _textureId7;
GLuint _textureId8;
GLuint loadtexture(char *name)
{
    GLuint temp ;
    glGenTextures(1,&temp);
    loadTGA(name,temp);
    return temp;
}
void Conditions()
{


x1 = x1 + Dx;		// mario moves
x2 = x2 + Dx;		// mario moves

if(gravityEnable==1 || Dy>0)
{
	y1 = y1 + Dy;		// mario moves
	y2 = y2 + Dy;		// mario moves
}

if(r4x1 <= 1.0 && goUp == 1)   // gate 1 opens
{
	r4x1 = r4x1 + 0.01;
}
if(r4x1 >= 0.7 && goUp == 0)   // gate 1 closes
{
	r4x1 = r4x1 -  0.01;
}

if(r7x1 <= 1.0 && goUp2 == 1) // gate 2 opens
{
	r7x1 = r7x1 + 0.01;
}
if(r7x1 >= 0.7 && goUp2 == 0) // gate 2 closes
{
	r7x1 = r7x1 - 0.01;
}

if(r8x1 <= 1.0 && goUp3 == 1) // gate 3 opens
{
	r8x1 = r8x1 + 0.01;
}
if(r8x1 >= 0.7 && goUp3 == 0) // gate 3 closes
{
	r8x1 = r8x1 - 0.01;
}
 

r12x1 = r12x1 + D4x; // enemy 4 movement
r12x2 = r12x2 + D4x;

if (r12x1>=0.25 && r12x2>=0.30) // enemy 4
{
	D4x = -0.001;
}
if (r12x1<=0.0 && r12x2<=0.05) // enemy 4
	D4x = 0.001;
	
if( y1+0.01 >= r12y1 && y1 <= r12y2)     // hitting right of enemy 4
{
	if( x1 <= r12x2 && x2 >= r12x1)
	{
		r1x1 = 0.0;
		r1x2 = 1.0;
		r1y1 = 0.0;
		r1y2 = 1.0;
	}
}
	if( y1 >= r12y1 && y1 <= r12y2)			// hitting the left of enemy 4
{
	if( x2 >= r12x1 && x1 <= r12x2)
	{
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
	}
}
	if( y1 <= (r12y2+0.01) && y2 >= (r12y2+0.01))	 //condition for resting on the top of Enemy 4
{
	printf("yes");
if( x2 >= r12x1 && x1 <= r12x2 )
{
	printf("no");


r12x1 = 0.0;
r12x2 = 0.0;
r12y1 = 0.0;
r12y2 = 0.0;
goUp3 = 1;
}
}

	r11x1 = r11x1 + D3x; // enemy 3 movement
r11x2 = r11x2 + D3x;// enemy 3 movement

if (r11x1>=0.65 && r11x2>=0.70) // enemy 3
{
	D3x = -0.01;
}
if (r11x1<=0.5 && r11x2<=0.55) // enemy 3
	D3x = 0.01;



	if( y1 >= (r11y2-0.02) && y1 <= (r11y2))	 //condition for resting on the top of Enemy of 3rd story
{
if( x2 >= r11x1 && x1 <= r11x2 )
{
r11x1 = 0.0;
r11x2 = 0.0;
r11y1 = 0.0;
r11y2 = 0.0;
}
}

	if( y1+0.01 >= r11y1 && y1 <= r11y2)     // hitting right of enemy 3
{
	
	if( x1 <= r11x2 && x2 >= r11x1)
	{
		
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
	}
}
	if( y1 >= r11y1 && y1 <= r11y2)			// hitting the left of enemy 3
{
	if( x2 >= r11x1 && x1 <= r11x2)
	{
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
	}
}

	
if (r10y2<=0.65) // movement of enemy spear 
	D5y = 0.01;

if (r10y2>=0.97) // movement of enemy spear
	D5y = -0.01;

r10y2 = r10y2 + D5y; // enemy spear movement

	if (r10y2<=y2 && r10y2>=y1 && r10x1 >= x1 && r10x2 <= x2)			// hitting the bottom of spear
{
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
}


	
r6x1 = r6x1 + D2x; // enemy 2 movemnt
r6x2 = r6x2 + D2x; // enemy 2 movement

	if( y1 >= (r6y2-0.02) && y1 <= (r6y2))					//condition for resting on the top of Enemy of 2nd story (spider)
{
	if( x2 >= r6x1 && x1 <= r6x2 )
	{
		r6x1 = 0.0;
		r6x2 = 0.0;
		r6y1 = 0.0;
		r6y2 = 0.0;
		goUp2 = 1;
	}
}

if( x2 >= r6x1 && y2 >=r6y1 && y1 <= r6y2 )							//condition for resting on the side of Enemy (spider)of 2nd story
{
	if (x1<(r6x2-0.02) && x2 < r6x2)
	{
		r1y1 = 0.0;
		r1y2 = 1.0;
		r1x1 = 0.0;
		r1x2 = 1.0;
	}
}
if (x1<=r6x2 && x2 >= r6x2 && y1 <= r6y2 && y2 <= (r6y2 + 0.48) && y1 >=r6y1) // resting on side of enemy(spider) 2 right
{
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
}
	if(r6x1 >= 0.7 || r6x2 >= 0.75 )					// ememie 2(spider) movement
	{
		D2x = 0;
		D2y = 0.01;
		r6y1 = r6y1 + D2y;
		r6y2 = r6y2 + D2y;
		
		if(r6y2 >= r2y1 )
		{
			D2y = 0;
			D2x = -0.01;
	
		}
	}
		if(r6x1 <= 0 || r6x2 <= 0)				//spider enemy 2
		{
			D2x = 0;
			D2y = -0.01;
			
			r6y1 = r6y1 + D2y;
			r6y2 = r6y2 + D2y;

		if(r6y1 <= r4y2 || r6y2 <= r4y2 )
		{
			D2y = 0;
			D2x = 0.01;
		}
		}
r5x1= r5x1 + D1x;  // enemy 1 movement
r5x2= r5x2 + D1x;
			
if( y1 >= (r5y2-0.02) && y1 <= (r5y2))					//condition for resting on the top of Enemy
{
	if( x2 >= r5x1 && x1 <= r5x2 )
	{
		r5x1 = 0.0;
		r5x2 = 0.0;
		r5y1 = 0.0;
		r5y2 = 0.0;
		goUp = 1;
	}
}
if( x2 >= r5x1 && y2 <=r5y2 )							//condition for resting on the side of Enemy
{
	if (x1<(r5x2-0.02) && x2 < r5x2)
	{
		r1y1 = 0.0;
		r1y2 = 1.0;
		r1x1 = 0.0;
		r1x2 = 1.0;
	}
} 
if (x1<=r5x2 && x2 >= r5x2 && y1 <= r5y2 && y2 <= (r5y2 + 0.98)) // resting on side of enemy 1 right
{
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
}
if (r5x1 <= 0.7 && r5x2 <= 1)							// enemie movement
{
	D1x = 0.01;
}
if (r5x1 >= 1 && r5x2 >= 0.7)							//emeie movement
{
	D1x = -0.01;
}
if( goUp == 0 )
{
	if( y2 >= r4y1 && y2 <=r4y1+0.1 && x1<r4x2 )		// hitting the bottom of gate of story 1 
	{
		y2 = r4y1;
		y1 = r4y1-0.1;
	}
}
if( goUp2 == 0 )
{
	if( y2 >= r7y1 && y2 <=r7y1+0.1 && x1<r7x2 )		// hitting the bottom of gate of story 2 
	{
		y2 = r7y1;
		y1 = r7y1-0.1;
	}
}
if( goUp3 == 0 )
{
	if( y2 >= r8y1 && y2 <=r8y1+0.1 && x1<r8x2 )		// hitting the bottom of gate of story 3 
	{
		y2 = r8y1;
		y1 = r8y1-0.1;
	}
}

if( y2 >= ry1 && y2 <=ry1+0.1 && x1<rx2 )				// hitting the bottom of story 1 
{
	y2 = ry1;
	y1 = ry1-0.1;
}
if( y1>=ry1+0.05 && y1<=ry1+0.06 && x1 <rx2 )			// resting on the top of story 1
{
	gravityEnable=0;
}
else
{
	gravityEnable=1;
}
if( y1 >= (r3y2-0.02) && y1 <= r3y2)					//condition for resting on the top of redblock of story 1
{
	if( x2 >= r3x1 && x1 <= r3x2 )
	{
		y1 = r3y2;
		y2 = r3y2 + 0.1;
	}
}
if( x2 >= r3x1 && y1 < r3y2)							// Condition for resting on side of redblock of story 1
{
	if (x1<(r3x2 - 0.02) && x2 < r3x2)
	{
		x2 = r3x1;
		x1 = r3x1 - 0.1;
	}
}
if (x1<=r3x2 && y1<r3y2)								//condition for resting on the side of redblock of story(right)
{
	if (x2>r3x2)
	{
		x1 = r3x2;
		x2 = r3x2 + 0.1;
	}
}
	if( y2 >= r2y1 && y2 <=r2y1+0.1 && x1<r2x2 && x2 > r2x1  )  // hitting the bottom of story2
	{
		y2 = r2y1;
		y1 = r2y1-0.1;
	}

if( y1 >= r2y1 && y1 <= r2y2)							//condition for resting on the top of story 2
{
	if( x2 >= r2x1 && x1 <= r2x2 )
	{
		y1 = r2y2;
		y2 = r2y2 + 0.1;
	}
}
	if( y2 >= r9y1 && y2 <=r9y1+0.1 && x1<r9x2 && x2 > r9x1  )  // hitting the bottom of story3
	{
		y2 = r9y1;
		y1 = r9y1-0.1;
	}

if( y1 >= r9y1 && y1 <= r9y2)							//condition for resting on the top of story 3
{
	if( x2 >= r9x1 && x1 <= r9x2 )
	{
		y1 = r9y2;
		y2 = r9y2 + 0.1;
	}
}
if( y2 >= r1y1 && y2 <=r1y1+0.1 && x1<r1x2 && x2 > r1x1  )  // hitting the bottom of greenblock
{
	y2 = r1y1;
	y1 = r1y1-0.1;
}

if( y1 >= r1y1 && y1 <= r1y2)								//condition for resting on the top of greenblock
{
	if( x2 >= r1x1 && x1 <= r1x2 )
	{
		y1 = r1y2;
		y2 = r1y2 + 0.1;
	}
}


if( x1 <= 0 && x2 <= 0.1 )									// condition for not going into -ve x axis
{ 
	x1 = 0.0;
	x2 = 0.1;
}
if( y1 <= 0 && y2 <= 0.1 )									// condition for not going into -ve y axis
{ 
	y1 = 0.0;
	y2 = 0.1;
}
if( x2 >= 1 && x1 >= 0.9)									// condition for not exceeding 1 on the x axis
{
	x1 = 0.9;
	x2 = 1;
}
if( y1 >= 0.9 && y2 >= 1 && levelcounter == 0)									// condition for not exceeding 1 on the y axis
{ 
	goUp = 0;
	goUp2 = 0;
	goUp3 = 0;

	x1 = 0.2;
	x2 = 0.3;
	y1 = 0.05;
	y2 = 0.15;

	levelcounter = 1;
}

}
void conditions2()
{
	    glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, _textureId2); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r19x1,r19y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r19x2,r19y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r19x2,r19y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r19x1,r19y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

r19x1 = r19x1 + D19x; // enemy 4/2 movement
r19x2 = r19x2 + D19x;

if (r19x1>=0.25 && r19x2>=0.30) // enemy 4/2
{
	D19x = -0.001;
}
if (r19x1<=0.0 && r19x2<=0.05) // enemy 4/2
	D19x = 0.001;
	
	if( y1+0.01 >= r19y1 && y1 <= r19y2)     // hitting right of enemy 4/2
{
		if( x1 <= r19x2 && x2 >= r19x1)
	{
	
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
	}
}
	if( y1 >= r19y1 && y1 <= r19y2)			// hitting the left of enemy 4/2
{
	if( x2 >= r19x1 && x1 <= r19x2)
	{
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
	}
}
	if( y1 <= (r19y2+0.01) && y2 >= (r19y2+0.01))	 //condition for resting on the top of Enemy 4/2
{
	printf("yes");
if( x2 >= r19x1 && x1 <= r19x2 )
{
	printf("no");


r19x1 = 0.0;
r19x2 = 0.0;
r19y1 = 0.0;
r19y2 = 0.0;
goUp3 = 1;
}
}

	    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId2); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r20x1,r20y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r20x2,r20y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r20x2,r20y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r20x1,r20y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

	r20x1 = r20x1 + D20x; // enemy 3 movement
r20x2 = r20x2 + D20x;// enemy 3 movement

if (r20x1>=0.65 && r20x2>=0.70) // enemy 3
{
	D20x = -0.01;
}
if (r20x1<=0.5 && r20x2<=0.55) // enemy 3
	D20x = 0.01;



	if( y1 >= (r20y2-0.02) && y1 <= (r20y2))	 //condition for resting on the top of Enemy of 3rd story/2
{
if( x2 >= r20x1 && x1 <= r20x2 )
{
r20x1 = 0.0;
r20x2 = 0.0;
r20y1 = 0.0;
r20y2 = 0.0;
}
}

	if( y1+0.01 >= r20y1 && y1 <= r20y2)     // hitting right of enemy 3/2
{
	
	if( x1 <= r20x2 && x2 >= r20x1)
	{
		
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
	}
}
	if( y1 >= r20y1 && y1 <= r20y2)			// hitting the left of enemy 3/2
{
	if( x2 >= r20x1 && x1 <= r20x2)
	{
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
	}
}
		
	    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId3); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r211x1,r211y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r211x2,r211y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r211x2,r211y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r211x1,r211y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);
if (r211y2<=0.65) // movement of enemy spear /2
	D211y = 0.01;

if (r211y2>=0.97) // movement of enemy spear /2
	D211y = -0.01;

r211y2 = r211y2 + D211y; // enemy spear movement /2

	if (r211y2<=y2 && r211y2>=y1 && r211x1 >= x1 && r211x2 <= x2)			// hitting the bottom of spear/2
{
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
}
	    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId5); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r16x1,r16y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r16x2,r16y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r16x2,r16y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r16x1,r16y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);
	
r16x1 = r16x1 + D16x; // enemy 2 movemnt/2
r16x2 = r16x2 + D16x; // enemy 2 movement/2

	if( y1 >= (r16y2-0.02) && y1 <= (r16y2))					//condition for resting on the top of Enemy of 2nd story (spider)/2
{
	if( x2 >= r16x1 && x1 <= r16x2 )
	{
		r16x1 = 0.0;
		r16x2 = 0.0;
		r16y1 = 0.0;
		r16y2 = 0.0;
		goUp2 = 1;
	}
}
if( x2 >= r16x1 && y2 >=r16y1 && y1 <= r16y2 )							//condition for resting on the side of Enemy (spider)of 2nd story/2
{
	if (x1<(r16x2-0.02) && x2 < r16x2)
	{
		r1y1 = 0.0;
		r1y2 = 1.0;
		r1x1 = 0.0;
		r1x2 = 1.0;
	}
}
if (x1<=r16x2 && x2 >= r16x2 && y1 <= r16y2 && y2 <= (r16y2 + 0.48) && y1 >=r16y1) // resting on side of enemy(spider) 2 right/2
{
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
}
	if(r16x1 >= 0.7 || r16x2 >= 0.75 )					// ememie 2(spider) movement/2
	{
		D16x = 0;
		D2y = 0.01;
		r16y1 = r16y1 + D2y;
		r16y2 = r16y2 + D2y;
		
		if(r16y2 >= r2y1 )
		{
			D2y = 0;
			D16x = -0.01;
	
		}
	}
		if(r16x1 <= 0 || r16x2 <= 0)				//spider enemy 2/2
		{
			D16x = 0;
			D2y = -0.01;
			
			r16y1 = r16y1 + D2y;
			r16y2 = r16y2 + D2y;

		if(r16y1 <= r4y2 || r16y2 <= r4y2 )
		{
			D2y = 0;
			D16x = 0.01;
		}
		}

	    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId5); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r16x1,r16y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r16x2,r16y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r16x2,r16y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r16x1,r16y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);


r17x1= r17x1 + D17x;  // enemy 1 movement/2
r17x2= r17x2 + D17x;
			
if( y1 >= (r17y2-0.02) && y1 <= (r17y2))					//condition for resting on the top of Enemy/2
{
	if( x2 >= r17x1 && x1 <= r17x2 )
	{
		r17x1 = 0.0;
		r17x2 = 0.0;
		r17y1 = 0.0;
		r17y2 = 0.0;
		goUp = 1;
	}
}
if( x2 >= r17x1 && y2 <=r17y2 )							//condition for resting on the side of Enemy/2
{
	if (x1<(r17x2-0.02) && x2 < r17x2)
	{
		r1y1 = 0.0;
		r1y2 = 1.0;
		r1x1 = 0.0;
		r1x2 = 1.0;
	}
} 
if (x1<=r17x2 && x2 >= r17x2 && y1 <= r17y2 && y2 <= (r17y2 + 0.98)) // resting on side of enemy 1 right/2
{
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
}
if (r17x1 <= 0.7 && r17x2 <= 1)							// enemie movement/2
{
	D17x = 0.01;
}
if (r17x1 >= 1 && r17x2 >= 0.7)							//emeie movement/2
{
	D17x = -0.01;
}
        
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId7); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r117x1,r117y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r117x2,r117y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r117x2,r117y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r117x1,r117y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);


r117x1= r117x1 + D117x;  // enemy 1 movement/2
r117x2= r117x2 + D117x;
			
if( y1 >= (r117y2-0.02) && y1 <= (r117y2))					//condition for resting on the top of Enemy/2
{
	if( x2 >= r117x1 && x1 <= r117x2 )
	{
		r117x1 = 0.0;
		r117x2 = 0.0;
		r117y1 = 0.0;
		r117y2 = 0.0;
		goUp = 1;
	}
}
if( x2 >= r117x1 && y2 <=r117y2 )							//condition for resting on the side of Enemy/2
{
	if (x1<(r117x2-0.02) && x2 < r117x2)
	{
		y1 = 0.0;
		y2 = 1.0;
		x1 = 0.0;
		x2 = 1.0;
	}
} 
if (x1<=r117x2 && x2 >= r117x2 && y1 <= r117y2 && y2 <= (r117y2 + 0.98)) // resting on side of enemy 1 right/2
{
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
}
if (r117x1 <= 0.7 && r117x2 <= 1)							// enemie movement/2
{
	D117x = 0.01;
}
if (r117x1 >= 1 && r117x2 >= 0.7)							//emeie movement/2
{
	D117x = -0.01;
}
		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId8); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r4x1,r4y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r4x2,r4y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r4x2,r4y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r4x1,r4y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId8); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r7x1,r7y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r7x2,r7y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r7x2,r7y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r7x1,r7y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId8); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r8x1,r8y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r8x2,r8y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r8x2,r8y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r8x1,r8y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

if( y1 >= 0.9 && y2 >= 1 && levelcounter == 1)									// condition for not exceeding 1 on the y axis
{ 
	goUp = 0;
	goUp2 = 0;
	goUp3 = 0;

	x1 = 0.2;
	x2 = 0.3;
	y1 = 0.05;
	y2 = 0.15;

	levelcounter = 2;
}
}
void keyboardUp(unsigned char mod , int x, int y)
{
if( (int)mod == 119){ //W
Dy = -0.01;
}if( mod == 115 )// S
Dy = -0.01;
if( mod == 100 )// D
Dx = 0;
if( mod == 97 )// A
Dx = 0;
}
bool init()
{
return true;
}
void keyboard(unsigned char mod , int x, int y)
{
switch (mod)
{
case 'w':
	Dy = 0.01;
break;
case 115:
Dy = -0.01;
break;
case 100:
Dx = 0.01;
break;
case 97:
Dx = -0.01;
break;
}
}
void special(int mod , int x, int y)
{
switch (mod)
{
}
}
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId1); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(0.0,0.0,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(1.0,0.0,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(1.0,1.0,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(0.0,1.0,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);


	    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId);

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(x1,y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(x2,y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(x2,y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(x1,y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId2); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r5x1,r5y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r5x2,r5y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r5x2,r5y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r5x1,r5y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);


		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId2); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r11x1,r11y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r11x2,r11y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r11x2,r11y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r11x1,r11y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId2); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r12x1,r12y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r12x2,r12y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r12x2,r12y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r12x1,r12y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId3); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r1x1,r1y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r1x2,r1y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r1x2,r1y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r1x1,r1y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId3); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r3x1,r3y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r3x2,r3y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r3x2,r3y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r3x1,r3y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId4); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(rx1,ry1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(rx2,ry1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(rx2,ry2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(rx1,ry2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);


		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId4); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r2x1,r2y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r2x2,r2y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r2x2,r2y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r2x1,r2y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

if (levelcounter == 0)
{

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId4); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r4x1,r4y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r4x2,r4y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r4x2,r4y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r4x1,r4y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId4); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r7x1,r7y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r7x2,r7y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r7x2,r7y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r7x1,r7y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId4); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r8x1,r8y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r8x2,r8y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r8x2,r8y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r8x1,r8y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

}

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId4); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r9x1,r9y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r9x2,r9y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r9x2,r9y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r9x1,r9y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId3); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r10x1,r10y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r10x2,r10y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r10x2,r10y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r10x1,r10y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId5); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(r6x1,r6y1,0.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(r6x2,r6y1,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(r6x2,r6y2,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(r6x1,r6y2,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);

		if (r1x1 == 0.0 && r1x2 == 1.0 && r1y1 == 0.0 && r1y2 == 1.0)
		{
		glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId6); 

        //Bottom
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(1,1,1);
        glColor4ub(255,255,255,255);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(0.0,0.0,0.0);
        glTexCoord2f(1.0, 0.0); 
        glVertex3f(1.0,0.0,0.0);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(1.0,1.0,0.0);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(0.0,1.0,0.0);

        glEnd();
        glDisable(GL_TEXTURE_2D);
		}

if( levelcounter == 1)
{
	conditions2 ();
}

if (levelcounter == 2)
{
	r1x1 = 0.0;
	r1x2 = 1.0;
	r1y1 = 0.0;
	r1y2 = 1.0;
}

Conditions();
glEnd();
glutSwapBuffers();
}
void Timer(int iUnused)
{
glutPostRedisplay();
glutTimerFunc(30, Timer, 10);
}
void Initialize() {
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    _textureId=loadtexture("abc.tga");
	_textureId1=loadtexture("BackgroundSkyFinalLook.tga");
	_textureId2=loadtexture("exit.tga");
	_textureId3=loadtexture("Stone-Wall-Dark_Half-256x256.tga");
	_textureId4=loadtexture("1ld1fifa.tga");
	_textureId5=loadtexture("0f0f1qne.tga");
	_textureId6=loadtexture("gameover_3_1.tga");
	_textureId7=loadtexture("exit.tga");
	_textureId8=loadtexture("1ld1fifa.tga");
}
int main(int iArgc, char** cppArgv) 
{

glutInit(&iArgc, cppArgv);
glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
glutInitWindowSize(500, 250);
glutInitWindowPosition(200, 200);
glutCreateWindow("XoaX.net");
Initialize();

glutDisplayFunc(Draw);

Timer(0);
glutKeyboardFunc(keyboard);
glutKeyboardUpFunc(keyboardUp);
glutSpecialFunc(special);
if( !init() )
return 1;
glutMainLoop();
return 0;
}
