// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>

// Ваші файли загловки 
//
#include "Lab3Expaple.h"
int main()
{
    std::cout << " Lab #3  !\n";
//  Код виконання завдань
//  Головне меню завдань
//  Функції та класи можуть знаходитись в інших файлах проекту

    int conv = 1;
    if (conv == 1) conv = mainExample1();
    if (conv == 1) conv = mainExample3(); 
    if (conv == 1) conv = mainExample4();

}

//task 1

#include <iostream>
#include <math.h>
using namespace std;
class Сircle{

	double radius; // circle
	unsigned int color;
public:
	
	Сircle() : radius(1.0), color(0) {}
	Сircle(double ai) : radius(ai), color(0) {}
	Сircle(int ic) : radius(1.0) { if (ic >= 0) color = ic; else color = 0; }
	Сircle(double radius, int c) {
		this->radius = radius;

		if (c >= 0) color = c; else color = 0;
	}
	double getRadius() const
	{
		
		return radius;
	}
	void setRadius(double radius)
	{
		if (radius < 0 || radius > 1.e+100)
		{
			cout << " Error set a \n";
			return;
		}
		this->radius = radius;
	}
	double getColor() const
	{
		return color;
	}
	void setColor(int c)
	{
		if (c < 0 || c > 10000)
		{
			cout << " Error set color \n";
			return;
		}
		this->color = c;
	}
	double S() {
		return 3.14 * radius * radius;
	}
	double C() {
		return 2 * radius * 3.14;
	}
	
	void printInfo()
	{
		cout << "\n Radius= " << radius << " color = " << color;
		cout << " S= " << S() << " C = " << C() << endl;
	}
};
int main()
{
	cout << "Object created " << endl;
	Сircle obj;
	obj.printInfo();
	double in_radius; int in_color;
	cout << " Input radius and color circle "; cin >> in_radius >> in_color;
	Сircle obj1(in_radius), obj2(in_color), obj3(in_radius, in_color);
	obj1.printInfo();
	obj2.printInfo();
	obj3.printInfo();
	obj.setRadius(-5);
	obj.printInfo();
	obj.setRadius(5);
	obj.printInfo();
	obj.setRadius(2.e100);
	obj.printInfo();
	obj.setColor(-10);
	obj.printInfo();
	obj.setColor(10);
	obj.printInfo();
	obj.setColor(10001);
	obj.printInfo();
	cout << " End testing \n";
	return 0;
}
