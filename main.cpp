//create by Kongkiat Aramkhachorndej 5005019350
//How to play
// press w,a,s,d to move character
// press Arrow to rotate camera
// press Enter for reset game
// press x for enable-disable auto rotate camera
// press z for enable-disable auto rotate light

#include <GL/glut.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

#define PI          3.1415926535897932384626433832795
#define SIZE_WIN    500
#define SIZE_ORT    500.0
#define RN          5


	float pos_x	 =  0;
	float pos_y = 0;
	int count = 0 ;
	int yyy = 0;
	int fall = 230;
	int xy1 = 20;
	int xy2 = -20;
	int e = 1;
	int z = 1;

GLfloat theta = 0.0;
GLfloat theta1 = 0.0;
GLint sign = 1;
GLint flag = 1;



double rotate_y=45; 
double rotate_x=30;


const GLfloat light_ambient[]  = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_position[] ={2.0, 5.0, 5.0, 0.0};

const GLfloat mat_ambient[]    = { 0.7, 0.7, 0.7, 1.0 };
const GLfloat mat_diffuse[]    = { 0.8, 0.8, 0.8, 1.0 };
const GLfloat mat_specular[]   = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat high_shininess[] = { 100.0 };

	void Idle(void)
	{
		if(pos_x>=300||pos_x<=-300||pos_y>=300||pos_y<=-300)			//this source make character walk out of way to falling
		fall-= 5; 
		if(fall>0&&pos_x<=100&&pos_x>=-100&&pos_y>=-800&&pos_y<=-300)
		fall = 230;
		if(fall>0&&(pos_x<=-100&&pos_x>=-800)&&(pos_y<=-500&&pos_y>=-800))
		fall = 230;
		if(fall>0&&(pos_x<=-500&&pos_x>=-800)&&(pos_y<=800&&pos_y>=-800))
		fall = 230;
		if(fall>0&&(pos_x<=800&&pos_x>=-800)&&(pos_y<=800&&pos_y>=500))
        fall = 230;
        if(fall>0&&(pos_x<=800&&pos_x>=500)&&(pos_y<=800&&pos_y>=-800))
        fall = 230;
        
        if(e<0){				//theta for auto light
             if ((theta> 0.0))
        sign = sign *(-1);
     theta -= (0.1*sign);}
     
      if(z<0)theta1 += 0.1;			//theta for auto camera
     


     
	glutPostRedisplay();
	} 
void Init(void)
{



     glClearColor(0.0, 0.0, 0.0, 0.0);
     glPointSize(1.0);
     glEnable(GL_DEPTH_TEST);
     
    glEnable (GL_BLEND);
    glShadeModel (GL_FLAT);
    glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  
     
     
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();

     glOrtho(-1000, 1000, -1000, 1000, -1000, 1000);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     

       
}

void Transform(void)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
    glRotatef( rotate_x, 1.0, 0.0, 0.0 ); //manual rotate camera by arrow key
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  
       GLfloat angle = (theta1*PI)/180;
     GLfloat x=10.0;
       gluLookAt((cos(angle)*x)+(sin(angle)*x),0,(-sin(angle)*x)+(cos(angle)*x),0,0,0,0,1,0);  //auto rotate camera by x key

      glPushMatrix();


