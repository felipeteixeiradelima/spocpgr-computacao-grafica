#include <GL/glut.h>

// Variável para controlar qual luz está ativa (1 = Ambiente, 2 = Direcional, 3 = Pontual)
int tipoLuz = 2;

void configuraLuz() {

    glDisable(GL_LIGHT0);

    GLfloat luzBranca[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat semLuz[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat luzAmbienteForte[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat luzAmbienteFraca[] = { 0.2f, 0.2f, 0.2f, 1.0f };

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbienteFraca);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzBranca);

    GLfloat direcao[] = { 1.0f, 1.0f, 0.5f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, direcao);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Posiciona a câmera
    gluLookAt(
        0.0, 0.0, 5.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0
    );
    configuraLuz();

    // Desenha uma esfera no centro
    glutSolidSphere(1.0, 16, 16);
    glutSwapBuffers();
}

void inicializa() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.2f, 0.6f, 0.8f); // Azul

    glShadeModel(GL_FLAT);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Exercicio Pratico");

    inicializa();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
