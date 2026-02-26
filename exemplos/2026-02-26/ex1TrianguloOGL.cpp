#include <GL/glut.h>

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);

    // Vértice 1
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);

    // Vértice 2
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);

    // Vértice 3
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Triangulo Clássico com GLUT");

    glutDisplayFunc(desenhaCena);

    glutMainLoop();

    return 0;
}
