#include<GL/freeglut.h>     //incluye la biblioteca freeglut que proporciona funciones para crear y administrar ventanas y gráficos en OpenGL.
#include<math.h>            //incluye la biblioteca math.h que proporciona funciones matemáticas, como sin y cos

float x, y, i;              
float PI = 3.1416;          

void circulo(void)
{
    glClearColor(0.1, 0.1, 0.1, 0.1);    //Establece el color de fondo de la ventana en negro utilizando los valores RGB.
    glClear(GL_COLOR_BUFFER_BIT);        //limpiar el búfer de color

    float x, y;             //Estas variables se utilizarán para representar las coordenadas del centro del círculo en cada iteración.

    int i;                  //Declara la variable i se utilizará en los bucles para iterar.

    GLfloat radio;         //Esta variable se utilizará para especificar el radio del círculo, es tipo de dato GLfloat

    int numeroTriangulos = 100;//Esta variable determina la cantidad de triángulos utilizados para aproximar el círculo.

    GLfloat doblePi = 2.0 * PI;//Esta variable se utiliza para calcular los puntos en el círculo utilizando la fórmula trigonométrica


    //primer circulo
    glBegin(GL_TRIANGLE_FAN);    //Inicia la definición de un nuevo primitivo gráfico, en este caso, un TRIANGLE_FAN
        glColor3ub(0, 0, 255);    //Establece el color actual de los vértices a un tono de azul utilizando los valores RGB.
        x = 0; y = 0; radio = 20;    //Asigna los valores adecuados a las variables x, y y radio para el primer círculo.

        doblePi = 2.0 * PI;

        glVertex2f(x, y);     //Es el centro del círculo. Agrega un vértice en las coordenadas (x, y) al TRIANGLE_FAN. 
        for (i = 0; i <= numeroTriangulos;i++) {
            //Agrega vértices adicionales al TRIANGLE_FAN, calculados utilizando las funciones trigonométricas cos y sin.
            //esto especifica las coordenadas x e y del vértice en el espacio tridimensional.
            glVertex2f(
                x + (radio * cos(i * doblePi / numeroTriangulos)),
                y + (radio * sin(i * doblePi / numeroTriangulos))
            );
        }


    glEnd();    //Finaliza la definición del primitivo gráfico.

    //segundo circulo
    glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255, 255, 255);
        x = 50; y = 40; radio = 40;

        doblePi = 2.0 * PI;

        glVertex2f(x, y); //Es el centro del círculo. 
        for (i = 0; i <= numeroTriangulos;i++) {
            glVertex2f(
                x + (radio * cos(i * doblePi / numeroTriangulos)),
                y + (radio * sin(i * doblePi / numeroTriangulos))
            );
        }
    glEnd();


    glutSwapBuffers();    //Intercambia los buffers de la ventana, mostrando el resultado en pantalla.

}

void init(void)
{
   

    glLoadIdentity();    //Reemplaza la matriz actual con la matriz identidad.
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);    //Establece la matriz de proyección ortográfica para definir el volumen de visualización.

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);    //Inicializa la biblioteca GLUT.

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);    //Establece el modo de visualización de la ventana, en este caso, utilizando el modelo de color RGB y buffers dobles.
    glutInitWindowSize(500, 550);    //Establece el tamaño de la ventana.
    glutCreateWindow("Circulos");    //Crea una ventana con el título "Circulos".
    glutDisplayFunc(circulo);    //Establece la función circle como la función de visualización.
    init();    //Llama a la función init para realizar la inicialización adicional.

    glutMainLoop();    //Inicia el bucle principal de GLUT.

    return 0;    //Retorna 0 para indicar que el programa se ha ejecutado correctamente.

}