//static_cast: 정적(컴파일)
//dynamic_cast: 동적(런타임)
//RTTI(Run Time Type Information/Identification)
//RTTI는 다형클래스만 지원
#include <iostream>
using namespace std; //C++에는 두 가지의 클래스가 있음

class Base { //가상함수가 하나라도 있으면 다형 클래스
public:
	virtual void f(){}
	int x;
};
class Derived : public Base {
public:
	void f() {}
	int y;
};
int main()
{
	//Base* b = new Derived;
	//부모클래스를 가르키는 포인터,실제로는 Derived를 가르킴
	//Derived* d = static_cast<Derived*>(b);
	cout << sizeof(Base) << endl; 
	cout << sizeof(Derived) << endl;
	
}