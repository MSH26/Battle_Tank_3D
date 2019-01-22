#include <cstdio>
#include <iostream>
#include <cstring>
#include <windows.h>
#include <cmath>
#include <glut.h>

#include "imageloader.h"

using namespace std;


void moveMeFlat(float i);
void orientMe(float ang);
void Buildings1();
void Buildings2();

GLuint _textureId;
GLuint _textureField;
GLuint _textureWall;
GLuint _textureWall2;

const GLfloat sgenparams[] = { 1, 0, 0, 0 };
const GLfloat tgenparams[] = { 0, 1, 0, 0 };

//in this code +y axis uporer dike.+z axis left dike.+x axis screen theke byrer dike.

float angle = 0.0, deltaAngle = 0.0, ratio;
float x = 50.0f, y = 5.7f, z = 5.0f;
float lx = -10.0f, ly = 0.0f, lz = -1.0f;
float deltaMove = 0, h, w;
float lookup = 0, lookdown = 0;



void tank3D(){
	//back
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 6.0, 0.0);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(14.0, 0.0, 0.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(14.0, 6.0, 0.0);
	glEnd();
	glPopMatrix();

	//front
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0.0, 0.0, -20.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 6.0, 0.0);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(14.0, 0.0, 0.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(14.0, 6.0, 0.0);
	glEnd();
	glPopMatrix();

	//left
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, 0.2);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 6.0, 0.0);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(20.0, 0.0, 0.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(20.0, 6.0, 0.0);
	glEnd();
	glPopMatrix();

	//right
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, 14.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 6.0, 0.0);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(20.0, 0.0, 0.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(20.0, 6.0, 0.0);
	glEnd();
	glPopMatrix();

	//down
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glRotatef(90, -1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 20.0, 0.0);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(14.0, 0.0, 0.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(14.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	//up
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -20.0, -6.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 20.0, 0.0);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(14.0, 0.0, 0.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(14.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	//capsule
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(7.0, 3.0, -10.0);
	//glColor3f(0.0, 0.0, 0.0);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, sgenparams);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, tgenparams);
	glutSolidSphere(6, 30, 30);
	glPopMatrix();

	//firing gun
	glPushMatrix();
	glRotatef(25, 1.0, 0.0, 0.0);
	glTranslatef(7.0, 4.5, -20.0);
	glColor3f(1.0, 0.0, 0.0);
	GLUquadricObj *obj = gluNewQuadric();
	gluCylinder(obj, 1, 1, 8, 50, 50);
	glPopMatrix();

	//left wheel1
	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(4.0, 0.0, -1.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidTorus(1.0, 2.0, 30, 30);
	glPopMatrix();

	//left wheel2
	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(15.0, 0.0, -1.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidTorus(1.0, 2.0, 30, 30);
	glPopMatrix();

	//right wheel1
	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(4.0, 0.0, 15.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidTorus(1.0, 2.0, 30, 30);
	glPopMatrix();

	//right wheel2
	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(15.0, 0.0, 15.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidTorus(1.0, 2.0, 30, 30);
	glPopMatrix();
}


void renderScene(void){

	if (deltaMove)
		moveMeFlat(deltaMove);
	if (deltaAngle)
	{
		angle += deltaAngle;
		orientMe(angle);
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();
	//  	cout<<x<<" "<<y+lookup<<" "<<z<<endl;
	gluLookAt(x, y + lookup, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
	//glColor3f(1.0f, 1.0f, 1.0f);
	cout << "Out: " << x << "||" << y + lookup << "||" << z << "||" << x + lx << "||" << y + ly << "||" << z + lz << endl;

	//Main Project Items
	glPushMatrix(); 
		glBegin(GL_QUADS);

			glNormal3f(0.0, 0.0, 1.0);
			glColor3f(0.5, 1.0, 0.5);

			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 200.0);
			glVertex3f(200.0, 0.0, 200.0);
			glVertex3f(200.0, 0.0, 0.0);

		glEnd();
	glPopMatrix();

	//glPushMatrix();
	//	glutSolidCube(21.5);
	//	glPushMatrix();
	//		glTranslatef(0.0, 21.5, 0.0);
	//		glColor3f(0.0, 1.0, 0.0);
	//		glutSolidCube(21.5);
	//		glPushMatrix();
	//			glTranslatef(0.0, 40.0, 0.0);
	//			glColor3f(1.0, 0.0, 0.0);
	//			glutSolidCube(21.5);
	//		glPopMatrix();
	//	glPopMatrix();
	//glPopMatrix();

	//first block
	glPushMatrix();
		glTranslatef(0.0, 0.0, 22.0); 
		Buildings1();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.0, 44.0);
		Buildings2();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(22.0, 0.0, 22.0);
		Buildings2();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(22.0, 0.0, 44.0);
		Buildings1();
	glPopMatrix();


	//second block
	glPushMatrix();
		glTranslatef(0.0, 0.0, 100.0);
		Buildings1();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.0, 122.0);
		Buildings2();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(22.0, 0.0, 100.0);
		Buildings2();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(22.0, 0.0, 122.0);
		Buildings1();
	glPopMatrix();

	//third block
	glPushMatrix();
		glTranslatef(0.0, 0.0, 178.0);
		Buildings1();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.0, 200.0);
		Buildings2();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(22.0, 0.0, 178.0);
		Buildings2();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(22.0, 0.0, 200.0);
		Buildings1();
	glPopMatrix();

	//fourth block
	glPushMatrix();
		glTranslatef(100.0, 0.0, 22.0);
		Buildings1();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(100.0, 0.0, 44.0);
		Buildings2();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(122.0, 0.0, 22.0);
		Buildings2();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(122.0, 0.0, 44.0);
		Buildings1();
	glPopMatrix();


	//fifth block
	glPushMatrix();
		glTranslatef(100.0, 0.0, 100.0);
		Buildings1();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(100.0, 0.0, 122.0);
		Buildings2();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(122.0, 0.0, 100.0);
		Buildings2();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(122.0, 0.0, 122.0);
		Buildings1();
	glPopMatrix();

	//sixth block
	glPushMatrix();
		glTranslatef(100.0, 0.0, 178.0);
		Buildings1();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(100.0, 0.0, 200.0);
		Buildings2();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(122.0, 0.0, 178.0);
		Buildings2();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(122.0, 0.0, 200.0);
		Buildings1();
	glPopMatrix();

	//seventh block
	glPushMatrix();
	glTranslatef(178.0, 0.0, 22.0);
	Buildings1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(178.0, 0.0, 44.0);
	Buildings2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200.0, 0.0, 22.0);
	Buildings2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200.0, 0.0, 44.0);
	Buildings1();
	glPopMatrix();


	//eighth block
	glPushMatrix();
	glTranslatef(178.0, 0.0, 100.0);
	Buildings1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(178.0, 0.0, 122.0);
	Buildings2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200.0, 0.0, 100.0);
	Buildings2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200.0, 0.0, 122.0);
	Buildings1();
	glPopMatrix();

	//nineth block
	glPushMatrix();
	glTranslatef(178.0, 0.0, 178.0);
	Buildings1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(178.0, 0.0, 200.0);
	Buildings2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200.0, 0.0, 178.0);
	Buildings2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200.0, 0.0, 200.0);
	Buildings1();
	glPopMatrix();


	glPushMatrix();
		glRotated(90, 0.0, -1.0, 0.0);
		glTranslatef(51.0, 0.0, 0.0);
		tank3D();
	glPopMatrix();

	glPushMatrix();
		glLoadIdentity();
	glPopMatrix();
	
	glutSwapBuffers();
}


