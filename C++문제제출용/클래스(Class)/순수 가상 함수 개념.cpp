#include <iostream>
using namespace std;
//78,79강에서 가상 함수를 사용했음 기억하지?
class A {
public:       
	//virtual void f() { 사실 이건 순수 가상 함수가 아님
	//	cout << "A::f()" << endl;
	//}
	virtual void f() = 0; //이게 순수 가상 함수
};
//객체를 가질 수 없음
//순수 가상 함수를 가진 클래스를 '추상' 클래스라고 한다.
class B : public A{
public:
	void f() {
		cout << "B::f()" << endl;
	}
};//대신 상속을 받고 오버라이딩을 하면 B는 객체를 가질 수 있음
int main()
{
	//A* a = new A;
	A *a=new B;
	
	a->f();

	delete a;

}
