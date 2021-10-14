#include <GL/glut.h>

#include <iostream>
#include <sstream>

#include "Triangle.h"

void initScene(void);
void displayTriangles(void);
void reshapeWindow(void);
void recursiveTriangle(GLint, Triangle&);
bool isNumber(const std::string&);

GLint iterations;

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "Usage: ./sierpinski <number_of_triangles>" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (!isNumber(argv[1])) {
		std::cout << "Parameter is not a number or is a negative value." << std::endl;
		exit(EXIT_FAILURE);
	}

	std::stringstream ss;
	ss << argv[1];
	ss >> iterations;

	if (iterations > 10 || iterations < 1)
		iterations = 5;

	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition (0, 0);
	glutCreateWindow("Sierpinski-Triangle");
	initScene();
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutDisplayFunc(displayTriangles);
	reshapeWindow();
	glutMainLoop();
	return 0;
}

bool isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void reshapeWindow(void)
{
	const GLint screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	const GLint screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	glutReshapeWindow(screenWidth, screenHeight);
}

void displayTriangles (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	
	Triangle triangle;

	glBegin(GL_LINE_LOOP);
	glVertex2f(triangle.getLeftVertex().getX(), triangle.getLeftVertex().getY());
	glVertex2f(triangle.getTopVertex().getX(), triangle.getTopVertex().getY());
	glVertex2f(triangle.getRightVertex().getX(), triangle.getRightVertex().getY());
	glEnd();
	
	recursiveTriangle(iterations, triangle);

	glFlush ();
}

void recursiveTriangle(GLint iterations, Triangle& triangle)
{
	const Point leftHalf = triangle.getLeftTopHalf();
	const Point rightHalf = triangle.getRightTopHalf();
	const Point bottomHalf = triangle.getLeftRightHalf();

	glBegin(GL_LINE_LOOP);
	glVertex2f(leftHalf.getX(), leftHalf.getY());
	glVertex2f(bottomHalf.getX(), bottomHalf.getY());
	glVertex2f(rightHalf.getX(), rightHalf.getY());
	glEnd();

	if (iterations - 1 != 0) {
		const Point leftVertex{ triangle.getLeftVertex() };
		const Point rightVertex{ triangle.getRightVertex() };
		const Point topVertex{ triangle.getTopVertex() };

		Triangle leftTriangle{ leftHalf, leftVertex, bottomHalf };
		Triangle rightTriangle{ rightHalf, bottomHalf, rightVertex };
		Triangle topTriangle{ topVertex, leftHalf , rightHalf };

		recursiveTriangle(iterations - 1, leftTriangle);
		recursiveTriangle(iterations - 1, topTriangle);
		recursiveTriangle(iterations - 1, rightTriangle);
	}
}

void initScene (void)
{	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-300, 300.0, -300.0, 300.0);
}