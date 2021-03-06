// 2. Create and rotate a triangle about the origin and a fixed point.

#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

GLfloat tri[3][3]={{100,100,0},{200,100,0},{150,200,0}};
GLfloat arb_x=100;
GLfloat arb_y=100;
GLfloat rot_angle;

void drawtri()
{

	glBegin(GL_LINE_LOOP);
		glVertex3fv(tri[0]);
		glVertex3fv(tri[1]);
		glVertex3fv(tri[2]);
		//glVertex3fv(house[4]);
	glEnd();

}
void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	//glTranslatef(-200,200,0);
	/*Draw Rotated Triangle*/
	//glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(arb_x,arb_y,0.0);
	glRotatef(rot_angle,0.0,0.0,1.0);
	glTranslatef(-arb_x,-arb_y,0.0);
	glColor3f(0,1,0);
    drawtri();

    //glRotatef(-rot_angle,0.0,0.0,1.0);
        /*Draw Original Triangle*/

  glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1,0,0);
    drawtri();

	glFlush();
}

void myinit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	//glColor3f(1.0,0.0,0.0);
        //glMatrixMode(GL_MODELVIEW);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-250.0,499.0,-250.0,499.0);
}

int main(int argc, char *argv[])
{
	printf("\nENTER THE ROTATION ANGLE :-\n");
	scanf("%f",&rot_angle);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Triangle Rotation");
    myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
