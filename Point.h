#pragma once
#include <GL/glut.h>

class Point
{
private:
	GLfloat x;
	GLfloat y;
public:
	Point() : x(0), y(0) {}
	Point(GLfloat x, GLfloat y) : x(x), y(y) {}
	
	const GLfloat getX(void) const;
	const GLfloat getY(void) const;
};

