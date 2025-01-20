//상속에서의 형변환 (1)
//캐스팅은 형변환이라는 의미이다
//업캐스팅: 자식클래스 포인터->부모클래스 포인터(묵시적)
#include <iostream>
using namespace std;
class Base {

};
class Derived : public Base {

};
int main()
{
	Derived* d = new Derived;
	Base* b = d; //업캐스팅 상황
	//자식클래스를 가르키는 포인터가
	//부모클래스의 포인터에 대입이 가능한것은 
	//묵시적형변환 때문이다. ex) double a=1;

}



