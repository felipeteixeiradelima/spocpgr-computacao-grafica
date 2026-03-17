#include <GL/glut.h>
#include <math.h>

// Tamanho do círculo
const float TAMANHO_CIRCULO = 0.1f;

// Posição do círculo
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
    for (unsigned short angulo = 0; angulo < 360; angulo++) {
        glVertex2f(sin(angulo) * TAMANHO_CIRCULO, cos(angulo) * TAMANHO_CIRCULO);
    }
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