//route
    glBegin(GL_POLYGON);
  glColor4f( 0.3, 0.3,1 ,0.5);
     glVertex3f(  -300, 10, -300 );      
     glVertex3f(  300,  10, -300 );     
    glVertex3f( 300,  10, 300 );     
     glVertex3f( -300, 10, 300 );        
  glEnd();
            glBegin(GL_POLYGON);
       glColor4f( 0.3, 0.3,1 ,0.5);
            glVertex3f(  -800, 10, -800 );      
     glVertex3f(  -500,  10, -800 );     
    glVertex3f( -500,  10, 800 ); 
        glVertex3f(-800,10,800);   
  glEnd();
  
              glBegin(GL_POLYGON);
       glColor4f( 0.3, 0.3,1 ,0.5);
            glVertex3f(   -500, 10, 800 );      
     glVertex3f(  -500,  10, 500 );     
    glVertex3f( 500,  10, 500 ); 
        glVertex3f(500,10,800);   
  glEnd();
  
                glBegin(GL_POLYGON);
       glColor4f( 0.3, 0.3,1 ,0.5);
            glVertex3f(  800, 10, -800 );      
     glVertex3f(  500,  10, -800 );     
    glVertex3f( 500,  10, 800 ); 
        glVertex3f(800,10,800);     
  glEnd();
  
                  glBegin(GL_POLYGON);
       glColor4f( 0.3, 0.3,1 ,0.5);
            glVertex3f(   -500, 10, -800 );      
     glVertex3f(  -500,  10, -500 );     
    glVertex3f( 100,  10, -500 ); 
        glVertex3f(100,10,-800);   
  glEnd();
                    glBegin(GL_POLYGON);
       glColor4f( 0.3, 0.3,1 ,0.5);
            glVertex3f(   -500, 10, -800 );      
     glVertex3f(  -500,  10, -500 );     
    glVertex3f( 100,  10, -500 ); 
        glVertex3f(100,10,-800);   
  glEnd();
  glBegin(GL_POLYGON);
         glColor4f( 0.3, 0.3,1 ,0.5);
            glVertex3f(   -100, 10, -300 );      
     glVertex3f(  -100,  10, -500 );     
    glVertex3f( 100,  10, -500 ); 
        glVertex3f(100,10,-300);
  glEnd();

glBegin(GL_POLYGON);
       glColor4f( 0.3, 0.3,1 ,0.1);
            glVertex3f(   100, 10, -800 );      
     glVertex3f(  100,  -1000, -800 );     
    glVertex3f( -800,  -1000, -800 ); 
        glVertex3f(-800,10,-800);   
  glEnd();
glBegin(GL_POLYGON);
       glColor4f( 0.3, 0.3,1 ,0.1); 
    glVertex3f( -800,  -1000, -800 ); 
        glVertex3f(-800,10,-800);   
        glVertex3f(   -800, 10, 800 );      
     glVertex3f(  -800,  -1000, 800 );    
  glEnd();
  glBegin(GL_POLYGON);
       glColor4f( 0.3, 0.3,1 ,0.1); 
        glVertex3f(   -800, 10, 800 );      
     glVertex3f(  -800,  -1000, 800 );    
         glVertex3f( 800,  -1000, 800 ); 
        glVertex3f(800,10,800);   
  glEnd();
glBegin(GL_POLYGON);
       glColor4f( 0.3, 0.3,1 ,0.1); 
    glVertex3f( 800,  -1000, -800 ); 
        glVertex3f(800,10,-800);   
        glVertex3f(   800, 10, 800 );      
     glVertex3f(  800,  -1000, 800 );    
  glEnd();
