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

	d.bFunc(); //�ڽ��� �θ�Ŭ������ �޼��� ȣ�� ����
	d.bNum = 2; //�ڽ��� �θ�Ŭ������ ��������� ���� ����
	d.deFunc();
	d.dNum = 3;

	/*Hello!
	  Hello!
	  Hello?*/
}