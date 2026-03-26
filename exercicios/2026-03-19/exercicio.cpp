#include <GL/glut.h>

// Posição do quadrado
float x = 0.0f;
float y = 0.0f;
float step = 0.1f;

// Cores do quadrado
float r = 0.0f;
float g = 0.0f;
float b = 1.0f;

// Tamanho do quadrado
float tamanhoQuadrado = 0.1f;
float stepTamanho = 0.01f;

// Função para desenhar a cena
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-tamanhoQuadrado, -tamanhoQuadrado);
    glVertex2f(tamanhoQuadrado, -tamanhoQuadrado);
    glVertex2f(tamanhoQuadrado, tamanhoQuadrado);
    glVertex2f(-tamanhoQuadrado, tamanhoQuadrado);
    glEnd();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int xMouse, int yMouse) {
    // Verifica qual tecla foi pressionada
    switch (key) {

        // Se a tecla pressionada for 'w':
        case 'w':
            // Incrementa o valor de y
            y += step;
            break;

            // Se a tecla pressionada for 's':
        case 's':
            // Decrementa o valor de y
            y -= step;
            break;

            // Se a tecla pressionada for 'a':
        case 'a':
            // Incrementa o valor de x
            x -= step;
            break;

            // Se a tecla pressionada for 'd':
        case 'd':
            // Decrementa o valor de x
            x += step;
            break;

            // Se a tecla pressionada for '+':
        case '+':
            // Aumenta o tamanho do quadrado
            tamanhoQuadrado += stepTamanho;
            break;

            // Se a tecla pressionada for '-':
        case '-':
            // Diminui o tamanho do quadrado (somente se for maior que o stepTamanho)
            if (tamanhoQuadrado > stepTamanho)
                tamanhoQuadrado -= stepTamanho;
            break;

            // Se a tecla pressionada for ESC (27)
        case 27:
            exit(0); // encerra o programa
    }
    glutPostRedisplay(); // Solicita redesenho
}

void mouse(int button, int state, int xMouse, int yMouse) {
    switch (button) {

        // Se o botão pressionado for o esquerdo:
        case GLUT_LEFT_BUTTON:
            // Muda a cor para vermelho
            r = 1.0f;
            g = 0.0f;
            b = 0.0f;
            break;

            // Se o botão pressionado for o direito:
        case GLUT_RIGHT_BUTTON:
            // Muda a cor para azul
            r = 0.0f;
            g = 0.0f;
            b = 1.0f;
            break;
        
            // Se o botão pressionado for o do meio:
        case GLUT_MIDDLE_BUTTON:
            // Reinicia a posição do quadrado para (0,0)
            x = 0.0f;
            y = 0.0f;
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
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
