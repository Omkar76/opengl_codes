#include <GL/freeglut.h>
#include <stdio.h>
void init(void) {
	glClearColor(0, 0, 0, 1);
	glColor3f(0, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 18, 0, 5);
}

void starShape(GLenum mode) {
	glBegin(mode);

	glVertex2f(2.5, 5);
	glVertex2f(0, 0);
	glVertex2f(5, 2.5);
	glVertex2f(0, 2.5);
	glVertex2f(5, 0);

	glEnd();
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	// GL_LINES specifies a set of unconnected lines unless a vertice is repeated
	starShape(GL_LINES); 
	glTranslated(6, 0, 0); // translate x 

	// GL_LINE_STRIP specifies a polyline formed by connecting given vertices.
	// first and last vertices are not connected to each other
	starShape(GL_LINE_STRIP);
	glTranslated(6, 0, 0); //translate  x

	// GL_LINE_LOOP same as GL_LINE_STRIP but first and last vertices are connected
	// with line
	starShape(GL_LINE_LOOP);

	glFlush();
	printf(__FUNCTION__ " called\n");

	glTranslated(-12, 0, 0); //reset translation
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1080, 300);
	glutCreateWindow("Lines");
	init();
	glutDisplayFunc(display);

	const GLubyte* str = glGetString(GL_VERSION);
	printf("Opengl version %s\n", str);

	glutMainLoop();
}
