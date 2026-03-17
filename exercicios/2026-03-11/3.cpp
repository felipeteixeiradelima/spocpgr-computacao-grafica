#include <GL/glut.h>

// Posição do quadrado
float x = 0.0f;
float y = 0.0f;
float step = 0.1f;

// Cores do quadrado
float r = 1.0f;
float g = 0.0f;
float b = 0.0f;

// Função para desenhar a cena
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int xMouse, int yMouse) {
    switch (key) {
        case 'w':
            y += step;
            break;
        case 's':
            y -= step;
            break;
        case 'a':
            x -= step;
            break;
        case 'd':
            x += step;
            break;
        case '1':
            r = 1.0f;
            g = 0.0f;
            b = 0.0f;
            break;
        case '2':
            r = 0.0f;
            g = 1.0f;
            b = 0.0f;
            break;
        case '3':
            r = 0.0f;
            g = 0.0f;
            b = 1.0f;
            break;
        case 27:
            exit(0); // tecla ESC
    }
    glutPostRedisplay(); // Solicita redesenho
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Controle com Teclado - OpenGL");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
