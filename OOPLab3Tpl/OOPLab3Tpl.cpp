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




//task 2 
#include <iostream>
#include <math.h>
#include <clocale>
using namespace std;
enum STATE {
	OK, BAD_INIT, BAD_DIV
};


class ComplexNumber {
	float re;
	float im;
	int state;


public: 
	ComplexNumber() : re(0), im(0), state(0){}
	ComplexNumber(float iv) : re(iv), im(iv) {}
	ComplexNumber(float* p) {
		if (p == nullptr) {
			state = 4;
			re = 0;
			im = 0;
		}
		else {
			re = p[0];
			im = p[1];
		}
	}

	ComplexNumber(const ComplexNumber&);
	ComplexNumber :: ComplexNumber(const ComplexNumber& s) {
		if (this == &s) return;
		re = s.re; im = s.im;
		count++;
	}

	void Input();
	void Output();
	bool CompLessAll(ComplexNumber& s);
	static int getCount() {
		if (count <= 0) cout << " Немає об'єктів ComplexNumber ";
		return count;
	}
	int getState() { return state; }

};
	void ComplexNumber::Input() {
		cout << "Input re and im: ";
		cin >> im >> re;

	}


	void ComplexNumber::Otput() {
		cout << "re = " << re << "im = " << im << "state = " << state << endl;
	}

	ComplexNumber ComplexNumber::Add(ComplexNumber& s) {
		ComplexNumber tmp;
		tmp.re = re + s.re;
		tmp.im = im + s.im;
		return tmp;
	}

	ComplexNumber ComplexNumber::Sub(ComplexNumber& s) {
		ComplexNumber tmp;
		tmp.re = re - s.re;
		tmp.im = im - s.im;
		return tmp;
	}
	
	ComplexNumber ComplexNumber::Div(double d) {
		ComplexNumber tmp;
		if (fabs(d) < 1.e-25) {
			tmp.state = BAD_DIV;
			cout << " Error div \n";
			return *this;
		}
		tmp.re = re / d;
		tmp.im = im / d;
		return tmp;
	}
	ComplexNumber ComplexNumber::Mul(double d) {
		ComplexNumber tmp;
		tmp.re = re * d;
		tmp.im = im * d;
		return tmp;
	}
	bool ComplexNumber::CompLessAll(ComplexNumber& s) {
		if (re < s.re && im < s.im) return true;
		return false;

	}

int main()
{
   
	setlocale(LC_CTYPE, "ukr");
	cout << "Тестування створенного класу \n";
	cout << "Тестування конструкторiв \n";
	ComplexNumber ObjCDef;
	ObjCDef.Output();
	ComplexNumber ObjP1(10.0);

	ObjP1.Output();
	double a = 1.0, b = 2.0;
	ComplexNumber ObjP2(a, b);
	ObjP2.Output();
	ComplexNumber ObjCopy(ObjP2);
	double* v = nullptr, v2[] = { 1.2, 3.3 };
	ComplexNumber ObjP3(v2);
	if (ObjP3.getState() != OK) cout << " ObjP3 re= 0 im= 0 \n";
	ComplexNumber ObjP4(v2);
	if (ObjP4.getState() != OK) cout << " ObjP4 re= 0 im= 0 \n";
	cout << " Кiлькiсть створених об'єктiв Vec2 " << ComplexNumber::getCount() << endl;
	cout << "Тестування введення \n";
	ObjCDef.Input();
	cout << "Тестування функцiй \n";
	ObjCDef = ObjCDef.Add(ObjP2);
	ObjCDef.Output();
	cout << " \n Кiлькiсть створених об'єктiв ComplexNumber до Sub " << ComplexNumber::getCount() << endl;
	ObjCDef = ObjCDef.Sub(ObjP2);
	cout << " \n Кiлькiсть створених об'єктiв ComplexNumber пiсля Sub " << ComplexNumber::getCount() << endl;
	ObjCDef.Output();
	ObjCDef = ObjCDef.Mul(5);
	ObjCDef.Output();
	ObjCDef = ObjCDef.Div(1.3);
	if (ObjCDef.getState() == STATE::BAD_DIV) cout << "BAD_DIV \n";
	ObjCDef.Output();
	ObjCDef = ObjCDef.Div(0.0);
	if (ObjCDef.getState() == STATE::BAD_DIV) cout << "BAD_DIV \n";
	ObjCDef.Output();
	cout << "ObjCopy state " << ObjCopy.getState() << endl;
	if (ObjCopy.CompLessAll(ObjCDef)) cout << "ObjCopy less ObjDef " << endl;
	cout << "Завершення тестування \n";
	return 1;
}
