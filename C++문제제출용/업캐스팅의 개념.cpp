//��ӿ����� ����ȯ (1)
//ĳ������ ����ȯ�̶�� �ǹ��̴�
//��ĳ����: �ڽ�Ŭ���� ������->�θ�Ŭ���� ������(������)
#include <iostream>
using namespace std;
class Base {

};
class Derived : public Base {

};
int main()
{
	Derived* d = new Derived;
	Base* b = d; //��ĳ���� ��Ȳ
	//�ڽ�Ŭ������ ����Ű�� �����Ͱ�
	//�θ�Ŭ������ �����Ϳ� ������ �����Ѱ��� 
	//����������ȯ �����̴�. ex) double a=1;

}