void Buildings1(){
	//back
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureWall2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 50.0, 0.0);

	glTexCoord2f(0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(15.0, 15.0);
	glVertex3f(21.5, 0.0, 0.0);

	glTexCoord2f(15.0, 0.0);
	glVertex3f(21.5, 50.0, 0.0);
	glEnd();
	glPopMatrix();

	//front
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureWall2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0.0, 0.0, -21.5);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 50.0, 0.0);

	glTexCoord2f(0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(15.0, 15.0);
	glVertex3f(21.5, 0.0, 0.0);

	glTexCoord2f(15.0, 0.0);
	glVertex3f(21.5, 50.0, 0.0);
	glEnd();
	glPopMatrix();

	//left
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureWall);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, 0.2);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 50.0, 0.0);

	glTexCoord2f(0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(15.0, 15.0);
	glVertex3f(21.5, 0.0, 0.0);

	glTexCoord2f(15.0, 0.0);
	glVertex3f(21.5, 50.0, 0.0);
	glEnd();
	glPopMatrix();

	//right
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureWall);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, 21.5);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 50.0, 0.0);

	glTexCoord2f(0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(15.0, 15.0);
	glVertex3f(21.5, 0.0, 0.0);

	glTexCoord2f(15.0, 0.0);
	glVertex3f(21.5, 50.0, 0.0);
	glEnd();
	glPopMatrix();

	//down
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureWall);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glRotatef(90, -1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 21.5, 0.0);

	glTexCoord2f(0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(15.0, 15.0);
	glVertex3f(21.5, 0.0, 0.0);

	glTexCoord2f(15.0, 0.0);
	glVertex3f(21.5, 21.5, 0.0);
	glEnd();
	glPopMatrix();

	//up
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureWall2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -21.5, -50.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 21.5, 0.0);

	glTexCoord2f(0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(15.0, 15.0);
	glVertex3f(21.5, 0.0, 0.0);

	glTexCoord2f(15.0, 0.0);
	glVertex3f(21.5, 21.5, 0.0);
	glEnd();
	glPopMatrix();
}

