
#include <iostream>
#include <GL/freeglut.h>

void reshape(GLint w, GLint h);
void initGL();
void display3D();
void dibujarCubo();
void timer(int valor);

void keyDown(int key, int, int);
void keyUp(int key, int, int);


void spinDisplayIzq();
void spinDisplayDer();

int refreshRate = 5;//variable tipica de los scripts

float rotAng = 0.0f;

bool iskey = false, ismouse = false;//verifica si la tecla esta presionada con iskey
bool isFirts = true;
float posx = 0.0f;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ejercicio Animaciones 3D");

    glutDisplayFunc(display3D);//no se puede mandar paramatros porque es puntero funcion
    glutReshapeFunc(reshape);

    glutSpecialFunc(keyDown);
    glutSpecialUpFunc(keyUp);

    //para que funcione con teclado paramos el timer y redibujar
    glutTimerFunc(0, timer, 0);//el tiempo en el que llame

    initGL();
    glutMainLoop();

}


void timer(int valor)
{

    glutPostRedisplay();//forzando a que se redibuje la pantalla
    glutTimerFunc(refreshRate, timer, 0);//refreshtimer es un int cada cuando debe refrescarse

}


void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    //glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, 1, 5, 100);
}

//es mejor tenerlo como funcion porque luego usamos para inicializar varias cosas, como la correccion de profundidad
//aqui se hara las correcciones iniciales de los buffer
void initGL() {
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluPerspective(45.0f, 1, 5, 100); ya se llama en el reshape


    //prueba de profundiad para ver las caras
    glEnable(GL_DEPTH_TEST);
}

void spinDisplayIzq() {
    //calculamos la posicion y luego hacemos un translate
    //si esta presionado la tecla
    if (iskey)
        posx -= 0.05f;
    //hago un redisplay
    glutPostRedisplay();


}
void spinDisplayDer() {
    //calculamos la posicion y luego hacemos un translate
    //si esta presionado la tecla
    if (iskey)
        posx += 0.05f;
    //hago un redisplay
    glutPostRedisplay();


}
void keyDown(int key, int, int) {
    switch (key) {
    case GLUT_KEY_LEFT:

        //verifico si esta presionado la tecla
        iskey = true;
        glutIdleFunc(spinDisplayIzq);//Mantengo mi condicion de parada
        break;
    case GLUT_KEY_RIGHT:
        //verifico si esta presionado la tecla
        iskey = true;
        glutIdleFunc(spinDisplayDer);
        break;
    default:
        break;
    }
}
void keyUp(int key, int, int) {
    switch (key) {
    case GLUT_KEY_LEFT:

        //verifico si esta presionado la tecla
        iskey = false;
        glutIdleFunc(NULL);//Mantengo mi condicion de parada
        break;
    case GLUT_KEY_RIGHT:
        //verifico si esta presionado la tecla
        iskey = false;
        glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}

void display3D() {//no se puede mandar paramatros porque es puntero funcion
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(9, 9, 9, 0, 0, 0, 0, 1, 0); //camara en 5,5,5 apunta al 0,0,0 y el vector hacia arriba es 0,1,0

    //grafico objeto nuevo
    //para colocar en coordenadas de mundo toca trasladar

    glPushMatrix();
    if (iskey) {
        glTranslatef(posx, 0, -6.0f);
    }
    else {
        //este translate solo se necesita la 1ra vez para posicionar el cubo, luego ya no
        glTranslatef(0.0f, 0.0f, -6.0f); //la mando al fondo, esto afecta a las 2, para solucionarlo usar push y pop
    }
    glRotatef(-rotAng, 0, 0, 1);
    dibujarCubo();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-3.0f, 0.0f, 0.0f);
    glScalef(1.5f, 1.5f, 1.5f);//escalamos para ver la diferencia por tamaño entre los 2 cubos 
    //glRotatef(45.0f, 0, 0, 1);
    glRotatef(rotAng, 0, 0, 1);
    dibujarCubo();
    glPopMatrix();

    glutSwapBuffers();
    rotAng += 0.005f;
    //display3D();//para no dar click
    //glutPostRedisplay();


    //isFirts = false;
}


//en teoria no importa en que orden coloco las caras, la correccion de profundidad nos ayuda
void dibujarCubo()
{
    glBegin(GL_QUADS);//SIEMPRE colocar porque aqui defino primitivas
    //primero definimos en coordenadas locales
    //luego lo trasladamos para ponerlo en coordenadas del mundo


    //color primera cara
    glColor3f(0.9f, 0.8f, 0.7f);
    //defino 4 vertices para 1 cara , la lateral izquierda
    //defino en coordenadas locales
    //tambien pueden se posiciones de mundo siempre y cuando esten dentro de la perspectiva segun esto la perpectiva va de 1 a 5  en gluPerspective(60.0f, 1, 5, 100);

    //otra cara, lateral izquierda
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);

    //otra cara, inferior
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);


    //otra cara, posterior
    glColor3f(0.95f, 0.8f, 0.4f);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);

    //otra cara, superior
    glColor3f(0.85f, 0.25f, 0.4f);

    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);


    //otra cara, frontal
    glColor3f(0.0f, 0.1f, 0.7f);

    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);


    //otra cara, lateral derecha
    glColor3f(1.0f, 0.5f, 0.0f);

    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);


    glEnd();
}
