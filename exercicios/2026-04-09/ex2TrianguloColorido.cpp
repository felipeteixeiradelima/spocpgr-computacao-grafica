#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // COMANDO glPolygonMode()
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Desenhando triângulo
    glBegin(GL_TRIANGLES);

    // Vértice 1
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.9f, -0.9f);

    // Vértice 2
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.9f, -0.9f);

    // Vértice 3
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.9f);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Triângulo Grande");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
