#include <GL/glut.h>

// Posição do quadrado 1
float xQuadrado1 = 0.0f;
float yQuadrado1 = 0.0f;

// Posição do quadrado 2
float xQuadrado2 = 0.0f;
float yQuadrado2 = 0.0f;

float step = 0.1f;

// Função para desenhar quadrado
void drawSquare(float x, float y, float r, float g, float b) {
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();
}

// Função para desenhar a cena
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSquare(xQuadrado1, yQuadrado1, 1.0f, 0.0f, 0.0f);
    drawSquare(xQuadrado2, yQuadrado2, 0.0f, 0.0f, 1.0f);
    glutSwapBuffers();
}

void keyboard(unsigned char key, int xMouse, int yMouse) {
    switch (key) {
        case 'w':
            yQuadrado1 += step;
            break;
        case 's':
            yQuadrado1 -= step;
            break;
        case 'a':
            xQuadrado1 -= step;
            break;
        case 'd':
            xQuadrado1 += step;
            break;
        case 'i':
            yQuadrado2 += step;
            break;
        case 'k':
            yQuadrado2 -= step;
            break;
        case 'j':
            xQuadrado2 -= step;
            break;
        case 'l':
            xQuadrado2 += step;
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
