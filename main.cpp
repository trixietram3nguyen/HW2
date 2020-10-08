/**************************************************************************
//COSC4370
//hw2 - Basic openGL
//Trixie Tram Nguyen - 1518295
//Compute output to match 2 of the 3 samples for the first 2 problems
//For the last one do something creative
***************************************************************************/

#define _USE_MATH_DEFINES //to use pi
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = { 0, 1, 4, 1 }; // TODO: Your code here! setup a proper camera position. It should be 4 dimentions homogeneous coordinate, first three elements represent position and 4th element should be 1.
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples.

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {
	//total teapots are 10
	int maxTeapot = 10;

	//loop 10 time to rotate and translate each teapot
	for (int solidTeapot = 0; solidTeapot < maxTeapot; solidTeapot++)
	{
		//glPushMatrix and glPopMatrix to preserve each translatation and rotation to each teapot
		glPushMatrix();
		//use sine and cosine function to get the position of each teapot
		glTranslatef(sin((360 / maxTeapot * solidTeapot) * M_PI / 180 + 1.50), cos((360 / maxTeapot * solidTeapot) * M_PI / 180 + 1.50), 0);
		glRotatef((0 - 360/maxTeapot) * solidTeapot - 1.50, 0, 0, 1);
		glutSolidTeapot(0.25);
		glPopMatrix();
	}
}

void problem2() {
	//total cubes are 15
	int maxCube = 15;
	
	//outside forloop to iterate through each cube
	for (int solidCube = 0; solidCube <= maxCube; solidCube++)
	{
		//inside forloop to display the cube to a required height
		for (int height = 0; height < solidCube; height++)
		{
			//glPushMatrix and glPopMatrix to preserve each translatation to each cube
			glPushMatrix();
			glTranslatef(-2 + solidCube * 0.25, 0.0125 * pow(height, 1.5), 0);
			glutSolidCube(0.25);
			glPopMatrix();
		}
	}
}

void problem3() {
	//total teapots are 10
	int maxTeapot = 10;

	//translate spots of the cubes
	float translateSpot[] = { 1.0, 1.5 };
	//sizes of the cubes
	float size = 0.0;

	//display the small cube in the middle
	glutSolidCube(0.10);

	//display the cubes in different positions with different sizes around the main output
	for (int i = 0; i < 2; i++)
	{
		//the further spot, result in a bigger cube
		if (translateSpot[i] == 1)
		{
			size = 0.25;
		}
		else
		{
			size = 0.5;
		}

		//forloop to display the cubes in 4 different spots
		for (int j = 0; j < 4; j++)
		{
			if (j == 0)
			{
				glPushMatrix();
				glTranslatef(0, translateSpot[i], 0);
				glutSolidCube(size);
				glPopMatrix();
			}
			else if (j == 1)
			{
				glPushMatrix();
				glTranslatef(0, -translateSpot[i], 0);
				glutSolidCube(size);
				glPopMatrix();
			}
			else if (j == 2)
			{
				glPushMatrix();
				glTranslatef(translateSpot[i], 0, 0);
				glutSolidCube(size);
				glPopMatrix();
			}
			else
			{
				glPushMatrix();
				glTranslatef(-translateSpot[i], 0, 0);
				glutSolidCube(size);
				glPopMatrix();
			}
		}
		
	}

	//modify this from problem 1, to get an X with teapots
	//display the teapot look like a diagonal up direction
	for (int solidTeapot = 0; solidTeapot < maxTeapot; solidTeapot++)
	{
		//glPushMatrix and glPopMatrix to preserve each translatation and rotation to each teapot
		glPushMatrix();
		//use sine and cosine function to get the position of each teapot
		glTranslatef(sin((360 / maxTeapot * solidTeapot) * M_PI / 180 + 1), cos((360 / maxTeapot * solidTeapot) * M_PI / 180 - 1), 0);
		glRotatef((0 - 360 / maxTeapot) * solidTeapot, 0, 0, 1);
		glutSolidTeapot(0.25);
		glPopMatrix();
	}

	//display the teapot look like a diagonal down direction
	for (int solidTeapot = 0; solidTeapot < maxTeapot; solidTeapot++)
	{
		//glPushMatrix and glPopMatrix to preserve each translatation and rotation to each teapot
		glPushMatrix();
		//use sine and cosine function to get the position of each teapot
		glTranslatef(sin((360 / maxTeapot * solidTeapot) * M_PI / 180 - 1), cos((360 / maxTeapot * solidTeapot) * M_PI / 180 + 1), 0);
		glRotatef((0 - 360 / maxTeapot) * solidTeapot, 0, 0, 1);
		glutSolidTeapot(0.25);
		glPopMatrix();
	}

}

void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); // x axis
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0); // y axis
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//set lower left coner of the viewport to be 0 and actual height and width of viewport by window height and width
	glViewport(0, 0, windowWidth, windowHeight);

	//calulate the ratio for aspect of perspective by dividing window width and height
	float ratio = (float)windowWidth / (float)windowHeight;
	//set field view to 50, aspect, near distance is 1, and far distance is 1000
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//gluLookAt to view the display, first 3 numbers which is eye point depend on the camera postions,
	//middle 3 numbers which is the reference point is the center
	//last 3 numbers which is the direction of the up vector
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot, 0, 1, 0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0]) * .1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1, (y - lastPos[1]) * .1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	//in this case use 1,2,3 to display the output of the problem so key minus character 0 which leave the binary of the numbers
	curProblem = key - '0';
	if (key == 'q' || key == 'Q' || key == 27)
	{
		exit(0);
	}

	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}