//static_cast: ����(������)
//dynamic_cast: ����(��Ÿ��)
//RTTI(Run Time Type Information/Identification)
//RTTI�� ����Ŭ������ ����
#include <iostream>
using namespace std; //C++���� �� ������ Ŭ������ ����

class Base { //�����Լ��� �ϳ��� ������ ���� Ŭ����
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
	//�θ�Ŭ������ ����Ű�� ������,�����δ� Derived�� ����Ŵ
	//Derived* d = static_cast<Derived*>(b);
	cout << sizeof(Base) << endl; 
	cout << sizeof(Derived) << endl;
	
}