#include <GL/freeglut.h>
#include <stdio.h>

void init(void) {
	glClearColor(0,0,0, 0.6);
	glColor3f(0, 0.4, 0.3);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-10, 510, -10, 510);
}
void lineSegment(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2i(0, 0);
	glVertex2i(500, 0); 

	glColor3f(0, 1, 0);
	glVertex2i(500, 0);
	glVertex2i(500, 500);

	glColor3f(0, 0, 1);
	glVertex2i(500, 500);
	glVertex2i(0, 0);

	printf(__FUNCTION__ " called\n");
	glEnd();
	glFlush();
}
int main(int argc, char * argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Lines");
	init();
	glutDisplayFunc(lineSegment);
	const GLubyte * str = glGetString(GL_VERSION);
	printf("Opengl version %s\n", str);
	glutMainLoop();
	
}
