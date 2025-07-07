
#include <iostream>
#include <vector>
#include <cmath> // sqrt

using namespace std;

struct Rectangle
{
	int x;
	int y;
	int width;
	int height;

	Rectangle(int _x, int _y, int _width, int _height) : x(_x), y(_y), width(_width), height(_height) {}
};

bool collisionCheck(Rectangle r1, Rectangle r2)
{	
	//                 r1이 왼쪽                         r2가 왼쪽
	bool x_overlap = (r1.x + r1.width >= r2.x) && (r1.x <= r2.x + r2.width);

	bool y_overlap = (r1.y + r1.height >= r2.y) && (r1.y <= r2.y + r2.height);

	bool IsCollision = x_overlap && y_overlap;

	if (IsCollision)
	{
		cout << "겹칩니다." << endl;
		return true;
	}
	else
	{
		cout << "겹치지 않습니다." << endl;
		return false;
	}
}

struct Circle
{
	double x;
	double y;
	double radious;	

	Circle(double _x, double _y, double _radious) : x(_x), y(_y), radious(_radious) {}
};

bool circleCheck(Circle c1, Circle c2)
{
	double dx = c1.x - c2.x;
	double dy = c1.y - c2.y;
	double distanceSq = (dx * dx) + (dy * dy);

	//(c1.radious + c2.radious) * (c1.radious + c2.radious)
	bool isCollision = sqrt(distanceSq) <= (c1.radious + c2.radious);

	if (isCollision)
	{
		cout << "충돌합니다." << endl;
		return true;
	}
	else
	{
		cout << "충돌하지 않습니다." << endl;
		return false;
	}
}

class Bullet
{
public:
	Rectangle collider;
	bool      isCollision;
	Bullet(Rectangle _col) : collider(_col), isCollision(false) {}

	void IsCollisionCheck(const Bullet& other)
	{
		if (collisionCheck(collider, other.collider))
		{
			isCollision = true;
		}
		else
		{
			isCollision = false;
		}
	}
};

int main()
{
	Rectangle r1(3, 3, 4, 4);
	Rectangle r2(8, 3, 4, 4);
	collisionCheck(r1, r2);

	cout << endl;
	Circle c1(1,1,3);
	Circle c2(3,3,2);
	circleCheck(c1, c2);

	cout << endl;
	Bullet bullet(r1);
	Bullet bullet2(r2);

	bullet.IsCollisionCheck(bullet2);

	if (bullet.isCollision)
	{
		cout << "그리지 마시오." << endl;
	}
	else
	{
		cout << "그립니다." << endl;
	}
}
