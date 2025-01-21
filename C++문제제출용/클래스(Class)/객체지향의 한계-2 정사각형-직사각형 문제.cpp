//객체지향 프로그램의 한계점 2
//정사각형-직사각형 문제
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//immutable(불변) 클래스
class Rectangle {//직사각형
public:
	Rectangle(double a, double b) : a(a),b(b){}
	virtual ~Rectangle() {} //다형클래스
	Rectangle ResizeX(double k) { return Rectangle(a * k, b); }
	Rectangle ResizeY(double k) { return Rectangle(a, b * k); }
	double GetA() const { return a; }
	double GetB() const { return b; }
private:
	const double a, b;
};
class Square : public Rectangle{ //정사각형
public:
	Square(double a) : Rectangle(a,a) {}
	
private:
	double a;
};
int main()
{
	Square s(10);
	s.ResizeX(2);

	Rectangle r = s.ResizeX(2);
	cout << s.GetA() << endl;
	cout << s.GetB() << endl;
	cout << r.GetA() << endl;
	cout << r.GetB() << endl;

	/*Rectangle* r = new Square(10);
	r->ResizeX(2);*/
}
