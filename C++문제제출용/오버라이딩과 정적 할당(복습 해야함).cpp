//�������̵�(override) : �������ǹ̷δ� '�켱�ϴ�'
//�����ε�(overload) : 
//��������Ʈ(overwite) : ���������δ� '�����'
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
//Base* b=&d; �θ�Ŭ������ �����Ͱ� �ڽ� Ŭ������ ����ų�� ����
class Derived2 :public Base {

};
int main()
{
	Base* b = new Derived();
	//DerivedŸ���� ��ü�� �����Ҵ��ϰ�, �� �����͸� b�� �����϶�.
	b->Print();
	//==(*b).Print();
	/*
	From Base!! �̰� ��µ�.. Derived�� ����Ű�µ� ����ü ��??
	*/
	delete b;
	b = new Derived2();
	b->Print();
	
}