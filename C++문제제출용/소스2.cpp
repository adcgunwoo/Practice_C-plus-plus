#include <iostream>
using namespace std;
int main()
{
	int a = 7; //a�� ����, 7�� ����,C���� �Ȱ���
	//�� ������ a�� 7�� �ʱ�ȭ �ߴٰ� �Ѵ�.
	double b = 3.14;
	char c = 'C';
	bool d = 0;
	bool e = 1;
	bool f = 10; //bool�� 0 �Ǵ� 1�� �����ϰ� ��, 0�� �ƴ϶� 1�� ���

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	cout << "f = " << f << " " << "f�� ũ��� = " << sizeof(f) << "����Ʈ" << endl;
	return 0;
}