//���� ����
//����) ���� ����������
//public : �ܺ� ����O, �ڽ�Ŭ���� O
//private : �ܺ� ����X, �ڽ�Ŭ���� X
//protected : �ܺ� ����X, �ڽ�Ŭ���� O
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
//��κ��� Ŭ������ public���� ��ӹ�����
//protected�� ��ӹ޴� ���� �θ�Ŭ������
//public�� protectd�� protected�� private�� �״�� ����
//���� �θ�Ŭ������ public���� ��������� �ܺο��� ���Ұ����ϴ�.
//private�� ��� ���� ���� ��� �����ڸ� private�� �ٲ������.