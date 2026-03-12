#include <GL/glut.h>

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha quadrado (GL_QUADS)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.8f, 0.2f); // Canto inferior esquerdo
    glVertex2f(0.2f, 0.2f); // Canto inferior direito
    glVertex2f(0.2f, 0.8f); // Canto superior direito
    glVertex2f(0.8f, 0.8f); // Canto superior esquerdo
    glEnd();

    // Desenhando triângulo (GL_TRIANGLES)
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.8f, -0.2f);
    glVertex2f(-0.2f, -0.5f);
    glEnd();

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
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Triangulo e Quadrado com GLUT");

    glutDisplayFunc(desenhaCena);

    glutMainLoop();

    return 0;
}
