#include<iostream>
#include<system_error>

using namespace std;

//������
class Shape
{
public:
	//Shape() = default;
	Shape(int) {}
	virtual ~Shape() {}
	virtual double GetArea() = 0; //���麯��
	virtual double GetPerm() = 0;
	virtual void Draw() =0;

};

class Circle:public Shape
{
public:
//	Circle() = default;
	Circle(int radius) :itsRadius(radius) {}

	//ֻҪ���������麯�������������������һ����������������
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
	//���ܴ���������Ķ���
//Shape a;
//	Circle a;
//	a.Draw();

	system("pause");
	return 0;
}