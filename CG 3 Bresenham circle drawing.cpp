#include <GL/glut.h>
#include <iostream>
using namespace std;
int r, xc, yc;

int putPixel(int px,int py){
	glBegin(GL_POINTS);
	glVertex2f((float)px,(float)py);
	glEnd();
}

void drawCircle() {
    glBegin(GL_LINES);
    glVertex2f(-640.0F, 0);
    glVertex2f(640.0F, 0);
    glVertex2f(0, -480.0F);
    glVertex2f(0, 480.0F);
    glEnd();

    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (x <= y) {
        putPixel(xc + x, yc + y);
        putPixel(xc + x, yc - y);
        putPixel(xc - x, yc + y);
        putPixel(xc - x, yc - y);
        putPixel(xc + y, yc + x);
        putPixel(xc + y, yc - x);
        putPixel(xc - y, yc + x);
        putPixel(xc - y, yc - x);

        if (d <= 0) {
            d += 4 * x + 6;
        } else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }

    glFlush();
}

void init() {
    glColor3f(1.0F, 1.0F, 1.0F);
    glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-640.0, 640.0, -480.0, 480.0, -1.0, 1.0);
}

int main(int argc, char **argv) {
    cout << "Enter radius: ";
    cin >> r;
    cout << "Enter X coordinate of center: ";
    cin >> xc;
    cout << "Enter Y coordinate of center: ";
    cin >> yc;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(1,1);
    glutCreateWindow("Bresenham's Circle Drawing Algorithm");
    init();
    glutDisplayFunc(drawCircle);
    glutMainLoop();

    return 0;
}

