// Bai3.cpp : Defines the entry point for the console application.
//
#include <math.h>
#include <iostream>
#include "supportClass.h"
#include "Mesh.h"

using namespace std;

int		screenWidth = 600;
int		screenHeight = 300;

float wheelAngle = 0;

Mesh	tetrahedron;
Mesh	cube;
Mesh cuboid;
Mesh cylinder;
Mesh holdcylinder;
Mesh shape1;
Mesh shape2;
Mesh shape3;
Mesh shape4;
Mesh shape5;
Mesh cone;

int		nChoice = 1;

void holder() {
	Mesh holder_cuboid;
	Mesh holder_shape4;
	Mesh holder_shape5;
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	holder_shape5.Shape5(7, 2, 0.5, 0.5);
	holder_shape5.SetColor(1);
	holder_shape5.DrawColor();
	glPopMatrix();


	holder_cuboid.CreateCuboid(0.5, 2, 0.25);
	holder_cuboid.SetColor(2);
	glPushMatrix();
	glTranslatef(0, 1.5, 0.25);
	holder_cuboid.DrawColor();
	glPopMatrix();

	holder_shape4.Shape4(1.5, 2, 0.25, 0.5);
	holder_shape4.SetColor(3);
	
	glPushMatrix();
	glTranslatef(0, 3.5 - 1, 0.75);
	holder_shape4.DrawColor();
	glPopMatrix();

}


void wheel() {
	Mesh wheel_shape1;
	wheel_shape1.Shape1(50, 0.5, 2, 1);
	wheel_shape1.SetColor(4);
	glPushMatrix();
	glRotatef(wheelAngle, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	wheel_shape1.DrawColor();
	glPopMatrix();
}


void slider() {
	Mesh slider_cuboid;
	Mesh slider_cylinder;
	Mesh slider_shape2;

	slider_cuboid.CreateCuboid(0.5, 5, 0.25);
	slider_cuboid.SetColor(5);
	glPushMatrix();
	glTranslatef(0, 0, 5);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -2.5, 0);
	slider_cuboid.DrawColor();
	glPopMatrix();


	slider_shape2.Shape2(100, 1,  2 , 1.5 , 2.5, 0.75, 0.75);
	slider_shape2.SetColor(1);


	slider_cylinder.CreateCylinder(100, 5, 0.1);
	slider_cylinder.SetColor(2);
	// First cylinder (along Z)
	glPushMatrix();
	glRotatef(-35, 0, 1, 0);
	glTranslatef(0, 0, 1.8);
	slider_cylinder.SetColor(2);
	slider_cylinder.DrawColor();
	glPopMatrix();

	// Second cylinder (along X)
	glPushMatrix();
	glRotatef(35, 0, 1, 0);
	glTranslatef(0, 0.5, 1.8); // move slightly aside
	slider_cylinder.SetColor(3);
	slider_cylinder.DrawColor();
	glPopMatrix();


	slider_shape2.DrawColor();
}


void chot_dem() {
	Mesh chot_dem_cylinder1;
	Mesh chot_dem_cylinder2;
	Mesh chot_dem_shape3;

	

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	chot_dem_cylinder1.CreateCylinder(50, 1, 0.5);
	chot_dem_cylinder1.SetColor(1);
	chot_dem_cylinder1.DrawColor();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	chot_dem_cylinder2.CreateCylinder(50, 3, 0.15);
	chot_dem_cylinder2.SetColor(2);
	chot_dem_cylinder2.DrawColor();
	glPopMatrix();

	chot_dem_shape3.Shape3(0.5, 1, 25);
	chot_dem_shape3.SetColor(3);
	chot_dem_shape3.DrawColor();
}



void drawAxis()
{
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(4, 0, 0);

	glVertex3f(0, 0, 0);
	glVertex3f(0, 4, 0);

	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 4);
	glEnd();
}


