#include <iostream>
#include <stdlib.h>

#include <glut.h>

#include "imageloader.h"

using namespace std;


void tank3D();
void gameBase();
void Buildings1();
void Buildings2();
void placeBuildings();
void enemyCar();
void bullet();
void firing();
void explosion();

GLuint _textureId;
GLuint _textureCar;
GLuint _textureField;
GLuint _textureWall;
GLuint _textureWall2;


float _angle = 0.0, xAxis = 0.0, yAxis = 0.0, zAxis = 0.0, zAx = 0.0;
bool rightFlag = false, leftFlag = false, bFlag = false, eFlag=false;
int flag = 0, cFlag = 1;

const GLfloat sgenparams[] = { 1, 0, 0, 0 };
const GLfloat tgenparams[] = { 0, 1, 0, 0 };


void Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);

	if (cFlag == 0){
		gluLookAt(-26.6348, 24.0, 58.1209, -15.6348, 19.8, 58.1282, 0.0, 1.0, 0.0); //2nd choice
	}
	else{
		gluLookAt(-26.6348, 20.0, 58.1209, -25.6348, 19.8, 58.1282, 0.0, 1.0, 0.0); //selected
	}
	//cout << _angle << " | " << xAxis << " | " << yAxis << " | " << zAxis << endl;
	glPushMatrix();
		glRotated(_angle, 0.0, 1.0, 0.0);
		glTranslatef(xAxis, 0.0, 0.0);
		glPushMatrix();
			gameBase();
		glPopMatrix();

		glPushMatrix();
			placeBuildings();
		glPopMatrix();
	glPopMatrix();

	if (flag == 0){
		glPushMatrix();
		glRotated(90, 0.0, -1.0, 0.0);
		glTranslatef(53.0, 2.5, ((-100.0) - xAxis));
		enemyCar();
		glPopMatrix();
	}

	if (flag == 1){
		glPushMatrix();
		glRotated(90, 0.0, -1.0, 0.0);
		glTranslatef(53.0, 2.5, ((-250.0) - xAxis));
		enemyCar();
		glPopMatrix();
	}

	if (flag == 2){
		glPushMatrix();
		glRotated(90, 0.0, -1.0, 0.0);
		glTranslatef(53.0, 2.5, ((-370.0) - xAxis));
		enemyCar();
		glPopMatrix();
	}

	if (bFlag == true){
		glPushMatrix();
		glRotated(90, 0.0, -1.0, 0.0);
		glTranslatef(60.0, 12.5 - yAxis, -zAxis - 25.0);
		bullet();
		glPopMatrix();
	}

	if (eFlag == true){
		explosion();
	}

	glPushMatrix();
	glRotated(90, 0.0, -1.0, 0.0);
	glTranslatef(53.0, 2.5, -5.0);
	tank3D();
	glPopMatrix();
	
	glutSwapBuffers();
}

void gameBase(){
	float gx = 0.0;
	for (int i = 0; i < 7; i++){
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, _textureField);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		glColor3f(0.5, 1.0, 0.5);

		glTexCoord2f(0.0, 0.0);
		glVertex3f(0.0 + gx, 0.0, 200.0);

		glTexCoord2f(0.0, 20.0);
		glVertex3f(0.0 + gx, 0.0, 0.0);

		glTexCoord2f(20.0, 20.0);
		glVertex3f(200.0 + gx, 0.0, 0.0);

		glTexCoord2f(20.0, 0.0);
		glVertex3f(200.0 + gx, 0.0, 200.0);
		glEnd();
		glPopMatrix();

		gx += 200;
	}
	/*glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, _textureField);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
			glNormal3f(0.0, 0.0, 1.0);
			glColor3f(0.5, 1.0, 0.5);

			glTexCoord2f(0.0, 0.0);
			glVertex3f(0.0, 0.0, 200.0);

			glTexCoord2f(0.0, 20.0);
			glVertex3f(0.0, 0.0, 0.0);

			glTexCoord2f(20.0, 20.0);
			glVertex3f(200.0, 0.0, 0.0);

			glTexCoord2f(20.0, 0.0);
			glVertex3f(200.0, 0.0, 200.0);
		glEnd();
	glPopMatrix();*/
}

