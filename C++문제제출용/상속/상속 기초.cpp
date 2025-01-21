#include <iostream>
using namespace std;
class Base {
public:
	void bFunc() {
		cout << "Hello!" << endl;
	}
	int bNum;
};
class Derived : public Base {
public:
	void deFunc() {
		cout << "Hello?" << endl;
	}
	int dNum;
};
int main() {
	Base b;
	Derived d;

	b.bFunc();
	b.bNum = 1;

	d.bFunc(); //자식이 부모클래스의 메서드 호출 가능
	d.bNum = 2; //자식이 부모클래스의 멤버변수에 접근 가능
	d.deFunc();
	d.dNum = 3;

	/*Hello!
	  Hello!
	  Hello?*/
}
