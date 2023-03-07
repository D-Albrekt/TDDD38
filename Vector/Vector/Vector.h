#pragma once
#include <string>

class Vector
{
public:

	Vector();
	Vector(double x, double y);
	Vector operator-();
	bool operator==(Vector const& rhs) const;
	bool operator!=(Vector const& rhs) const;
	Vector operator*(double rhs) const;
	Vector operator+(Vector const& rhs) const;
	
	
	void print(std::string str);
private:
	double x;
	double y;
};

Vector operator*(int lhs, Vector const& rhs);
