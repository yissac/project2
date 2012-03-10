#include <GL/gl.h>
#include <GL/glut.h>
#include <SOLID/solid.h>
#include <stdio.h>

void something(void);

float coords[2][3] = {{0,0,0},{0,-2,0}};

DtObjectRef obj1,obj2;

void buttonPress(unsigned char key, int x, int y){
	switch(key){
		case 'w':
			coords[0][1]++;
			break;
		case 's':
			coords[0][1]--;
			break;
		case 'a':
			coords[0][0]++;
			break;
		case 'd':
			coords[0][0]--;
			break;
		case 'q':
			coords[0][2]++;
			break;
		case 'e':
			coords[0][2]--;
			break;
	
	}
	glutPostRedisplay();
}

void display(void){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0.0f,0.0f,-5.0f);
	
	glColor3f(0.0f, 1.0f, 0.0f);
	//something();
	//glutWireCube(2.0f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glColor3f(0.0f,0.0f,1.0f);
	glVertex3f(0.0f, 0.0f, 3.0f);
	glEnd();

//	glRotatef(45, 1.0f,1.0f,0.0f);


	glColor3f(1.0f,0.0f,1.0f);
	glPushMatrix();
	glTranslatef(coords[0][0],coords[0][1],coords[0][2]);
	glRotatef(0,0,1,0);
	glutWireCube(2.0f);
	glPopMatrix();
	
//	glLoadIdentity();
	glPushMatrix();
	glTranslatef(coords[1][0],coords[1][1],coords[1][2]);
	glRotatef(0,0,1,0);
	glutWireSphere(1.0f,10,10);
	glPopMatrix();


	dtSelectObject(&obj1);
	dtLoadIdentity();
	dtTranslate(coords[0][0],coords[0][1],coords[0][2]);
	dtRotate(0,0,1,0);
	
	dtSelectObject(&obj2);
	dtLoadIdentity();
	dtTranslate(coords[1][0],coords[1][1], coords[1][2]);
	dtRotate(0,0,1,0);


	if(dtTest()) printf("one {%f, %f, %f}, {%f,%f,%f}\n", coords[0][0],coords[0][1],coords[0][2],
			coords[1][0], coords[1][1], coords[1][2]);
	else printf("zero {%f, %f, %f}, {%f,%f,%f}\n", coords[0][0],coords[0][1],coords[0][2],
			coords[1][0], coords[1][1], coords[1][2]);

	glFlush();
}

void reshape(int width, int height){
	glViewport(0,0,(GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)width/(GLfloat)height, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void something(void){
	glColor3f(0.0f,0.0f,1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-1.0f, 1.0f,0.0f);
	glVertex3f(-1.0f, 1.0f,0.0f);
	glVertex3f( 1.0f, 1.0f,0.0f);
	glVertex3f( 1.0f,-1.0f,0.0f);
	glEnd();
}

void collide1(void * client_data, DtObjectRef obj1, DtObjectRef obj2,
	      const DtCollData *coll_data) {
}


int main (int argc, char ** argv){
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Window title");
	glutKeyboardFunc(buttonPress);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	DtShapeRef box1 = dtBox(2.0,2.0,2.0);
	DtShapeRef sphere1 = dtSphere(2.0);
	dtCreateObject(&obj1, box1);
	dtCreateObject(&obj2, sphere1);
	



 	dtSetDefaultResponse(collide1, DT_SIMPLE_RESPONSE, stdout);

	glutMainLoop();
}