void placeBuildings(){
	float bx = 0.0;
	for (int i = 0; i<21; i++){
		//first block
		glPushMatrix();
		glTranslatef(0.0 + bx, 0.0, 22.0);
		Buildings1();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0 + bx, 0.0, 44.0);
		Buildings2();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(22.0 + bx, 0.0, 22.0);
		Buildings2();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(22.0 + bx, 0.0, 44.0);
		Buildings1();
		glPopMatrix();


		//second block
		glPushMatrix();
		glTranslatef(0.0 + bx, 0.0, 100.0);
		Buildings1();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0 + bx, 0.0, 122.0);
		Buildings2();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(22.0 + bx, 0.0, 100.0);
		Buildings2();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(22.0 + bx, 0.0, 122.0);
		Buildings1();
		glPopMatrix();

		bx += 78;
	}

	////first block
	//glPushMatrix();
	//	glTranslatef(0.0, 0.0, 22.0);
	//	Buildings1();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(0.0, 0.0, 44.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(22.0, 0.0, 22.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(22.0, 0.0, 44.0);
	//	Buildings1();
	//glPopMatrix();


	////second block
	//glPushMatrix();
	//	glTranslatef(0.0, 0.0, 100.0);
	//	Buildings1();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(0.0, 0.0, 122.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(22.0, 0.0, 100.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(22.0, 0.0, 122.0);
	//	Buildings1();
	//glPopMatrix();

	////third block
	//glPushMatrix();
	//	glTranslatef(0.0, 0.0, 178.0);
	//	Buildings1();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(0.0, 0.0, 200.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(22.0, 0.0, 178.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(22.0, 0.0, 200.0);
	//	Buildings1();
	//glPopMatrix();

	////fourth block
	//glPushMatrix();
	//	glTranslatef(78.0, 0.0, 22.0);
	//	Buildings1();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(78.0, 0.0, 44.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(100.0, 0.0, 22.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(100.0, 0.0, 44.0);
	//	Buildings1();
	//glPopMatrix();


	////fifth block
	//glPushMatrix();
	//	glTranslatef(78.0, 0.0, 100.0);
	//	Buildings1();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(78.0, 0.0, 122.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(100.0, 0.0, 100.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(100.0, 0.0, 122.0);
	//	Buildings1();
	//glPopMatrix();

	////sixth block
	//glPushMatrix();
	//	glTranslatef(78.0, 0.0, 178.0);
	//	Buildings1();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(78.0, 0.0, 200.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(100.0, 0.0, 178.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(100.0, 0.0, 200.0);
	//	Buildings1();
	//glPopMatrix();

	////seventh block
	//glPushMatrix();
	//	glTranslatef(156.0, 0.0, 22.0);
	//	Buildings1();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(156.0, 0.0, 44.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(178.0, 0.0, 22.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(178.0, 0.0, 44.0);
	//	Buildings1();
	//glPopMatrix();


	////eighth block
	//glPushMatrix();
	//	glTranslatef(156.0, 0.0, 100.0);
	//	Buildings1();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(156.0, 0.0, 122.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(178.0, 0.0, 100.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(178.0, 0.0, 122.0);
	//	Buildings1();
	//glPopMatrix();

	////nineth block
	//glPushMatrix();
	//	glTranslatef(178.0, 0.0, 178.0);
	//	Buildings1();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(178.0, 0.0, 200.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(200.0, 0.0, 178.0);
	//	Buildings2();
	//glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(200.0, 0.0, 200.0);
	//	Buildings1();
	//glPopMatrix();
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

void enemyCar(){
	//back
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureCar);

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
	glBindTexture(GL_TEXTURE_2D, _textureCar);

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
	glBindTexture(GL_TEXTURE_2D, _textureCar);

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
	glBindTexture(GL_TEXTURE_2D, _textureCar);

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
	glBindTexture(GL_TEXTURE_2D, _textureCar);

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
	glBindTexture(GL_TEXTURE_2D, _textureCar);

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
		glRotatef(15, 1.0, 0.0, 0.0);
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

