//static_cast: 정적(컴파일)
//dynamic_cast: 동적(런타임)
//RTTI(Run Time Type Information/Identification)
#include <iostream>
#include <math.h>
using namespace std;

class Shape {
public:
	virtual double GetArea() const = 0;
	virtual void Resize(double k) = 0;
};
class Circle : public Shape {
public:
	Circle(double r) : r(r) {}
	double GetArea() const {
		return r * r * 3.14;
	}
	void Resize(double k) {
		r *= k;
	}
private:
	double r;
};
class Rectangle : public Shape {
public:
	Rectangle(double a, double b) : a(a), b(b) {}
	double GetArea() const {
		return a * b;
	}
	void Resize(double k) {
		a *= k;
		b *= k;
	}
	double GetDiag() const {
		return sqrt(a * a + b * b);
	}
private:
	double a, b;
};
int main()
{
	Shape* shapes[] = { new Circle(1), new  Rectangle(1,2)};
	for (int i = 0; i < 2; i++) {
		//도형의 넓이
		//직사각형의 경우만, 대각선 길이 출력
		cout <<"도형의 넓이 : " << shapes[i]->GetArea() << endl;
		Rectangle* r = dynamic_cast<Rectangle*>(shapes[i]);
		//shapes[i]가 Rectangle을 가르키고 있으면 주솟값이 들어가고
		//Circle이라면 널값이 들어감
		if (r != NULL) {
			cout << "대각선의 길이 : " << r->GetDiag() << endl;
		}
	}

	for (int i = 0; i < 2; i++) {
		delete shapes[i];
	}

}
