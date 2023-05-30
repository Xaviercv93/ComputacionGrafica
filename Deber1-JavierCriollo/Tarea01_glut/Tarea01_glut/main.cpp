#include <GL/freeglut.h>

void reshape(GLint w, GLint h);
void display();

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	//Generar venta y poner posicion
	glutInitWindowSize(512, 512);// Establecer el tamaño inicial de la ventana
	glutInitWindowPosition(100, 100);// Establecer la posición inicial de la ventana en la pantalla

	// Crear la ventana con el título "Hola mundo grafico"
	glutCreateWindow("Hola mundo grafico");
	/* Configurar el modo de visualización para OpenGL de a ventana creada con GLUT.
	En este caso, se utiliza GLUT_RGB para especificar que se utilizará el modelo de color RGB (Rojo, Verde, Azul) para representar los colores en la ventana.*/
	glutInitDisplayMode(GLUT_RGB);
	/* 1 en verde, 1 en rojo, 1 en azul y el ultimo 1 es el alfa Opacidad, el blending combina los colores
	Establecer el color de fondo de la ventana en rojo oscuro*/
	glClearColor(0.5, 0, 0, 1);


	/*establece la función de callback que se llamará cada vez que se necesite volver a dibujar la ventana de OpenGL.
	Cada vez que se requiera redibujar la ventana, OpenGL llamará a la función display() para realizar el dibujo en la ventana.
	Dentro de esta función, se colocará el código necesario para dibujar los objetos deseados utilizando las funciones y comandos de OpenGL.
	se realiza generalmente después de crear la ventana y configurar el modo de visualización
	para indicar a OpenGL qué función debe ejecutar cuando sea necesario actualizar y redibujar la ventana.*/
	glutDisplayFunc(display);  // Funcion de display(visualización)  para dibujar en cada frame por seg, en cada refresco de pantalla

	/* función de callback que se llamará cada vez que se produzca un cambio en el tamaño de la ventana.
	Recibe como argumento el nombre de la función que se encargará de manejar este evento.
	En este caso, se pasa el nombre de la función reshape como argumento.
	Esto significa que cada vez que se cambie el tamaño de la ventana, OpenGL llamará a la función reshape()
	para ajustar la proyección y configurar la vista de acuerdo al nuevo tamaño de la ventana.
	La llamada glutReshapeFunc(reshape) se realiza generalmente después de crear la ventana y configurar el modo de visualización,
	para indicar a OpenGL qué función debe ejecutar cuando se produzca un cambio en el tamaño de la ventana.*/
	glutReshapeFunc(reshape);  // Se ejecuta cuando se cambia el tamaño de la pantalla o se mueve.


	/*La función glutMainLoop() inicia el bucle principal de GLUT.
	Es una función que se ejecuta de forma indefinida y permite que la ventana se mantenga abierta y responda a eventos hasta que se cierre explícitamente.
	Después de llamar a glutMainLoop(), la ejecución del programa queda en manos de GLUT. GLUT se encarga de gestionar los eventos de la ventana, como la interacción del usuario,
	las actualizaciones de la pantalla y los eventos del teclado y el ratón. Cada vez que ocurre un evento, GLUT llama a las funciones de callback correspondientes registradas previamente,
	como la función de visualización (display()) o la función de cambio de tamaño de la ventana (reshape()).

	En resumen, glutMainLoop() es una función clave en las aplicaciones GLUT,
	ya que mantiene la ventana abierta y permite que el programa responda a eventos hasta que se cierre explícitamente la ventana o se termine el programa.*/
	glutMainLoop();   // Permite que se mantenga abierta la ventana

	/*es una instrucción que indica que la función main() ha finalizado y devuelve un valor entero de salida al sistema operativo.
	el valor de retorno 0 generalmente indica que el programa se ha ejecutado correctamente sin errores.
	Este valor de retorno puede ser utilizado por el sistema operativo o por otros programas para determinar si el programa se ha ejecutado correctamente o si ha ocurrido algún error.

	Es importante destacar que el valor de retorno 0 es una convención comúnmente utilizada para indicar éxito o finalización exitosa del programa,
	pero en algunos casos se pueden utilizar otros valores para indicar diferentes estados o errores específicos.*/
	return 0;
}

/*la función reshape se utiliza para ajustar la proyección y la matriz de vista cuando se produce un cambio de tamaño en la ventana.
Esto garantiza que los objetos se muestren correctamente en relación con las nuevas dimensiones de la ventana.*/
void reshape(GLint w, GLint h) {		// Ancho por alto
	/* Establecer el área de visualización en función del tamaño de la ventana
	Define la región de visualización en la ventana.
	Establece las coordenadas (0, 0) como la esquina inferior izquierda
	y usa los valores de w y h para determinar el ancho y la altura de la región de visualización.*/
	glViewport(0, 0, w, h);				// Desde donde inicia 0,0

	/* Cambiar al modo de proyección
	Establece la matriz de proyección como la matriz de trabajo actual.*/
	glMatrixMode(GL_PROJECTION);	// Definir perspectiva

	/*Carga la matriz de identidad como la matriz de trabajo actual.
	Esto restablece cualquier transformación previa que se haya aplicado a la matriz de proyección.
	Restablecer la matriz de proyección a la identidad*/
	glLoadIdentity();				// Cambio lo que esta en la matriz por la identidad

	/*Define una proyección ortográfica en 2D con límites de visualización específicos.
	En este caso, se establece un límite izquierdo de -1.5, un límite derecho de 1.5, un límite inferior de -1.5 y un límite superior de 1.5.

	Definir una proyección ortográfica en el rango (-1.5, 1.5) para X e Y */
	gluOrtho2D(-1.5, 1.5, -1.5, 1.5);	// Primero se desplaza en X luego en Y
}

void display() {    // Aqui se dibuja, se trabaja en la matriz de Modelo, de los objetos

	/*Borrar el búfer de color para iniciar un nuevo cuadro*/
	glClear(GL_COLOR_BUFFER_BIT);      // Se pone en cero los buffers

	/*Cambiar al modo de vista de modelo*/
	glMatrixMode(GL_MODELVIEW);			// Genera nueva matriz de proyeccion

	/*Restablecer la matriz de modelo a la identidad*/
	glLoadIdentity();

	/*Guardar la matriz de modelo actual*/
	glPushMatrix();


	/*Establecer el color actual a un tono de verde claro*/
	glColor3f(0.3, 0.8, 0.6);		// Rojo, verde, azul, valores entre 0 y 1



	//glutSolidTeapot(1);       // Tamaño de la tetera

	/*Dibujar una tetera alámbrica con un tamaño de 1*/
	glutWireTeapot(1);

	/*Restaurar la matriz de modelo anterior*/
	glPopMatrix();

	/*Establecer el color actual a un tono de amarillo oscuro*/
	glColor3f(0.5, 0.5, 0.2);		// Rojo, verde, azul, valores entre 0 y 1
	//glPopMatrix();

	/*Realizar una traslación en el eje X y el eje Y*/
	glTranslatef(0.5, 0.5, 0); //traslado los solo el objeto cone

	/*Dibujar un cono alámbrico con un radio y altura de 0.5 y 10 segmentos*/
	glutWireCone(0.5, 0.5, 10, 10);
	//glTranslatef(2,2, 0); //traslado los 2 objetos
	//glPopMatrix();

	/*Enviar los comandos de dibujo a la GPU para que se muestren en la ventana*/
	glFlush();

}