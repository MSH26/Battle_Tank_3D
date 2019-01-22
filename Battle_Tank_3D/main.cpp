#include <glut.h>

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(2.0, 7.0, 9.0, 0.0, 0.0, -9.0, 0.0, 1.0, 0.0);

	glColor3f(0.0, 0.0, 0.0);

	//glTranslatef(0.0, 0.0, -90.0);
	//glRotatef(10, 1.0, 0.0, 0.0);
	//glPushMatrix();
	glTranslatef(0.0, 0.0, -7);
	glutSolidCube(5);
	//glPopMatrix();
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0, 1.0);
	glColor3f(0.5, 1.0, 0.5);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 200.0);
	glVertex3f(200.0, 0.0, 200.0);
	glVertex3f(200.0, 0.0, 0.0);

	glEnd();

	glutSwapBuffers();
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

void Initialize() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 1.00, 40.0, 200.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(200, 0);
	glutCreateWindow("Battle Tank 3D");
	Initialize();
	lightSetting();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}