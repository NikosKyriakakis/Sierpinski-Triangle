#include "Triangle.h"

const Point& Triangle::getTopVertex() const
{
    return topVertex;
}

const Point& Triangle::getLeftVertex() const
{
    return leftVertex;
}

const Point& Triangle::getRightVertex() const
{
    return rightVertex;
}

const Point Triangle::getLeftTopHalf() const
{
    const GLfloat midX = (topVertex.getX() + leftVertex.getX()) / 2;
    const GLfloat midY = (topVertex.getY() + leftVertex.getY()) / 2;
    return Point(midX, midY);
}

const Point Triangle::getRightTopHalf() const
{
    const GLfloat midX = (topVertex.getX() + rightVertex.getX()) / 2;
    const GLfloat midY = (topVertex.getY() + rightVertex.getY()) / 2;
    return Point(midX, midY);
}

const Point Triangle::getLeftRightHalf() const
{
    const GLfloat midX = (rightVertex.getX() + leftVertex.getX()) / 2;
    const GLfloat midY = (rightVertex.getY() + leftVertex.getY()) / 2;
    return Point(midX, midY);
}
