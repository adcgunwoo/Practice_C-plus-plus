//��ĳ����: �ڽ�Ŭ����->�θ�Ŭ����
//�ٿ�ĳ����: �θ�Ŭ����->�ڽ�Ŭ����
//�ٿ�ĳ������ static_cast, dynamic_cast�� Ȱ����
#include <iostream>
using namespace std;
//�̹� �ð��� static_cast
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
	//Derived1 �� ������ ����Ű�� �־
	//b��� �����Ϳ����� Base�ۿ� ������ �ȵ�
	Derivde1* d1 = (Derivde1*)b; 
	//�ٿ�ĳ���� ��Ȳ�ε� �ڵ����� �ȵ�
	//��������� �����ͷ� ����ȯ �������
	d1->f();
	
	/*Derivde1* ac = static_cast<Derivde1*>(a);*/
	Derivde1* d2 = static_cast<Derivde1*>(b); 
	//static_cast�� �� ����ȯ�� ��������� ��������
	//�˻����ִ� ����� ��

	//static_cast ������
	//Base* b = new Derivde1;
	Derivde2* d3 = static_cast<Derivde2*>(b); //�� ����
	//�����Ͱ� ����Ű�� ���� �˻� ���̶� �ٸ��� �̻��� ����� ����
	d3->f();
	delete b;
}