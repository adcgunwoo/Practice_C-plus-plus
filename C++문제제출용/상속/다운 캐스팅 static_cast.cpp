//업캐스팅: 자식클래스->부모클래스
//다운캐스팅: 부모클래스->자식클래스
//다운캐스팅은 static_cast, dynamic_cast을 활용함
#include <iostream>
using namespace std;
//이번 시간은 static_cast
class Base {
public:
	int a = 1;
};
class Derivde1 : public Base {
public:
	float b = 3.14;
	void f() {
		cout << "Derivded1::f()" << endl;
		cout << b << endl;
	}
};
class Derivde2 : public Base {
public:
	void f() {
		cout << "Derivded2::f()" << endl;
		cout << c << endl;
	}
	int c = 3;
};
int main()
{
	int* a = new int(5);
	Base* b = new Derivde1;
	//Derived1 을 실제로 가르키고 있어도
	//b라는 포인터에서는 Base밖에 접근이 안됨
	Derivde1* d1 = (Derivde1*)b; 
	//다운캐스팅 상황인데 자동으로 안됨
	//명시적으로 포인터로 형변환 해줘야함
	d1->f();
	
	/*Derivde1* ac = static_cast<Derivde1*>(a);*/
	Derivde1* d2 = static_cast<Derivde1*>(b); 
	//static_cast는 이 형변환이 상식적으로 가능한지
	//검사해주는 기능을 함

	//static_cast 주의점
	//Base* b = new Derivde1;
	Derivde2* d3 = static_cast<Derivde2*>(b); //과 같이
	//포인터가 가르키는 값이 검사 값이랑 다르면 이상한 출력이 나옴
	d3->f();
	delete b;
}
