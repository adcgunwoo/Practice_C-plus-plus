//��ü ���� �Ҵ�
#include <iostream>
using namespace std;

int main()
{
	int* a = new int(5);
	int* b = new int(3);

	//a = b;   ���� ����(������ ����)
	*a = *b; //���� ����(���� ����)
	cout << *a;
	delete a;
	delete b;
	
}