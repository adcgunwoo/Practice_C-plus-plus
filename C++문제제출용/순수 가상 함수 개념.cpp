#include <iostream>
using namespace std;
//78,79������ ���� �Լ��� ������� �������?
class A {
public:       
	//virtual void f() { ��� �̰� ���� ���� �Լ��� �ƴ�
	//	cout << "A::f()" << endl;
	//}
	virtual void f() = 0; //�̰� ���� ���� �Լ�
};
//��ü�� ���� �� ����
//���� ���� �Լ��� ���� Ŭ������ '�߻�' Ŭ������� �Ѵ�.
class B : public A{
public:
	void f() {
		cout << "B::f()" << endl;
	}
};//��� ����� �ް� �������̵��� �ϸ� B�� ��ü�� ���� �� ����
int main()
{
	//A* a = new A;
	A *a=new B;
	
	a->f();

	delete a;

}