#include<iostream>
#include<system_error>

using namespace std;

//抽象类
class Shape
{
public:
	//Shape() = default;
	Shape(int) {}
	virtual ~Shape() {}
	virtual double GetArea() = 0; //纯虚函数
	virtual double GetPerm() = 0;
	virtual void Draw() =0;

};

class Circle:public Shape
{
public:
//	Circle() = default;
	Circle(int radius) :itsRadius(radius) {}

	//只要基类中有虚函数，派生类的析构函数一定的是虚析构函数
	virtual ~Circle() {}

	double GetAera()
	{
		return 3.14 * itsRadius * itsRadius;
	}

	double GetPerm()
	{
		return 3.14 * 2 * itsRadius;
	}

	void Draw();
private:
	int itsRadius;
};

void Circle::Draw()
{
	cout << "Drawing the circle*************" << endl;
}

//class Rercentage:public Shape
//{};
//
//class Square:public Rercentage
//{};

int main()
{
	//不能创建抽象类的对象
//Shape a;
//	Circle a;
//	a.Draw();

	system("pause");
	return 0;
}