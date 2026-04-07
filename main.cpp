#include <GL/glut.h>
#include <math.h>

// Global variable for animation
float angle = 0.0;

// Function to draw circle
void drawCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for(int i = 0; i < 100; i++) {
        float theta = 2.0f * 3.1416f * i / 100;
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    // ✅ TRANSFORMATION 1: Translation
    glTranslatef(0.0, 0.0, 0.0);

    // ✅ TRANSFORMATION 2: Rotation (animation)
    glRotatef(angle, 0, 0, 1);

    // ✅ TRANSFORMATION 3: Scaling
    glScalef(0.9, 0.9, 1.0);

    // White background (flag base)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0, 0.6);
        glVertex2f(1.0, 0.6);
        glVertex2f(1.0, -0.6);
        glVertex2f(-1.0, -0.6);
    glEnd();

    // Red part (top)
    glColor3f(0.8, 0.0, 0.0);
    drawCircle(0.0, 0.2, 0.3);

    // Blue part (bottom)
    glColor3f(0.0, 0.0, 0.8);
    drawCircle(0.0, -0.2, 0.3);

    glPopMatrix();

    glFlush();
}

// Animation function
void update(int value) {
    angle += 0.5;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("South Korea Flag");
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
}