void Buildings2(){
	//back
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureWall);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 40.0, 0.0);

	glTexCoord2f(0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(15.0, 15.0);
	glVertex3f(21.5, 0.0, 0.0);

	glTexCoord2f(15.0, 0.0);
	glVertex3f(21.5, 40.0, 0.0);
	glEnd();
	glPopMatrix();

	//front
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureWall);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(0.0, 0.0, -21.5);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 40.0, 0.0);

	glTexCoord2f(0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(15.0, 15.0);
	glVertex3f(21.5, 0.0, 0.0);

	glTexCoord2f(15.0, 0.0);
	glVertex3f(21.5, 40.0, 0.0);
	glEnd();
	glPopMatrix();

	//left
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureWall2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, 0.2);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 40.0, 0.0);

	glTexCoord2f(0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(15.0, 15.0);
	glVertex3f(21.5, 0.0, 0.0);

	glTexCoord2f(15.0, 0.0);
	glVertex3f(21.5, 40.0, 0.0);
	glEnd();
	glPopMatrix();

	//right
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureWall2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, 21.5);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 40.0, 0.0);

	glTexCoord2f(0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(15.0, 15.0);
	glVertex3f(21.5, 0.0, 0.0);

	glTexCoord2f(15.0, 0.0);
	glVertex3f(21.5, 40.0, 0.0);
	glEnd();
	glPopMatrix();

	//down
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureWall2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glRotatef(90, -1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 21.5, 0.0);

	glTexCoord2f(0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(15.0, 15.0);
	glVertex3f(21.5, 0.0, 0.0);

	glTexCoord2f(15.0, 0.0);
	glVertex3f(21.5, 21.5, 0.0);
	glEnd();
	glPopMatrix();

	//up
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureWall);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -21.5, -40.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 21.5, 0.0);

	glTexCoord2f(0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(15.0, 15.0);
	glVertex3f(21.5, 0.0, 0.0);

	glTexCoord2f(15.0, 0.0);
	glVertex3f(21.5, 21.5, 0.0);
	glEnd();
	glPopMatrix();
}


GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now
		GL_RGB,                       //Format OpenGL uses for image
		image->width, image->height,  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
		//as unsigned numbers
		image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}


void Initialize1() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 2.0, 1.0, 100.0);
	Image* image = loadBMP("I:\\CG_Project\\Project\\CG_Project\\DemoProject\\images\\grass3.bmp");
	Image* image1 = loadBMP("I:\\CG_Project\\Project\\CG_Project\\DemoProject\\images\\Surface.bmp");
	Image* image2 = loadBMP("I:\\CG_Project\\Project\\CG_Project\\DemoProject\\images\\wall.bmp");
	Image* image3 = loadBMP("I:\\CG_Project\\Project\\CG_Project\\DemoProject\\images\\wall2.bmp");
	_textureId = loadTexture(image);
	_textureField = loadTexture(image1);
	_textureWall = loadTexture(image2);
	_textureWall2 = loadTexture(image3);
	delete image;
	delete image1;
	delete image2;
	delete image3;
}

void lightSetting(){
	float lightAmbient[4] = { 0.0, 0.0, 0.0, 1.0 };
	float lightDiffuse[4] = { 1.0, 1.0, 1.0, 1.0 };
	float lightSpecular[4] = { 1.0, 1.0, 1.0, 1.0 };
	float lightPosition[4] = { 100.0, -50.0, 40.0, 1.0 };

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	float materialSpecular[4] = { 1.0, 1.0, 1.0, 1.0 };
	float materialShininess[1] = { 50 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);


}

void orientMe(float ang){
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void moveMeFlat(float i){
	x = x + i*(lx)*.10;
	z = z + i*(lz)*.10;
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void pressKey(int key, int x, int y){

	switch (key)
	{
	case GLUT_KEY_LEFT: deltaAngle = -0.005f; break;
	case GLUT_KEY_RIGHT: deltaAngle = 0.005f; break;
	case GLUT_KEY_UP: deltaMove = .50; break;
	case GLUT_KEY_DOWN: deltaMove = -.50; break;
	}
	//    cout<<deltaAngle<<endl;
}

void releaseKey(int key, int x, int y){

	switch (key)
	{
	case GLUT_KEY_LEFT: if (deltaAngle < 0.0f)
		deltaAngle = 0.0f;
		break;
	case GLUT_KEY_RIGHT: if (deltaAngle > 0.0f)
		deltaAngle = 0.0f;
		break;
	case GLUT_KEY_UP:     if (deltaMove > 0)
		deltaMove = 0;
		break;
	case GLUT_KEY_DOWN: if (deltaMove < 0)
		deltaMove = 0;
		break;
	}
	//    cout<<deltaAngle<<endl;
}

void Initialize(int w1, int h1){
	if (h1 == 0)
		h1 = 1;

	w = w1;
	h = h1;
	ratio = 1.0f * w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);

	gluPerspective(45, ratio, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}


int main() {
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(1300, 680);
	glutInitWindowPosition(200, 0);
	glutCreateWindow("Battle Tank 3D");
	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutReshapeFunc(Initialize);
	Initialize1();
	//lightSetting();
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutMainLoop();

	return 0;
}
