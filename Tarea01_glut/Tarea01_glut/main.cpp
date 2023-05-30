#include <GL/freeglut.h>

void reshape(GLint w, GLint h);
void display();

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	//Generar venta y poner posicion
	glutInitWindowSize(512, 512);// Establecer el tama�o inicial de la ventana
	glutInitWindowPosition(100, 100);// Establecer la posici�n inicial de la ventana en la pantalla

	// Crear la ventana con el t�tulo "Hola mundo grafico"
	glutCreateWindow("Hola mundo grafico");
	/* Configurar el modo de visualizaci�n para OpenGL de a ventana creada con GLUT.
	En este caso, se utiliza GLUT_RGB para especificar que se utilizar� el modelo de color RGB (Rojo, Verde, Azul) para representar los colores en la ventana.*/
	glutInitDisplayMode(GLUT_RGB);
	/* 1 en verde, 1 en rojo, 1 en azul y el ultimo 1 es el alfa Opacidad, el blending combina los colores
	Establecer el color de fondo de la ventana en rojo oscuro*/
	glClearColor(0.5, 0, 0, 1);


	/*establece la funci�n de callback que se llamar� cada vez que se necesite volver a dibujar la ventana de OpenGL.
	Cada vez que se requiera redibujar la ventana, OpenGL llamar� a la funci�n display() para realizar el dibujo en la ventana.
	Dentro de esta funci�n, se colocar� el c�digo necesario para dibujar los objetos deseados utilizando las funciones y comandos de OpenGL.
	se realiza generalmente despu�s de crear la ventana y configurar el modo de visualizaci�n
	para indicar a OpenGL qu� funci�n debe ejecutar cuando sea necesario actualizar y redibujar la ventana.*/
	glutDisplayFunc(display);  // Funcion de display(visualizaci�n)  para dibujar en cada frame por seg, en cada refresco de pantalla

	/* funci�n de callback que se llamar� cada vez que se produzca un cambio en el tama�o de la ventana.
	Recibe como argumento el nombre de la funci�n que se encargar� de manejar este evento.
	En este caso, se pasa el nombre de la funci�n reshape como argumento.
	Esto significa que cada vez que se cambie el tama�o de la ventana, OpenGL llamar� a la funci�n reshape()
	para ajustar la proyecci�n y configurar la vista de acuerdo al nuevo tama�o de la ventana.
	La llamada glutReshapeFunc(reshape) se realiza generalmente despu�s de crear la ventana y configurar el modo de visualizaci�n,
	para indicar a OpenGL qu� funci�n debe ejecutar cuando se produzca un cambio en el tama�o de la ventana.*/
	glutReshapeFunc(reshape);  // Se ejecuta cuando se cambia el tama�o de la pantalla o se mueve.


	/*La funci�n glutMainLoop() inicia el bucle principal de GLUT.
	Es una funci�n que se ejecuta de forma indefinida y permite que la ventana se mantenga abierta y responda a eventos hasta que se cierre expl�citamente.
	Despu�s de llamar a glutMainLoop(), la ejecuci�n del programa queda en manos de GLUT. GLUT se encarga de gestionar los eventos de la ventana, como la interacci�n del usuario,
	las actualizaciones de la pantalla y los eventos del teclado y el rat�n. Cada vez que ocurre un evento, GLUT llama a las funciones de callback correspondientes registradas previamente,
	como la funci�n de visualizaci�n (display()) o la funci�n de cambio de tama�o de la ventana (reshape()).

	En resumen, glutMainLoop() es una funci�n clave en las aplicaciones GLUT,
	ya que mantiene la ventana abierta y permite que el programa responda a eventos hasta que se cierre expl�citamente la ventana o se termine el programa.*/
	glutMainLoop();   // Permite que se mantenga abierta la ventana

	/*es una instrucci�n que indica que la funci�n main() ha finalizado y devuelve un valor entero de salida al sistema operativo.
	el valor de retorno 0 generalmente indica que el programa se ha ejecutado correctamente sin errores.
	Este valor de retorno puede ser utilizado por el sistema operativo o por otros programas para determinar si el programa se ha ejecutado correctamente o si ha ocurrido alg�n error.

	Es importante destacar que el valor de retorno 0 es una convenci�n com�nmente utilizada para indicar �xito o finalizaci�n exitosa del programa,
	pero en algunos casos se pueden utilizar otros valores para indicar diferentes estados o errores espec�ficos.*/
	return 0;
}

