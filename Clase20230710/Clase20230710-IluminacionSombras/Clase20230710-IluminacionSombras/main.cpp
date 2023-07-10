#include <iostream>
#include <GL/freeglut.h>

// se creara un proyeccion ortogonal

int main(int argc, char ** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600,400);
	glutInitWindowPosition(100,100);

	glutCreateWindow("Ejemplo Iluminacion");
	
	initGL();


	glutReshapeFunc(display);
	glutMainLoop();

	return 0;

}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);

}