void firingUpdate(int value){
	if (zAxis < 51.0 && bFlag == true){
		zAxis += 0.2;
		yAxis += 0.02;
		if (flag == 0){
			cout << (-100.0 - xAxis) << "|" << (-zAxis - 25.0) << endl;
			if ((-100.0 - xAxis) >= (-zAxis - 25.0 - 5.0) && (-100.0 - xAxis) <= (-zAxis - 25.0)){
				zAx = -100.0 - xAxis;
				eFlag = true;
				flag = 1;
				bFlag = false;
				zAxis = 0.0;
				yAxis = 0.0;
			}
		}
		if (flag == 1){
			if ((-250.0 - xAxis) >= (-zAxis - 25.0 - 5.0) && (-250.0 - xAxis) <= (-zAxis - 25.0)){
				bFlag = false;
				zAx = -250.0 - xAxis;
				eFlag = true;
				flag = 2;
				zAxis = 0.0;
				yAxis = 0.0;
			}
		}
		if (flag == 2){
			if ((-370.0 - xAxis) >= (-zAxis - 25.0 - 5.0) && (-370.0 - xAxis) <= (-zAxis - 25.0)){
				bFlag = false;
				zAx = -370.0 - xAxis;
				eFlag = true;
				flag = 3;
				zAxis = 0.0;
				yAxis = 0.0;
			}
		}
		if (bFlag == true){
			glutPostRedisplay();
			glutTimerFunc(5, firingUpdate, 0);
		}
	}
	else{
		bFlag = false;
		zAxis = 0.0;
		yAxis = 0.0;
	}
}

void explosion(){
	for (int i = 0; i < 40000; i++){
		glPushMatrix();
			glRotated(90, 0.0, -1.0, 0.0);
			glTranslatef(60.0, 5.5, zAx); 
			glColor3f(1.0, 0.0, 0.0);
			glutSolidSphere(20, 30, 30);
		glPopMatrix();

		glutPostRedisplay();
	}
	eFlag = false;
}

void bullet(){
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glutSolidSphere(1, 30, 30);
	glPopMatrix();
}

void lightSetting()
{
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

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 'f':
		bFlag = true;
		glutTimerFunc(5, firingUpdate, 0);
		break;
	case 'v':
		if (cFlag == 1){
			cFlag = 0;
		}
		else{
			cFlag = 1;
		}
		break;
	}
}

void pressKey(int key, int x, int y){

	switch (key)
	{
	case GLUT_KEY_LEFT: 
		if (_angle != -10){
			_angle -= 10.0;
		}
			break;
	case GLUT_KEY_RIGHT: 
		if (_angle != 10){
			_angle += 10.0;
		}
			break;
	case GLUT_KEY_UP: 
		if ((xAxis + 0.5) <= 800.0){
			xAxis -= .5;
		}
			break;
	case GLUT_KEY_DOWN:
		if ((xAxis + 0.5) <= 0.0){
			xAxis += .5;
		}
			break;
	}
}

void releaseKey(int key, int x, int y){

	switch (key)
	{
	case GLUT_KEY_LEFT:
			break;
	case GLUT_KEY_RIGHT:
			break;
	case GLUT_KEY_UP:
		break;
	case GLUT_KEY_DOWN:
		break;
	}
}

void Initialize() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION); 
	gluPerspective(45.0, 2.0, 1.0, 100.0);
	Image* image = loadBMP("D:\\7th Semister\\CG\\Project\\CG_Project\\DemoProject\\images\\grass3.bmp");
	Image* image1 = loadBMP("D:\\7th Semister\\CG\\Project\\CG_Project\\DemoProject\\images\\Surface.bmp");
	Image* image2 = loadBMP("D:\\7th Semister\\CG\\Project\\CG_Project\\DemoProject\\images\\wall.bmp");
	Image* image3 = loadBMP("D:\\7th Semister\\CG\\Project\\CG_Project\\DemoProject\\images\\wall2.bmp");
	Image* image4 = loadBMP("D:\\7th Semister\\CG\\Project\\CG_Project\\DemoProject\\images\\Car.bmp");
	_textureId = loadTexture(image);
	_textureField = loadTexture(image1);
	_textureWall = loadTexture(image2);
	_textureWall2 = loadTexture(image3);
	_textureCar = loadTexture(image4);
	delete image;
	delete image1;
	delete image2;
	delete image3;
	delete image4;
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(200, 0);
	glutCreateWindow("Battle Tank 3D");
	//glutIgnoreKeyRepeat(1);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	Initialize();
	lightSetting();
	glutDisplayFunc(Draw);
	glutKeyboardFunc(handleKeypress);
	glutIdleFunc(Draw);
	glutMainLoop();
	return 0;
}