void myDisplay()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(4.5, 4, 2, 0, 0, 0, 0, 1, 0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawAxis();


	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	holder();
	glPopMatrix();
	
	glPushMatrix();
	
	if (wheelAngle >= 45 && wheelAngle <= 45 + 270) {
		glTranslatef(0, -1, -0.85);
	}
	else{
		glTranslatef(0, -3, -0.85);
	}
	glRotatef(-90, 1, 0, 0);
	glScalef(0.8, 0.8, 0.8);
	slider();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -3, -0.85);
	wheel();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -3, -0);
	glRotatef(-90, 1, 0, 0);
	chot_dem();
	glPopMatrix();

	//glViewport(0, 0, screenWidth / 2, screenHeight);

	//drawAxis();

	//glColor3f(0, 0, 0);
	//if (nChoice == 1)
	//	tetrahedron.DrawWireframe();
	//else if (nChoice == 2)
	//	cube.DrawWireframe();
	//else if (nChoice == 3)
	//	cuboid.DrawWireframe();
	//else if (nChoice == 4)
	//	cylinder.DrawWireframe();
	//else if (nChoice == 5)
	//	holdcylinder.DrawWireframe();
	//else if (nChoice == 6)
	//	shape1.DrawWireframe();
	//else if (nChoice == 7)
	//	shape2.DrawWireframe();
	//else if (nChoice == 8)
	//	shape3.DrawWireframe();
	//else if (nChoice == 9)
	//	shape4.DrawWireframe();
	//else if(nChoice == 10)
	//	shape5.DrawWireframe();
	//else if(nChoice == 11)
	//	cone.DrawWireframe();

	//glViewport(screenWidth / 2, 0, screenWidth / 2, screenHeight);

	//drawAxis();
	//if (nChoice == 1)
	//	tetrahedron.DrawColor();
	//else if (nChoice == 2)
	//	cube.DrawColor();
	//else if (nChoice == 3)
	//	cuboid.DrawColor();
	//else if (nChoice == 4)
	//	cylinder.DrawColor();
	//else if (nChoice == 5)
	//	holdcylinder.DrawColor();
	//else if (nChoice == 6)
	//	shape1.DrawColor();
	//else if (nChoice == 7)
	//	shape2.DrawColor();
	//else if (nChoice == 8)
	//	shape3.DrawColor();
	//else if (nChoice == 9)
	//	shape4.DrawColor();
	//else if (nChoice == 10)
	//	shape5.DrawColor();
	//else if (nChoice == 11)
	//	cone.DrawColor();

	glFlush();
	glutSwapBuffers();
}

void myInit()
{
	float	fHalfSize = 4;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-fHalfSize, fHalfSize, -fHalfSize, fHalfSize, -1000, 1000);
}



void myKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
		wheelAngle += 5.0f;  // rotate clockwise
		if (wheelAngle >= 360.0f) wheelAngle -= 360.0f;
		glutPostRedisplay(); // ask GLUT to redraw
		break;
	case '2':
		wheelAngle -= 5.0f;  // rotate counterclockwise
		if (wheelAngle < 0.0f) wheelAngle += 360.0f;
		glutPostRedisplay();
		break;
	}
}


int main(int argc, char* argv[])
{
	//cout << "1. Tetrahedron" << endl;
	//cout << "2. Cube" << endl;
	//cout << "3. Cuboid" << endl;
	//cout << "4. Cylinder" << endl;
	//cout << "5. Hole Cylinder" << endl;
	//cout << "6. Shape1" << endl;
	//cout << "7. Shape2" << endl;
	//cout << "8. Shape3" << endl;
	//cout << "9. Shape4" << endl;
	//cout << "10. Shape5" << endl;
	//cout << "11. Cone" << endl;
	//cout << "Input the choice: " << endl;
	//cin >> nChoice;

	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Lab 2"); // open the screen window

	tetrahedron.CreateTetrahedron();
	cube.CreateCube(1);
	cuboid.CreateCuboid(2, 1, 1);
	cylinder.CreateCylinder(20, 2, 1);
	holdcylinder.CreateCylinderWithHole(20, 2, 1, 0.5);
	shape1.Shape1(50, 2, 2, 1.5);
	shape2.Shape2(50, 0.5, 1.5 , 1, 2, 1, 5);
	shape3.Shape3(2, 5, 25);
	shape4.Shape4(4, 2, 1, 2);
	shape5.Shape5(7, 2, 0.5, 0.5);
	cone.CreateCone(1, 2, 20);

	myInit();
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(myKeyboard);

	glutMainLoop();
	return 0;
}

