#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define number_of_points 1000

typedef struct Point{
	int x, y;
} Point;

Point points[number_of_points];

void getRandomPoint(int, Point*);
void init(void) {
	glClearColor(0, 0, 0, 1);
	glColor3f(0, 0.4, 0.3);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-10, 510, -10, 510);
	glClear(GL_COLOR_BUFFER_BIT);
	
	//seed the pseudo random number genrator
	srand(time(0));

	Point out;
	
	//store all points in array
	for(int i = 0; i < number_of_points; i++){
    getRandomPoint(200, &out);	
		points[i].x  =  out.x; 
		points[i].y  =  out.y;
	}
}

// write coords of a random point to `outPoint` that lies within 
// circle specified by `radius` and has origin at 0, 0

void getRandomPoint(int radius, Point* outPoint ){
	int r = rand() % radius;
	int precision = 100000;
	double phi = ((rand() % (int)(2 * precision * M_PI)) - (M_PI * precision )) /(double) precision; 
	
	outPoint->x  = r * cos(phi);
	outPoint->y = r * sin(phi);	
		
	//printf(" %d %d\n", outPoint->x, outPoint->y);
	
}

void draw(){
	// translate to center of window
	glTranslatef(250, 250, 0);
	glBegin(GL_POINTS);	
  
	for(int i=0; i< number_of_points; i++){
		glVertex2i(points[i].x, points[i].y);
	}
	
	glEnd();
	glFlush();
	//translate back to origin
	glTranslatef(-250, -250, 0);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("dots in circular area");
	init();
	glutDisplayFunc(draw);
	const GLubyte* str = glGetString(GL_VERSION);
	printf("Opengl version %s\n", str);
	glutMainLoop();
}
