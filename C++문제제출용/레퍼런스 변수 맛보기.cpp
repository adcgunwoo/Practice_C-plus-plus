#include <iostream>
using namespace std;
int main()
{
	int a(5);
	int& p = a;
	//���۷����� �Ʒ����� ���� �ٲ��
	//�Ѵ� �ٲ��
	p = 10;
	cout << p << endl;
	cout << a << endl;

	int b(5);
	int& r1 = b;
	int& r2 = 3;//����� ����ų�� ����
	int& r3 = b * b;//�ĵ� �ȵ�
	//r-value �� l-value
	//b�� ���� ����, 3�� �Ұ�, b*b �Ұ�
	//�� ��ü�� ���� �� �ֱ� ����
	
	//r-value
	int c(5);
	int&& r4 = b;//�ٲܼ� �ִ� ���̱⿡ �ȵ�
	int&& r5 = 4;//���� �Ұ��ϱ⿡ ����
	int&& r6 = b * b;//�Լ����� ���� �Ұ��ϱ⿡ ����


	return 0;
}