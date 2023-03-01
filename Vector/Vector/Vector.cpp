#include "Vector.h"
#include <iostream>

Vector::Vector()
	: x{0}, y{0}
{}

Vector::Vector(double x, double y)
	: x{x}, y{y}
{}

bool Vector::operator==(Vector const& rhs) const
{
	return (rhs.x == x && rhs.y == y);
}

bool Vector::operator!=(Vector const& rhs) const
{
	return !(*(this) == rhs);
}



Vector Vector::operator*(double rhs) const
{
	Vector v{ x * rhs, y * rhs };
	return v;
}

Vector Vector::operator+(Vector const& rhs) const
{
	Vector vec1{ (x + rhs.x), (y + rhs.y) };
	return vec1;
}



void Vector::print(std::string str)
{
	std::cout << "Hello Vector World\n";
}

Vector operator*(int lhs, Vector const& rhs)
{
	return (rhs * lhs);
}