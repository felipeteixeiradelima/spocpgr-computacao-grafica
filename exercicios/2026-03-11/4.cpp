#include <GL/glut.h>

// Posição do quadrado
float x = 0.0f;
float y = 0.0f;
float step = 0.1f;

// Função para desenhar a cena
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int xMouse, int yMouse) {
    if (key == 27) exit(0); // tecla ESC
}

// Função especial
void keyboardSpecial(int key, int xMouse, int yMouse) {
    switch (key) {
        case GLUT_KEY_UP:
            y += step;
            break;
        case GLUT_KEY_DOWN:
            y -= step;
            break;
        case GLUT_KEY_LEFT:
            x -= step;
            break;
        case GLUT_KEY_RIGHT:
            x += step;
            break;
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
    glutSpecialFunc(keyboardSpecial);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