glBegin(GL_POLYGON);
       glColor4f( 0.3, 0.3,1 ,0.1); 
    glVertex3f( 800,  -1000, -800 ); 
        glVertex3f(800,10,-800);   
        glVertex3f(   500, 10, -800 );      
     glVertex3f(  500,  -1000, -800 );    
  glEnd();
  glBegin(GL_POLYGON);
         glColor4f( 0.3, 0.3,1 ,0.1);  
        glVertex3f(   500, 10, -800 );      
     glVertex3f(  500,  -1000, -800 );    
         glVertex3f( 500,  -1000, 500 ); 
        glVertex3f(500,10,500);  
  glEnd();
    glBegin(GL_POLYGON);
         glColor4f( 0.3, 0.3,1 ,0.1);    
         glVertex3f( 500,  -1000, 500 ); 
        glVertex3f(500,10,500);  
        glVertex3f(   -500, 10, 500 );      
     glVertex3f(  -500,  -1000, 500 );  
  glEnd();
      glBegin(GL_POLYGON);
         glColor4f( 0.3, 0.3,1 ,0.1);     
        glVertex3f(   -500, 10, 500 );      
          glVertex3f(  -500,  -1000, 500 );  
          glVertex3f( -500,  -1000, -500 ); 
        glVertex3f(-500,10,-500); 
  glEnd();
        glBegin(GL_POLYGON);
         glColor4f( 0.3, 0.3,1 ,0.1);     
          glVertex3f( -500,  -1000, -500 ); 
        glVertex3f(-500,10,-500); 
        glVertex3f(   -100, 10, -500 );      
          glVertex3f(  -100,  -1000, -500 );  
  glEnd();
          glBegin(GL_POLYGON);
         glColor4f( 0.3, 0.3,1 ,0.1);     
        glVertex3f(   -100, 10, -500 );      
          glVertex3f(  -100,  -1000, -500 );  
        glVertex3f( -100,  -1000, -300 ); 
        glVertex3f(-100,10,-300); 
  glEnd();
            glBegin(GL_POLYGON);
         glColor4f( 0.3, 0.3,1 ,0.1);     
        glVertex3f( -100,  -1000, -300 ); 
        glVertex3f(-100,10,-300); 
        glVertex3f(   -300, 10, -300 );      
          glVertex3f(  -300,  -1000, -300 );  
  glEnd();
              glBegin(GL_POLYGON);
         glColor4f( 0.3, 0.3,1 ,0.1);     
        glVertex3f(   -300, 10, -300 );      
          glVertex3f(  -300,  -1000, -300 );  
          glVertex3f( -300,  -1000, 300 ); 
        glVertex3f(-300,10,300); 
  glEnd();
                glBegin(GL_POLYGON);
         glColor4f( 0.3, 0.3,1 ,0.1);     
          glVertex3f( -300,  -1000, 300 ); 
        glVertex3f(-300,10,300); 
        glVertex3f(   300, 10, 300 );      
          glVertex3f(  300,  -1000, 300 );  
  glEnd();
                  glBegin(GL_POLYGON);
         glColor4f( 0.3, 0.3,1 ,0.1);     
        glVertex3f(   300, 10, 300 );      
          glVertex3f(  300,  -1000, 300 );  
         glVertex3f( 300,  -1000, -300 ); 
        glVertex3f(300,10,-300); 
  glEnd();
                    glBegin(GL_POLYGON);
         glColor4f( 0.3, 0.3,1 ,0.1);      
         glVertex3f( 300,  -1000, -300 ); 
        glVertex3f(300,10,-300); 
                glVertex3f(   100, 10, -300 );      
          glVertex3f(  100,  -1000, -300 ); 
  glEnd();
                      glBegin(GL_POLYGON);
         glColor4f( 0.3, 0.3,1 ,0.1);      
                glVertex3f(   100, 10, -300 );      
          glVertex3f(  100,  -1000, -300 ); 
                   glVertex3f( 100,  -1000, -800 ); 
        glVertex3f(100,10,-800); 
  glEnd();




				//human
glPushMatrix();
		  glTranslatef(pos_x,fall,pos_y);
		  glRotatef(yyy,0,1,0);
		glPushMatrix();
  glColor3f(0.0, 0.5, 0.0);
			glTranslatef(0.0, 0.0, 0.0);
			glutSolidSphere(75, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 1, 1.0);
			glTranslatef(0.0, 90.0, 0.0); 
			glutSolidSphere(40, 20, 20); 

			glColor3f(0.0, 0.0, 0.0); 
			glPushMatrix();
			
				glPushMatrix();
					glTranslatef(-20, 20.0, 30.0);
					glutSolidSphere(8, 20, 20); 
				glPopMatrix();
				glPushMatrix();
					glTranslatef(20.0, 20.0, 30.0);
					glutSolidSphere(8, 20, 20); 
				glPopMatrix();
			glPopMatrix();

			glColor3f(1.0, 0.5, 0.5); 
			glPushMatrix();
				glTranslatef(0.0, 95.0, 35.0);
				glutSolidCone(10, 30, 10, 20); 
			glPopMatrix(); 
			
			glPushMatrix();
            glColor3f(0.0, 0.5, 0.0);
				glTranslatef(0.0, 115.0, 0);
							glRotatef(-90,1,0,0);
				glutSolidCone(40, 100, 20, 20); 
			glPopMatrix(); 
		
glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
glTranslatef(40.0, -60.0, 0);
glRotatef(xy1,0,0,1);
  glScalef(20, 120, 20);
  glutSolidCube(1.0);
  glPopMatrix();
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
glTranslatef(40.0, -160.0, 0);
glRotatef(xy2,0,0,1);
  glScalef(20, 120, 20);
  glutSolidCube(1.0);
			glPopMatrix();
		
			glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
glTranslatef(-40.0, -60.0, 0);
glRotatef(xy2,0,0,1);
  glScalef(20, 120, 20);
  glutSolidCube(1.0);
  glPopMatrix();
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
glTranslatef(-40.0, -160.0, 0);
glRotatef(xy1,0,0,1);
  glScalef(20, 120, 20);
  glutSolidCube(1.0);
			glPopMatrix();
		glRotatef(180,0,0,1);	
		glPushMatrix();
		glRotatef(30,0,0,1);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
glTranslatef(40.0, -60.0, 0);
glRotatef(xy1,0,0,1);
  glScalef(20, 120, 20);
  glutSolidCube(1.0);
  glPopMatrix();
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
glTranslatef(40.0, -160.0, 0);
glRotatef(xy2,0,0,1);
  glScalef(20, 120, 20);
  glutSolidCube(1.0);
			glPopMatrix();
		glPopMatrix();
		
				glPushMatrix();
		glRotatef(-30,0,0,1);
			glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
glTranslatef(-40.0, -60.0, 0);
glRotatef(xy2,0,0,1);
  glScalef(20, 120, 20);
  glutSolidCube(1.0);
  glPopMatrix();
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
glTranslatef(-40.0, -160.0, 0);
glRotatef(xy1,0,0,1);
  glScalef(20, 120, 20);
  glutSolidCube(1.0);
			glPopMatrix();
				glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		
  
  //flag
  glPushMatrix();
   glTranslatef(0.0, -90.0, 0);
  glPushMatrix();
  glColor3f(1.0, 1.0, 1.0);
  glTranslatef(650.0, 200.0, -650);
  glScalef(10, 200, 10);
  glutSolidCube(1.0);
  glPopMatrix();
   glPushMatrix();
  glTranslatef(650.0, 200.0, -650);
  glBegin(GL_POLYGON);
       glColor4f( 1, 0,0 ,1);
       
            glVertex3f(   0, 100, 0 );      
     glVertex3f(  0,  0, 0 );     
    glVertex3f( 100,  10, 0 ); 
  glEnd();
  glPopMatrix();
   glPopMatrix();
  
       glPushMatrix();
        glRotatef(theta,1.0,0.0,0.0);
        glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glPopMatrix();
    

  glFlush();
    
  glutSwapBuffers();
}


void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
 
  //  Request display update
  glutPostRedisplay();
 
}

void KeyboardKey(GLubyte Key,GLint X,GLint Y)        
{
         switch (tolower(Key))
         {
                case 0x7a:		//press z
                e=-e;
                break;
                case 0x78:		//press x
                z=-z;
                break;
                case 0x77:		//press w
                pos_y -= 20;
                yyy =180;
                xy1 *= -1;
                xy2 *= -1;
                break;
                case 0x61:		//press a
                pos_x -= 20;
                yyy = 270;
                xy1 *= -1;
                xy2 *= -1;
                break;
                case 0x73:		//press s
                pos_y +=20;
                yyy = 360;
                xy1 *= -1;
                xy2 *= -1;
                break;
                case 0x64:		//press d
                pos_x += 20;
                yyy = 90;
                xy1 *= -1;
                xy2 *= -1;
                break;
                case 13:			//press enter
                pos_x =0;
                pos_y =0;
                fall = 230;
                break;
                 case 0x1B :         	//press escape
                 exit(0);
                 break;
					}
					glutPostRedisplay();
					}
					


int main(int argc, char** argv)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(SIZE_WIN, SIZE_WIN);
	glutInitWindowPosition(SIZE_WIN, 0);
	glutCreateWindow("Transform3D");

	Init();

	glutDisplayFunc(Transform);	
   glutIdleFunc(Idle);
   glutKeyboardFunc(KeyboardKey);
   glutSpecialFunc(specialKeys);

    glClearColor(1,1,1,1);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 

	glutMainLoop();

    return 0;
}

