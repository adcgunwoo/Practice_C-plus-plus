//���� �˴� ���� �Ҵ�: int a;
//C++���� ���� �Ҵ�:�����׷� ���� �߿� ������ �޸𸮿� �Ҵ��ϴ� ��
#include <iostream>
using namespace std;
int main()
{
	int *a = new int(5); //���콺�� �÷����� operator�� ��
						 //operator�� �����ڶ�� �ǹ�
	
	cout << a << endl; //�ּҰ� ���
	cout << *a << endl; //�� ���

	*a = 10;
	cout << a << endl;
	cout << *a << endl;

	delete a;
}    