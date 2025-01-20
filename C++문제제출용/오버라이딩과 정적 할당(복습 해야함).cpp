//오버라이드(override) : 사전적의미로는 '우선하다'
//오버로딩(overload) : 
//오버라이트(overwite) : 사전적으로는 '덮어쓰다'
#include <iostream>
using namespace std;

class Base {
public:
	void Print() {
		cout << "From Base!!" << endl;
	}
private:

};
class Derived : public Base {
public:
	void Print() {
		cout << "From Derived!!" << endl;
	}
private:
};
//Derived d;
//Base* b=&d; 부모클래스의 포인터가 자식 클래스를 가르킬수 있음
class Derived2 :public Base {

};
int main()
{
	Base* b = new Derived();
	//Derived타입의 객체를 동적할당하고, 그 포인터를 b에 저장하라.
	b->Print();
	//==(*b).Print();
	/*
	From Base!! 이게 출력됨.. Derived를 가르키는데 도대체 왜??
	*/
	delete b;
	b = new Derived2();
	b->Print();
	
}