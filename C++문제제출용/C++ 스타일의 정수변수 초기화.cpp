#include <iostream>
using namespace std;
int main()
{
	int a(10);//C++������ �̷��� ���� ����
	//int a=10; �̰� C��� ��Ÿ��
	//C++�� �̷��� �ᵵ ��
	
	//a(5)�� ����, �Լ����� �������� ��
	int b(a);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 0;
}