//incluye la biblioteca freeglut que proporciona funciones para crear y administrar ventanas y gráficos en OpenGL.
#include<GL/freeglut.h>
//incluye la biblioteca math.h que proporciona funciones matemáticas, como sin y cos
#include<math.h>
//Declara las variables x, y e i como tipo de dato float
float x, y, i;
//Declara la variable PI y le asigna el valor de π (pi) aproximado a 3.1416
float PI = 3.1416;
//Define una función llamada circle sin argumentos ni valor de retorno.
void circle(void)
{
    //Declara las variables x e y como tipo de dato float dentro de la función circle. 
    //Estas variables se utilizarán para representar las coordenadas del centro del círculo en cada iteración.
    float x, y;
    //Declara la variable i como tipo de dato int dentro de la función circle. 
    //Esta variable se utilizará en los bucles para iterar.
    int i;
    //Declara la variable radius como tipo de dato GLfloat dentro de la función circle. 
    //Esta variable se utilizará para especificar el radio del círculo.
    GLfloat radius;
    //Declara la variable triangleAmount y le asigna el valor de 40. 
    //Esta variable determina la cantidad de triángulos utilizados para aproximar el círculo.
    int triangleAmount = 40;
    //Declara la variable twicePi y le asigna el valor de 2.0 * PI. 
    //Esta variable se utiliza para calcular los puntos en el círculo utilizando la fórmula trigonométrica
    GLfloat twicePi = 2.0 * PI;


    //Inicia la definición de un nuevo primitivo gráfico, en este caso, un TRIANGLE_FAN
    glBegin(GL_TRIANGLE_FAN);
    //Establece el color actual de los vértices a un tono de naranja utilizando los valores RGB.
    glColor3ub(238, 139, 21);
    //Asigna los valores adecuados a las variables x, y y radius para el primer círculo.
    x = 0; y = 0; radius = 20;



    
    twicePi = 2.0 * PI;


    //Agrega un vértice en las coordenadas (x, y) al abanico de triángulos. En este caso, representa el centro del círculo.
    //centro del circulo
    glVertex2f(x, y); 
    //Inicia un bucle que itera desde 0 hasta triangleAmount, incrementando i en cada iteración.
    for (i = 0; i <= triangleAmount;i++) {
        //Agrega vértices adicionales al abanico de triángulos, calculados utilizando las funciones trigonométricas cos y sin.
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }


    //Finaliza la definición del primitivo gráfico.
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(199, 194, 187);
    x = -50; y = 50; radius = 20;




    twicePi = 2.0 * PI;



    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount;i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }



    glEnd();


    //Intercambia los buffers de la ventana, mostrando el resultado en pantalla.
    glutSwapBuffers();
}
//Define la función init sin argumentos ni valor de retorno.
void init(void)
{
    //Establece el color de fondo de la ventana en blanco utilizando los valores RGB.
    glClearColor(1.0, 1.0, 1.0, 0.0);
    //Reemplaza la matriz actual con la matriz identidad.
    glLoadIdentity();
    //Establece la matriz de proyección ortográfica para definir el volumen de visualización.
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{
    //Inicializa la biblioteca GLUT.
    glutInit(&argc, argv);
    //Establece el modo de visualización de la ventana, en este caso, utilizando el modelo de color RGB y buffers dobles.
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    //Establece el tamaño de la ventana.
    glutInitWindowSize(500, 550);
    //Crea una ventana con el título "Circle".
    glutCreateWindow("Circle");
    //Establece la función circle como la función de visualización.
    glutDisplayFunc(circle);
    //Llama a la función init para realizar la inicialización adicional.
    init();
    //Inicia el bucle principal de GLUT.
    glutMainLoop();
    //Retorna 0 para indicar que el programa se ha ejecutado correctamente.
    return 0;
}