/*la funci�n reshape se utiliza para ajustar la proyecci�n y la matriz de vista cuando se produce un cambio de tama�o en la ventana.
Esto garantiza que los objetos se muestren correctamente en relaci�n con las nuevas dimensiones de la ventana.*/
void reshape(GLint w, GLint h) {		// Ancho por alto
	/* Establecer el �rea de visualizaci�n en funci�n del tama�o de la ventana
	Define la regi�n de visualizaci�n en la ventana.
	Establece las coordenadas (0, 0) como la esquina inferior izquierda
	y usa los valores de w y h para determinar el ancho y la altura de la regi�n de visualizaci�n.*/
	glViewport(0, 0, w, h);				// Desde donde inicia 0,0

	/* Cambiar al modo de proyecci�n
	Establece la matriz de proyecci�n como la matriz de trabajo actual.*/
	glMatrixMode(GL_PROJECTION);	// Definir perspectiva

	/*Carga la matriz de identidad como la matriz de trabajo actual.
	Esto restablece cualquier transformaci�n previa que se haya aplicado a la matriz de proyecci�n.
	Restablecer la matriz de proyecci�n a la identidad*/
	glLoadIdentity();				// Cambio lo que esta en la matriz por la identidad

	/*Define una proyecci�n ortogr�fica en 2D con l�mites de visualizaci�n espec�ficos.
	En este caso, se establece un l�mite izquierdo de -1.5, un l�mite derecho de 1.5, un l�mite inferior de -1.5 y un l�mite superior de 1.5.

	Definir una proyecci�n ortogr�fica en el rango (-1.5, 1.5) para X e Y */
	gluOrtho2D(-1.5, 1.5, -1.5, 1.5);	// Primero se desplaza en X luego en Y
}

void display() {    // Aqui se dibuja, se trabaja en la matriz de Modelo, de los objetos

	/*Borrar el b�fer de color para iniciar un nuevo cuadro*/
	glClear(GL_COLOR_BUFFER_BIT);      // Se pone en cero los buffers

	/*Cambiar al modo de vista de modelo*/
	glMatrixMode(GL_MODELVIEW);			// Genera nueva matriz de proyeccion

	/*Restablecer la matriz de modelo a la identidad*/
	glLoadIdentity();

	/*Guardar la matriz de modelo actual*/
	glPushMatrix();


	/*Establecer el color actual a un tono de verde claro*/
	glColor3f(0.3, 0.8, 0.6);		// Rojo, verde, azul, valores entre 0 y 1



	//glutSolidTeapot(1);       // Tama�o de la tetera

	/*Dibujar una tetera al�mbrica con un tama�o de 1*/
	glutWireTeapot(1);

	/*Restaurar la matriz de modelo anterior*/
	glPopMatrix();

	/*Establecer el color actual a un tono de amarillo oscuro*/
	glColor3f(0.5, 0.5, 0.2);		// Rojo, verde, azul, valores entre 0 y 1
	//glPopMatrix();

	/*Realizar una traslaci�n en el eje X y el eje Y*/
	glTranslatef(0.5, 0.5, 0); //traslado los solo el objeto cone

	/*Dibujar un cono al�mbrico con un radio y altura de 0.5 y 10 segmentos*/
	glutWireCone(0.5, 0.5, 10, 10);
	//glTranslatef(2,2, 0); //traslado los 2 objetos
	//glPopMatrix();

	/*Enviar los comandos de dibujo a la GPU para que se muestren en la ventana*/
	glFlush();

}