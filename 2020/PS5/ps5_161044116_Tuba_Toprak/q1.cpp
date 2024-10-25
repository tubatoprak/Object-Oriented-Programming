


//I got the sources from the videos my teacher uploaded to moodle.


#include <iostream>
#include <cstdlib>
using namespace std;

class Vector2D
{
public:
	Vector2D();
	Vector2D(int newx, int newy);
	void SetXY(int newx, int newy);
	int getX();
	int getY();
	int operator *(const Vector2D &object);
private:
	int x,y;
};

Vector2D::Vector2D()
{
	x=0;
	y=0;
}

Vector2D::Vector2D(int newx, int newy)
{
	x = newx;
	y = newy;
}

void Vector2D::SetXY(int newx, int newy)
{
	x = newx;
	y = newy;
}

int Vector2D::getX()
{
	return x;
}
int Vector2D::getY()
{
	return y;
}

int Vector2D::operator *(const Vector2D &object)
{
	return (x*object.x) + (y*object.y);
}

int main()
{
 
 Vector2D v1(10,0), v2(0,10), v3(10,10);
 

 cout<<"("<<v1.getX()<<","<<v1.getY()<<")*("<<v2.getX()<<","<<v2.getY()<<")="<<v1*v2<<endl;
 cout<<"("<<v2.getX()<<","<<v2.getY()<<")*("<<v3.getX()<<","<<v3.getY()<<")="<<v2*v3<<endl;
 
 return 0;
}
