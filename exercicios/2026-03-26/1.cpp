#include <GL/glut.h>

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenhando linhas (GL_LINES)
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Linha 1 horizontal
    glVertex2f(-0.9f, 0.0f);
    glVertex2f(0.9f, 0.0f);

    // Linha 2 vertical
    glVertex2f(0.0f, -0.9f);
    glVertex2f(0.0f, 0.9f);
    
    glEnd();

    // Desenhando quadrado
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.7f, 0.0f);
    glVertex2f(-0.75f, 0.25f);
    glVertex2f(0.75f, 0.25f);
    glVertex2f(0.75f, -0.75f);
    glVertex2f(-0.75f, -0.75f);
    glEnd();

    // Desenhando triângulo
    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(-0.75f, 0.25f);
    glVertex2f(0.75f, 0.25f);
    glVertex2f(0.0f, 0.75f);
    glEnd();

    // Desenhando porta
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.8f);
    glVertex2f(-0.55f, -0.375f);
    glVertex2f(-0.25f, -0.375f);
    glVertex2f(-0.25f, -0.75f);
    glVertex2f(-0.55f, -0.75f);
    glEnd();

    // Desenhando janela
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 0.5f);
    glVertex2f(0.25f, -0.125);
    glVertex2f(0.6f, -0.125);
    glVertex2f(0.6f, -0.375f);
    glVertex2f(0.25f, -0.375f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Casinha");

    glutDisplayFunc(desenhaCena);

    glutMainLoop();

    return 0;
}
