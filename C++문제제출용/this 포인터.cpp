//this �ڱ� �ڽ��� ����Ű�� ������
#include <iostream>
using namespace std;
class myclass {
public:
	void printthis() {
		cout << "���� �ּҴ�() " << this << endl;
	}//this�� ������ �ʴ� �Ű�����
//printthis�� ���� �Ű������� ���� �ʾƵ� ��� ��ü �Ҽ������� �� �� �ִ�.
	void printthisptr(myclass *ptr) {
		cout << "���� �ּҴ�(*ptr) " <<ptr <<endl;
	}
};
int main()
{
	myclass a, b;//��ü ����
	cout << "a�� �ּҴ� " << &a << endl;
	cout << "b�� �ּҴ� " << &b << endl;
	a.printthisptr(&a);
	b.printthisptr(&b);
	a.printthis();
	b.printthis();
	//16������ ��µ�
	//&a�� a.printthis()�� ���� ����
	//���� this�� �Ҽӵ� ��ü�� �ּҰ��� ���
	
	return 0;
}