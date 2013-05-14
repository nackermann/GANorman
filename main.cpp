#include <iostream>
#include <string>

#include "algorithm.h"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


//#include "folding.h"
//#include "population.h"

// benchmark sequences for the 2d HP model
// 0 = hydrophil, "white"
// 1 = hydrophob, "black"
// source: Ron Unger, John Moult: Genetic Algorithms for Protein Folding Simulations,
//         Journal of Molecular Biology, Vol. 231, No. 1, May 1993

std::string SEQ20 = "10100110100101100101";
std::string SEQ24 = "110010010010010010010011";
std::string SEQ25 = "0010011000011000011000011";
std::string SEQ36 = "000110011000001111111001100001100100";
std::string SEQ48 = "001001100110000011111111110000001100110010011111";
std::string SEQ50 = "11010101011110100010001000010001000101111010101011";


Algorithm myAlgorithm;

void Animate (int value);
void RenderScene();
void Reshape(int width, int height);
void keyPressed(unsigned char key, int mousePosX, int mousePosY);
void init(void);


void keyPressed(unsigned char key, int mousePosX, int mousePosY)
{
	//inputmanager.keyPressed(key,mousePosX,mousePosY);
}

void Animate (int value)    
{
	// magic
    
	glutPostRedisplay();
    
	glutTimerFunc(15, Animate, ++value);     
}

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();
	
	// Kameraposition ist dynamisch
	gluLookAt (0,  0,  5,
               0,  0,  0, 
               0., 1., 0.);
    
    Population myPopulation = myAlgorithm.getPopulation();
    Folding myFolding = myPopulation.getFolding(0);
    
    Vector2i position;
    
    for (unsigned int i=0; i<myFolding.getSize(); ++i) {
        position = myFolding.getElement(i).getPosition();
        glPushMatrix();
        glTranslatef(position.x, position.y , 0);
        glutSolidSphere(0.25, 100, 100);
        glPopMatrix();
    }
    
    glutSwapBuffers();
	glFlush();
}

void Reshape(int width, int height)
{
    GLfloat aspectRatio;
    
	// Matrix f¸r Transformation: Frustum->viewport 
	glMatrixMode(GL_PROJECTION); 
    
	// Aktuelle Transformations-Matrix zuruecksetzen 
	glLoadIdentity ();
    
	// Viewport definieren
	glViewport(0, 0, width, height);
    
	// Frustum definieren (siehe unten) 
    
	aspectRatio = (GLfloat)width/(GLfloat)height;
	gluPerspective(60.f, aspectRatio, 0.1f, 150.0f);
    
	// Matrix f¸r Modellierung/Viewing 
	glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
    glClearColor(0,0,1, 1.0 );
	glEnable(GL_DEPTH_TEST);
    
    myAlgorithm.run(SEQ20,10);
    
	myAlgorithm.browsePopulation(std::cout);

	glClearDepth(1); 
}

int main(int argc, char **argv)
{
    
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    unsigned int width = 800;
    unsigned int height = 600;
    
	glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH)/2-width/2,glutGet(GLUT_SCREEN_HEIGHT)/2-height/2);
	glutInitWindowSize(width,height);
	glutCreateWindow("Norman Ackermann; Manuel Reinfurt");
    
    glutDisplayFunc(RenderScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(keyPressed);
    
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc(10, Animate, 0);
    
	init();




	glutMainLoop();
    
    
}