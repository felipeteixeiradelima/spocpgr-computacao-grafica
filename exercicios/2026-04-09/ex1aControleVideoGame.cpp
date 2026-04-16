#include <GL/glut.h>
#include <math.h>

// Funções do controle feitas com ajuda de IA e GeoGebra

// Domínio das funções: [-0.75, 0.75]

const double DOMINIO_MINIMO_FUNC = -0.75;
const double DOMINIO_MAXIMO_FUNC = 0.75;

const double NIVEL_DE_DETALHE = 20; // ALTERE PARA AUMENTAR OU DIMINUIR O NÍVEL DE DETALHE

double funcParteSuperiorControle(double x) {
    const double xQuadrado = pow(x, 2);

    return sqrt((1 - xQuadrado / 0.5625) * (0.2 + xQuadrado));
}

double funcParteInferiorControle(double x) {
    return -sqrt((1 - pow(x, 2) / 0.5625) * (0.05 + 8 * pow(x, 4)));
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // AUMENTANDO ESPESSURA DAS LINHAS
    glLineWidth(5.0f);

    // USANDO LINHAS TRACEJADAS
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);

    // Desenhando linhas (GL_LINES)
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    double x1 = DOMINIO_MINIMO_FUNC, x2;
    double ySuperior1 = 0.0, ySuperior2 = 0.0;
    double yInferior1 = 0.0, yInferior2 = 0.0;

    const double step = (DOMINIO_MAXIMO_FUNC - DOMINIO_MINIMO_FUNC) / NIVEL_DE_DETALHE;

    for (x2 = x1 + step; x1 < DOMINIO_MAXIMO_FUNC; x2 += step) {

        // Para não passar do domínio da função de desenho
        if (x2 > DOMINIO_MAXIMO_FUNC) x2 = DOMINIO_MAXIMO_FUNC;

        ySuperior1 = funcParteSuperiorControle(x1);
        yInferior1 = funcParteInferiorControle(x1);

        ySuperior2 = funcParteSuperiorControle(x2);
        yInferior2 = funcParteInferiorControle(x2);

        // Desenhando parte superior
        glVertex2d(x1, ySuperior1);
        glVertex2d(x2, ySuperior2);

        // Desenhando parte inferior
        glVertex2d(x1, yInferior1);
        glVertex2d(x2, yInferior2);

        x1 = x2;
    }

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Controle de Videogame");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
