#pragma once
#include "Point.h"
class Triangle
{
private:
	Point topVertex;
	Point leftVertex;
	Point rightVertex;
public:
	Triangle() : topVertex(0.0, 300.0), leftVertex(-300.0, -300.0), rightVertex(300.0, -300.0) {}
	Triangle(const Point& topVertex, const Point& leftVertex, const Point& rightVertex):
			topVertex(topVertex), 
			leftVertex(leftVertex), 
			rightVertex(rightVertex) {}
	const Point& getTopVertex() const;
	const Point& getLeftVertex() const;
	const Point& getRightVertex() const;
	const Point getLeftTopHalf() const;
	const Point getRightTopHalf() const;
	const Point getLeftRightHalf() const;
};

