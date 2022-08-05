#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>

void init(void) {
        glClearColor(0, 0, 0, 1);
        glColor3f(0, 0.4, 0.3);

        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-10, 510, -10, 510);
        glClear(GL_COLOR_BUFFER_BIT);
}

void dda(int x1, int y1, int x2, int y2) {
        int dy = (y2 - y1);
        int dx = (x2 - x1);
        float m = (float)dy / dx;
        float step;

        if (abs(dx) > abs(dy)) {
                step = abs(dx);
        }
        else {
                step = abs(dy);
        }

        float x = x1, y = y1;

        float xInc = dx / step;
        float yInc = dy / step;

        glBegin(GL_POINTS);

        for (int i = 0; i < step; i++) {
                x += xInc;
                y += yInc;
                glVertex2i(roundf(x) , roundf(y));
        }

        glEnd();
        glFlush();
}

void draw(){
        dda(20, 20, 300, 300);
        dda(300, 200, 50, 29);
        dda(10, 10, 10, 300);
}

int main(int argc, char* argv[]) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB);
        glutInitWindowPosition(0, 0);
        glutInitWindowSize(500, 500);
        glutCreateWindow("DDA Algorithm");
        init();
        glutDisplayFunc(draw);
        const GLubyte* str = glGetString(GL_VERSION);
        printf("Opengl version %s\n", str);
        glutMainLoop();
}
 
