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

struct Vector3f
{
    
	float x;
	float y;
	float z;
    
	Vector3f(float a = 0, float b = 0, float c = 0) : x(a), y(b), z(c) 
	{
        
	}
    
	bool operator==(Vector3f &rhs) const
	{
		return (x == rhs.x && y == rhs.y && z == rhs.z);
	}
};

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


Vector3f eyePos(0,0,5);
Vector3f centerPos(0,0,0);
bool fullscreen = false;
GLfloat sphereRadius = 0.25;
bool toggle = false;
float rotation = 0;

Algorithm myAlgorithm;

void Animate (int value);
void RenderScene();
void Reshape(int width, int height);
void keyPressed(unsigned char key, int mousePosX, int mousePosY);
void init(void);


void keyPressed(unsigned char key, int mousePosX, int mousePosY)
{
    
    if (key == 'r')
    {
        if (fullscreen)
        {
            glutReshapeWindow(glutGet(GLUT_INIT_WINDOW_WIDTH),glutGet(GLUT_INIT_WINDOW_HEIGHT));
            glutPositionWindow(glutGet(GLUT_INIT_WINDOW_X),glutGet(GLUT_INIT_WINDOW_Y));
            fullscreen = false;
        }
        else
        {
            glutFullScreen();
            fullscreen = true;
        }
    }
    else if (key == 'w')
	{
        eyePos.y += 0.5;
        centerPos.y += 0.5;
	}
    else if (key == 's')
	{
        eyePos.y += -0.5;
        centerPos.y += -0.5;
	}
    else if (key == 'a')
	{
        eyePos.x += -0.5;
        centerPos.x += -0.5;
	}
    else if (key == 'd')
	{
        eyePos.x += 0.5;
        centerPos.x += 0.5;
	}
	else if (key==27) // ESC
	{
		exit(0);
	}
    else if (key == 'k')
    {
        eyePos.z += 0.5;
    }
    else if (key == 'l')
    {
        eyePos.z += -0.5;
    }
	else if (key == 'o')
	{
		eyePos.y += +0.5;
	}
	else if (key == 'p')
	{
		eyePos.y += -0.5;
	}
}

void Animate (int value)    
{
	// magic

    
    /*if (eyePos.x >= 20 && eyePos.y >= 20) {
        toggle = true;
    }
    else if (eyePos.x <= 0 && eyePos.y <= 0)
    {
        toggle = false;
    }
    
    if (!toggle) {
        ++eyePos.x;
        ++eyePos.y;
    }
    else
    {
        --eyePos.x;
        --eyePos.y;
    }*/
    
    ++rotation;
    if (rotation>=360) {
        rotation = 0;
    }
    
	glutPostRedisplay();
    
	glutTimerFunc(10, Animate, ++value); // ms  
}

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();
	
	// Kameraposition ist dynamisch
	gluLookAt ( eyePos.x,  eyePos.y,  eyePos.z,
               centerPos.x,  centerPos.y,  centerPos.z, 
               0., 1., 0.);
    
    //glRotated(rotation, 1, 1, 1);
    
    Population myPopulation = myAlgorithm.getPopulation();
    
    for (unsigned int i=0,j=0; i<myPopulation.getNumberOfFoldings() ; ++i, j+=10) {
        Folding myFolding = myPopulation.getFolding(i);
        
        Vector2i position;
        
        for (unsigned int i=0; i<myFolding.getSize(); ++i) {
            position = myFolding.getElement(i).getPosition();
            position.x += j;
            //position.y += j;
            glPushMatrix();
            if (myFolding.getElement(i).isHydrophob()) {
                glColor3f(0, 0, 0);
            }
            else
            {
                glColor3f(1, 1, 1);
            }
            glTranslatef(position.x, position.y , 0);
            glutSolidSphere(sphereRadius, 30, 30);
            glPopMatrix();
            
            if (i==myFolding.getSize()-1) {
                continue;
            }
            
            ViewingDirection viewingDirection = myFolding.getElement(i).getViewingDirection();
            Direction direction = myFolding.getElement(i).getDirection();
            
            
            glPushMatrix();
            glTranslatef(position.x, position.y, 0);
            glColor3f(0, 1, 0);
            if (((viewingDirection == East) && (direction == Left)) ||
                ((viewingDirection == North) && (direction == Straight)) ||
                ((viewingDirection == West) && (direction == Right)))
            {
                glPushMatrix();
                glRotatef(90, 0, 0, 1); // Hoch
                glTranslatef(0.5, 0, 0);
                glScalef((1/sphereRadius)*sphereRadius, 0.1, 0.1);
                glutSolidCube(1);
                glPopMatrix();
            }
            else if (((viewingDirection == East) && (direction == Straight)) ||
                     ((viewingDirection == South) && (direction == Left)) ||
                     ((viewingDirection == North) && (direction == Right)))
            {
                glPushMatrix();         // Rechts
                glTranslatef(0.5, 0, 0);
                glScalef((1/sphereRadius)*sphereRadius, 0.1, 0.1);
                glutSolidCube(1);
                glPopMatrix();
            }
            else if (((viewingDirection == East) && (direction == Right)) ||
                     ((viewingDirection == West) && (direction == Left)) ||
                     ((viewingDirection == South) && (direction == Straight)))
            {
                glPushMatrix();
                glRotatef(270, 0, 0, 1); // Runter
                glTranslatef(0.5, 0, 0);
                glScalef((1/sphereRadius)*sphereRadius, 0.1, 0.1);
                glutSolidCube(1);
                glPopMatrix();
            }
            else if (((viewingDirection == West) && (direction == Straight)) ||
                     ((viewingDirection == North) && (direction == Left)) ||
                     ((viewingDirection == South) && (direction == Right))) // Links
            {
                glPushMatrix();
                glRotatef(180, 0, 0, 1); // links
                glTranslatef(0.5, 0, 0);
                glScalef((1/sphereRadius)*sphereRadius, 0.1, 0.1);
                glutSolidCube(1);
                glPopMatrix();
            }
            
            glPopMatrix();
            
        }
        
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
    
    /*if (width <= height) 
    {
        glOrtho( -2., 2., -2. / aspectRatio , 2. / aspectRatio , 0.0, 150);
    }
    else
    {
        glOrtho( -2. * aspectRatio , 2. * aspectRatio , -2., 2., 0.0, 150);
    }*/
    
    gluPerspective(90.f, aspectRatio, 0.1f, 150.0f);
    
	// Matrix f¸r Modellierung/Viewing 
	glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
    glClearColor(0,0,1, 1.0 );
	glEnable(GL_DEPTH_TEST);
    
    /*do {
        myAlgorithm.getPopulation().killPopulation();
        myAlgorithm.run(SEQ20,1);
    } while ((myAlgorithm.getPopulation().getFolding(0).getOverlaps())!=0);*/
    
    myAlgorithm.run(SEQ20, 50);

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