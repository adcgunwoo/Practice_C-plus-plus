//접근 제어
//예시) 접근 제어지시자
//public : 외부 접근O, 자식클래스 O
//private : 외부 접근X, 자식클래스 X
//protected : 외부 접근X, 자식클래스 O
#include <iostream>
using namespace std;
class Base {
public:
	int bPublic;
protected:
	int bProtected;
private:
	int bPrivate;
};
class Derived : public Base {
public:
	int dPublic;
	void dFunc() {
		bPublic = 1;
		bProtected = 2;
		dPublic = 4;
		dPrivate = 5;
	}
private:
	int dPrivate;
};
int main()
{
	Base b;
	Derived d;

	b.bPublic = 1;
	d.dPublic = 4;
}
//대부분의 클래스는 public으로 상속받지만
//protected로 상속받는 경우는 부모클래스의
//public과 protectd를 protected로 private은 그대로 간다
//따라서 부모클래스의 public였던 멤버들을을 외부에서 사용불가능하다.
//private로 상속 받은 경우는 모든 지시자를 private로 바꿔버린다.