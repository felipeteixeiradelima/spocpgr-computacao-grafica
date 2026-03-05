# include <GL/glut.h>

// Variáveis globais para controlar a animação
float anguloTriangulo = 0.0f;
float posicaoQuadradoX = -1.0f;
float direcaoQuadrado = 1.0f;

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Guarda o estado original da tela
    glPushMatrix();

    // Move o triângulo pra esquerda
    glTranslatef(-0.4f, 0.0f, 0.0f);

    // Roda o triângulo
    glRotatef(anguloTriangulo, 0.0f, 0.0f, 1.0f);

    // Inicializa o triângulo
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.3f, -0.3f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.3f, -0.3f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.3f);
    glEnd();

    // Reseta o estado original (cancela translate e rotate)
    glPopMatrix();

    // Guarda o estado original de novo
    glPushMatrix();

    // Move o quadrado no eixo X
    glTranslatef(posicaoQuadradoX, 0.0f, 0.0f);

    // Inicializa o quadrado
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();

    // Reseta o estado original (cancela translate e rotate)
    glPopMatrix();

    // Troca os buffers (exibe na tela o que acabou de ser desenhado)
    glutSwapBuffers();
}

void atualizaAnimacao(int valor) {
    // Atualiza o ângulo do triângulo
    anguloTriangulo += 2.0f;

    if (anguloTriangulo > 360.0f) {
        anguloTriangulo -= 360.0f;
    }

    // Atualiza a posição do quadrado (vai e volta)
    posicaoQuadradoX +=0.02f * direcaoQuadrado;

    if (posicaoQuadradoX > 1.0f | posicaoQuadradoX < -1.0f) {
        direcaoQuadrado *= -1.0f; // Inverte a direção do quadrado
    }

    // Redesenha a tela
    glutPostRedisplay();

    // Regista o temporizador para ser chamado novamente daqui a 16 milissegundos (aprox. 60 FPS)
    glutTimerFunc(16, atualizaAnimacao, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Animacao com OpenGL e GLUT");

    // Inicia o temporizador
    glutTimerFunc(25, atualizaAnimacao, 0);

    glutDisplayFunc(desenhaCena);

    glutMainLoop();

    return 0;
}
