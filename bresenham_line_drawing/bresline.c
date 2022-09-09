/*
this version is written to work with only lines with slope m, 0 < m < 1
*/
#include <GL/freeglut.h>
#include <stdio.h>

void init(void) {
        glClearColor(0,0,0, 0.6);
        glColor3f(0, 0.4, 0.3);

        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-10, 510, -10, 510);
}

void bresenham_line(int x1, int y1,int x2,int y2){
        glBegin(GL_POINTS);
        int dx = x2 - x1;
        int dy = y2 - y1;
        int twodx = 2*dx;
        int twody = 2*dy;
        int pk = twodx - dy;


        glVertex2i(x1, x2); 

        for(int i = 0; i < dx; i++){
                if(pk < 0){
                        pk+=twody;
                        x1++;
                }else{
                        pk+=twody-twodx;
                        x1++;
                        y1++;
                }
                glVertex2i(x1, y1);
        }

        glEnd();
        glFlush();
}
void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        //printf(__FUNCTION__ " called\n");
        bresenham_line(100, 100, 300, 200);
        bresenham_line(30, 20, 300, 100); 
        bresenham_line(30, 20, 300, 20);
}
int main(int argc, char * argv[]) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB);
        glutInitWindowPosition(0, 0);
        glutInitWindowSize(500, 500);
        glutCreateWindow("Lines");
        init();
        glutDisplayFunc(display);
        const GLubyte * str = glGetString(GL_VERSION);
        printf("Opengl version %s\n", str);
        glutMainLoop();

}
